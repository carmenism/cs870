/**
 * Baseball.cpp - A class implementation representing a baseball.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/27/2012: Created class.
 */
#include "Baseball.h"

Baseball::Baseball() {
    setSize(1, 1, 1);
    setRotation(0.0, 0.0, 0.0);
    setLocation(0.0, 0.0, 0.0);
    setColor(new Color(1.0, 1.0, 1.0, 1.0));

    Texture *baseballTex = new Texture();
    baseballTex->setMagFilterValue(GL_NEAREST);
    baseballTex->setMinFilterValue(GL_NEAREST);
    baseballTex->setWrapSValue(GL_REPEAT);
    baseballTex->setWrapTValue(GL_REPEAT);
    baseballTex->setBorderColor(new Color(1.0, 1.0, 1.0, 1.0));
    baseballTex->loadJPEG("SoftballColor.jpg");

    setTexture(baseballTex);

    baseball = new Sphere();
    baseball->setColor(new Color(1.0, 1.0, 1.0, 1.0));
    baseball->setTexture(baseballTex);
}

Baseball::~Baseball() {
}

/**
 * Draws the baseball object at the origin.
 */
void Baseball::drawAtOrigin() {
    baseball->redraw();
}
