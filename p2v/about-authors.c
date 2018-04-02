/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED
 *          from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2018 Red Hat Inc.
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

#include <config.h>

#include "p2v.h"

/* Authors involved with virt-v2v and virt-p2v directly. */
const char *authors[] = {
  "Cédric Bosdonnat",
  "John Eckersberg",
  "Junqin Zhou",
  "Kean Li",
  "Kun Wei",
  "Laura Bailey",
  "Matthew Booth",
  "Mike Latimer",
  "Ming Xie",
  "Pino Toscano",
  "Richard W.M. Jones",
  "Roman Kagan",
  "Shahar Havivi",
  "Tingting Zheng",
  "Xiang Hua Chen",
  "Yehuda Zimmerman",
  NULL
};

/* Libguestfs quality assurance (if not included above). */
const char *qa[] = {
  NULL
};

/* Libguestfs documentation (if not included above). */
const char *documenters[] = {
  "Yuri Chornoivan",
  NULL
};

/* Libguestfs developers (if not included above). */
const char *others[] = {
  "Adam Huffman",
  "Andrea Bolognani",
  "Angus Salkeld",
  "Ani Peter",
  "Bastien ROUCARIÈS",
  "Cao jin",
  "Charles Duffy",
  "Chen Hanxiao",
  "Cole Robinson",
  "Colin Walters",
  "Dan Lipsitt",
  "Daniel P. Berrangé",
  "Daniel Cabrera",
  "Daniel Exner",
  "Dave Vasilevsky",
  "David Sommerseth",
  "Dawid Zamirski",
  "Douglas Schilling Landgraf",
  "Eric Blake",
  "Erik Nolte",
  "Evaggelos Balaskas",
  "Florian Klink",
  "Gabriele Cerami",
  "Geert Warrink",
  "Guido Günther",
  "Hilko Bengen",
  "Hu Tao",
  "infernix",
  "Jamie Iles",
  "Jaswinder Singh",
  "Jim Meyering",
  "Jiri Popelka",
  "Joseph Wang",
  "Karel Klíč",
  "Kashyap Chamarthy",
  "Ken Stailey",
  "Lars Kellogg-Stedman",
  "Lars Seipel",
  "Lee Yarwood",
  "Marcin Gibula",
  "Margaret Lewicka",
  "Maros Zatko",
  "Martin Kletzander",
  "Masami HIRATA",
  "Matteo Cafasso",
  "Maxim Koltsov",
  "Maxim Perevedentsev",
  "Menanteau Guy",
  "Michael Scherer",
  "Mike Frysinger",
  "Mike Kelly",
  "Mykola Ivanets",
  "Nicholas Strugnell",
  "Nikita A Menkovich",
  "Nikita Menkovich",
  "Nikos Skalkotos",
  "Olaf Hering",
  "Or Goshen",
  "Paul Mackerras",
  "Pavel Butsykin",
  "Piotr Drąg",
  "Qin Guan",
  "Rajesh Ranjan",
  "Robert Antoni Buj Gelonch",
  "Sandeep Shedmake",
  "Shahar Lev",
  "Shankar Prasad",
  "Thomas S Hatch",
  "Tomáš Golembiovský",
  "Török Edwin",
  "Wanlong Gao",
  "Wulf C. Krueger",
  "Yann E. MORIN",
  NULL
};
