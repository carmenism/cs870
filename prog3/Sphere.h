/**
 * Sphere.h - A class implementation representing a sphere.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/07/2012: Created class.
 */
#ifndef SPHERE_H_
#define SPHERE_H_

#include "Object3D.h"

class Sphere: public Object3D {
public:
    Sphere();
    virtual ~Sphere();
    void drawAtOrigin();

    GLUquadricObj *quadratic;
};

#endif /* SPHERE_H_ */
