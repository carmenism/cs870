/**
 * CameraBody.cpp - A class implementation representing the body of a camera.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/07/2012: Created class.
 */
#include "CameraBody.h"

CameraBody::CameraBody() {
    setSize(1, 1, 1);
    setRotation(0.0, 0.0, 0.0);
    setLocation(0.0, 0.0, 0.0);

    setIthColor(new Color(0.82, 0.82, 0.82, 1.0), 0); // light color
    setIthColor(new Color(0.18, 0.18, 0.18, 1.0), 1); // dark color
    setIthColor(new Color(0.66, 0.66, 0.66, 1.0), 2); // darker silver
    setIthColor(new Color(0.38, 0.69, 1.0, 1.0), 3);  // glass color
    setIthColor(new Color(0.09, 0.09, 0.09, 1.0), 4); // darkest color

    mainBody = new Cube();
    mainBody->setSize(22, 12, 6);
    mainBody->setLocation(0, 0, 0);

    mainBlack = new Cube();
    mainBlack->setSize(22.25, 9.25, 6.25);
    mainBlack->setLocation(0, 0, 0);

    lensLock = new Cylinder();
    lensLock->setSize(10.5, 10.5, 0.5);
    lensLock->setLocation(0, 0, 3);

    shutterButton = new Cylinder();
    shutterButton->setSize(2.5, 2.5, 2.5);
    shutterButton->setLocation(-4.75, 6.75, 1);
    shutterButton->setRotation(90, 0, 0);

    isoSelectOuter = new Cylinder();
    isoSelectOuter->setSize(3.25, 3.25, 3.25);
    isoSelectOuter->setLocation(7, 6.5, 0);
    isoSelectOuter->setRotation(90, 0, 0);

    isoSelectInner = new Cylinder();
    isoSelectInner->setSize(2.75, 2.75, 2.75);
    isoSelectInner->setLocation(7, 6.75, 0);
    isoSelectInner->setRotation(90, 0, 0);

    filmWinder = new Cylinder();
    filmWinder->setSize(3.25, 3.25, 3.25);
    filmWinder->setLocation(-8.75, 6.75, -0.5);
    filmWinder->setRotation(90, 0, 0);

    filmWinderLever = new Cube();
    filmWinderLever->setSize(5, 0.45, 1);
    filmWinderLever->setLocation(-5.5, 6.5, -1.5);

    filmWinderLeverHandle = new Cube();
    filmWinderLeverHandle->setSize(2.25, 0.6, 1.25);
    filmWinderLeverHandle->setLocation(-4, 6.5, -1.5);

    viewFinderGlass = new Cube();
    viewFinderGlass->setSize(3, 2.25, 0.5);
    viewFinderGlass->setLocation(0, 4, -3);

    viewFinderTop = new Cube();
    viewFinderTop->setSize(3.25, 0.25, 0.75);
    viewFinderTop->setLocation(0, 5.25, -3);

    viewFinderBottom = new Cube();
    viewFinderBottom->setSize(3.25, 0.25, 0.75);
    viewFinderBottom->setLocation(0, 2.75, -3);

    viewFinderLeft = new Cube();
    viewFinderLeft->setSize(0.25, 2.75, 0.75);
    viewFinderLeft->setLocation(1.5, 4, -3);

    viewFinderRight = new Cube();
    viewFinderRight->setSize(0.25, 2.75, 0.75);
    viewFinderRight->setLocation(-1.5, 4, -3);
}

CameraBody::~CameraBody() {
}

/**
 * Redraws the camera body object.
 */
void CameraBody::redraw() {
    glPushMatrix();
        glTranslatef(xLoc, yLoc, zLoc);

        glMultMatrixf(ballRotate);

        glRotatef(xRotation, 1, 0, 0);
        glRotatef(yRotation, 0, 1, 0);
        glRotatef(zRotation, 0, 0, 1);

        glScalef(xSize, ySize, zSize);

        mainBody->setColor(getIthColor(0));
        mainBlack->setColor(getIthColor(1));
        lensLock->setColor(getIthColor(0));
        shutterButton->setColor(getIthColor(4));
        isoSelectOuter->setColor(getIthColor(2));
        isoSelectInner->setColor(getIthColor(1));
        filmWinder->setColor(getIthColor(2));
        filmWinderLever->setColor(getIthColor(2));
        filmWinderLeverHandle->setColor(getIthColor(1));
        viewFinderGlass->setColor(getIthColor(3));
        viewFinderBottom->setColor(getIthColor(4));
        viewFinderTop->setColor(getIthColor(4));
        viewFinderLeft->setColor(getIthColor(4));
        viewFinderRight->setColor(getIthColor(4));

        mainBody->redraw();
        mainBlack->redraw();
        lensLock->redraw();
        shutterButton->redraw();
        isoSelectOuter->redraw();
        isoSelectInner->redraw();
        filmWinder->redraw();
        filmWinderLever->redraw();
        filmWinderLeverHandle->redraw();
        viewFinderGlass->redraw();
        viewFinderTop->redraw();
        viewFinderBottom->redraw();
        viewFinderLeft->redraw();
        viewFinderRight->redraw();
    glPopMatrix();
}
