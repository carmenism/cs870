/**
 * Scene.cpp - A class to keep track of a scene of objects and mouse
 *  interactions with the screen.
 * 
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on Scene.cpp of demo3 by Dan Bergeron.
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/07/2012: Modified class based on original in demo3.
 */
#include "Scene.h"
#include "Object3D.h"
#include "ControlPanel.h"
#include "GlutMouseSource.h"
#include <GL/glui.h>
#include <stddef.h>
//------------------ Class variables ---------------------------------
Scene *Scene::instance = NULL;

/**
 * Initialize any values, register callbacks.
 */
Scene::Scene() {
    glEnable( GL_COLOR_MATERIAL );
    GLUI_Master.set_glutDisplayFunc( redraw_cb ); // Register redraw function.

    float defRotate[] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
    float defTranslate[] = { 0.0, 0.0, 0.0 };
    float defScale[] = { 1.0, 1.0, 1.0 };

    for (int i = 0; i < 16; i++) {
        sceneRotate[i] = defRotate[i];
    }

    for (int i = 0; i < 3; i++) {
        sceneTranslate[i] = defTranslate[i];
        sceneScale[i] = defScale[i];
    }
}

/**
 * Return the singleton instance.  If it does not exist, create one.
 *
 * @return The singleton instance of the scene.
 */
Scene *Scene::getInstance() {
    if ( !instance ) {
        instance = new Scene();
    }

    return instance;
}

void Scene::setRotation( float *r )
{
    for (int i = 0; i < 16; i++) {
       sceneRotate[i] = r[i];
    }
}

void Scene::setTranslation( float *t )
{
    for (int i = 0; i < 3; i++) {
       sceneTranslate[i] = t[i];
    }
}

void Scene::setScale( float *s )
{
    for (int i = 0; i < 3; i++) {
       sceneScale[i] = s[i];
    }
}

/**
 * Redraws the scene.
 */
void Scene::redraw( void ) {
    // Clear the screen.
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT  );
    ControlPanel::getInstance()->updateProjection();

    // Create a vector iterator to access the Shapes in the "shapes" vector.
    std::vector<Object3D*>::iterator it;

    glPushMatrix();
        glTranslatef(sceneTranslate[0], sceneTranslate[1], sceneTranslate[2]);
        glMultMatrixf(sceneRotate);
        glScalef(sceneScale[0], sceneScale[1], sceneScale[2]);

        for ( it = shapes.begin(); it < shapes.end(); it++ ) {
           (*it)->redraw();
        }
    glPopMatrix();

    // Send all output to display.
    glFlush();
}

/**
 * Adds an object to the list of objects to be drawn on the screen.
 *
 * @param newShape A pointer to an Object3D object.
 */
void Scene::addObject3D( Object3D *newShape ) {
    shapes.push_back( newShape );
}

/**
 * Clear the scene of all shapes.
 */
void Scene::clear() {
    shapes.clear();
}

/**
 * Pass control to the class's redraw method.
 */
void Scene::redraw_cb() {
    getInstance()->redraw();
}

//----------------- GlutMouseListener methods ------------------------

/**
 * Indicates the mouse was pressed.  Kept in case mouse methods are to be
 * readded later.
 */
void Scene::mousePressed( int button, int x, int y ) {

}

/**
 * Indicates the mouse was released.  Kept in case mouse methods are to be
 * readded later.
 */
void Scene::mouseReleased( int button, int x, int y ) {

}

/**
 * Indicates the mouse was moved.  Kept in case mouse methods are to be readded
 * later.
 */
void Scene::mouseMoved( int x, int y ) {

}
