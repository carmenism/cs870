/**
 * Square.cpp - A class implementation representing a square object in OpenGL.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on Triangle.cpp from Professor Dan Bergeron's demo1 program.
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  09/07/2012: Modified to inherit from NShape instead of Shape.
 *  09/06/2012: Created class; modified to redraw with border.
 */
#include "Square.h"
//------------- constructor -----------------------
Square::Square()
{
   float dxDefault[] = { 0.0, 40.0, 40.0, 0.0  };
   float dyDefault[] = { 0.0, 0.0,  40.0, 40.0 };

   nPoints = 4;
   for ( int i = 0; i < nPoints; i++ )
   {
      dx[ i ] = dxDefault[ i ];
      dy[ i ] = dyDefault[ i ];
   }
}

//------------- destructor -----------------------
Square::~Square()
{
}

