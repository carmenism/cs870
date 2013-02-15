/**
 * SquareFrustum.cpp - A class implementation representing a square frustum.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/27/2012: Created class.
 */
#include "SquareFrustum.h"

SquareFrustum::SquareFrustum() : Object3D() {
    setLocation(0.0, 0.0, 0.0);
    setRotation(0.0, 0.0, 0.0);
    setColor(new Color(1.0, 1.0, 1.0, 1.0));
    setSize(1.0, 1.0, 1.0);

    setTopSquareLength(1.0);
    setBottomSquareLength(2.0);
}

SquareFrustum::~SquareFrustum() {
}


/**
 * Sets the length for the top square of the frustum.
 *
 * @param The new length for the top square of the frustum.
 */
void SquareFrustum::setTopSquareLength( float t ) {
    topSquareLength = t;
}

/**
 * Gets the length for the top square of the frustum.
 *
 * @return The length of the sides of the top square of the frustum.
 */
float SquareFrustum::getTopSquareLength() {
    return topSquareLength;
}

/**
 * Sets the length for the bottom square of the frustum.
 *
 * @param The new length for the bottom square of the frustum.
 */
void SquareFrustum::setBottomSquareLength( float b ) {
    bottomSquareLength = b;
}

/**
 * Gets the length for the bottom square of the frustum.
 *
 * @return The length of the sides of the bottom square of the frustum.
 */
float SquareFrustum::getBottomSquareLength() {
    return bottomSquareLength;
}

/**
 * Draws the normal for a face of the square frustum based on three points that
 * form the side.
 */
void SquareFrustum::drawNormal( float * p1, float * p2, float * p3 ) {
    float u[] = { p1[0] - p2[0], p1[1] - p2[1], p1[2] - p2[2] };
    float v[] = { p3[0] - p2[0], p3[1] - p2[1], p3[2] - p2[2] };

    float normal[] = { u[1] * v[2] - u[2] * v[1],
                       u[2] * v[0] - u[0] * v[2],
                       u[0] * v[1] - u[1] * v[0] };
    glNormal3f( normal[0], normal[1], normal[2] );
}

/**
 * Draws the square frustum object at the origin.
 */
void SquareFrustum::drawAtOrigin() {
    Color *color = getIthColor(0);
    glColor4f(color->r, color->g, color->b, color->a);

    float small = topSquareLength / 2.0;
    float large = bottomSquareLength / 2.0;
    float height = 0.5;

    float p1[] = { -small, height, small };
    float p2[] = { small, height, small };
    float p3[] = { large, -height, large };
    float p4[] = { -large, -height, -large };
    float p5[] = { large, -height, -large };
    float p6[] = { small, height, -small };
    float p7[] = { -large, -height, large };
    float p8[] = { -small, height, -small };

    // TOP
    glBegin( GL_QUADS );
        glNormal3f(0, 1, 0);

        glTexCoord2f( 0, 0 );
        glVertex3f( p8[0], p8[1], p8[2] );
        glTexCoord2f( 1, 0 );
        glVertex3f( p6[0], p6[1], p6[2] );
        glTexCoord2f( 1, 1 );
        glVertex3f( p2[0], p2[1], p2[2] );
        glTexCoord2f( 0, 1 );
        glVertex3f( p1[0], p1[1], p1[2] );
    glEnd();

    // BOTTOM
    glBegin( GL_QUADS );
        glNormal3f(0, -1, 0);

        glTexCoord2f( 0, 0 );
        glVertex3f( p4[0], p4[1], p4[2] );
        glTexCoord2f( 1, 0 );
        glVertex3f( p5[0], p5[1], p5[2] );
        glTexCoord2f( 1, 1 );
        glVertex3f( p3[0], p3[1], p3[2] );
        glTexCoord2f( 0, 1 );
        glVertex3f( p7[0], p7[1], p7[2] );
    glEnd();

    // FRONT
    glBegin( GL_QUADS );
        drawNormal(p1, p2, p3);

        glTexCoord2f( 0, 0 );
        glVertex3f( p1[0], p1[1], p1[2] );
        glTexCoord2f( 1, 0 );
        glVertex3f( p2[0], p2[1], p2[2] );
        glTexCoord2f( 1, 1 );
        glVertex3f( p3[0], p3[1], p3[2] );
        glTexCoord2f( 0, 1 );
        glVertex3f( p7[0], p7[1], p7[2] );
    glEnd();

    // BACK V
    glBegin( GL_QUADS );
        drawNormal(p4, p5, p6);

        glTexCoord2f( 0, 0 );
        glVertex3f( p4[0], p4[1], p4[2] );
        glTexCoord2f( 1, 0 );
        glVertex3f( p5[0], p5[1], p5[2] );
        glTexCoord2f( 1, 1 );
        glVertex3f( p6[0], p6[1], p6[2] );
        glTexCoord2f( 0, 1 );
        glVertex3f( p8[0], p8[1], p8[2] );
    glEnd();

    // Left V
    glBegin( GL_QUADS );
        drawNormal(p1, p8, p4);

        glTexCoord2f( 0, 0 );
        glVertex3f( p1[0], p1[1], p1[2] );
        glTexCoord2f( 1, 0 );
        glVertex3f( p8[0], p8[1], p8[2] );
        glTexCoord2f( 1, 1 );
        glVertex3f( p4[0], p4[1], p4[2] );
        glTexCoord2f( 0, 1 );
        glVertex3f( p7[0], p7[1], p7[2] );
    glEnd();

    // Right
    glBegin( GL_QUADS );
        drawNormal(p2, p6, p5);

        glTexCoord2f( 0, 0 );
        glVertex3f( p2[0], p2[1], p2[2] );
        glTexCoord2f( 1, 0 );
        glVertex3f( p6[0], p6[1], p6[2] );
        glTexCoord2f( 1, 1 );
        glVertex3f( p5[0], p5[1], p5[2] );
        glTexCoord2f( 0, 1 );
        glVertex3f( p3[0], p3[1], p3[2] );
    glEnd();
}
