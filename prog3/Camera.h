/**
 * Camera.h - A class implementation representing a 3D camera.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/07/2012: Created class.
 */
#ifndef CAMERA_H_
#define CAMERA_H_

#include "Object3D.h"
#include "CameraBody.h"
#include "CameraLens.h"

class Camera: public Object3D {
public:
    Camera();
    virtual ~Camera();
private:
    void drawAtOrigin();
    CameraLens *lens;
    CameraBody *body;
};

#endif /* CAMERA_H_ */
