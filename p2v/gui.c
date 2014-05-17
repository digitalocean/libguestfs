/* virt-p2v
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
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <errno.h>
#include <locale.h>
#include <assert.h>
#include <libintl.h>

#include <pthread.h>

#pragma GCC diagnostic ignored "-Wstrict-prototypes" /* error in <gtk.h> */
#include <gtk/gtk.h>

#include "p2v.h"

/* Interactive GUI configuration. */

static void create_connection_dialog (struct config *);
static void create_conversion_dialog (struct config *);
static void create_running_dialog (void);
static void show_connection_dialog (void);
static void show_conversion_dialog (void);
static void show_running_dialog (void);

/* The connection dialog. */
static GtkWidget *conn_dlg,
  *server_entry, *port_entry,
  *username_entry, *password_entry, *sudo_button,
  *spinner_hbox, *spinner, *spinner_message, *next_button;

/* The conversion dialog. */
static GtkWidget *conv_dlg,
  *guestname_entry, *vcpus_entry, *memory_entry, *debug_button,
  *disks_list, *removable_list, *interfaces_list,
  *start_button;

/* The running dialog which is displayed when virt-v2v is running. */
static GtkWidget *run_dlg,
  *v2v_output_sw, *v2v_output, *log_label, *status_label,
  *cancel_button;

/* The entry point from the main program.
 * Note that gtk_init etc have already been called in main().
 */
void
gui_application (struct config *config)
{
  /* Create the dialogs. */
  create_connection_dialog (config);
  create_conversion_dialog (config);
  create_running_dialog ();

  /* Start by displaying the connection dialog. */
  show_connection_dialog ();

  gtk_main ();
  gdk_threads_leave ();
}

/*----------------------------------------------------------------------*/
/* Connection dialog. */

static void test_connection_clicked (GtkWidget *w, gpointer data);
static void *test_connection_thread (void *data);
static void about_button_clicked (GtkWidget *w, gpointer data);
static void connection_next_clicked (GtkWidget *w, gpointer data);

