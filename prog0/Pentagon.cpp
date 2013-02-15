/**
 * Pentagon.cpp - A class implementation representing a pentagon object in
 * OpenGL.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on Triangle.h from Professor Dan Bergeron's demo1 program.
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  09/07/2012: Modified to inherit from NShape instead of Shape.
 *  09/06/2012: Created class; modified to redraw with border.
 */
#include "Pentagon.h"
//------------- constructor -----------------------
Pentagon::Pentagon()
{
   float dxDefault[] = { 12.36, 52.36, 64.72, 32.36, 0.0   };
   float dyDefault[] = { 0.0,   0.0,   38.04, 61.56, 38.04 };

   nPoints = 5;
   for ( int i = 0; i < nPoints; i++ )
   {
      dx[ i ] = dxDefault[ i ];
      dy[ i ] = dyDefault[ i ];
   }
}

//------------- destructor -----------------------
Pentagon::~Pentagon()
{
}
