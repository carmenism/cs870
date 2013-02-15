/**
 * CameraBody.h - A class implementation representing the body of a camera.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/27/2012: Added materials, added square frustum to top.
 *  10/07/2012: Created class.
 */
#ifndef CAMERABODY_H_
#define CAMERABODY_H_

#include "Object3D.h"
#include "Cube.h"
#include "Cylinder.h"
#include "SquareFrustum.h"

class CameraBody: public Object3D {
public:
    CameraBody();
    virtual ~CameraBody();
private:
    void drawAtOrigin();
    Cube *mainBody, *mainBlack, *filmWinderLever, *filmWinderLeverHandle;
    Cube *viewFinderTop, *viewFinderBottom, *viewFinderLeft, *viewFinderRight;
    Cube *viewFinderGlass;
    Cylinder *lensLock, *shutterButton;
    Cylinder *isoSelectOuter, *isoSelectInner, *filmWinder;
    SquareFrustum *flashMount;
};

#endif /* CAMERABODY_H_ */
