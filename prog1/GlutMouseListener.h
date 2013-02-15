/**
 * GlutMouseListener.h - A class that can receive mouse event notifications.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on GlutMouseListener.h from Professor Dan Bergeron's demoGlui
 *         program.
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  09/19/2012: Modified the version found in the demo.
 */
#ifndef GLUTMOUSELISTENER_H_
#define GLUTMOUSELISTENER_H_

#include "Listener.h"
#include <iostream>
#include <GL/glut.h>

class GlutMouseListener : public Listener
{
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