static void
create_connection_dialog (struct config *config)
{
  GtkWidget *intro, *table;
  GtkWidget *server_label;
  GtkWidget *port_label;
  GtkWidget *username_label;
  GtkWidget *password_label;
  GtkWidget *test_hbox, *test;
  GtkWidget *about;
  char port_str[64];

  conn_dlg = gtk_dialog_new ();
  gtk_window_set_title (GTK_WINDOW (conn_dlg), program_name);
  gtk_window_set_resizable (GTK_WINDOW (conn_dlg), FALSE);

  /* The main dialog area. */
  intro = gtk_label_new (_("Connect to a virt-v2v conversion server over SSH:"));
  gtk_label_set_line_wrap (GTK_LABEL (intro), TRUE);
  gtk_misc_set_padding (GTK_MISC (intro), 10, 10);

  table = gtk_table_new (5, 2, FALSE);
  server_label = gtk_label_new (_("Conversion server:"));
  gtk_misc_set_alignment (GTK_MISC (server_label), 1., 0.5);
  gtk_table_attach (GTK_TABLE (table), server_label,
                    0, 1, 0, 1, GTK_FILL, GTK_FILL, 4, 4);
  server_entry = gtk_entry_new ();
  if (config->server != NULL)
    gtk_entry_set_text (GTK_ENTRY (server_entry), config->server);
  gtk_table_attach (GTK_TABLE (table), server_entry,
                    1, 2, 0, 1, GTK_FILL, GTK_FILL, 4, 4);

  port_label = gtk_label_new (_("SSH port:"));
  gtk_misc_set_alignment (GTK_MISC (port_label), 1., 0.5);
  gtk_table_attach (GTK_TABLE (table), port_label,
                    0, 1, 1, 2, GTK_FILL, GTK_FILL, 4, 4);
  port_entry = gtk_entry_new ();
  gtk_entry_set_width_chars (GTK_ENTRY (port_entry), 6);
  snprintf (port_str, sizeof port_str, "%d", config->port);
  gtk_entry_set_text (GTK_ENTRY (port_entry), port_str);
  gtk_table_attach (GTK_TABLE (table), port_entry,
                    1, 2, 1, 2, GTK_FILL, GTK_FILL, 4, 4);

  username_label = gtk_label_new (_("User name:"));
  gtk_misc_set_alignment (GTK_MISC (username_label), 1., 0.5);
  gtk_table_attach (GTK_TABLE (table), username_label,
                    0, 1, 2, 3, GTK_FILL, GTK_FILL, 4, 4);
  username_entry = gtk_entry_new ();
  if (config->username != NULL)
    gtk_entry_set_text (GTK_ENTRY (username_entry), config->username);
  else
    gtk_entry_set_text (GTK_ENTRY (username_entry), "root");
  gtk_table_attach (GTK_TABLE (table), username_entry,
                    1, 2, 2, 3, GTK_FILL, GTK_FILL, 4, 4);

  password_label = gtk_label_new (_("Password:"));
  gtk_misc_set_alignment (GTK_MISC (password_label), 1., 0.5);
  gtk_table_attach (GTK_TABLE (table), password_label,
                    0, 1, 3, 4, GTK_FILL, GTK_FILL, 4, 4);
  password_entry = gtk_entry_new ();
  gtk_entry_set_visibility (GTK_ENTRY (password_entry), FALSE);
#ifdef GTK_INPUT_PURPOSE_PASSWORD
  gtk_entry_set_input_purpose (GTK_ENTRY (password_entry),
                               GTK_INPUT_PURPOSE_PASSWORD);
#endif
  if (config->password != NULL)
    gtk_entry_set_text (GTK_ENTRY (password_entry), config->password);
  gtk_table_attach (GTK_TABLE (table), password_entry,
                    1, 2, 3, 4, GTK_FILL, GTK_FILL, 4, 4);

  sudo_button =
    gtk_check_button_new_with_label (_("Use sudo when running virt-v2v"));
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (sudo_button),
                                config->sudo);
  gtk_table_attach (GTK_TABLE (table), sudo_button,
                    1, 2, 4, 5, GTK_FILL, GTK_FILL, 4, 4);

  test_hbox = gtk_hbox_new (FALSE, 0);
  test = gtk_button_new_with_label (_("Test connection"));
  gtk_box_pack_start (GTK_BOX (test_hbox), test, TRUE, FALSE, 0);

  spinner_hbox = gtk_hbox_new (FALSE, 10);
  spinner = gtk_spinner_new ();
  gtk_box_pack_start (GTK_BOX (spinner_hbox), spinner, FALSE, FALSE, 0);
  spinner_message = gtk_label_new (NULL);
  gtk_label_set_line_wrap (GTK_LABEL (spinner_message), TRUE);
  gtk_misc_set_padding (GTK_MISC (spinner_message), 10, 10);
  gtk_box_pack_start (GTK_BOX (spinner_hbox), spinner_message, TRUE, TRUE, 0);

  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (conn_dlg)->vbox),
                      intro, TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (conn_dlg)->vbox),
                      table, TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (conn_dlg)->vbox),
                      test_hbox, FALSE, FALSE, 0);
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (conn_dlg)->vbox),
                      spinner_hbox, TRUE, TRUE, 0);

  /* Buttons. */
  gtk_dialog_add_buttons (GTK_DIALOG (conn_dlg),
                          _("Configure network ..."), 1,
                          _("About ..."), 2,
                          _("Next"), 3,
                          NULL);

  next_button = gtk_dialog_get_widget_for_response (GTK_DIALOG (conn_dlg), 3);
  gtk_widget_set_sensitive (next_button, FALSE);

  about = gtk_dialog_get_widget_for_response (GTK_DIALOG (conn_dlg), 2);

  /* Signals. */
  g_signal_connect_swapped (G_OBJECT (conn_dlg), "destroy",
                            G_CALLBACK (gtk_main_quit), NULL);
  g_signal_connect (G_OBJECT (test), "clicked",
                    G_CALLBACK (test_connection_clicked), config);
  g_signal_connect (G_OBJECT (about), "clicked",
                    G_CALLBACK (about_button_clicked), NULL);
  g_signal_connect (G_OBJECT (next_button), "clicked",
                    G_CALLBACK (connection_next_clicked), NULL);
}

static void
show_connection_dialog (void)
{
  /* Hide the other dialogs. */
  gtk_widget_hide (conv_dlg);
  gtk_widget_hide (run_dlg);

  /* Show everything except the spinner. */
  gtk_widget_show_all (conn_dlg);
  gtk_widget_hide_all (spinner_hbox);
}

