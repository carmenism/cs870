/**
 * Camera.cpp - A class implementation representing a 3D camera.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/07/2012: Created class.
 */
#include "Camera.h"

Camera::Camera() : Object3D() {
    setSize(1, 1, 1);
    setRotation(0.0, 0.0, 0.0);
    setLocation(0.0, 0.0, 0.0);

    setIthColor(new Color(0.20, 0.20, 0.20, 1.0), 0);
    setIthColor(new Color(0.82, 0.82, 0.82, 1.0), 1);

    body = new CameraBody();
    lens = new CameraLens();
}

Camera::~Camera() {
}

/**
 * Draws the camera object at the origin.
 */
void Camera::drawAtOrigin() {
    body->setIthColor(getIthColor(0), 1);
    body->setIthColor(getIthColor(1), 0);

    lens->setIthColor(getIthColor(0), 0);
    lens->setLocation(0, 0, 1.15);

    body->redraw();
    lens->redraw();
}
