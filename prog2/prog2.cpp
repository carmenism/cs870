/**
 * CS 870, Program 1, Fall 2012
 * 
 * Code heavily derived from Chapter 2 examples of Hill & Kelley textbook
 * Updated further by Carmen St. Jean to showcase  3D objects.
 * 
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 * @date   October 7, 2012
 *
 * History
 *  10/07/2012: Modified to draw 3D objects.
 *  09/07/2012: Modified based on Dan Bergon's demoGlui example.
 */

#include <vector>

#include "Axis3D.h"
#include "Tetrahedron.h"
#include "Cube.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "CameraBody.h"
#include "CameraLens.h"
#include "Camera.h"
#include "GlutMouseListener.h"
#include "ControlPanel.h"
#include "Scene.h"

// A vector of all the shapes we will create
int windowWidth  = 640;
int windowHeight = 480;

 //<<<<<<<<<<<<<<<<<<<<<<< appInit >>>>>>>>>>>>>>>>>>>>
void appInit( void ) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    float lightIntensity[] = { 1.0, 1.0, 1.0, 1.0 };
    float lightPosition[] = { 100.0, 100.0, 100.0, 0.0 };

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    glClearColor( 0.25, 0.25, 0.25, 0.0 ); // set the bg color to grey
    glColor3f( 0.0f, 0.0f, 0.0f );       // set the drawing color to black
    glPointSize( 4.0 );                  // set the point size to 4 by 4 pixels
    glMatrixMode( GL_PROJECTION );       // set up matrices; to be explained
    glLoadIdentity();                    // to be explained
    gluOrtho2D( 0.0, windowWidth, 0.0, windowHeight ); // to be explained

    Scene *scene = Scene::getInstance();

    Axis3D *axes = new Axis3D();
    scene->addObject3D(axes);

    Cube *cube = new Cube();
    cube->setRotation(0.0, 45.0, 45.0);
    cube->setLocation(-60.0, 0, 0);
    scene->addObject3D(cube);

    Sphere *sphere = new Sphere();
    sphere->setLocation(-45, -20, 0);
    sphere->setSize(10, 10, 20);
    sphere->setRotation(90, -30, -15);
    scene->addObject3D(sphere);

    Cylinder *cyl = new Cylinder();
    cyl->setLocation(-90, 0, 0);
    cyl->setSize(10, 10, 10);
    cyl->setRotation(-15, -15, 0);
    scene->addObject3D(cyl);

    Tetrahedron *t = new Tetrahedron();
    t->setLocation(-45, 0, 30);
    t->setSize(5, 5, 5);
    t->setRotation(-15, -15, 0);
    scene->addObject3D(t);

    CameraLens *cl = new CameraLens();
    cl->setLocation(50, 20, 0);
    cl->setRotation(15, 0, 0);
    scene->addObject3D(cl);

    CameraBody *cb = new CameraBody();
    cb->setRotation(0, -15, -30);
    cb->setLocation(50, 0, 30);
    scene->addObject3D(cb);

    Camera *cam1 = new Camera();
    cam1->setIthColor(new Color(0.69, 0.09, 0.12), 0);
    cam1->setIthColor(new Color(1.0, 0.89, 0.01), 1);
    cam1->setLocation(-40, 40, 10);
    cam1->setRotation(10, 0, 0);
    scene->addObject3D(cam1);

    Camera *cam2 = new Camera();
    cam2->setIthColor(new Color(0.11, 0.64, 0.22), 0);
    cam2->setLocation(-70, 40, 10);
    cam2->setRotation(0, 45, 10);
    scene->addObject3D(cam2);

    Camera *cam = new Camera();
    cam->setSize(2.0, 2.0, 2.0);
    scene->addObject3D(cam);

    (ControlPanel::getInstance())->setMovableObject3D( cam );
}

//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main( int argc, char **argv )
{
    int mainWin;

    glutInit( &argc, argv ); // Initialize toolkit.
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH ); // Display mode.
    glutInitWindowSize( windowWidth, windowHeight );
    glutInitWindowPosition( 100, 150 ); // Set window position on screen.

    // Open screen window.
    mainWin = glutCreateWindow( "Carmen St. Jean - prog2" );
    appInit();

    GlutMouseListener mouseListener;

    // Create a GLUI control panel window (code adapted from GLUI 2.0 manual).
    ControlPanel* controls = ControlPanel::getInstance();
    controls->initialize( "Control Panel", mainWin );

    // Register the Idle callback with GLUI (instead of with GLUT).
    GLUI_Master.set_glutIdleFunc( 0 );

    // Now call the regular GLUT main loop.
    glutMainLoop(); // Go into a perpetual loop.
}
