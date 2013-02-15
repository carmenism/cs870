#
# Makefile for C++ OpenGL applications suitable for CS770/870
# 
# Carmen St. Jean (crr8, carmen@cs.unh.edu)
# 
# UNH, CS 870, fall 2012, program 0
#
# History:
#  09/07/2012: Modified the list of source files assigned to the SRCS
#              variable.
#  09/06/2012: Copied Makefile from demo1 program by Professor Dan
#              Bergeron.
#

CC          = gcc
CCC	        = g++

GL_INC      = -I/usr/X11/include/GL
X_INC       = -I/usr/X11/include

CPPFLAGS    = -Wall  $(X_INC) $(GL_INC)  

GL_LIBS     = $(LD_LIBS) -lglut -lGLU -lGL 
XLIBS       = -L/usr/X11R6/lib -lXmu -lXext -lX11 #-lXi
LIBS	    = $(XLIBS)  $(GL_LIBS) -lm -ldl

LINKER	    = g++

MAKEFILE    = Makefile

PROG = prog0

SRCS = $(PROG).cpp \
       Hexagon.cpp \
       Pentagon.cpp \
       Square.cpp \
       Triangle.cpp \
       NShape.cpp \
       Shape.cpp

OBJS = $(SRCS:.cpp=.o) $(CSRCS:.c=.o)

all:		compile $(PROG)

compile:     $(OBJS)

#		@echo -n "Loading $(PROGRAM) ... "
#		$(LINKER) $(LDFLAGS) $(OBJS) $(LIBS) -o $(PROGRAM)
#		@echo "done"

%.o : %.cpp %.h
	$(CCC) -c $(CPPFLAGS) $*.cpp

$(PROG): $(PROG).o 
	$(LINKER) $(LDFLAGS) $(OBJS) $(LIBS) -o $(PROG)

new: clean all

clean:
	rm -f *.o $(PROG)
