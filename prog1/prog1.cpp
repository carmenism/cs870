/**
 * CS 870, Program 1, Fall 2012
 * 
 * Code heavily derived from Chapter 2 examples of Hill & Kelley textbook
 * Updated further by Carmen St. Jean to showcase GLUI control panel
 * and mouse events.
 * 
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 * @date   September 19, 2012
 *
 * History
 *  09/07/2012: Modified based on Dan Bergon's demoGlui example.
 */

#include <vector>

#include "Triangle.h"  // includes Shape.h which includes glut.h
#include "GlutMouseListener.h"
#include "ControlPanel.h"
#include "Scene.h"

// A vector of all the shapes we will create
int windowWidth  = 640;
int windowHeight = 480;

 //<<<<<<<<<<<<<<<<<<<<<<< appInit >>>>>>>>>>>>>>>>>>>>
 void appInit( void )
 {
    glClearColor( 1.0, 1.0, 1.0, 0.0 );  // set the bg color to a bright white
    glColor3f( 0.0f, 0.0f, 0.0f );       // set the drawing color to black 
    glPointSize( 4.0 );                  // set the point size to 4 by 4 pixels
    glMatrixMode( GL_PROJECTION );       // set up matrices- to be explained
    glLoadIdentity();                    // to be explained
    gluOrtho2D( 0.0, windowWidth, 0.0, windowHeight );// to be explained
   
    // Create 3 triangle objects, with different locations/sizes/colors
    //    add them to the shapes array.
    Scene *scene = Scene::getInstance();
   
    Triangle* tri = new Triangle();  

    tri = new Triangle();
    tri->setLocation( 10, 50 );
    tri->setColor( 0, 1, 1 );    
    scene->addShape( tri );
    
    tri = new Triangle();  
    tri->setLocation( 70, 50 );
    tri->setColor( 1, 0, 1 );
    tri->setSize( 2, 2 );    
    scene->addShape( tri );
    (ControlPanel::getInstance())->setMovableShape( tri );
    
    tri = new Triangle();  // triangle with default color (now red)
    tri->setLocation( 300, 50 );
    scene->addShape( tri );
}

//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
//rdb void main( int argc, char **argv )
int main( int argc, char **argv )
{
   int mainWin;

   glutInit( &argc, argv );                       // initialize toolkit
   glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB ); // set the display mode
   glutInitWindowSize( windowWidth, windowHeight );
   glutInitWindowPosition( 100, 150 );            // set window position on screen
   mainWin = glutCreateWindow( "Carmen St. Jean - prog1" ); // open screen window
   appInit();
   std::cerr << "back from appInit\n";

   GlutMouseListener mouseListener;

   //create a GLUI control panel window (code adapted from GLUI 2.0 manual)
   ControlPanel* controls = ControlPanel::getInstance();
   controls->initialize( "Control Panel", mainWin );

   /** Register the Idle callback with GLUI (instead of with GLUT) **/
   GLUI_Master.set_glutIdleFunc( 0 );

   /** Now call the regular GLUT main loop **/
   glutMainLoop();                           // go into a perpetual loop
}
