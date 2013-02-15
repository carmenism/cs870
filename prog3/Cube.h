/**
 * Cube.h - A class implementation representing a cube.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/27/2012: Modified to be texturable.
 *  10/07/2012: Created class.
 */
#ifndef CUBE_H_
#define CUBE_H_

#include "Object3D.h"

class Cube: public Object3D {
public:
    Cube();
    virtual ~Cube();
private:
    void drawAtOrigin();
};

#endif /* CUBE_H_ */
