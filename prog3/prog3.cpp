/**
 * CS 870, Program 3, Fall 2012
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 * @date   October 27, 2012
 *
 * History
 *  10/27/2012: Modified to feature more lighting options, textures, and
 *              materials.
 *  10/07/2012: Modified to draw 3D objects.
 *  09/07/2012: Modified based on Dan Bergon's demoGlui example.
 */

#include <vector>

#include "Axis3D.h"
#include "SquareFrustum.h"
#include "Tetrahedron.h"
#include "Cube.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "CameraBody.h"
#include "CameraLens.h"
#include "Camera.h"
#include "Baseball.h"
#include "PikachuPicture.h"
#include "PikachuWrappingPaper.h"
#include "FilmCanister.h"
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

    float ptLightIntensity[] = { 1.0, 1.0, 1.0, 1.0 };
    float ptLightPosition[] = { -4.3125, 2.4375, 10.0, 1.0 };

    float dLightIntensity[] = { 1.0, 1.0, 1.0, 1.0 };
    float dLightPosition[] = { 9.0, 9.0, -9.0, 0.0 };

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, ptLightIntensity);
    glLightfv(GL_LIGHT0, GL_POSITION, ptLightPosition);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, dLightIntensity);
    glLightfv(GL_LIGHT1, GL_POSITION, dLightPosition);

    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearColor( 0.49, 0.62, 0.75, 0.0 ); // set the bg color to grey
    glColor3f( 0.0f, 0.0f, 0.0f );       // set the drawing color to black
    glPointSize( 4.0 );                  // set the point size to 4 by 4 pixels
    glMatrixMode( GL_PROJECTION );       // set up matrices; to be explained
    glLoadIdentity();                    // to be explained
    gluOrtho2D( 0.0, windowWidth, 0.0, windowHeight ); // to be explained

    Scene *scene = Scene::getInstance();

    Axis3D *axes = new Axis3D();
    scene->addObject3D(axes);

    Camera *cam = new Camera();
    scene->addObject3D(cam);

    Scene::getInstance()->redraw_cb();
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
    mainWin = glutCreateWindow( "Carmen St. Jean - prog3" );
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
