/**
 * Scene.h - A class to keep track of a scene of objects and mouse interactions
 *  with the screen.
 * 
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on Scene.h of demo3 by Dan Bergeron.
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/07/2012: Modified class based on original in demo3.
 */
#ifndef SCENE_H_
#define SCENE_H_

#include <vector>
#include <string>
#include <GL/glut.h>
#include "GlutMouseListener.h"
#include "Object3D.h"

class Shape;

class Scene : public GlutMouseListener
{
public:
    //----Singleton Pattern getInstance method----
    static Scene *getInstance();

    //----Methods----
    void addObject3D( Object3D *newShape );
    void clear();

    static void redraw_cb();
protected: 
    //----Singleton Pattern parts----
    Scene();
    static Scene *instance;

    //----MouseListener response methods----
    virtual void mousePressed( int button, int x, int y );
    virtual void mouseReleased( int button, int x, int y );
    virtual void mouseMoved( int x, int y );

    //object-level method for handling callbacks
    void redraw( void );

    //----Member variables----
    std::vector<Object3D*> shapes;
};

#endif /*SCENE_H_*/
