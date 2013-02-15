/**
 * Baseball.h - A class implementation representing a baseball.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/27/2012: Created class.
 */
#ifndef BASEBALL_H_
#define BASEBALL_H_

#include "Object3D.h"
#include "Sphere.h"

class Baseball: public Object3D {
public:
    Baseball();
    virtual ~Baseball();
    void drawAtOrigin();
private:
    Sphere *baseball;
};

#endif /* BASEBALL_H_ */
