/**
 * Axis3D.cpp - A class implementation representing the x, y, and z axes in 3D.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/07/2012: Created class.
 */
#include "Axis3D.h"

Axis3D::Axis3D() {
    setSize(1, 1, 1);
    setRotation(0.0, 0.0, 0.0);
    setLocation(0.0, 0.0, 0.0);

    setIthColor(new Color(1, 0, 0, 1), 0); // red
    setIthColor(new Color(0, 1, 0, 1), 1); // blue
    setIthColor(new Color(0, 0, 1, 1), 2); // green
}

Axis3D::~Axis3D() {
}

/**
 * Draws the axes at the origin.
 */
void Axis3D::drawAtOrigin() {
    Color *xColor = getIthColor(0);
    Color *yColor = getIthColor(1);
    Color *zColor = getIthColor(2);

    glBegin(GL_LINES);
        glColor4f(xColor->r, xColor->g, xColor->b, xColor->a); // red, x axis
        glVertex3f(-2.5, 0, 0);
        glVertex3f(2.5, 0, 0);

        glColor4f(yColor->r, yColor->g, yColor->b, yColor->a); // blue, y axis
        glVertex3f(0, -2.5, 0);
        glVertex3f(0, 2.5, 0);

        glColor4f(zColor->r, zColor->g, zColor->b, zColor->a); // green, z axis
        glVertex3f(0, 0, -2.5);
        glVertex3f(0, 0, 2.5);
    glEnd();
}
