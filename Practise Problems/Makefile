# This sample Makefile allows you to make any OpenGL application
# whose source is exactly one .c file.
#
# To use this Makefile, you must type:
#
#        make PROG
#                  
# where
#       PROG.c is the name of the file you wish to compile.
#       ----

CC = gcc

CFLAGS = -g

INCLUDE = -I/usr/include 

LDLIBS =  -lglut -lGLU -lGL -lXext -lX11 -lm

LDFLAGS = -L/usr/lib

executable:
	$(CC) $(INCLUDE) $(CFLAGS) $(PROG).c $(LDFLAGS) $(LDLIBS) -o $(PROG)
