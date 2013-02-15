/**
 * Listener.cpp - An abstract class that can be registered with an observable
 *  so it can be informed of changes in the observable.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on Listener.cpp of demo3 by Dan Bergeron.
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/07/2012: Created class based on version in demo3.
 */
#include "Observable.h"

//------------------ Constructors ------------------------------------
/**
 * Register ourselves with the observable so we get notified.
 */
Listener::Listener( Observable *observable ) {
    observed = observable;

    if ( observed ) {
        observed->attach( this );
    }
}

//------------------ Destructor ------------------------------------
/**
 * Remove ourselves from the obervable's list!
 */
Listener::~Listener() {
    if ( observed ) {
        observed->detach( this );
    }
}
