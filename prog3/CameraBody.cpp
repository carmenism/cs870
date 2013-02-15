/**
 * CameraBody.cpp - A class implementation representing the body of a camera.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/27/2012: Added materials, added square frustum to top.
 *  10/07/2012: Created class.
 */
#include "CameraBody.h"

CameraBody::CameraBody() : Object3D() {
    setSize(1, 1, 1);
    setRotation(0.0, 0.0, 0.0);
    setLocation(0.0, 0.0, 0.0);

    setIthColor(new Color(0.82, 0.82, 0.82, 1.0), 0); // light color
    setIthColor(new Color(0.18, 0.18, 0.18, 1.0), 1); // dark color
    setIthColor(new Color(0.66, 0.66, 0.66, 1.0), 2); // darker silver
    setIthColor(new Color(0.38, 0.69, 1.0, 1.0), 3);  // glass color
    setIthColor(new Color(0.09, 0.09, 0.09, 1.0), 4); // darkest color

    Material *chrome = new Material();
    chrome->setAmbient(new Color(0.25, 0.25, 0.25, 1));
    chrome->setDiffuse(new Color(0.4, 0.4, 0.4, 1));
    chrome->setSpecular(new Color(0.774597, 0.774597, 0.774597, 1));
    chrome->setShininess(0.6 * 128);

    Material *rubber = new Material();
    rubber->setAmbient(new Color(0.02, 0.02, 0.02, 1.0));
    rubber->setDiffuse(new Color(0.01, 0.01, 0.01, 1.0));
    rubber->setSpecular(new Color(0.4, 0.4, 0.4, 1.0));
    rubber->setShininess(0.078125 * 128);

    Material *obsidian = new Material();
    obsidian->setAmbient(new Color(0.0215, 0.1745, 0.0215));
    obsidian->setDiffuse(new Color(0.07568, 0.61424, 0.07568));
    obsidian->setSpecular(new Color(0.633, 0.727811, 0.633));
    obsidian->setShininess(0.6 * 128);

    Material *glass = new Material();
    glass->setShininess(135.0);
    glass->setAmbient(new Color(0.0, 0.0, 0.0, 1.0));
    glass->setEmission(new Color(0.0, 0.0, 0.0, 1.0));
    glass->setSpecular(new Color(1.0, 1.0, 1.0, 1.0));

    mainBody = new Cube();
    mainBody->setSize(2.2, 1.2, 0.6);
    mainBody->setLocation(0, 0, 0);
    mainBody->setMaterial(chrome);

    mainBlack = new Cube();
    mainBlack->setSize(2.225, 0.925, 0.625);
    mainBlack->setLocation(0, 0, 0);
    mainBody->setMaterial(rubber);

    lensLock = new Cylinder();
    lensLock->setSize(1.05, 1.05, 0.05);
    lensLock->setLocation(0, 0, 0.3);
    lensLock->setMaterial(chrome);

    shutterButton = new Cylinder();
    shutterButton->setSize(0.25, 0.25, 0.25);
    shutterButton->setLocation(-0.475, 0.675, 0.1);
    shutterButton->setRotation(90, 0, 0);
    shutterButton->setMaterial(obsidian);

    isoSelectOuter = new Cylinder();
    isoSelectOuter->setSize(0.325, 0.325, 0.325);
    isoSelectOuter->setLocation(0.7 + 0.1, 0.65, 0);
    isoSelectOuter->setRotation(90, 0, 0);
    isoSelectOuter->setMaterial(chrome);

    isoSelectInner = new Cylinder();
    isoSelectInner->setSize(0.275, 0.275, 0.275);
    isoSelectInner->setLocation(0.7 + 0.1, 0.675, 0);
    isoSelectInner->setRotation(90, 0, 0);
    isoSelectInner->setMaterial(obsidian);

    filmWinder = new Cylinder();
    filmWinder->setSize(0.325, 0.325, 0.325);
    filmWinder->setLocation(-0.875 - 0.03, 0.675, -0.05);
    filmWinder->setRotation(90, 0, 0);
    filmWinder->setMaterial(chrome);

    filmWinderLever = new Cube();
    filmWinderLever->setSize(0.5, 0.045, 0.1);
    filmWinderLever->setLocation(-0.55 - 0.03, 0.65, -0.15);
    filmWinderLever->setMaterial(chrome);

    filmWinderLeverHandle = new Cube();
    filmWinderLeverHandle->setSize(0.225, 0.06, 0.125);
    filmWinderLeverHandle->setLocation(-0.4 - 0.03, 0.65, -0.15);
    filmWinderLeverHandle->setMaterial(rubber);

    viewFinderGlass = new Cube();
    viewFinderGlass->setSize(0.3, 0.225, 0.05);
    viewFinderGlass->setLocation(0, 0.4, -0.3);
    viewFinderGlass->setMaterial(glass);

    viewFinderTop = new Cube();
    viewFinderTop->setSize(0.325, 0.025, 0.075);
    viewFinderTop->setLocation(0, 0.525, -0.3);
    viewFinderTop->setMaterial(obsidian);

    viewFinderBottom = new Cube();
    viewFinderBottom->setSize(0.325, 0.025, 0.075);
    viewFinderBottom->setLocation(0, 0.275, -0.3);
    viewFinderBottom->setMaterial(obsidian);

    viewFinderLeft = new Cube();
    viewFinderLeft->setSize(0.025, 0.275, 0.075);
    viewFinderLeft->setLocation(0.15, 0.4, -0.3);
    viewFinderLeft->setMaterial(obsidian);

    viewFinderRight = new Cube();
    viewFinderRight->setSize(0.025, 0.275, 0.075);
    viewFinderRight->setLocation(-0.15, 0.4, -0.3);
    viewFinderRight->setMaterial(obsidian);

    flashMount = new SquareFrustum();
    flashMount->setLocation(0, 0.675, 0);
    flashMount->setSize(0.35, 0.25, 0.25);
    flashMount->setMaterial(chrome);
}

CameraBody::~CameraBody() {
}

/**
 * Draws the camera body object at the origin.
 */
void CameraBody::drawAtOrigin() {
    mainBody->setColor(getIthColor(0));
    mainBlack->setColor(getIthColor(1));
    lensLock->setColor(getIthColor(0));
    shutterButton->setColor(getIthColor(4));
    isoSelectOuter->setColor(getIthColor(0));
    isoSelectInner->setColor(getIthColor(4));
    filmWinder->setColor(getIthColor(0));
    filmWinderLever->setColor(getIthColor(0));
    filmWinderLeverHandle->setColor(getIthColor(1));
    viewFinderGlass->setColor(getIthColor(3));
    viewFinderBottom->setColor(getIthColor(4));
    viewFinderTop->setColor(getIthColor(4));
    viewFinderLeft->setColor(getIthColor(4));
    viewFinderRight->setColor(getIthColor(4));
    flashMount->setColor(getIthColor(0));

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
    flashMount->redraw();
}
