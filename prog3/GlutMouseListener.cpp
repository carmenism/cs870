/**
 * GlutMouseListener.cpp - A class that can receive mouse event notifications.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on GlutMouseListener.cpp of demo3 by Dan Bergeron.
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/07/2012: Created class based on version in demo3.
 */
#include "GlutMouseListener.h"
#include "GlutMouseSource.h"

//------------------ Constructors ------------------------------------
/** Instantiate as an listener that attaches to a GlutMouseSource
 */
GlutMouseListener::GlutMouseListener()
: Listener( GlutMouseSource::getInstance() )
{
}

//------------------ other methods -----------------------------------
void GlutMouseListener::update( int info, int x, int y ) {
    switch ( info & GlutMouseSource::MOUSE_ACTION_MASK ) {
        case GlutMouseSource::MOUSE_BUTTON_DOWN:
            mousePressed( info & GlutMouseSource::MOUSE_BUTTON_MASK, x, y );
            break;
        case GlutMouseSource::MOUSE_BUTTON_UP:
            mouseReleased( info & GlutMouseSource::MOUSE_BUTTON_MASK, x, y );
            break;
        case GlutMouseSource::MOUSE_MOTION:
            mouseMoved( x, y );
    }
}

