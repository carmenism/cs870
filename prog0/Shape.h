/**
 * Shape.h - An abstract class representing an OpenGL graphical object.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on Shape.h from Professor Dan Bergeron's demo1 program.
 * 
 * UNH CS 870, fall 2012
 *
 * History
 *  09/07/2012: Added setBorderWidth and setBorderColor properties and method
 *              declarations.
 */
#ifndef SHAPE_H_
#define SHAPE_H_

#include <GL/glut.h>

class Shape
{
public:
   Shape();
   virtual ~Shape();
   
   void setLocation( float x, float y ); // set the location (origin) of object
   
   void setSize( float xs, float ys ); // set the size of the object
   
   void setColor( float r, float g, float b ); // set color
   
   void setBorderWidth( float w ); // set boundary width

   void setBorderColor( float r, float g, float b ); // set boundary color

   virtual void redraw() = 0; // redraw; to be overwritten
   
protected: 
   float xLoc, yLoc;                         // location of the object
   float xSize, ySize;                       // size of the object
   float red, green, blue;                   // color
   float borderWidth;                        // width of the boundary
   float borderRed, borderGreen, borderBlue; // boundary color
};

#endif /*SHAPE_H_*/
