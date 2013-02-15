/**
 * Object3D.h - A class implementation representing a 3D object in OpenGL.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/07/2012: Created class based on Shape class from previous assignments.
 */
#ifndef OBJECT3D_H_
#define OBJECT3D_H_

#include <GL/glut.h>

#include "Color.h"

class Object3D
{
public:
   Object3D();
   virtual ~Object3D();
   virtual void redraw() = 0; // redraw; to be overwritten

   void setColor( Color *c );           // set nominal color
   void setIthColor( Color *c, int i ); // set ith color color
   Color * getIthColor( int i );        // get ith color

   void setLocation( float x, float y, float z ); // set the location of object
   float getX();                                  // return x location
   float getY();                                  // return y location
   float getZ();                                  // return z location

   void setSize( float xs, float ys, float zs ); // set the size of the object
   float getXSize();                             // return x size
   float getYSize();                             // return y size
   float getZSize();                             // return z size

   void setRotation( float xr, float yr, float zr ); // set the rotation
   void setRotation( float *r );                     // set the rotation
   float getXRotation();                             // return x rotation
   float getYRotation();                             // return y rotation
   float getZRotation();                             // return z rotation
protected:
   int numberColors;                         // total number of colors
   Color *colors[100];                       // colors of the object
   float xLoc, yLoc, zLoc;                   // location of the object
   float xSize, ySize, zSize;                // size of the object
   float xRotation, yRotation, zRotation;    // rotation of the object
   float *xPts, *yPts, *zPts;                // arrays of points
   float ballRotate[16];
};


#endif /*OBJECT3D_H_*/
