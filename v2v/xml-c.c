/* virt-v2v
 * Copyright (C) 2009-2014 Red Hat Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/* Mini interface to libxml2. */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <caml/alloc.h>
#include <caml/custom.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <caml/mlvalues.h>

#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>
#include <libxml/uri.h>

#include "guestfs.h"
#include "guestfs-internal-frontend.h"

#pragma GCC diagnostic ignored "-Wmissing-prototypes"

/* xmlDocPtr type */
#define Doc_val(v) (*((xmlDocPtr *)Data_custom_val(v)))

static void
doc_finalize (value docv)
{
  xmlDocPtr doc = Doc_val (docv);

  if (doc)
    xmlFreeDoc (doc);
}

static struct custom_operations doc_custom_operations = {
  (char *) "doc_custom_operations",
  doc_finalize,
  custom_compare_default,
  custom_hash_default,
  custom_serialize_default,
  custom_deserialize_default
};

/* xmlXPathContextPtr type */
#define Xpathctx_val(v) (*((xmlXPathContextPtr *)Data_custom_val(v)))

static void
xpathctx_finalize (value xpathctxv)
{
  xmlXPathContextPtr xpathctx = Xpathctx_val (xpathctxv);

  if (xpathctx)
    xmlXPathFreeContext (xpathctx);
}

static struct custom_operations xpathctx_custom_operations = {
  (char *) "xpathctx_custom_operations",
  xpathctx_finalize,
  custom_compare_default,
  custom_hash_default,
  custom_serialize_default,
  custom_deserialize_default
};

/* xmlXPathObjectPtr type */
#define Xpathobj_val(v) (*((xmlXPathObjectPtr *)Data_custom_val(v)))

static void
xpathobj_finalize (value xpathobjv)
{
  xmlXPathObjectPtr xpathobj = Xpathobj_val (xpathobjv);

  if (xpathobj)
    xmlXPathFreeObject (xpathobj);
}

static struct custom_operations xpathobj_custom_operations = {
  (char *) "xpathobj_custom_operations",
  xpathobj_finalize,
  custom_compare_default,
  custom_hash_default,
  custom_serialize_default,
  custom_deserialize_default
};

value
v2v_xml_parse_memory (value xmlv)
{
  CAMLparam1 (xmlv);
  CAMLlocal1 (docv);
  xmlDocPtr doc;

  /* For security reasons, call xmlReadMemory (not xmlParseMemory) and
   * pass XML_PARSE_NONET.  See commit 845daded5fddc70f.
   */
  doc = xmlReadMemory (String_val (xmlv), caml_string_length (xmlv),
                       NULL, NULL, XML_PARSE_NONET);
  if (doc == NULL)
    caml_invalid_argument ("parse_memory: unable to parse XML from libvirt");

  docv = caml_alloc_custom (&doc_custom_operations, sizeof (xmlDocPtr), 0, 1);
  Doc_val (docv) = doc;

  CAMLreturn (docv);
}

value
v2v_xml_xpath_new_context (value docv)
{
  CAMLparam1 (docv);
  CAMLlocal1 (xpathctxv);
  xmlDocPtr doc;
  xmlXPathContextPtr xpathctx;

  doc = Doc_val (docv);
  xpathctx = xmlXPathNewContext (doc);
  if (xpathctx == NULL)
    caml_invalid_argument ("xpath_new_context: unable to create xmlXPathNewContext");

  xpathctxv = caml_alloc_custom (&xpathctx_custom_operations,
                                 sizeof (xmlXPathContextPtr), 0, 1);
  Xpathctx_val (xpathctxv) = xpathctx;

  CAMLreturn (xpathctxv);
}

value
v2v_xml_xpath_register_ns (value xpathctxv, value prefix, value uri)
{
  CAMLparam3 (xpathctxv, prefix, uri);
  xmlXPathContextPtr xpathctx;
  int r;

  xpathctx = Xpathctx_val (xpathctxv);
  r = xmlXPathRegisterNs (xpathctx, BAD_CAST String_val (prefix), BAD_CAST String_val (uri));
  if (r == -1)
      caml_invalid_argument ("xpath_register_ns: unable to register namespace");

  CAMLreturn (Val_unit);
}

value
v2v_xml_xpath_eval_expression (value xpathctxv, value exprv)
{
  CAMLparam2 (xpathctxv, exprv);
  CAMLlocal1 (xpathobjv);
  xmlXPathContextPtr xpathctx;
  xmlXPathObjectPtr xpathobj;

  xpathctx = Xpathctx_val (xpathctxv);
  xpathobj = xmlXPathEvalExpression (BAD_CAST String_val (exprv), xpathctx);
  if (xpathobj == NULL)
    caml_invalid_argument ("xpath_eval_expression: unable to evaluate XPath expression");

  xpathobjv = caml_alloc_custom (&xpathobj_custom_operations,
                                 sizeof (xmlXPathObjectPtr), 0, 1);
  Xpathobj_val (xpathobjv) = xpathobj;

  CAMLreturn (xpathobjv);
}

value
v2v_xml_xpathobj_nr_nodes (value xpathobjv)
{
  CAMLparam1 (xpathobjv);
  xmlXPathObjectPtr xpathobj = Xpathobj_val (xpathobjv);

  if (xpathobj->nodesetval == NULL)
    CAMLreturn (Val_int (0));
  else
    CAMLreturn (Val_int (xpathobj->nodesetval->nodeNr));
}

