/**
 * PikachuWrappingPaper.h - A class implementation representing a tiled
 * picture of pikachu.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/27/2012: Created class.
 */
#ifndef PIKACHUWRAPPINGPAPER_H_
#define PIKACHUWRAPPINGPAPER_H_

#include "Object3D.h"

class PikachuWrappingPaper: public Object3D {
public:
    PikachuWrappingPaper();
    virtual ~PikachuWrappingPaper();
    void drawAtOrigin();
};

#endif /* PIKACHUWRAPPINGPAPER_H_ */
