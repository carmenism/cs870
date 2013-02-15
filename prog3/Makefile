#
# Revised Makefile for C++ OpenGL applications suitable for CS770/870
#   rdb
#   10/25/2012
#
# Modified by Carmen St. Jean (crr8) for prog3.
#

CC          = gcc
CCC	      = g++

GL_INC      = -I/usr/X11/include/GL
X_INC       = -I/usr/X11/include

#
# If any linker flags are needed, they should be prefixed by "-Wl," 
# This insures that cpp or cc will not confuse these flags with ones
# intended for it.
# 
LDFLAGS     = 

# library search specs
GL_LIBS     = -lglut -lGLU -lGL -lglui
XLIBS       = -L/usr/X11/lib -lXmu -lXext -lX11 -lXi

#---------------- libjpeg set up ------------------------------
# Setting JPEG_INC to /usr/include isn't really necessary since linux and
#                  Mac OS X search /usr/include anyway.
#         However, if jpeglib.h is not put into /usr/include or 
#                 /usr/local/include or other directory normally searched
#                 you need to set its location here.
#                         
#JPEG_INC	= -I/usr/include
#
# If libjpeg.a (or libjpeg.so or libjpeg.dylib) is NOT stored in a standard
#      loader library search directory, need first version of this line
#      after replacing /usr/lib with the directory containing libjpeg
#
#JPEG_LIB   = -L/usr/local/lib -ljpeg
#
JPEG_LIB    = -ljpeg
#------------------------------------------------------------

LIBS	    = $(XLIBS) $(GLUI_LIB) $(GL_LIBS) $(JPEG_LIB) -lm -ldl

CPPFLAGS    = -Wall  $(X_INC) $(GL_INC) $(JPEG_INC)

LINKER	    = g++

MAKEFILE    = Makefile

PROG = prog3

SRCS = $(PROG).cpp \
       Material.cpp \
       Texture.cpp \
       Object3D.cpp \
       Axis3D.cpp \
       Tetrahedron.cpp \
       Cube.cpp \
       Sphere.cpp \
       SquareFrustum.cpp \
       EmptyCylinder.cpp \
       Cylinder.cpp \
       Color.cpp \
       CameraLens.cpp \
       CameraBody.cpp \
       Camera.cpp \
       FilmCanister.cpp \
       PikachuPicture.cpp \
       PikachuWrappingPaper.cpp \
       Baseball.cpp \
       ControlPanel.cpp \
       GlutMouseListener.cpp \
       GlutMouseSource.cpp \
       Listener.cpp \
       Observable.cpp \
       Scene.cpp

OBJS = $(SRCS:.cpp=.o) 

all:	compile $(PROG)

clean:  cleanup all

compile: $(OBJS) 

new:	clean all

%.o : %.cpp %.h
	$(CCC) -c $(CPPFLAGS) $*.cpp

$(PROG): $(OBJS) $(COBJS)
	$(LINKER) $(LDFLAGS) $(OBJS) $(LIBS) -o $(PROG)

cleanup:
	rm -f *.o $(PROG)
