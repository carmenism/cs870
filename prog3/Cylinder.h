/**
 * Cylinder.h - A class implementation representing a cylinder.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/07/2012: Created class.
 */
#ifndef CYLINDER_H_
#define CYLINDER_H_

#include "Object3D.h"

class Cylinder: public Object3D {
public:
    Cylinder();
    virtual ~Cylinder();
private:
    void drawAtOrigin();

    GLUquadricObj *quadratic;
};

#endif /* CYLINDER_H_ */
