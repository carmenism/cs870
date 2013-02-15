/**
 * PikachuPicture.h - A class implementation representing a picture of pikachu.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/27/2012: Created class.
 */
#ifndef PIKACHUPICTURE_H_
#define PIKACHUPICTURE_H_

#include "Object3D.h"
#include "Texture.h"

class PikachuPicture: public Object3D {
public:
    PikachuPicture();
    virtual ~PikachuPicture();
    void drawAtOrigin();
};

#endif /* PIKACHUPICTURE_H_ */
