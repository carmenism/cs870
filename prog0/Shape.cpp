/**
 * Shape.cpp - An abstract class representing an OpenGL graphical object.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on Shape.cpp from Professor Dan Bergeron's demo1 program.
 *
 * UNH CS 870, fall 2012
 * 
 * History
 *  09/07/2012: Added setBorderWidth and setBorderColor methods.
 */
#include "Shape.h"
//------------------ Constructors ------------------------------------
/**
 * Create a new shape at position 0,0 of size 1,1 with a black border of width
 * 1.
 */
Shape::Shape()
{
   setLocation( 0, 0 );
   setSize( 1, 1 );
   setBorderWidth( 1.0 );
   setBorderColor( 0.0, 0.0, 0.0 );
}

//------------------ Destructor ------------------------------------
Shape::~Shape()
{
}

//------------------ public methods -------------------------------
/**
 * Set the location of the object.
 *
 * @param x The x coordinate for the new location.
 * @param y The y coordinate for the new location.
 */
void Shape::setLocation( float x, float y )
{
   xLoc = x;
   yLoc = y;
}

/**
 * Set the "nomimal" color of the object to the specified color.  This does not
 * require that all components of the object must be the same color.  Typically,
 * the largest component will take on this color, but the decision is made by
 * the child class.
 *
 * @param r The red component of the desired color (a value from 0.0 to 1.0).
 * @param g The green component of the desired color (a value from 0.0 to 1.0).
 * @param b The blue component of the desired color (a value from 0.0 to 1.0).
 */  
void Shape::setColor( float r, float g, float b )
{
   red = r;
   green = g;
   blue = b;
}
 
/** 
 * Set the size of the shape to be scaled by xs, ys.  That is, the shape has an
 * internal fixed size, the shape parameters scale that internal size.
 *
 * @param xs The size scale for the x direction.
 * @param ys The size scale for the y direction.
 */  
void Shape::setSize( float xs, float ys )
{
   xSize = xs;
   ySize = ys;
}

/**
 * Set the border width to the specified value.
 *
 * @param w The desired width of the border.
 */
void Shape::setBorderWidth( float w )
{
   borderWidth = w;
}

/**
 * Set the border color to the specified RGB color values.
 *
 * @param r The red component of the desired border color (a value from 0.0 to
 *  1.0).
 * @param g The green component of the desired border color (a value from 0.0 to
 *  1.0).
 * @param b The blue component of the desired border color (a value from 0.0 to
 *  1.0).
 */
void Shape::setBorderColor( float r, float g, float b )
{
   borderRed = r;
   borderGreen = g;
   borderBlue = b;
}
