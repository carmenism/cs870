/**
 * ControlPanel.cpp - A class to set up user controls and handle changes in
 * them.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on ControlPanel.cpp from Professor Dan Bergeron's demoGlui
 *         program.
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  09/19/2012: Modified the version found in the demo.
 */
#include "ControlPanel.h"
#include "Triangle.h"
#include "Scene.h"

//------------------ Class variables ---------------------------------
ControlPanel *ControlPanel::instance = NULL;

//------------------ Constructors ------------------------------------
/** Initialize values
 */
ControlPanel::ControlPanel()
{
    //initialize values
	deleteShapeValue = 0;
    shapeRadioGroupValue = 0.0;
    mouseBoxValue = 1;
    fillBoxValue = 1.0;
    fillListValue = 0;
    boundaryBoxValue = 1.0;
    boundaryListValue = 0;
    scrollValue = 0.0;
    scrollValue2 = 0.0;
    glui = 0;
    movableShape = NULL;
	shapeRadioGroup = NULL;
	fillColorListBox = NULL;
	boundaryColorListBox = NULL;
}

//--------------------------------------------------------------------
/** Create the GLUI window, and add controls.
 */
void ControlPanel::initialize( std::string name, int windowID )
{
    GLUI_Panel *newPanel;

    // Create interface
    glui = GLUI_Master.create_glui( name.c_str() );

    // Shape radio group selection
    shapeRadioGroup = glui->add_radiogroup_to_panel( glui->add_panel( "Shape" ),
                                                   &shapeRadioGroupValue,
                                                   SHAPE_RADIO,
                                                   controlChanged_cb );
    glui->add_radiobutton_to_group(shapeRadioGroup, "Triangle");
    glui->add_radiobutton_to_group(shapeRadioGroup, "Rectangle");
    glui->add_radiobutton_to_group(shapeRadioGroup, "Pentagon");
    glui->add_radiobutton_to_group(shapeRadioGroup, "Hexagon");

    // Fill panel
    newPanel = glui->add_panel("Fill", GLUI_PANEL_EMBOSSED);

    // Fill checkbox
    glui->add_checkbox_to_panel( newPanel,
                                 "Draw fill", &fillBoxValue,
                                 FILL_CHECKBOX, controlChanged_cb );

    // Fill list box
    fillColorListBox = glui->add_listbox_to_panel( newPanel,
                                                   "Color",
                                                   &fillListValue,
                                                   FILL_COLOR_LIST,
                                                   controlChanged_cb );
    addColorsToListbox(fillColorListBox);

    // Boundary panel
    newPanel = glui->add_panel("Boundary", GLUI_PANEL_EMBOSSED);

    // Boundary checkbox
    glui->add_checkbox_to_panel( newPanel,
                                 "Draw boundary", &boundaryBoxValue,
                                 BOUNDARY_CHECKBOX, controlChanged_cb );

    // Boundary list box
    boundaryColorListBox = glui->add_listbox_to_panel( newPanel,
                                                       "Color",
                                                       &boundaryListValue,
                                                       BOUNDARY_COLOR_LIST,
                                                       controlChanged_cb );
    addColorsToListbox(boundaryColorListBox);

    glui->add_column(true);

    int viewport[4];
    glGetIntegerv( GL_VIEWPORT, viewport );

    // X scroll bar
    xScroll = new GLUI_Scrollbar( glui->add_panel( "X location" ),
                                    "leftScroll", GLUI_SCROLL_HORIZONTAL,
                                    &scrollValue, X_ORIGIN,
                                    controlChanged_cb );
    xScroll->set_float_limits( viewport[0], viewport[2] );

    // Y scroll bar
    yScroll = new GLUI_Scrollbar( glui->add_panel( "Y location" ),
                                    "RightScroll", GLUI_SCROLL_HORIZONTAL,
                                    &scrollValue2, Y_ORIGIN,
                                    controlChanged_cb );
    yScroll->set_float_limits( viewport[1], viewport[3] );

    glui->add_edittext( "Delete Shape", GLUI_EDITTEXT_INT,
                        &deleteShapeValue, DELETE_SHAPE,
                        controlChanged_cb );

    // Mouse checkbox
    glui->add_checkbox( "Enable mouse", &mouseBoxValue,
                                 ENABLE_MOUSE, controlChanged_cb );
    // Erase button
    glui->add_button( "Erase All",
                      ERASE_ALL_BUTTON, controlChanged_cb );

    // Quit button
    glui->add_button( "Quit Test",
                      QUIT_BUTTON, controlChanged_cb );

    // Tell GLUI window which other window to recognize as the main gfx window
    if ( windowID >= 0 )
        glui->set_main_gfx_window( windowID );
}

