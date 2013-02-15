/**
 * FilmCanister.h - A class implementation representing a film canister.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/27/2012: Created class.
 */
#ifndef FILMBOX_H_
#define FILMBOX_H_

#include "Object3D.h"
#include "EmptyCylinder.h"
#include "Cylinder.h"
#include "Cube.h"

class FilmCanister: public Object3D {
public:
    FilmCanister();
    virtual ~FilmCanister();
    void drawAtOrigin();
private:
    EmptyCylinder *label, *top;
    Cylinder *canister;
    Cube *cube, *cubeLabel, *film, *labelStripe;
};

#endif /* FILMBOX_H_ */
