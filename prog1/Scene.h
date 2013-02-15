/**
 * Scene.h - A class to keep track of a scene of objects, and mouse interactions
 * with the screen.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on Scene.h from Professor Dan Bergeron's demoGlui program.
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  09/19/2012: Modified the version found in the demo.
 */
#ifndef SCENE_H_
#define SCENE_H_

#include <vector>
#include <string>
#include <GL/glut.h>
#include "GlutMouseListener.h"

class Shape;

class Scene : public GlutMouseListener
{
public:
    //----Singleton Pattern getInstance method----
    static Scene *getInstance();

    //----Methods----
    void addShape( Shape *newShape );
    void removeShape( int idToRemove );
    void clear();

    void setShape( int shapeNumber );
    void setFillColor( int colorNumber );
    void setBoundaryColor( int colorNumber );
    void setDrawBoundary( bool db );
    void setDrawFill( bool df );
    void setMouseEnabled( bool mouse );

    enum { COLOR_RED,
		   COLOR_ORANGE,
		   COLOR_YELLOW,
		   COLOR_GREEN,
		   COLOR_BLUE,
		   COLOR_PURPLE,
		   COLOR_BLACK
    };

protected: 
    //----Singleton Pattern parts----
    Scene();
    static Scene *instance;

    //----MouseListener response methods----
    virtual void mousePressed( int button, int x, int y );
    virtual void mouseReleased( int button, int x, int y );
    virtual void mouseMoved( int x, int y );

    //----Callback for redraw and mouse-button menus---
    //Callbacks to register w/ GLUT, and call object-level method
    static void redraw_cb();
    static void processLeftButtonMenu_cb( int command );
    static void processRightButtonMenu_cb( int command );

    enum { SHAPE_TRIANGLE,
		   SHAPE_RECTANGLE,
		   SHAPE_PENTAGON,
		   SHAPE_HEXAGON
    };

    //object-level method for handling callbacks
    void redraw( void );
    void leftButtonMenu( int command );
    void rightButtonMenu( int command );

    //----Member variables----
    std::vector<Shape*> shapes;
    Shape* shape;                   // the shape we are currently drawing
    bool mouseEnabled;              // is the mouse enabled for drawing?
    bool rubberbanding;             // are we currently rubberbanding?
    bool currentDrawBoundary;       // do we draw boundaries?
    bool currentDrawFill;           // do we draw fill?
    int rbStartX, rbStartY;         // where is the rubberband starting?
    int currentShape;               // what shape are we going to draw next?
    int currentFillColor;           // what color is the shape's fill?
    int currentBoundaryColor;       // what color is the shape's boundary?
    int nColors;                    // total number of colors available
    float colorR[ 7 ];              // R-values to our colors
    float colorG[ 7 ];              // G-values to our colors
    float colorB[ 7 ];              // B-values to our colors
};

#endif /*SCENE_H_*/
