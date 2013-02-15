/**
 * EmptyCylinder.h - A class implementation representing an empty cylinder.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/27/2012: Created class.
 */
#ifndef EMPTYCYLINDER_H_
#define EMPTYCYLINDER_H_

#include "Object3D.h"

class EmptyCylinder: public Object3D {
public:
    EmptyCylinder();
    virtual ~EmptyCylinder();
private:
    void drawAtOrigin();

    GLUquadricObj *quadratic;
};

#endif /* EMPTYCYLINDER_H_ */