static void
test_connection_clicked (GtkWidget *w, gpointer data)
{
  struct config *config = data;
  const gchar *port_str;
  size_t errors = 0;
  struct config *copy;
  int err;
  pthread_t tid;
  pthread_attr_t attr;

  gtk_label_set_text (GTK_LABEL (spinner_message), "");
  gtk_widget_show_all (spinner_hbox);

  /* Get the fields from the various widgets. */
  free (config->server);
  config->server = strdup (gtk_entry_get_text (GTK_ENTRY (server_entry)));
  if (STREQ (config->server, "")) {
    gtk_label_set_text (GTK_LABEL (spinner_message),
                        _("error: No conversion server given."));
    gtk_widget_grab_focus (server_entry);
    errors++;
  }
  port_str = gtk_entry_get_text (GTK_ENTRY (port_entry));
  if (sscanf (port_str, "%d", &config->port) != 1 ||
      config->port <= 0 || config->port >= 65536) {
    gtk_label_set_text (GTK_LABEL (spinner_message),
                        _("error: Invalid port number. If in doubt, use \"22\"."));
    gtk_widget_grab_focus (port_entry);
    errors++;
  }
  free (config->username);
  config->username = strdup (gtk_entry_get_text (GTK_ENTRY (username_entry)));
  if (STREQ (config->username, "")) {
    gtk_label_set_text (GTK_LABEL (spinner_message),
                        _("error: No user name.  If in doubt, use \"root\"."));
    gtk_widget_grab_focus (username_entry);
    errors++;
  }
  free (config->password);
  config->password = strdup (gtk_entry_get_text (GTK_ENTRY (password_entry)));

  config->sudo = gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (sudo_button));

  if (errors)
    return;

  /* Give the testing thread its own copy of the config in case we
   * update the config in the main thread.
   */
  copy = copy_config (config);

  /* No errors so far, so test the connection in a background thread. */
  pthread_attr_init (&attr);
  pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_DETACHED);
  err = pthread_create (&tid, &attr, test_connection_thread, copy);
  if (err != 0) {
    fprintf (stderr, "pthread_create: %s\n", strerror (err));
    exit (EXIT_FAILURE);
  }
  pthread_attr_destroy (&attr);
}

/* Run test_connection (in a detached background thread).  Once it
 * finishes stop the spinner and set the spinner message
 * appropriately.  If the test is successful then we enable the "Next"
 * button.
 */
static void *
test_connection_thread (void *data)
{
  struct config *copy = data;
  int r;

  gdk_threads_enter ();
  gtk_label_set_text (GTK_LABEL (spinner_message),
                      _("Testing the connection to the conversion server ..."));
  gtk_spinner_start (GTK_SPINNER (spinner));
  gdk_threads_leave ();
  r = test_connection (copy);
  free_config (copy);
  gdk_threads_enter ();
  gtk_spinner_stop (GTK_SPINNER (spinner));

  if (r == -1) {
    /* Error testing the connection. */
    const char *err = get_ssh_error ();

    gtk_label_set_text (GTK_LABEL (spinner_message), err);
    /* Disable the Next button. */
    gtk_widget_set_sensitive (next_button, FALSE);
  }
  else {
    /* Connection is good. */
    gtk_label_set_text (GTK_LABEL (spinner_message),
                        _("Connected to the conversion server.\n"
                          "Press the \"Next\" button to configure the conversion process."));
    /* Enable the Next button. */
    gtk_widget_set_sensitive (next_button, TRUE);
    gtk_widget_grab_focus (next_button);
  }
  gdk_threads_leave ();

  /* Thread is detached anyway, so no one is waiting for the status. */
  return NULL;
}

static void
about_button_clicked (GtkWidget *w, gpointer data)
{
  gtk_show_about_dialog (GTK_WINDOW (conn_dlg),
                         "program-name", program_name,
                         "version", PACKAGE_VERSION,
                         "copyright", "\u00A9 2009-2014 Red Hat Inc.",
                         "comments", "Convert a physical machine to use KVM",
                         "license", gplv2plus,
                         "website", "http://libguestfs.org/",
                         "authors", authors,
                         NULL);
}

/* The connection dialog Next button has been clicked. */
static void
connection_next_clicked (GtkWidget *w, gpointer data)
{
  /* Switch to the conversion dialog. */
  show_conversion_dialog ();
}

/*----------------------------------------------------------------------*/
/* Conversion dialog. */

static void populate_disks (GtkTreeView *disks_list);
static void populate_removable (GtkTreeView *removable_list);
static void populate_interfaces (GtkTreeView *interfaces_list);
static void toggled (GtkCellRendererToggle *cell, gchar *path_str, gpointer data);
static void set_disks_from_ui (struct config *);
static void set_removable_from_ui (struct config *);
static void set_interfaces_from_ui (struct config *);
static void conversion_back_clicked (GtkWidget *w, gpointer data);
static void start_conversion_clicked (GtkWidget *w, gpointer data);
static void notify_ui_callback (int type, const char *data);

enum {
  DISKS_COL_CONVERT = 0,
  DISKS_COL_DEVICE,
  DISKS_COL_SIZE,
  DISKS_COL_MODEL,
  NUM_DISKS_COLS,
};

enum {
  REMOVABLE_COL_CONVERT = 0,
  REMOVABLE_COL_DEVICE,
  NUM_REMOVABLE_COLS,
};

enum {
  INTERFACES_COL_CONVERT = 0,
  INTERFACES_COL_DEVICE,
  NUM_INTERFACES_COLS,
};

