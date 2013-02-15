/**
 * GlutMouseSource.h - A class that tells registered listeners when the user
 * has moved the mouse or changed a button state.  This is a singleton class.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on GlutMouseSource.h from Professor Dan Bergeron's demoGlui
 *         program.
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  09/19/2012: Modified the version found in the demo.
 */
#ifndef GLUTMOUSESOURCE_H_
#define GLUTMOUSESOURCE_H_

#include "Observable.h"

class GlutMouseSource : public Observable
{
    public:
        static GlutMouseSource *getInstance();
        enum {MOUSE_BUTTON_LEFT = 0x00,
              MOUSE_BUTTON_MIDDLE = 0x01,
              MOUSE_BUTTON_RIGHT = 0x02,
              MOUSE_BUTTON_MASK = 0x0F,
              MOUSE_MOTION = 0x10,
              MOUSE_BUTTON_DOWN = 0x20,
              MOUSE_BUTTON_UP = 0x40,
              MOUSE_ACTION_MASK = 0xF0
             };
	
    protected:
        GlutMouseSource();
        virtual ~GlutMouseSource();

        static GlutMouseSource *instance;

        static void mouseButtonCallback(int button, int state, int x, int y);
        static void mouseMotionCallback(int x, int y);
        static void menuStatusCallback(int state, int x, int y);

};

#endif /*GLUTMOUSESOURCE_H_*/
