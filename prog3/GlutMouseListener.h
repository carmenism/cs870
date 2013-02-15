/**
 * GlutMouseListener.h - A class that can receive mouse event notifications.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on GlutMouseListener.h of demo3 by Dan Bergeron.
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/07/2012: Created class based on version in demo3.
 */
#ifndef GLUTMOUSELISTENER_H_
#define GLUTMOUSELISTENER_H_

#include "Listener.h"
#include <iostream>
#include <GL/glut.h>

class GlutMouseListener : public Listener {
    public:
        GlutMouseListener();

    protected:
        virtual void mousePressed(int button, int x, int y) {};
        virtual void mouseReleased(int button, int x, int y) {};
        virtual void mouseMoved(int x, int y) {};

    private:
        virtual void update(int info, int x, int y);
};

#endif /*GLUTMOUSELISTENER_H_*/