value
v2v_xml_xpathobj_get_node_ptr (value xpathobjv, value iv)
{
  CAMLparam2 (xpathobjv, iv);
  xmlXPathObjectPtr xpathobj = Xpathobj_val (xpathobjv);
  int i = Int_val (iv);

  /* Because xmlNodePtrs are owned by the document, we don't want to
   * wrap this up with a finalizer, so just pass the pointer straight
   * back to OCaml as a value.  OCaml will ignore it because it's
   * outside the heap, and just pass it back to us when needed.  This
   * relies on the xmlDocPtr not being freed, but we pair the node
   * pointer with the doc in the OCaml layer so the GC will not free
   * one without freeing the other.
   */
  CAMLreturn ((value) xpathobj->nodesetval->nodeTab[i]);
}

value
v2v_xml_xpathctx_set_node_ptr (value xpathctxv, value nodev)
{
  CAMLparam2 (xpathctxv, nodev);
  xmlXPathContextPtr xpathctx = Xpathctx_val (xpathctxv);
  xmlNodePtr node = (xmlNodePtr) nodev;

  xpathctx->node = node;

  CAMLreturn (Val_unit);
}

value
v2v_xml_node_ptr_name (value nodev)
{
  CAMLparam1 (nodev);
  xmlNodePtr node = (xmlNodePtr) nodev;

  switch (node->type) {
  case XML_ATTRIBUTE_NODE:
  case XML_ELEMENT_NODE:
    CAMLreturn (caml_copy_string ((char *) node->name));

  default:
    caml_invalid_argument ("node_name: don't know how to get the name of this node");
  }
}

value
v2v_xml_node_ptr_as_string (value docv, value nodev)
{
  CAMLparam2 (docv, nodev);
  xmlDocPtr doc = Doc_val (docv);
  xmlNodePtr node = (xmlNodePtr) nodev;
  CLEANUP_FREE char *str = NULL;

  switch (node->type) {
  case XML_TEXT_NODE:
  case XML_COMMENT_NODE:
  case XML_CDATA_SECTION_NODE:
  case XML_PI_NODE:
    CAMLreturn (caml_copy_string ((char *) node->content));

  case XML_ATTRIBUTE_NODE:
  case XML_ELEMENT_NODE:
    str = (char *) xmlNodeListGetString (doc, node->children, 1);

    if (str == NULL)
      caml_invalid_argument ("node_as_string: xmlNodeListGetString cannot convert node to string");

    CAMLreturn (caml_copy_string (str));

  default:
    caml_invalid_argument ("node_as_string: don't know how to convert this node to a string");
  }
}

value
v2v_xml_parse_uri (value strv)
{
  CAMLparam1 (strv);
  CAMLlocal3 (rv, sv, ov);
  xmlURIPtr uri;

  uri = xmlParseURI (String_val (strv));
  if (uri == NULL)
    caml_invalid_argument ("parse_uri: unable to parse URI");

  rv = caml_alloc_tuple (9);

  /* field 0: uri_scheme : string option */
  if (uri->scheme) {
    sv = caml_copy_string (uri->scheme);
    ov = caml_alloc (1, 0);
    Store_field (ov, 0, sv);
  }
  else ov = Val_int (0);
  Store_field (rv, 0, ov);

  /* field 1: uri_opaque : string option */
  if (uri->opaque) {
    sv = caml_copy_string (uri->opaque);
    ov = caml_alloc (1, 0);
    Store_field (ov, 0, sv);
  }
  else ov = Val_int (0);
  Store_field (rv, 1, ov);

  /* field 2: uri_authority : string option */
  if (uri->authority) {
    sv = caml_copy_string (uri->authority);
    ov = caml_alloc (1, 0);
    Store_field (ov, 0, sv);
  }
  else ov = Val_int (0);
  Store_field (rv, 2, ov);

  /* field 3: uri_server : string option */
  if (uri->server) {
    sv = caml_copy_string (uri->server);
    ov = caml_alloc (1, 0);
    Store_field (ov, 0, sv);
  }
  else ov = Val_int (0);
  Store_field (rv, 3, ov);

  /* field 4: uri_user : string option */
  if (uri->user) {
    sv = caml_copy_string (uri->user);
    ov = caml_alloc (1, 0);
    Store_field (ov, 0, sv);
  }
  else ov = Val_int (0);
  Store_field (rv, 4, ov);

  /* field 5: uri_port : int */
  Store_field (rv, 5, Val_int (uri->port));

  /* field 6: uri_path : string option */
  if (uri->path) {
    sv = caml_copy_string (uri->path);
    ov = caml_alloc (1, 0);
    Store_field (ov, 0, sv);
  }
  else ov = Val_int (0);
  Store_field (rv, 6, ov);

  /* field 7: uri_fragment : string option */
  if (uri->fragment) {
    sv = caml_copy_string (uri->fragment);
    ov = caml_alloc (1, 0);
    Store_field (ov, 0, sv);
  }
  else ov = Val_int (0);
  Store_field (rv, 7, ov);

  /* field 8: uri_query_raw : string option */
  if (uri->query_raw) {
    sv = caml_copy_string (uri->query_raw);
    ov = caml_alloc (1, 0);
    Store_field (ov, 0, sv);
  }
  else ov = Val_int (0);
  Store_field (rv, 8, ov);

  xmlFreeURI (uri);

  CAMLreturn (rv);
}
