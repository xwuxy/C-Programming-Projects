# Generic Makefile for compiling a single C program and linking with relevant
# MyroC, bluetooth, jpeg, etc. libraries for CSC 161
#
# Written by Jerod Weinman, 14 January 2015
# Extended by Henry M. Walker, 15 January 2015

# To build a program "foo" from "foo.c", simply type "make foo". 
# To build an object file "foo.o" from "foo.c", simply type "make foo.o"
# We rely on make's implicit rules foo.c -> foo.o for compiling and
# foo.o --> foo for linking

# Set preprocessor flags
CPPFLAGS=-I/home/walker/MyroC/include

# Set appropriate compiler flags
CFLAGS=-g -Wall -std=c11

# Set linker flags to include the relevant libraries
LDFLAGS=-L/home/walker/MyroC/lib -lm -lMyroC -lbluetooth -ljpeg -leSpeakPackage 

NCURSEFLAGS=-lcurses
#----------------------------------------------------------------------------
# cleanup rules: To invoke this command, type "make clean".
# Use this target to clean up your directory, deleting (without warning) 
#   object files, old emacs source versions, and core dumps.


hanoi-curse: hanoi.c list.c stack.c hanoi-curse.c 
	gcc ${CFLAGS}  ${NCURSEFLAGS} list.c list.h stack.h stack.c hanoi.c hanoi.h hanoi-curse.c -o hanoi-curse

clean: 
	rm -rf hanoi-curse *.o *.core
