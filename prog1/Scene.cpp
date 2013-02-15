/**
 * Scene.cpp - A class to keep track of a scene of objects, and mouse
 * interactions with the screen.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on Scene.cpp from Professor Dan Bergeron's demoGlui program.
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  09/19/2012: Modified the version found in the demo.
 */
#include <iostream>
#include "Scene.h"
#include "Shape.h"
#include "Triangle.h"
#include "Square.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "GlutMouseSource.h"
#include "ControlPanel.h"
#include <GL/glui.h>
#include <stddef.h>
//------------------ Class variables ---------------------------------
Scene *Scene::instance = NULL;
int id = 0;

//------------------ Constructors ------------------------------------
/** Initialize any values, register callbacks
 */
Scene::Scene()
{
    rubberbanding = false;
    rbStartX = 0;
    rbStartY = 0;

    GLUI_Master.set_glutDisplayFunc( redraw_cb );   // register redraw function

    glutCreateMenu( processLeftButtonMenu_cb );
        glutAddMenuEntry( "Red", COLOR_RED );
        glutAddMenuEntry( "Orange", COLOR_ORANGE );
        glutAddMenuEntry( "Yellow", COLOR_YELLOW );
        glutAddMenuEntry( "Green", COLOR_GREEN );
        glutAddMenuEntry( "Blue", COLOR_BLUE );
        glutAddMenuEntry( "Purple", COLOR_PURPLE );
        glutAddMenuEntry( "Black", COLOR_BLACK );
        //attach current menu to a left-click
    glutAttachMenu( GLUT_LEFT_BUTTON );

    glutCreateMenu( processRightButtonMenu_cb );
        glutAddMenuEntry( "Triangle", SHAPE_TRIANGLE );
        glutAddMenuEntry( "Rectangle", SHAPE_RECTANGLE );
        glutAddMenuEntry( "Pentagon", SHAPE_PENTAGON );
        glutAddMenuEntry( "Hexagon", SHAPE_HEXAGON );
        //attach current menu to a right-click
    glutAttachMenu( GLUT_RIGHT_BUTTON );

    currentShape = SHAPE_TRIANGLE;
    currentFillColor = COLOR_RED;
    currentBoundaryColor = COLOR_BLACK;
    currentDrawBoundary = true;
    currentDrawFill = true;
    mouseEnabled = true;

    nColors = 7;

    float rDefault[] = { 0.83,  1.0,  1.0, 0.6,  0.0, 0.41, 0.0 };
    float gDefault[] = { 0.10, 0.38,  0.8, 0.8,  0.6, 0.13, 0.0 };
    float bDefault[] = { 0.12, 0.01, 0.07, 0.2, 0.88, 0.55, 0.0 };

    for ( int i = 0; i < nColors; i++ )
    {
        colorR[ i ] = rDefault[ i ];
        colorG[ i ] = gDefault[ i ];
        colorB[ i ] = bDefault[ i ];
    }
}

//------------------ public class methods --------------------------

/**
 * Return the singleton instance.  If it does not exist, create one.
 */
Scene *Scene::getInstance()
{
    if ( !instance )
        instance = new Scene();
    return instance;
}

//--------------------------------------------------------------------

/**
 * Adds a shape to the vector of shape objects.
 *
 * @param newShape The shape to be added.
 */
void Scene::addShape( Shape *newShape )
{
    shapes.push_back( newShape );
}

/**
 * Removes a shape found in the vector if there is one with the given ID.
 *
 * @param A unique ID for a shape object.
 */
void Scene::removeShape( int idToRemove )
{
    int indexToRemove = -1;

	for (int i = 0; i < shapes.size(); i++) {
		if ( shapes[ i ]->getId() == idToRemove ) {
			indexToRemove = i;
			break;
		}
	}

    if ( indexToRemove != -1 )
    {
	   shapes.erase( shapes.begin() + indexToRemove );
	   std::cout << "Removing shape with ID " << idToRemove << "\n";
    }
}

/**
 * Clears all shapes from the shape vector (and therefore screen).
 */
void Scene::clear()
{
    shapes.clear();
    redraw();
}

/**
 * Sets the type for the next shape to be drawn to the enum specified.
 *
 * @param shapeNumber The enum for the shape type desired.
 */
void Scene::setShape( int shapeNumber )
{
    currentShape = shapeNumber;
}

/**
 * Sets the fill color for the next shape to be drawn to the enum specified.
 *
 * @param colorNumber The enum for the color type desired.
 */
void Scene::setFillColor( int colorNumber )
{
    currentFillColor = colorNumber;
}

/**
 * Sets the boundary color for the next shape to be drawn to the enum specified.
 *
 * @param colorNumber The enum for the color type desired.
 */
void Scene::setBoundaryColor( int colorNumber )
{
    currentBoundaryColor = colorNumber;
}

/**
 * Sets the preference for whether or not the next shape to be drawn will have
 * a boundary.
 *
 * @param db True if a boundary is desired.
 */
void Scene::setDrawBoundary( bool db )
{
    currentDrawBoundary = db;
}

/**
 * Sets the preference for whether or not the next shape to be drawn will have
 * a fill.
 *
 * @param df True if a fill is desired.
 */
void Scene::setDrawFill( bool df )
{
    currentDrawFill = df;
}

