/**
 * Axis3D.h - A class implementation representing the x, y, and z axes in 3D.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/07/2012: Created class.
 */
#ifndef AXIS3D_H_
#define AXIS3D_H_

#include <GL/glut.h>

#include "Object3D.h"

class Axis3D: public Object3D {
public:
    Axis3D();
    virtual ~Axis3D();
    void drawAtOrigin();
};

#endif /* AXIS3D_H_ */
