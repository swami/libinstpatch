#!/bin/bash


echo "run make instead. (or edit this script)"

exit 0

# Define compiler and variables
CC="gcc"

# CFLAGS for compilation (includes headers and debug/sanitizer flags)
CFLAGS="-I./include/ -fsanitize=address -ggdb -Wall -Wextra $(pkg-config --cflags glib-2.0 gobject-2.0)"

# LDFLAGS for linking (rpath and sanitizer flag)
LDFLAGS="-Wl,-rpath=./lib -fsanitize=address"

# LIBS for actual library files (must be placed after the object file)
LIBS="./lib/libinstpatch-1.0.so $(pkg-config --libs glib-2.0 gobject-2.0)"

echo "Compiling..."
$CC -c src/main.c -o lsan_test.o $CFLAGS

echo "Linking..."
$CC -o lsan_test lsan_test.o $LIBS $LDFLAGS

echo "Done! Run with ./lsan_test"
