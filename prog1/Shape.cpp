/**
 * Shape.cpp - An abstract class representing an OpenGL graphical object.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on Shape.cpp from Professor Dan Bergeron's demo1 program.
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  09/19/2012: Added range methods and ability to not draw fill color.
 *  09/07/2012: Added setBorderWidth and setBorderColor methods.
 */
#include "Shape.h"
//------------------ Constructors ------------------------------------
/**
 * Create a new shape at position 0,0 of size 1,1 with a black border of width
 * 2.
 */
Shape::Shape()
{
   setLocation( 0, 0 );
   setSize( 1, 1 );
   setBorderWidth( 2.0 );
   setBorderColor( 0.0, 0.0, 0.0 );
   setDrawFill( true );
   setId( -1 );
}

//------------------ Destructor ------------------------------------
Shape::~Shape()
{
}

//------------------ public methods -------------------------------

/**
 * Return the shape's ID.
 *
 * @return The shape's ID number.
 */
int Shape::getId()
{
   return id;
}

/**
 * Return the x-value of the origin of the shape.
 *
 * @return The x-value.
 */
float Shape::getX()
{
   return xLoc;
}

/**
 * Return the y-value of the origin of the shape.
 *
 * @return The y-value of the shape.
 */
float Shape::getY()
{
   return yLoc;
}

/**
 * Return the range of x-values of the vertices of the shape (max x-value minus
 * min x-value).
 *
 * @return The range of x-values.
 */
float Shape::getRangeX()
{
   return rangeX;
}

/**
 * Return the range of y-values of the vertices of the shape (max y-value minus
 * min y-value).
 *
 * @return The range of y-values.
 */
float Shape::getRangeY()
{
   return rangeY;
}

/**
 * Given an array of values and its length, find the range of the values, i.e.
 * the maximum value minus the minimum value.
 *
 * @param arr An array of floats.
 * @param length The length of the arr array.
 * @return The range of the array.
 */
float Shape::findRange( float arr [], int length )
{
   float min = arr[0], max = arr[0];

   for ( int i = 0; i < length; i++ )
   {
      if ( arr[i] > max )
         max = arr[i];
      if ( arr[i] < min )
         min = arr[i];
   }

   return ( max - min );
}

/**
 * Set the ID of the object.
 *
 * @param i The integer representing the unique ID for this shape.
 */
void Shape::setId( int i )
{
   id = i;
}

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
 * Set the draw fill boolean to the specified value.
 *
 * @param df Set to true if you would like for shapes to be drawn with a fill
 *  color.
 */
void Shape::setDrawFill( bool df )
{
   drawFill = df;
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