static void
create_conversion_dialog (struct config *config)
{
  GtkWidget *back;
  GtkWidget *hbox, *right_vbox;
  GtkWidget *target, *target_vbox, *target_tbl;
  GtkWidget *guestname_label, *vcpus_label, *memory_label;
  GtkWidget *disks_frame, *disks_sw;
  GtkWidget *removable_frame, *removable_sw;
  GtkWidget *interfaces_frame, *interfaces_sw;
  char vcpus_str[64];
  char memory_str[64];

  conv_dlg = gtk_dialog_new ();
  gtk_window_set_title (GTK_WINDOW (conv_dlg), program_name);
  gtk_window_set_resizable (GTK_WINDOW (conv_dlg), FALSE);
  /* XXX It would be nice not to have to set this explicitly, but
   * if we don't then Gtk chooses a very small window.
   */
  gtk_widget_set_size_request (conv_dlg, 800, 500);

  /* The main dialog area. */
  hbox = gtk_hbox_new (TRUE, 1);
  right_vbox = gtk_vbox_new (TRUE, 1);

  /* The left column: target properties. */
  target = gtk_frame_new (_("Target properties"));

  target_vbox = gtk_vbox_new (FALSE, 1);

  target_tbl = gtk_table_new (3, 2, FALSE);
  guestname_label = gtk_label_new (_("Name:"));
  gtk_misc_set_alignment (GTK_MISC (guestname_label), 1., 0.5);
  gtk_table_attach (GTK_TABLE (target_tbl), guestname_label,
                    0, 1, 0, 1, GTK_FILL, GTK_FILL, 1, 1);
  guestname_entry = gtk_entry_new ();
  if (config->guestname != NULL)
    gtk_entry_set_text (GTK_ENTRY (guestname_entry), config->guestname);
  gtk_table_attach (GTK_TABLE (target_tbl), guestname_entry,
                    1, 2, 0, 1, GTK_FILL, GTK_FILL, 1, 1);

  vcpus_label = gtk_label_new (_("# vCPUs:"));
  gtk_misc_set_alignment (GTK_MISC (vcpus_label), 1., 0.5);
  gtk_table_attach (GTK_TABLE (target_tbl), vcpus_label,
                    0, 1, 1, 2, GTK_FILL, GTK_FILL, 1, 1);
  vcpus_entry = gtk_entry_new ();
  snprintf (vcpus_str, sizeof vcpus_str, "%d", config->vcpus);
  gtk_entry_set_text (GTK_ENTRY (vcpus_entry), vcpus_str);
  gtk_table_attach (GTK_TABLE (target_tbl), vcpus_entry,
                    1, 2, 1, 2, GTK_FILL, GTK_FILL, 1, 1);

  memory_label = gtk_label_new (_("Memory (MB):"));
  gtk_misc_set_alignment (GTK_MISC (memory_label), 1., 0.5);
  gtk_table_attach (GTK_TABLE (target_tbl), memory_label,
                    0, 1, 2, 3, GTK_FILL, GTK_FILL, 1, 1);
  memory_entry = gtk_entry_new ();
  snprintf (memory_str, sizeof memory_str, "%" PRIu64,
            config->memory / 1024 / 1024);
  gtk_entry_set_text (GTK_ENTRY (memory_entry), memory_str);
  gtk_table_attach (GTK_TABLE (target_tbl), memory_entry,
                    1, 2, 2, 3, GTK_FILL, GTK_FILL, 1, 1);

  debug_button =
    gtk_check_button_new_with_label (_("Enable server-side debugging\n"
                                       "(This is saved in /tmp on the conversion server)"));
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (debug_button),
                                config->verbose);

  gtk_box_pack_start (GTK_BOX (target_vbox), target_tbl, TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (target_vbox), debug_button, TRUE, TRUE, 0);
  gtk_container_add (GTK_CONTAINER (target), target_vbox);

  /* The right column: select devices to be converted. */
  disks_frame = gtk_frame_new (_("Fixed hard disks"));
  disks_sw = gtk_scrolled_window_new (NULL, NULL);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (disks_sw),
                                  GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
  disks_list = gtk_tree_view_new ();
  populate_disks (GTK_TREE_VIEW (disks_list));
  gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW (disks_sw),
                                         disks_list);
  gtk_container_add (GTK_CONTAINER (disks_frame), disks_sw);

  removable_frame = gtk_frame_new (_("Removable media"));
  removable_sw = gtk_scrolled_window_new (NULL, NULL);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (removable_sw),
                                  GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
  removable_list = gtk_tree_view_new ();
  populate_removable (GTK_TREE_VIEW (removable_list));
  gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW (removable_sw),
                                         removable_list);
  gtk_container_add (GTK_CONTAINER (removable_frame), removable_sw);

  interfaces_frame = gtk_frame_new (_("Network interfaces"));
  interfaces_sw = gtk_scrolled_window_new (NULL, NULL);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (interfaces_sw),
                                  GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
  interfaces_list = gtk_tree_view_new ();
  populate_interfaces (GTK_TREE_VIEW (interfaces_list));
  gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW (interfaces_sw),
                                         interfaces_list);
  gtk_container_add (GTK_CONTAINER (interfaces_frame), interfaces_sw);

  gtk_box_pack_start (GTK_BOX (right_vbox), disks_frame, TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (right_vbox), removable_frame, TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (right_vbox), interfaces_frame, TRUE, TRUE, 0);

  gtk_box_pack_start (GTK_BOX (hbox), target, TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (hbox), right_vbox, TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (conv_dlg)->vbox),
                      hbox, TRUE, TRUE, 0);

  /* Buttons. */
  gtk_dialog_add_buttons (GTK_DIALOG (conv_dlg),
                          _("Back"), 1,
                          _("Start conversion"), 2,
                          NULL);
  back = gtk_dialog_get_widget_for_response (GTK_DIALOG (conv_dlg), 1);
  start_button = gtk_dialog_get_widget_for_response (GTK_DIALOG (conv_dlg), 2);

  /* Signals. */
  g_signal_connect_swapped (G_OBJECT (conv_dlg), "destroy",
                            G_CALLBACK (gtk_main_quit), NULL);
  g_signal_connect (G_OBJECT (back), "clicked",
                    G_CALLBACK (conversion_back_clicked), NULL);
  g_signal_connect (G_OBJECT (start_button), "clicked",
                    G_CALLBACK (start_conversion_clicked), config);
}

