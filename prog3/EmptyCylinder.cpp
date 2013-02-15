/**
 * EmptyCylinder.cpp - A class implementation representing an empty cylinder.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/27/2012: Created class.
 */
#include "EmptyCylinder.h"

EmptyCylinder::EmptyCylinder() : Object3D() {
    setLocation(0.0, 0.0, 0.0);
    setRotation(0.0, 0.0, 0.0);
    setColor(new Color(1.0, 1.0, 1.0, 1.0));
    setSize(1.0, 1.0, 1.0);

    quadratic = gluNewQuadric();
    gluQuadricNormals(quadratic, GLU_SMOOTH);
    gluQuadricTexture(quadratic, GL_TRUE);
}

EmptyCylinder::~EmptyCylinder() {
}

/**
 * Draws the empty cylinder object at the origin.
 */
void EmptyCylinder::drawAtOrigin() {
    Color *color = getIthColor(0);
    glColor4f(color->r, color->g, color->b, color->a);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    gluCylinder(quadratic, 0.5, 0.5, 1, 36.0, 36.0);
}
