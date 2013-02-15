/**
 * Tetrahedron.cpp - A class implementation representing a tetrahedron.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/07/2012: Created class.
 */
#include "Tetrahedron.h"

Tetrahedron::Tetrahedron() {
    setLocation(0.0, 0.0, 0.0);
    setRotation(0.0, 0.0, 0.0);
    setColor(new Color(0.4, 1.0, 0.0));
    setSize(10.0, 10.0, 10.0);
}

Tetrahedron::~Tetrahedron() {
}

/**
 * Redraws the tetrahedron object.
 */
void Tetrahedron::redraw() {
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

        glutSolidTetrahedron();
    glPopMatrix();
}
