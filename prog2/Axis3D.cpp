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
    setIthColor(new Color(1, 0, 0, 1), 0); // red
    setIthColor(new Color(0, 1, 0, 1), 1); // blue
    setIthColor(new Color(0, 0, 1, 1), 2); // green
}

Axis3D::~Axis3D() {
}

/**
 * Redraws the axes.
 */
void Axis3D::redraw() {
    Color *xColor = getIthColor(0);
    Color *yColor = getIthColor(1);
    Color *zColor = getIthColor(2);

    glBegin(GL_LINES);
        glColor3f(xColor->r, xColor->b, xColor->g); // red, x axis
        glVertex3f(-50, 0, 0);
        glVertex3f(50, 0, 0);

        glColor3f(yColor->r, yColor->b, yColor->g); // blue, y axis
        glVertex3f(0, -50, 0);
        glVertex3f(0, 50, 0);

        glColor3f(zColor->r, zColor->b, zColor->g); // green, z axis
        glVertex3f(0, 0, -50);
        glVertex3f(0, 0, 50);
    glEnd();
}
