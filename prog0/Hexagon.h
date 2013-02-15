/**
 * Hexagon.h - A class implementation representing a hexagon object in OpenGL.
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
#ifndef HEXAGON_H_
#define HEXAGON_H_


#include "NShape.h"

class Hexagon: public NShape
{
public:
   Hexagon();
   virtual ~Hexagon();
};

#endif /*HEXAGON_H_*/
