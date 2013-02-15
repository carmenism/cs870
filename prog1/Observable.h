/**
 * Observable.h - An abstract class that tells registered listeners when a
 * change has occurred.  Implements the Subject part of the Observer pattern.
 * 
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on Observable.h from Professor Dan Bergeron's demoGlui
 *         program.
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  09/19/2012: Modified the version found in the demo.
 */
#ifndef OBSERVABLE_H_
#define OBSERVABLE_H_

#include <vector>
#include "Listener.h"

class Observable
{
    public:
	
        Observable();
        virtual ~Observable();

        virtual bool attach(Listener *);
        virtual bool detach(Listener *);
        virtual void notify(int info, int x, int y);

    private:
        std::vector<Listener *> listeners;
};

#endif /*OBSERVABLE_H_*/
