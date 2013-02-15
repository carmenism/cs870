/**
 * PikachuWrappingPaper.cpp - A class implementation representing a tiled
 * picture of pikachu.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/27/2012: Created class.
 */
#include "PikachuWrappingPaper.h"

PikachuWrappingPaper::PikachuWrappingPaper() {
    setSize(1, 1, 1);
    setRotation(0.0, 0.0, 0.0);
    setLocation(0.0, 0.0, 0.0);
    setColor(new Color(1.0, 1.0, 1.0, 1.0));

    Texture *t = new Texture();
    t->loadJPEG("pikachu.jpg");

    setTexture(t);
}

PikachuWrappingPaper::~PikachuWrappingPaper() {
}

/**
 * Draws the pikachu wrapping paper object at the origin.
 */
void PikachuWrappingPaper::drawAtOrigin() {
    Color *color = getIthColor(0);
    glColor4f(color->r, color->g, color->b, color->a);

    float replication = 4.0f;
    float offset = 0.0f;

    glBegin( GL_QUADS );
        // Lower left quad corner
        glTexCoord2f( offset, offset );
        glVertex3f( -1.0f, -1.0f, 0.0f );

        // Lower right quad corner
        glTexCoord2f( replication + offset, offset );
        glVertex3f( 1.0f, -1.0f, 0.0f );

        // Upper right quad corner
        glTexCoord2f( replication + offset, replication + offset );
        glVertex3f( 1.0f, 1.0f, 0.0f );

        // Upper left quad corner
        glTexCoord2f( offset, replication + offset );
        glVertex3f( -1.0f, 1.0f, 0.0f );
    glEnd();
}
