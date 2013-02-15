#
# Makefile for C++ OpenGL applications suitable for CS770/870
#   rdb
#   08/30/08
#
# Simply modify the list of source files assigned to the SRCS variable
#

CC          = gcc
CCC	        = g++

GL_INC      = -I/usr/X11/include/GL
X_INC       = -I/usr/X11/include

CPPFLAGS    = -Wall  $(X_INC) $(GL_INC)  

# next line required for Mac OS X
#LD_LIBS     = -L /Library/Frameworks/GLUI.framework
#LD_BUG      = -Wl,-dylib_file,$(LD_LIBS)
LD_BUG      = -Wl

#GLUI_LIB    = -framework GLUI 
GLUI_LIB   = -lglui

GL_LIBS     = $(LD_LIBS) -lglut -lGLU -lGL $(LD_BUG) 
XLIBS       = -L/usr/X11/lib -lXmu -lXext -lX11 -lXi
LIBS	    = $(XLIBS)  $(GLUI_LIB) $(GL_LIBS) -lm -ldl

LINKER	    = g++

MAKEFILE    = Makefile

PROG = prog2

SRCS = $(PROG).cpp \
       Object3D.cpp \
       Axis3D.cpp \
       Tetrahedron.cpp \
       Cube.cpp \
       Sphere.cpp \
       Cylinder.cpp \
       Color.cpp \
       CameraLens.cpp \
       CameraBody.cpp \
       Camera.cpp \
       ControlPanel.cpp \
       GlutMouseListener.cpp \
       GlutMouseSource.cpp \
       Listener.cpp \
       Observable.cpp \
       Scene.cpp


OBJS = $(SRCS:.cpp=.o) $(CSRCS:.c=.o)

all:	compile $(PROG)

compile: $(OBJS)

new:	cleanup all
clean:	cleanup all

#		@echo -n "Loading $(PROGRAM) ... "
#		$(LINKER) $(LDFLAGS) $(OBJS) $(LIBS) -o $(PROGRAM)
#		@echo "done"

%.o : %.cpp %.h
	$(CCC) -c $(CPPFLAGS) $*.cpp

$(PROG): $(OBJS)
	$(LINKER) $(LDFLAGS) $(OBJS) $(LIBS) -o $(PROG)

cleanup:
	rm -f *.o $(PROG)
