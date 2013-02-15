/**
 * Observable.cpp - An abstract class that tells registered listeners when a
 * change has occurred.  Implements the Subject part of the Observer pattern.
 * 
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on Observable.cpp from Professor Dan Bergeron's demoGlui
 *         program.
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  09/19/2012: Modified the version found in the demo.
 */
#include "Observable.h"
//------------------ Constructors ------------------------------------
/** 
 */
Observable::Observable()
{
}

//------------------ Destructor ------------------------------------
Observable::~Observable()
{
}

//------------------ public methods -------------------------------
/** Add the passed listener to our list, return true if it works
 */
bool Observable::attach( Listener *l)
{
    listeners.push_back( l );
    return true;
}

//-----------------------------------------------------------------
/** Remove the passed listener to our list, return true if it was
 *  there, and false otherwise.
 */
bool Observable::detach( Listener *l )
{
    std::vector<Listener *>::iterator it;
    for( it = listeners.begin(); it < listeners.end(); it++ )
    {
        if ( *it == l )
        {
            listeners.erase( it );
            return true;
        }
    }
    return false;
}

//-----------------------------------------------------------------
/** Go through our list of listeners and let them know about the
 *  change.
 */
void Observable::notify( int info, int x, int y )
{
    std::vector<Listener *>::iterator it;
    for( it = listeners.begin(); it < listeners.end(); it++ )
    {
        (*it)->update( info, x, y );
    }
}
