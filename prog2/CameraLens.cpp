/**
 * CameraLens.cpp - A class implementation representing the lens of a camera.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/07/2012: Created class.
 */
#include "CameraLens.h"

CameraLens::CameraLens() {
    numberColors = 2;

    setSize(1, 1, 1);
    setRotation(0.0, 0.0, 0.0);
    setLocation(0.0, 0.0, 0.0);

    setIthColor(new Color(0.20, 0.20, 0.20, 1.0), 0); // body color
    setIthColor(new Color(0.12, 0.12, 0.12, 1.0), 1); // control color
    setIthColor(new Color(0.09, 0.09, 0.09, 1.0), 2); // control color
    setIthColor(new Color(0.38, 0.69, 1.0, 1.0), 3); // glass color

    lensBody = new Cylinder();
    lensBody->setSize(10, 10, 8);
    lensBody->setRotation(180, 0, 0);
    lensBody->setLocation(0, 0, 0);

    apertureControl = new Cylinder();
    apertureControl->setSize(11, 11, 1.5);
    apertureControl->setRotation(180, 0, 0);
    apertureControl->setLocation(0, 0, -5.2);

    focusControl = new Cylinder();
    focusControl->setSize(10.5, 10.5, 3);
    focusControl->setRotation(180, 0, 0);
    focusControl->setLocation(0, 0, -1.2);

    lensGlass = new Sphere();
    lensGlass->setSize(8, 8, 2.5);
    lensGlass->setRotation(180, 0, 0);
    lensGlass->setLocation(0, 0, 0);
}

CameraLens::~CameraLens() {
}

/**
 * Redraws the camera lens object.
 */
void CameraLens::redraw() {
    glPushMatrix();
        glTranslatef(xLoc, yLoc, zLoc);

        glMultMatrixf(ballRotate);

        glRotatef(xRotation, 1, 0, 0);
        glRotatef(yRotation, 0, 1, 0);
        glRotatef(zRotation, 0, 0, 1);

        glScalef(xSize, ySize, zSize);

        lensBody->setColor(getIthColor(0));
        apertureControl->setColor(getIthColor(2));
        focusControl->setColor(getIthColor(1));
        lensGlass->setColor(getIthColor(3));

        lensBody->redraw();
        apertureControl->redraw();
        focusControl->redraw();
        lensGlass->redraw();
    glPopMatrix();
}
