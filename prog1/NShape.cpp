/**
 * NShape.cpp - An abstract class representing an OpenGL graphical object with
 * n sides.  This inherits from the Shape class.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on Shape.cpp from Professor Dan Bergeron's demo1 program.
 *
 * UNH CS 870, fall 2012
 * 
 * History
 *  09/19/2012: Modified to include rangeX and range Y.
 *  09/07/2012: Created NShape, inheriting from Shape class.
 */
#include "NShape.h"

//------------------ Constructors ------------------------------------
NShape::NShape()
{
}

//------------------ Destructor ------------------------------------
NShape::~NShape()
{
}

//------------------ public methods -------------------------------

//------------- redraw ---------------------------

/**
 * Redraw the polygon.
 */
void NShape::redraw()
{
   // Draw the filled polygon from the vertices.
   if (drawFill) {
      glPolygonMode( GL_FRONT, GL_FILL );
      glColor3f( red, green, blue );
      glBegin( GL_POLYGON );
         drawVertices();
      glEnd();
   }

   // Draw the border if one is desired.
   if ( borderWidth != 0 ) {
      glPolygonMode( GL_FRONT, GL_LINE );
      glColor3f( borderRed, borderGreen, borderBlue );
      glLineWidth( borderWidth );
      glBegin( GL_POLYGON );
         drawVertices();
      glEnd();
   }
}

//------------- drawVertices ---------------------

/**
 * Draw the vertices of the NShape polygon based on the dx and dy values.
 */
void NShape::drawVertices()
{
   // The n-shape is defined by positions relative to its location stored in the
   // dx and dy arrays.  The scale factor applies to the relative offset of each
   // coordinate from the origin (which is xLoc, yLoc).
   for ( int i = 0; i < nPoints; i++ )
   {
      glVertex2f( xLoc + dx[ i ] * xSize,
                  yLoc + dy[ i ] * ySize );
   }
}