//------------------ public class methods --------------------------

/**
 * Return the singleton instance.  If it does not exist, create one.
 */
ControlPanel *ControlPanel::getInstance()
{
    if ( !instance )
        instance = new ControlPanel();
    return instance;
}

/**
 * Set the object to be moved.
 *
 * @param s The new Shape object to be movable.
 */
void ControlPanel::setMovableShape( Shape* s )
{
    if ( s != NULL ) {
       movableShape = s;
    }
}

/**
 * Sets the shape radio group's value to the desired shape type.
 *
 * @param shapeValue The enum corresponding to a shape type.
 */
void ControlPanel::setShapeRadio( int shapeValue )
{
    if ( shapeRadioGroup != NULL ) {
        shapeRadioGroup->set_int_val( shapeValue );
    }
}

/**
 * Sets the X scroll bar's value to the x-position value.
 *
 * @param x The value to set the scroll bar to.
 */
void ControlPanel::setXScrollValue( float x )
{
    if ( xScroll != NULL ) {
    	xScroll->set_float_val( x );
    }
}

/**
 * Sets the Y scroll bar's value to the y-position value.
 *
 * @param y The value to set the scroll bar to.
 */
void ControlPanel::setYScrollValue( float y )
{
    if ( yScroll != NULL ) {
    	yScroll->set_float_val( y );
    }
}

/**
 * Pass control to the class's controlChanged method.
 *
 * @param control_enum_value The value of the control that was changed.
 */
void ControlPanel::controlChanged_cb( int control_enum_value )
{
    getInstance()->controlChanged( control_enum_value );
}

//-------------------- protected methods -----------------------------

/**
 * Determines what action should be taken based on the change that occured in
 * the control panel.
 *
 * @param control_enum_value The value of the control that was changed.
 */
void ControlPanel::controlChanged( int control_enum_value )
{
    float x = 0;
    float y = 0;
    switch ( control_enum_value )
    {
        case BOUNDARY_CHECKBOX:
            Scene::getInstance()->setDrawBoundary( boundaryBoxValue == 1 );
            break;
        case FILL_CHECKBOX:
            Scene::getInstance()->setDrawFill( fillBoxValue == 1 );
            break;
        case QUIT_BUTTON:
            std::cerr << "Exiting..." << std::endl;
            exit( 0 );
            break;
        case X_ORIGIN:
            x = scrollValue;
            if ( movableShape != NULL )
                movableShape->setLocation( x, movableShape->getY() );
            break;
        case Y_ORIGIN:
            y = scrollValue2;
            if ( movableShape != NULL )
                movableShape->setLocation( movableShape->getX(), y );
            break;
        case ERASE_ALL_BUTTON:
            Scene::getInstance()->clear();
            break;
        case SHAPE_RADIO:
            Scene::getInstance()->setShape( shapeRadioGroupValue );
            break;
        case FILL_COLOR_LIST:
            Scene::getInstance()->setFillColor( fillListValue );
            break;
        case BOUNDARY_COLOR_LIST:
            Scene::getInstance()->setBoundaryColor( boundaryListValue );
            break;
        case ENABLE_MOUSE:
        	Scene::getInstance()->setMouseEnabled( mouseBoxValue == 1 );
            break;
        case DELETE_SHAPE:
        	Scene::getInstance()->removeShape( deleteShapeValue );
    }
}

/**
 * Adds a color items to a GLUI listbox object.
 *
 * @param *lb A GLUI_Listbox object.
 */
void ControlPanel::addColorsToListbox( GLUI_Listbox *lb ) {
    lb->add_item(Scene::COLOR_RED, "Red");
    lb->add_item(Scene::COLOR_ORANGE, "Orange");
    lb->add_item(Scene::COLOR_YELLOW, "Yellow");
    lb->add_item(Scene::COLOR_GREEN, "Green");
    lb->add_item(Scene::COLOR_BLUE, "Blue");
    lb->add_item(Scene::COLOR_PURPLE, "Purple");
    lb->add_item(Scene::COLOR_BLACK, "Black");
}
