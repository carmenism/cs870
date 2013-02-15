/**
 * PikachuPicture.cpp - A class implementation representing a picture of
 * pikachu.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/27/2012: Created class.
 */
#include "PikachuPicture.h"

PikachuPicture::PikachuPicture() {
    setSize(1, 1, 1);
    setRotation(0.0, 0.0, 0.0);
    setLocation(0.0, 0.0, 0.0);
    setColor(new Color(1.0, 1.0, 1.0, 1.0));

    Texture *t = new Texture();
    t->setBorderColor(new Color(1.0, 0.0, 0.0, 1.0));
    t->setWrapSValue(GL_CLAMP);
    t->setWrapTValue(GL_CLAMP);
    t->loadJPEG("pikachu.jpg");

    setTexture(t);
}

PikachuPicture::~PikachuPicture() {
}

/**
 * Draws the pikachu picture object at the origin.
 */
void PikachuPicture::drawAtOrigin() {
    Color *color = getIthColor(0);
    glColor4f(color->r, color->g, color->b, color->a);

    float replication = 1.5f;
    float offset = 0.25f;

    glBegin( GL_QUADS );
        // Lower left quad corner
        glTexCoord2f( -offset, -offset );
        glVertex3f( -1.0f, -1.0f, 0.0f );

        // Lower right quad corner
        glTexCoord2f( replication - offset, -offset );
        glVertex3f( 1.0f, -1.0f, 0.0f );

        // Upper right quad corner
        glTexCoord2f( replication - offset, replication - offset );
        glVertex3f( 1.0f, 1.0f, 0.0f );

        // Upper left quad corner
        glTexCoord2f( -offset, replication - offset );
        glVertex3f( -1.0f, 1.0f, 0.0f );
    glEnd();
}
