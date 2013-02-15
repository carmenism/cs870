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
    setColor(new Color(0.4, 1.0, 0.0, 1.0));
    setSize(1.0, 1.0, 1.0);
}

Tetrahedron::~Tetrahedron() {
}

/**
 * Draws the tetrahedron object at the origin.
 */
void Tetrahedron::drawAtOrigin() {
    Color *color = getIthColor(0);
    glColor4f(color->r, color->g, color->b, color->a);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glutSolidTetrahedron();
}
