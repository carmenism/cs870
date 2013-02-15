/**
 * Hexagon.cpp - A class implementation representing a hexagon object in OpenGL.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on Triangle.h from Professor Dan Bergeron's demo1 program.
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  09/19/2012: Modified to include rangeX and range Y.
 *  09/07/2012: Modified to inherit from NShape instead of Shape.
 *  09/06/2012: Created class; modified to redraw with border.
 */
#include "Hexagon.h"
//------------- constructor -----------------------
Hexagon::Hexagon()
{
   float dxDefault[] = { 20.0, 60.0, 80.0, 60.0, 20.0, 0.0 };
   float dyDefault[] = { 0.0, 0.0, 34.641, 69.282, 69.282, 34.641 };

   nPoints = 6;
   for ( int i = 0; i < nPoints; i++ )
   {
      dx[ i ] = dxDefault[ i ];
      dy[ i ] = dyDefault[ i ];
   }

   rangeX = findRange( dx, nPoints );
   rangeY = findRange( dy, nPoints );
}

//------------- destructor -----------------------
Hexagon::~Hexagon()
{
}
