/**
 * Cube.cpp - A class implementation representing a cube.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/27/2012: Modified to be texturable.
 *  10/07/2012: Created class.
 */
#include "Cube.h"

Cube::Cube() : Object3D() {
    setLocation(0.0, 0.0, 0.0);
    setRotation(0.0, 0.0, 0.0);
    setColor(new Color(1.0, 1.0, 1.0, 1.0));
    setSize(1.0, 1.0, 1.0);
}

Cube::~Cube() {
}

/**
 * Draws the cube object at the origin.
 */
void Cube::drawAtOrigin() {
    Color *color = getIthColor(0);
    glColor4f(color->r, color->g, color->b, color->a);

    // TOP
    glBegin( GL_QUADS );
        glNormal3f(0, 1, 0);
        glTexCoord2f( 0, 0 );
        glVertex3f( -0.5, 0.5, -0.5 );
        glTexCoord2f( 1, 0 );
        glVertex3f( 0.5, 0.5, -0.5 );
        glTexCoord2f( 1, 1 );
        glVertex3f( 0.5, 0.5, 0.5 );
        glTexCoord2f( 0, 1 );
        glVertex3f( -0.5, 0.5, 0.5 );
    glEnd();

    // BOTTOM
    glBegin( GL_QUADS );
        glNormal3f(0, -1, 0);
        glTexCoord2f( 0, 0 );
        glVertex3f( -0.5, -0.5, -0.5 );
        glTexCoord2f( 1, 0 );
        glVertex3f( 0.5, -0.5, -0.5 );
        glTexCoord2f( 1, 1 );
        glVertex3f( 0.5, -0.5, 0.5 );
        glTexCoord2f( 0, 1 );
        glVertex3f( -0.5, -0.5, 0.5 );
    glEnd();

    // FRONT
    glBegin( GL_QUADS );
        glNormal3f(0, 0, 1);
        glTexCoord2f( 0, 0 );
        glVertex3f( -0.5, 0.5, 0.5 );
        glTexCoord2f( 1, 0 );
        glVertex3f( 0.5, 0.5, 0.5 );
        glTexCoord2f( 1, 1 );
        glVertex3f( 0.5, -0.5, 0.5 );
        glTexCoord2f( 0, 1 );
        glVertex3f( -0.5, -0.5, 0.5 );
    glEnd();

    // BACK V
    glBegin( GL_QUADS );
        glNormal3f(0, 0, -1);
        glTexCoord2f( 0, 0 );
        glVertex3f( -0.5, -0.5, -0.5 );
        glTexCoord2f( 1, 0 );
        glVertex3f( 0.5, -0.5, -0.5 );
        glTexCoord2f( 1, 1 );
        glVertex3f( 0.5, 0.5, -0.5 );
        glTexCoord2f( 0, 1 );
        glVertex3f( -0.5, 0.5, -0.5 );
    glEnd();

    // Left V
    glBegin( GL_QUADS );
        glNormal3f(-1, 0, 0);
        glTexCoord2f( 0, 0 );
        glVertex3f( -0.5, 0.5, 0.5 );
        glTexCoord2f( 1, 0 );
        glVertex3f( -0.5, 0.5, -0.5 );
        glTexCoord2f( 1, 1 );
        glVertex3f( -0.5, -0.5, -0.5 );
        glTexCoord2f( 0, 1 );
        glVertex3f( -0.5, -0.5, 0.5 );
    glEnd();

    // Right
    glBegin( GL_QUADS );
        glNormal3f(1, 0, 0);
        glTexCoord2f( 0, 0 );
        glVertex3f( 0.5, 0.5, 0.5 );
        glTexCoord2f( 1, 0 );
        glVertex3f( 0.5, 0.5, -0.5 );
        glTexCoord2f( 1, 1 );
        glVertex3f( 0.5, -0.5, -0.5 );
        glTexCoord2f( 0, 1 );
        glVertex3f( 0.5, -0.5, 0.5 );
    glEnd();
}
