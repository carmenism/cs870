/**
 * CS 870, Program 0, Fall 2012
 * 
 * Code heavily derived from Chapter 2 examples of Hill & Kelley textbook
 * Updated further by Carmen St. Jean to print several examples of 
 * custom shape objects.
 * 
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 * @date   September 7, 2012
 *
 * History
 *  09/07/2012: Added border functionality.
 *  09/06/2012: Added square, pentagon, hexagon shapes.
 */

// define std:vector to be included
#include <vector>

// glut.h includes GL.h and glu.h
#include <GL/glut.h>

#include "Triangle.h"
#include "Square.h"
#include "Pentagon.h"
#include "Hexagon.h"

// A vector of all the shapes we will create
std::vector<Shape*>  shapes;
   
// window size parameters
int windowWidth  = 640;
int windowHeight = 480;

//----------------------< appInit --------------------
 void appInit(void)
 {
    glClearColor( 1.0, 1.0, 1.0, 0.0 );  // set the bg color to a bright white
    glColor3f( 0.0f, 0.0f, 0.0f );       // set the drawing color to black 

    glMatrixMode( GL_PROJECTION );       // set up matrices- to be explained 
    glLoadIdentity();                    //                  to be explained
    gluOrtho2D( 0.0, windowWidth, 0.0, windowHeight );// to be explained
   
    // Create 3 triangle objects, with different locations/sizes/colors
    //    add them to the shapes array.
    //
    Triangle* tri = new Triangle();  
    tri->setLocation( 10, 50 );
    tri->setColor( 0.0, 0.6, 0.88 );
    tri->setBorderWidth( 3.0 );
    shapes.push_back( tri );

    tri = new Triangle();  
    tri->setLocation( 70, 50 );
    tri->setColor( 0.41, 0.13, 0.55 );
    tri->setSize( 2, 2 );    
    tri->setBorderColor( 0.0, 0.6, 0.88 );
    tri->setBorderWidth( 3.0 );
    shapes.push_back( tri );
    
    tri = new Triangle(); 
    tri->setLocation( 300, 50 );
    tri->setColor( 0.83, 0.10, 0.12 );
    shapes.push_back( tri );

    // Create 3 square objects, with different locations/sizes/colors
    //    add them to the shapes array.
    //
    Square* sq = new Square();
    sq->setLocation( 350, 360 );
    sq->setColor( 1.0, 0.8, 0.07 );
    shapes.push_back( sq );

    sq = new Square();
    sq->setLocation( 200, 200 );
    sq->setColor( 0.6, 0.8, 0.2 );
    sq->setSize( 2, 4 );
    shapes.push_back( sq );

    sq = new Square();
    sq->setLocation( 400, 300 );
    sq->setColor( 0.34, 0.34, 0.56 );
    sq->setSize( 5, 1 );
    sq->setBorderColor( 0.83, 0.10, 0.12 );
    sq->setBorderWidth( 4.0 );
    shapes.push_back( sq );

    // Create 3 pentagon objects, with different locations/sizes/colors
    //    add them to the shapes array.
    //
    Pentagon* pt = new Pentagon();
    pt->setLocation( 200, 100 );
    pt->setColor( 0.94, 0.5, 0.5 );
    shapes.push_back( pt );

    pt = new Pentagon();
    pt->setLocation( 350, 100 );
    pt->setSize( 1, 2 );
    pt->setColor( 0.23, 0.29, 0.56 );
    pt->setBorderColor( 1.0, 0.8, 0.07 );
    pt->setBorderWidth( 6.0 );
    shapes.push_back( pt );

    pt = new Pentagon();
    pt->setLocation( 420, 150 );
    pt->setColor( 1.0, 0.38, 0.01 );
    pt->setSize( 2, 1 );
    shapes.push_back( pt );

    // Create 3 hexagon objects, with different locations/sizes/colors
    //    add them to the shapes array.
    //
    Hexagon* hex = new Hexagon();
    hex->setLocation( 50, 300 );
    hex->setColor( 1.0, 0.8, 0.07 );
    hex->setBorderWidth( 6.0 );
    shapes.push_back( hex );
}

//------------------------ redraw -----------------
// the redraw function
void redraw( void )
{
   glClear( GL_COLOR_BUFFER_BIT );     // clear the screen 

   // create a vector iterator to access the Shapes in the "shapes" vector
   std::vector<Shape*>::iterator it;
   for ( it = shapes.begin(); it < shapes.end(); it++ ) {
       (*it)->redraw();
   }

   glFlush();                     // send all output to display 
}
     
//------------------------ main ----------------------
int main( int argc, char **argv )
{
   glutInit( &argc, argv );                       // initialize toolkit
   glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB ); // set the display mode
   glutInitWindowSize( windowWidth, windowHeight ); 
   glutInitWindowPosition( 100, 150 );           // window position on screen
   glutCreateWindow( "Carmen St. Jean, CS870, 0P" ); // open the screen window
   glutDisplayFunc( redraw );                    // register redraw function
   appInit();                   
   glutMainLoop();                               // go into a perpetual loop
}
