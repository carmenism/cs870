/**
 * Sphere.cpp - A class implementation representing a sphere.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/07/2012: Created class.
 */
#include "Sphere.h"

Sphere::Sphere() {
    setLocation(0.0, 0.0, 0.0);
    setRotation(0.0, 0.0, 0.0);
    setColor(new Color(1.0, 0.0, 1.0));
    setSize(10.0, 10.0, 10.0);
}

Sphere::~Sphere() {
}

/**
 * Redraws the sphere object.
 */
void Sphere::redraw() {
    Color *color = getIthColor(0);
    glColor3f(color->r, color->g, color->b);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glPushMatrix();
        glTranslatef(xLoc, yLoc, zLoc);

        glMultMatrixf(ballRotate);

        glRotatef(xRotation, 1, 0, 0);
        glRotatef(yRotation, 0, 1, 0);
        glRotatef(zRotation, 0, 0, 1);

        glScalef(xSize, ySize, zSize);

        glutSolidSphere(0.5, 20.0, 20.0);
    glPopMatrix();
}
