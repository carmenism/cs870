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

CameraLens::CameraLens() : Object3D() {
    numberColors = 3;

    setSize(1, 1, 1);
    setRotation(0.0, 0.0, 0.0);
    setLocation(0.0, 0.0, 0.0);

    setIthColor(new Color(0.20, 0.20, 0.20, 1.0), 0); // body color
    setIthColor(new Color(0.0, 0.0, 0.0, 1.0), 1); // control color
    setIthColor(new Color(0.38, 0.69, 1.0, 0.80), 2); // glass color

    Material *rubber = new Material();
    rubber->setAmbient(new Color(0.02, 0.02, 0.02, 1.0));
    rubber->setDiffuse(new Color(0.01, 0.01, 0.01, 1.0));
    rubber->setSpecular(new Color(0.4, 0.4, 0.4, 1.0));
    rubber->setShininess(0.078125 * 128);

    Material *glass = new Material();
    glass->setShininess(128.0);
    glass->setAmbient(new Color(0.0, 0.0, 0.0, 1.0));
    glass->setEmission(new Color(0.0, 0.0, 0.0, 1.0));
    glass->setSpecular(new Color(1.0, 1.0, 1.0, 1.0));

    Material *plastic = new Material();
    plastic->setAmbient(new Color(0.0, 0.0, 0.0, 1.0));
    plastic->setDiffuse(new Color(0.01, 0.01, 0.01, 1.0));
    plastic->setSpecular(new Color(0.5, 0.5, 0.5, 1.0));
    plastic->setShininess(0.25 * 128);

    lensBody = new Cylinder();
    lensBody->setSize(1, 1, 0.8);
    lensBody->setRotation(180, 0, 0);
    lensBody->setLocation(0, 0, 0);
    lensBody->setMaterial(plastic);

    apertureControl = new Cylinder();
    apertureControl->setSize(1.1, 1.1, 0.15);
    apertureControl->setRotation(180, 0, 0);
    apertureControl->setLocation(0, 0, -0.52);
    apertureControl->setMaterial(rubber);

    focusControl = new Cylinder();
    focusControl->setSize(1.05, 1.05, 0.3);
    focusControl->setRotation(180, 0, 0);
    focusControl->setLocation(0, 0, -0.12);
    focusControl->setMaterial(rubber);

    lensGlass = new Sphere();
    lensGlass->setSize(0.8, 0.8, 0.25);
    lensGlass->setRotation(180, 0, 0);
    lensGlass->setLocation(0, 0, 0);
    lensGlass->setMaterial(glass);
}

CameraLens::~CameraLens() {
}

/**
 * Draws the camera lens object at the origin.
 */
void CameraLens::drawAtOrigin() {
    lensBody->setColor(getIthColor(0));
    apertureControl->setColor(getIthColor(1));
    focusControl->setColor(getIthColor(1));
    lensGlass->setColor(getIthColor(2));

    lensBody->redraw();
    apertureControl->redraw();
    focusControl->redraw();
    lensGlass->redraw();
}
