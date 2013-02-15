/**
 * Triangle.cpp - A class implementation representing a triangle object in
 * OpenGL.
 * 
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on Triangle.cpp from Professor Dan Bergeron's demo1 program.
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  09/07/2012: Modified to inherit from NShape instead of Shape.
 *  09/06/2012: Modified to redraw with border.
 */
#include "Triangle.h"
//------------- constructor -----------------------
Triangle::Triangle()
{
   float dxDefault[] = { 0.0, 40.0, 20.0 };
   float dyDefault[] = { 0.0, 0.0, 75.0 };

   nPoints = 3;
   for ( int i = 0; i < nPoints; i++ )
   {
      dx[ i ] = dxDefault[ i ];
      dy[ i ] = dyDefault[ i ];
   }
}

//------------- destructor -----------------------
Triangle::~Triangle()
{
}