static void
show_conversion_dialog (void)
{
  /* Hide the other dialogs. */
  gtk_widget_hide (conn_dlg);
  gtk_widget_hide (run_dlg);

  /* Show the conversion dialog. */
  gtk_widget_show_all (conv_dlg);
}

static void
populate_disks (GtkTreeView *disks_list)
{
  GtkListStore *disks_store;
  GtkCellRenderer *disks_col_convert, *disks_col_device,
    *disks_col_size, *disks_col_model;
  GtkTreeIter iter;
  size_t i;

  disks_store = gtk_list_store_new (NUM_DISKS_COLS,
                                    G_TYPE_BOOLEAN, G_TYPE_STRING,
                                    G_TYPE_STRING, G_TYPE_STRING);
  if (all_disks != NULL) {
    for (i = 0; all_disks[i] != NULL; ++i) {
      CLEANUP_FREE char *size_filename = NULL;
      CLEANUP_FREE char *model_filename = NULL;
      CLEANUP_FREE char *size_str = NULL;
      CLEANUP_FREE char *size_gb = NULL;
      CLEANUP_FREE char *model = NULL;
      uint64_t size;

      if (asprintf (&size_filename, "/sys/block/%s/size",
                    all_disks[i]) == -1) {
        perror ("asprintf");
        exit (EXIT_FAILURE);
      }
      if (g_file_get_contents (size_filename, &size_str, NULL, NULL) &&
          sscanf (size_str, "%" SCNu64, &size) == 1) {
        size /= 2*1024*1024; /* size from kernel is given in sectors? */
        if (asprintf (&size_gb, "%" PRIu64, size) == -1) {
          perror ("asprintf");
          exit (EXIT_FAILURE);
        }
      }

      if (asprintf (&model_filename, "/sys/block/%s/device/model",
                    all_disks[i]) == -1) {
        perror ("asprintf");
        exit (EXIT_FAILURE);
      }
      if (g_file_get_contents (model_filename, &model, NULL, NULL)) {
        /* Need to chomp trailing \n from the content. */
        size_t len = strlen (model);
        if (len > 0 && model[len-1] == '\n')
          model[len-1] = '\0';
      } else {
        model = strdup ("");
      }

      gtk_list_store_append (disks_store, &iter);
      gtk_list_store_set (disks_store, &iter,
                          DISKS_COL_CONVERT, TRUE,
                          DISKS_COL_DEVICE, all_disks[i],
                          DISKS_COL_SIZE, size_gb,
                          DISKS_COL_MODEL, model,
                          -1);
    }
  }
  gtk_tree_view_set_model (disks_list,
                           GTK_TREE_MODEL (disks_store));
  gtk_tree_view_set_headers_visible (disks_list, TRUE);
  disks_col_convert = gtk_cell_renderer_toggle_new ();
  gtk_tree_view_insert_column_with_attributes (disks_list,
                                               -1,
                                               _("Convert"),
                                               disks_col_convert,
                                               "active", DISKS_COL_CONVERT,
                                               NULL);
  disks_col_device = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (disks_list,
                                               -1,
                                               _("Device"),
                                               disks_col_device,
                                               "text", DISKS_COL_DEVICE,
                                               NULL);
  disks_col_size = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (disks_list,
                                               -1,
                                               _("Size (GB)"),
                                               disks_col_size,
                                               "text", DISKS_COL_SIZE,
                                               NULL);
  disks_col_model = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (disks_list,
                                               -1,
                                               _("Model"),
                                               disks_col_model,
                                               "text", DISKS_COL_MODEL,
                                               NULL);

  g_signal_connect (disks_col_convert, "toggled",
                    G_CALLBACK (toggled), disks_store);
}

