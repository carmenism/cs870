/**
 * Tetrahedron.h - A class implementation representing a tetrahedron.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/07/2012: Created class.
 */
#ifndef TETRAHEDRON_H_
#define TETRAHEDRON_H_

#include "Object3D.h"

class Tetrahedron: public Object3D {
public:
    Tetrahedron();
    virtual ~Tetrahedron();
    void redraw();
};

#endif /* TETRAHEDRON_H_ */