/**
 * Sets the preference for whether or not the mouse is enabled to draw shapes
 * on the screen.
 *
 * @param mouse True if the mouse is allowed to draw shapes.
 */
void Scene::setMouseEnabled( bool mouse )
{
    mouseEnabled = mouse;
}

//------------------ protected class methods --------------------------

/**
 * Pass control to the class's leftButtonMenu method.
 *
 * @param command The command to be processed.
 */
void Scene::processLeftButtonMenu_cb( int command )
{
    getInstance()->leftButtonMenu( command );
}

/**
 * Processes a left button mouse command.
 *
 * @param command The command to be processed.
 */
void Scene::leftButtonMenu( int command )
{
    currentFillColor = command;
}


/**
 * Pass control to the class's rightButtonMenu method.
 *
 * @param command The command to be processed.
 */
void Scene::processRightButtonMenu_cb( int command )
{
    getInstance()->rightButtonMenu( command );
}

/**
 * Processes a right button mouse command.
 *
 * @param command The command to be processed.
 */
void Scene::rightButtonMenu( int command )
{
    currentShape = command;
    ControlPanel::getInstance()->setShapeRadio( currentShape );
}

/**
 * Pass control to the class's redraw method.
 */
void Scene::redraw_cb()
{
    getInstance()->redraw();
}

/**
 * Redraws the scene.
 */
void Scene::redraw( void )
{
    glClear( GL_COLOR_BUFFER_BIT );     // clear the screen 

    // create a vector iterator to access the Shapes in the "shapes" vector
    std::vector<Shape*>::iterator it;
    for ( it = shapes.begin(); it < shapes.end(); it++ )
       (*it)->redraw();
       
    glFlush();                          // send all output to display
}

//----------------- GlutMouseListener methods ------------------------
/**
 * Start a rubberBand when left button is pressed.
 *
 * @param button The id for the button source.
 * @param x The x-position of where the left button was pressed.
 * @param y The y-position of where the left button was pressed.
 */
void Scene::mousePressed( int button, int x, int y )
{
    if ( button == GlutMouseSource::MOUSE_BUTTON_MIDDLE )
    {
        rubberbanding = GL_TRUE;
        rbStartX = x;
        rbStartY = y;

        switch ( currentShape )
        {
            case SHAPE_TRIANGLE:
                shape = new Triangle();
                break;
            case SHAPE_RECTANGLE:
                shape = new Square();
                break;
            case SHAPE_PENTAGON:
                shape = new Pentagon();
                break;
            case SHAPE_HEXAGON:
                shape = new Hexagon();
                break;
        }
    }
}

//---------------------------------------------------------------------
/**
 * Finishes a rubberBand when left button is released.
 *
 * @param button The id for the button source.
 * @param x The x-position of where the left button was released.
 * @param y The y-position of where the left button was released.
 */
void Scene::mouseReleased( int button, int x, int y )
{
	if ( mouseEnabled && ( currentDrawBoundary || currentDrawFill ) ) {
        if ( button == GlutMouseSource::MOUSE_BUTTON_MIDDLE ) {
            rubberbanding = GL_FALSE;

            int viewport[4];
            glGetIntegerv( GL_VIEWPORT, viewport );

            float xLoc = x, yLoc = y;
            float width, height;

            if (rbStartX < x) {
                xLoc = rbStartX;
                width = x - rbStartX;
            } else {
                width = rbStartX - x;
            }

            if (rbStartY > y) {
                yLoc = rbStartY;
                height = rbStartY - y;
            } else {
                height = y - rbStartY;
            }

            addShape(shape);
            shape->setId(id);
            shape->setLocation(xLoc, viewport[3] - yLoc);
            shape->setColor( colorR[ currentFillColor ],
                             colorG[ currentFillColor ],
                             colorB[ currentFillColor ] );
            shape->setBorderColor( colorR[ currentBoundaryColor ],
                                   colorG[ currentBoundaryColor ],
                                   colorB[ currentBoundaryColor ] );
            shape->setDrawFill( currentDrawFill );
            shape->setSize( width / shape->getRangeX(),
                            height / shape->getRangeY() );

            if ( !currentDrawBoundary ) {
                shape->setBorderWidth(0.0);
            }

            redraw();

            ControlPanel::getInstance()->setMovableShape(shape);
            ControlPanel::getInstance()->setXScrollValue( xLoc );
            ControlPanel::getInstance()->setYScrollValue( viewport[3] - yLoc );

            std::cout << "Added shape with ID " << id << "\n";

            id++;
        }
	}
}

//---------------------------------------------------------------------
/**
 * Continue rubberBand.
 *
 * @param x The x-position of where the mouse is.
 * @param y The y-position of where the mouse is.
 */
void Scene::mouseMoved( int x, int y )
{
    int viewport[4];
    glGetIntegerv( GL_VIEWPORT, viewport );

    int ySize = viewport[3];

    if ( rubberbanding )
    {
        redraw();
        glColor3f( 0.8f, 0.5f, 0.6f );
        glBegin( GL_LINE_STRIP );
            glVertex2f( rbStartX, ySize - rbStartY );
            glVertex2f( x, ySize - rbStartY );
            glVertex2f( x, ySize - y );
            glVertex2f( rbStartX, ySize - y );
            glVertex2f( rbStartX, ySize - rbStartY );
        glEnd();
        glFlush();
    }
}