static void
populate_removable (GtkTreeView *removable_list)
{
  GtkListStore *removable_store;
  GtkCellRenderer *removable_col_convert, *removable_col_device;
  GtkTreeIter iter;
  size_t i;

  removable_store = gtk_list_store_new (NUM_REMOVABLE_COLS,
                                        G_TYPE_BOOLEAN, G_TYPE_STRING);
  if (all_removable != NULL) {
    for (i = 0; all_removable[i] != NULL; ++i) {
      gtk_list_store_append (removable_store, &iter);
      gtk_list_store_set (removable_store, &iter,
                          REMOVABLE_COL_CONVERT, TRUE,
                          REMOVABLE_COL_DEVICE, all_removable[i],
                          -1);
    }
  }
  gtk_tree_view_set_model (removable_list,
                           GTK_TREE_MODEL (removable_store));
  gtk_tree_view_set_headers_visible (removable_list, TRUE);
  removable_col_convert = gtk_cell_renderer_toggle_new ();
  gtk_tree_view_insert_column_with_attributes (removable_list,
                                               -1,
                                               _("Convert"),
                                               removable_col_convert,
                                               "active", REMOVABLE_COL_CONVERT,
                                               NULL);
  removable_col_device = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (removable_list,
                                               -1,
                                               _("Device"),
                                               removable_col_device,
                                               "text", REMOVABLE_COL_DEVICE,
                                               NULL);

  g_signal_connect (removable_col_convert, "toggled",
                    G_CALLBACK (toggled), removable_store);
}

static void
populate_interfaces (GtkTreeView *interfaces_list)
{
  GtkListStore *interfaces_store;
  GtkCellRenderer *interfaces_col_convert, *interfaces_col_device;
  GtkTreeIter iter;
  size_t i;

  interfaces_store = gtk_list_store_new (NUM_INTERFACES_COLS,
                                         G_TYPE_BOOLEAN, G_TYPE_STRING);
  if (all_interfaces) {
    for (i = 0; all_interfaces[i] != NULL; ++i) {
      gtk_list_store_append (interfaces_store, &iter);
      gtk_list_store_set (interfaces_store, &iter,
                          INTERFACES_COL_CONVERT, TRUE,
                          INTERFACES_COL_DEVICE, all_interfaces[i],
                          -1);
    }
  }
  gtk_tree_view_set_model (interfaces_list,
                           GTK_TREE_MODEL (interfaces_store));
  gtk_tree_view_set_headers_visible (interfaces_list, TRUE);
  interfaces_col_convert = gtk_cell_renderer_toggle_new ();
  gtk_tree_view_insert_column_with_attributes (interfaces_list,
                                               -1,
                                               _("Convert"),
                                               interfaces_col_convert,
                                               "active", INTERFACES_COL_CONVERT,
                                               NULL);
  interfaces_col_device = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (interfaces_list,
                                               -1,
                                               _("Device"),
                                               interfaces_col_device,
                                               "text", INTERFACES_COL_DEVICE,
                                               NULL);

  g_signal_connect (interfaces_col_convert, "toggled",
                    G_CALLBACK (toggled), interfaces_store);
}

static void
toggled (GtkCellRendererToggle *cell, gchar *path_str, gpointer data)
{
  GtkTreeModel *model = data;
  GtkTreePath *path = gtk_tree_path_new_from_string (path_str);
  GtkTreeIter iter;
  gboolean v;

  gtk_tree_model_get_iter (model, &iter, path);
  gtk_tree_model_get (model, &iter, 0 /* CONVERT */, &v, -1);
  v ^= 1;
  gtk_list_store_set (GTK_LIST_STORE (model), &iter, 0 /* CONVERT */, v, -1);
  gtk_tree_path_free (path);
}

static void
set_from_ui_generic (char **all, char ***ret, GtkTreeView *list)
{
  GtkTreeModel *model;
  GtkTreeIter iter;
  gboolean b, v;
  size_t i, j;

  if (all == NULL) {
    guestfs___free_string_list (*ret);
    *ret = NULL;
    return;
  }

  model = gtk_tree_view_get_model (list);

  guestfs___free_string_list (*ret);
  *ret = malloc ((1 + guestfs___count_strings (all)) * sizeof (char *));
  if (*ret == NULL) {
    perror ("malloc");
    exit (EXIT_FAILURE);
  }
  i = j = 0;

  b = gtk_tree_model_get_iter_first (model, &iter);
  while (b) {
    gtk_tree_model_get (model, &iter, 0 /* CONVERT */, &v, -1);
    if (v) {
      assert (all[i] != NULL);
      (*ret)[j++] = strdup (all[i]);
    }
    b = gtk_tree_model_iter_next (model, &iter);
    ++i;
  }

  (*ret)[j] = NULL;
}

static void
set_disks_from_ui (struct config *config)
{
  set_from_ui_generic (all_disks, &config->disks,
                       GTK_TREE_VIEW (disks_list));
}

