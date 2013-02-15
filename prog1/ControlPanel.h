/**
 * ControlPanel.h - A class to set up user controls and handle changes in them.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on ControlPanel.h from Professor Dan Bergeron's demoGlui
 *         program.
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  09/19/2012: Modified the version found in the demo.
 */
#ifndef CONTROLPANEL_H_
#define CONTROLPANEL_H_

#include "Shape.h"
#include <string>
#include <GL/glut.h>
#include <GL/glui.h> // or <glui.h>

class ControlPanel
{
public:
    //----Singleton Pattern getInstance method----
    static ControlPanel *getInstance();

    //----Methods----
    void initialize(std::string name, int windowID = -1);
    void setMovableShape( Shape* s );
    void setShapeRadio( int shapeValue );
    void setXScrollValue( float x );
    void setYScrollValue( float y );

protected: 
    //----Singleton Pattern parts----
    ControlPanel();
    static ControlPanel *instance;

    //----Callback for when controls change, enum to tell them apart.---
    //Callback to register w/ GLUI, and call object-level method
    static void controlChanged_cb( int control_enum_value );
    enum { BOUNDARY_CHECKBOX,
           FILL_CHECKBOX,
           QUIT_BUTTON,
           X_ORIGIN,
           Y_ORIGIN,
           SHAPE_RADIO,
           ERASE_ALL_BUTTON,
           FILL_COLOR_LIST,
           BOUNDARY_COLOR_LIST,
           ENABLE_MOUSE,
           DELETE_SHAPE
         };
    //object-level method for handling changes in controls
    void controlChanged( int control_enum_value );
    void addColorsToListbox( GLUI_Listbox *lb );

    //----Member variables----
    GLUI *glui; //GLUI window
	GLUI_RadioGroup *shapeRadioGroup;
	GLUI_Listbox *fillColorListBox;
	GLUI_Listbox *boundaryColorListBox;
	GLUI_Scrollbar *xScroll;
	GLUI_Scrollbar *yScroll;
    int boundaryBoxValue;
    int fillBoxValue;
    int mouseBoxValue;
    float scrollValue;
    float scrollValue2;
    int shapeRadioGroupValue;
    int fillListValue;
    int boundaryListValue;
    int deleteShapeValue;

    Shape* movableShape;
};

#endif /*CONTROLPANEL_H_*/
