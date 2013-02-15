#
# Makefile for C++ OpenGL applications suitable for CS770/870
#   
# Carmen St. Jean (crr8), carmen@cs.unh.edu
# CS 870, fall 2012, prog1
#
# Only modified the list of source files assigned to the SRCS variable.
#

CC          = gcc
CCC	        = g++

GL_INC      = -I/usr/X11R6/include/GL
X_INC       = -I/usr/X11R6/include

CPPFLAGS    = -Wall  $(X_INC) $(GL_INC)  

# next line required for Mac OS X
#LD_LIBS     = -L /Library/Frameworks/GLUI.framework
#LD_BUG      = -Wl,-dylib_file,$(LD_LIBS)
LD_BUG      = -Wl

#GLUI_LIB    = -framework GLUI 
GLUI_LIB   = -lglui

GL_LIBS     = $(LD_LIBS) -lglut -lGLU -lGL $(LD_BUG) 
XLIBS       = -L/usr/X11R6/lib -lXmu -lXext -lX11 -lXi
LIBS	    = $(XLIBS)  $(GLUI_LIB) $(GL_LIBS) -lm -ldl

LINKER	    = g++

MAKEFILE    = Makefile

PROG = prog1

SRCS = $(PROG).cpp \
       Hexagon.cpp \
       Pentagon.cpp \
       Square.cpp \
       Triangle.cpp \
       NShape.cpp \
       Shape.cpp \
       ControlPanel.cpp \
       GlutMouseListener.cpp \
       GlutMouseSource.cpp \
       Listener.cpp \
       Observable.cpp \
       Scene.cpp


OBJS = $(SRCS:.cpp=.o) $(CSRCS:.c=.o)

all:	compile $(PROG)

compile: $(OBJS)

new:	clean all

#		@echo -n "Loading $(PROGRAM) ... "
#		$(LINKER) $(LDFLAGS) $(OBJS) $(LIBS) -o $(PROGRAM)
#		@echo "done"

%.o : %.cpp %.h
	$(CCC) -c $(CPPFLAGS) $*.cpp

$(PROG): $(PROG).o 
	$(LINKER) $(LDFLAGS) $(OBJS) $(LIBS) -o $(PROG)

clean:
	rm -f *.o $(PROG)