static void
set_removable_from_ui (struct config *config)
{
  set_from_ui_generic (all_removable, &config->removable,
                       GTK_TREE_VIEW (removable_list));
}

static void
set_interfaces_from_ui (struct config *config)
{
  set_from_ui_generic (all_interfaces, &config->interfaces,
                       GTK_TREE_VIEW (interfaces_list));
}

/* The conversion dialog Back button has been clicked. */
static void
conversion_back_clicked (GtkWidget *w, gpointer data)
{
  /* Switch to the connection dialog. */
  show_connection_dialog ();

  /* Better disable the Next button so the user is forced to
   * do "Test connection" again.
   */
  gtk_widget_set_sensitive (next_button, FALSE);
}

/*----------------------------------------------------------------------*/
/* Running dialog. */

static void set_log_dir (const char *remote_dir);
static void set_status (const char *msg);
static void add_v2v_output (const char *msg);
static void *start_conversion_thread (void *data);

static void
create_running_dialog (void)
{
  run_dlg = gtk_dialog_new ();
  gtk_window_set_title (GTK_WINDOW (run_dlg), program_name);
  gtk_window_set_resizable (GTK_WINDOW (run_dlg), FALSE);

  /* The main dialog area. */
  v2v_output_sw = gtk_scrolled_window_new (NULL, NULL);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (v2v_output_sw),
                                  GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
  v2v_output = gtk_text_view_new ();
  gtk_text_view_set_editable (GTK_TEXT_VIEW (v2v_output), FALSE);
  gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (v2v_output), GTK_WRAP_CHAR);
  gtk_widget_set_size_request (v2v_output, 700, 400);
  log_label = gtk_label_new (NULL);
  gtk_misc_set_alignment (GTK_MISC (log_label), 0., 0.5);
  gtk_misc_set_padding (GTK_MISC (log_label), 10, 10);
  set_log_dir (NULL);
  status_label = gtk_label_new (NULL);
  gtk_misc_set_alignment (GTK_MISC (status_label), 0., 0.5);
  gtk_misc_set_padding (GTK_MISC (status_label), 10, 10);

  gtk_container_add (GTK_CONTAINER (v2v_output_sw), v2v_output);

  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (run_dlg)->vbox),
                      v2v_output_sw, TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (run_dlg)->vbox),
                      log_label, TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (run_dlg)->vbox),
                      status_label, TRUE, TRUE, 0);

  /* Buttons. */
  gtk_dialog_add_buttons (GTK_DIALOG (run_dlg),
                          _("Cancel conversion"), 1,
                          NULL);
  cancel_button = gtk_dialog_get_widget_for_response (GTK_DIALOG (conv_dlg), 1);
  gtk_widget_set_sensitive (cancel_button, FALSE);

  /* Signals. */
  g_signal_connect_swapped (G_OBJECT (run_dlg), "destroy",
                            G_CALLBACK (gtk_main_quit), NULL);
}

static void
show_running_dialog (void)
{
  /* Hide the other dialogs. */
  gtk_widget_hide (conn_dlg);
  gtk_widget_hide (conv_dlg);

  /* Show the running dialog. */
  gtk_widget_show_all (run_dlg);
  gtk_widget_set_sensitive (cancel_button, FALSE);
}

static void
set_log_dir (const char *remote_dir)
{
  CLEANUP_FREE char *msg;

  if (asprintf (&msg,
                _("Log files and debug information "
                  "is saved to this directory "
                  "on the conversion server:\n"
                  "%s"),
                remote_dir ? remote_dir : "") == -1) {
    perror ("asprintf");
    exit (EXIT_FAILURE);
  }

  gtk_label_set_text (GTK_LABEL (log_label), msg);
}

static void
set_status (const char *msg)
{
  gtk_label_set_text (GTK_LABEL (status_label), msg);
}

/* Append output from the virt-v2v process to the buffer, and scroll
 * to ensure it is visible.
 */
static void
add_v2v_output (const char *msg)
{
  GtkTextBuffer *buf;
  GtkTextIter iter;

  /* Insert it at the end. */
  buf = gtk_text_view_get_buffer (GTK_TEXT_VIEW (v2v_output));
  gtk_text_buffer_get_end_iter (buf, &iter);
  gtk_text_buffer_insert (buf, &iter, msg, -1);

  /* Scroll to the end of the buffer. */
  gtk_text_buffer_get_end_iter (buf, &iter);
  gtk_text_view_scroll_to_iter (GTK_TEXT_VIEW (v2v_output), &iter,
                                0, FALSE, 0., 1.);
}

