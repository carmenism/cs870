/**
 * Listener.h - An abstract class that can be registered with an observable so
 * it can be informed of changes in the observable.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on Listener.h from Professor Dan Bergeron's demoGlui
 *         program.
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  09/19/2012: Modified the version found in the demo.
 */
#ifndef LISTENER_H_
#define LISTENER_H_

class Observable; //declare the class, we'll include it in the .cpp file

class Listener
{
    public:
        Listener(Observable *observable);
        virtual ~Listener();

        virtual void update(int info, int x, int y) = 0;

    protected:
        Observable *observed;
};

#endif /*LISTENER_H_*/
