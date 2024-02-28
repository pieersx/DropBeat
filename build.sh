#!/bin/sh

set -xe

CFLAGS="-Wall -Wextra -I./raylib/include/"

LIBS="-L./raylib/lib/ -lraylib -lm"

clang $CFLAGS -o musicaudio main.c $LIBS