/* User clicked the Start conversion button. */
static void
start_conversion_clicked (GtkWidget *w, gpointer data)
{
  struct config *config = data;
  int i;
  const char *vcpus_str;
  const char *memory_str;
  GtkWidget *dlg;
  struct config *copy;
  int err;
  pthread_t tid;
  pthread_attr_t attr;

  /* Unpack dialog fields and check them. */
  free (config->guestname);
  config->guestname = strdup (gtk_entry_get_text (GTK_ENTRY (guestname_entry)));

  if (STREQ (config->guestname, "")) {
    dlg = gtk_message_dialog_new (GTK_WINDOW (conv_dlg),
                                  GTK_DIALOG_DESTROY_WITH_PARENT,
                                  GTK_MESSAGE_ERROR,
                                  GTK_BUTTONS_OK,
                                  _("The guest \"Name\" field is empty."));
    gtk_window_set_title (GTK_WINDOW (dlg), _("Error"));
    gtk_dialog_run (GTK_DIALOG (dlg));
    gtk_widget_destroy (dlg);
    gtk_widget_grab_focus (guestname_entry);
    return;
  }

  vcpus_str = gtk_entry_get_text (GTK_ENTRY (vcpus_entry));
  if (sscanf (vcpus_str, "%d", &i) == 1 && i > 0)
    config->vcpus = i;
  else
    config->vcpus = 1;

  memory_str = gtk_entry_get_text (GTK_ENTRY (memory_entry));
  if (sscanf (memory_str, "%d", &i) == 1 && i >= 256)
    config->memory = (uint64_t) i * 1024 * 1024;
  else
    config->memory = 1024 * 1024 * 1024;

  config->verbose =
    gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (debug_button));

  /* Get the list of disks to be converted. */
  set_disks_from_ui (config);

  /* The list of disks must be non-empty. */
  if (config->disks == NULL || guestfs___count_strings (config->disks) == 0) {
    dlg = gtk_message_dialog_new (GTK_WINDOW (conv_dlg),
                                  GTK_DIALOG_DESTROY_WITH_PARENT,
                                  GTK_MESSAGE_ERROR,
                                  GTK_BUTTONS_OK,
                                  _("No disks were selected for conversion.\n"
                                    "At least one fixed hard disk must be selected.\n"));
    gtk_window_set_title (GTK_WINDOW (dlg), _("Error"));
    gtk_dialog_run (GTK_DIALOG (dlg));
    gtk_widget_destroy (dlg);
    return;
  }

  /* List of removable media and network interfaces. */
  set_removable_from_ui (config);
  set_interfaces_from_ui (config);

  /* Display the UI for conversion. */
  show_running_dialog ();

  /* Do the conversion, in a background thread. */

  /* Give the conversion (background) thread its own copy of the
   * config in case we update the config in the main thread.
   */
  copy = copy_config (config);

  pthread_attr_init (&attr);
  pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_DETACHED);
  err = pthread_create (&tid, &attr, start_conversion_thread, copy);
  if (err != 0) {
    fprintf (stderr, "pthread_create: %s\n", strerror (err));
    exit (EXIT_FAILURE);
  }
  pthread_attr_destroy (&attr);
}

static void *
start_conversion_thread (void *data)
{
  struct config *copy = data;
  int r;
  GtkWidget *dlg;

  r = start_conversion (copy, notify_ui_callback);
  free_config (copy);

  gdk_threads_enter ();

  if (r == -1) {
    const char *err = get_conversion_error ();

    dlg = gtk_message_dialog_new (GTK_WINDOW (run_dlg),
                                  GTK_DIALOG_DESTROY_WITH_PARENT,
                                  GTK_MESSAGE_ERROR,
                                  GTK_BUTTONS_OK,
                                  _("Conversion failed: %s"), err);
    gtk_window_set_title (GTK_WINDOW (dlg), _("Conversion failed"));
    gtk_dialog_run (GTK_DIALOG (dlg));
    gtk_widget_destroy (dlg);
  }
  else {
    dlg = gtk_message_dialog_new (GTK_WINDOW (run_dlg),
                                  GTK_DIALOG_DESTROY_WITH_PARENT,
                                  GTK_MESSAGE_ERROR,
                                  GTK_BUTTONS_OK,
                                  _("The conversion was successful."));
    gtk_window_set_title (GTK_WINDOW (dlg), _("Conversion was successful"));
    gtk_dialog_run (GTK_DIALOG (dlg));
    gtk_widget_destroy (dlg);
  }

  gdk_threads_leave ();

  /* Thread is detached anyway, so no one is waiting for the status. */
  return NULL;
}

static void
notify_ui_callback (int type, const char *data)
{
  gdk_threads_enter ();

  switch (type) {
  case NOTIFY_LOG_DIR:
    set_log_dir (data);
    break;

  case NOTIFY_REMOTE_MESSAGE:
    add_v2v_output (data);
    break;

  case NOTIFY_STATUS:
    set_status (data);
    break;

  default:
    fprintf (stderr,
             "%s: unknown message during conversion: type=%d data=%s\n",
             program_name, type, data);
  }

  gdk_threads_leave ();
}
