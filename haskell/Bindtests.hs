{- libguestfs generated file
   WARNING: THIS FILE IS GENERATED FROM:
     generator/generator_*.ml
   ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
  
   Copyright (C) 2009-2012 Red Hat Inc.
  
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
  
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
  
   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
-}

module Bindtests where
import qualified Guestfs

main = do
  g <- Guestfs.create
  Guestfs.test0 g "abc" (Just "def") [] False 0 0 "123" "456" "abc\0abc"
  Guestfs.test0 g "abc" Nothing [] False 0 0 "123" "456" "abc\0abc"
  Guestfs.test0 g "" (Just "def") [] False 0 0 "123" "456" "abc\0abc"
  Guestfs.test0 g "" (Just "") [] False 0 0 "123" "456" "abc\0abc"
  Guestfs.test0 g "abc" (Just "def") ["1"] False 0 0 "123" "456" "abc\0abc"
  Guestfs.test0 g "abc" (Just "def") ["1","2"] False 0 0 "123" "456" "abc\0abc"
  Guestfs.test0 g "abc" (Just "def") ["1"] True 0 0 "123" "456" "abc\0abc"
  Guestfs.test0 g "abc" (Just "def") ["1"] False (-1) (-1) "123" "456" "abc\0abc"
  Guestfs.test0 g "abc" (Just "def") ["1"] False (-2) (-2) "123" "456" "abc\0abc"
  Guestfs.test0 g "abc" (Just "def") ["1"] False 1 1 "123" "456" "abc\0abc"
  Guestfs.test0 g "abc" (Just "def") ["1"] False 2 2 "123" "456" "abc\0abc"
  Guestfs.test0 g "abc" (Just "def") ["1"] False 4095 4095 "123" "456" "abc\0abc"
  Guestfs.test0 g "abc" (Just "def") ["1"] False 0 0 "" "" "abc\0abc"
  putStrLn "EOF"
