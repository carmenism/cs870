/**
 * NShape.h - An abstract class representing an OpenGL graphical object with n
 * sides.  This inherits from the Shape class.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on Shape.h from Professor Dan Bergeron's demo1 program.
 *
 * UNH CS 870, fall 2012
 * 
 * History
 *  09/07/2012: Created NShape, inheriting from Shape class.
 */
#ifndef NSHAPE_H_
#define NSHAPE_H_

#include "Shape.h"

class NShape: public Shape
{
public:
   NShape();
   virtual ~NShape();
   
   void redraw();

   void drawVertices();

protected: 
   int   nPoints;
   float dx[ 100 ];
   float dy[ 100 ];
};

#endif /*NSHAPE_H_*/
