/**
 * Object3D.cpp - A class implementation representing a 3D object in OpenGL.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/07/2012: Created class based on Shape class from previous assignments.
 */
#include "Object3D.h"

Object3D::Object3D()
{
    float def[] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };

    for (int i = 0; i < 16; i++) {
	    ballRotate[i] = def[i];
    }
}

Object3D::~Object3D()
{
}

/**
 * Set the "nominal" color of the object to the specified color.  This does not
 * require that all components of the object must be the same color.  Typically,
 * the largest component will take on this color, but the decision is made by
 * the child class.
 *
 * @param c The new nominal color for the object.
 */
void Object3D::setColor( Color *c )
{
    setIthColor( c, 0 );
}

/**
 * Sets the ith color for the object.
 *
 * @param c A pointer to a Color object.
 * @param i The index where the new Color object will be stored.
 */
void Object3D::setIthColor( Color *c, int i )
{
    colors[i] = c;
}

/**
 * Returns the ith color of the object.
 *
 * @param i The index of the color desired.
 * @return The ith color of the object.
 */
Color * Object3D::getIthColor( int i )
{
    return colors[i];
}

/**
 * Sets the location of the object.
 *
 * @param x The x coordinate for the new location.
 * @param y The y coordinate for the new location.
 * @param z The z coordinate for the new location.
 */
void Object3D::setLocation( float x, float y, float z )
{
    xLoc = x;
    yLoc = y;
    zLoc = z;
}

/**
 * Return the x-value of the origin of the shape.
 *
 * @return The x-value.
 */
float Object3D::getX()
{
    return xLoc;
}

/**
 * Return the y-value of the origin of the shape.
 *
 * @return The y-value of the shape.
 */
float Object3D::getY()
{
    return yLoc;
}

/**
 * Return the z-value of the origin of the shape.
 *
 * @return The z-value of the shape.
 */
float Object3D::getZ()
{
    return zLoc;
}

/**
 * Sets the size of the object in the three dimensions.
 *
 * @param xs The x size.
 * @param ys The y size.
 * @param zs The z size.
 */
void Object3D::setSize( float xs, float ys, float zs )
{
    xSize = xs;
    ySize = ys;
    zSize = zs;
}

/**
 * Returns the size of the object in the x dimension.
 *
 * @return The x size.
 */
float Object3D::getXSize()
{
    return xSize;
}

/**
 * Returns the size of the object in the y dimension.
 *
 * @return The y size.
 */
float Object3D::getYSize()
{
    return ySize;
}

/**
 * Returns the size of the object in the z dimension.
 *
 * @return The z size.
 */
float Object3D::getZSize()
{
    return zSize;
}

/**
 * Set the rotation of the object about the three axes.
 *
 * @param xr The ration about the x axis.
 * @param yr The ration about the y axis.
 * @param zr The ration about the z axis.
 */
void Object3D::setRotation( float xr, float yr, float zr )
{
    xRotation = xr;
    yRotation = yr;
    zRotation = zr;
}
/**
 * Set the rotation of the object about the three axes.
 *
 * @param r A rotation matrix.
 */
void Object3D::setRotation( float *r )
{
    for (int i = 0; i < 16; i++) {
       ballRotate[i] = r[i];
    }
}

/**
 * Returns the rotation of the object about the x axis, an angle measured in
 * degrees.
 *
 * @return The x rotation.
 */
float Object3D::getXRotation()
{
    return xRotation;
}

/**
 * Returns the rotation of the object about the u axis, an angle measured in
 * degrees.
 *
 * @return The y rotation.
 */
float Object3D::getYRotation()
{
    return yRotation;
}

/**
 * Returns the rotation of the object about the z axis, an angle measured in
 * degrees.
 *
 * @return The z rotation.
 */
float Object3D::getZRotation()
{
    return zRotation;
}
