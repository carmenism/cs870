/**
 * ControlPanel.cpp - A class to set up user controls and handle changes in
 * them.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on ControlPanel.cpp of demo3.
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/07/2012: Modified from original to include more controls for 3D objects.
 */
#include <iostream>
#include "ControlPanel.h"
#include "Scene.h"

//------------------ Class variables ---------------------------------
ControlPanel *ControlPanel::instance = NULL;
float objectRotate[16] = { 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 };
//------------------ Constructors ------------------------------------
/**
 * Initialized values.
 */
ControlPanel::ControlPanel()
{
    // Initialize values
    scrollValue = 0.0;
    scrollValue2 = 0.0;
    lighting = 0;
    glui = 0;
    movableShape = NULL;

    eyeX = 50.0;
    eyeY = 50.0;
    eyeZ = 150.0;

    cenX = 0.0;
    cenY = 0.0;
    cenZ = 0.0;

    upX = 0.0;
    upY = 1.0;
    upZ = 0.0;

    perspFovy = 45.0;
    perspAsp = 640.0 / 480.0;
    perspZNr = 1.0;
    perspZFr = 500.0;

    orthL = -110.0;
    orthR = 110.0;
    orthBot = -85.0;
    orthTop = 85.0;
    orthNr = -100;
    orthFr = 100.0;

    float def[] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };

    for (int i = 0; i < 16; i++) {
        rotate[i] = def[i];
        lightsRotate[i] = def[i];
        eyeRotate[i] = def[i];
    }

    proj = PROJ_PERSPECTIVE;

    posX = 0;
    posY = 0;
    posZ = 0;
}

//--------------------------------------------------------------------

/**
 * Create the GLUI window, and add controls.
 *
 * @param name The name of the control panel.
 * @param windowID The id of the window that the control panel will be placed
 *  in.
 */
void ControlPanel::initialize( std::string name, int windowID )
{
    //Create interface
    glui = GLUI_Master.create_glui( name.c_str() );

    // LookAt controls.
    lookAtPanel = glui->add_panel("Look At");

    // LookAt eye controls.
    eyePanel = glui->add_panel_to_panel(lookAtPanel, "Eye");
    eyeXSpin = glui->add_spinner_to_panel( eyePanel, "X", GLUI_SPINNER_FLOAT,
                                           &eyeX, LOOK_AT, controlChanged_cb );
    eyeYSpin = glui->add_spinner_to_panel( eyePanel, "Y", GLUI_SPINNER_FLOAT,
                                           &eyeY, LOOK_AT, controlChanged_cb );
    eyeZSpin = glui->add_spinner_to_panel( eyePanel, "Z", GLUI_SPINNER_FLOAT,
                                           &eyeZ, LOOK_AT, controlChanged_cb );

    // LookAt center controls.
    cenPanel = glui->add_panel_to_panel(lookAtPanel, "Center");
    cenXSpin = glui->add_spinner_to_panel( cenPanel, "X", GLUI_SPINNER_FLOAT,
                                           &cenX, LOOK_AT, controlChanged_cb );
    cenYSpin = glui->add_spinner_to_panel( cenPanel, "Y", GLUI_SPINNER_FLOAT,
                                           &cenY, LOOK_AT, controlChanged_cb );
    cenZSpin = glui->add_spinner_to_panel( cenPanel, "Z", GLUI_SPINNER_FLOAT,
                                           &cenZ, LOOK_AT, controlChanged_cb );

    // LookAt up controls.
    upPanel = glui->add_panel_to_panel(lookAtPanel, "Look Up");
    upXSpin = glui->add_spinner_to_panel( upPanel, "X", GLUI_SPINNER_FLOAT,
                                           &upX, LOOK_AT, controlChanged_cb );
    upYSpin = glui->add_spinner_to_panel( upPanel, "Y", GLUI_SPINNER_FLOAT,
                                           &upY, LOOK_AT, controlChanged_cb );
    upZSpin = glui->add_spinner_to_panel( upPanel, "Z", GLUI_SPINNER_FLOAT,
                                           &upZ, LOOK_AT, controlChanged_cb );

    glui->add_column(true);

    // Projection controls.
    projPanel = glui->add_panel("Projection");

    // Choose between orth and perspective.
    projRadio = glui->add_radiogroup_to_panel(projPanel, &proj, PROJ,
                                           controlChanged_cb);
    glui->add_radiobutton_to_group(projRadio, "Perspective");
    glui->add_radiobutton_to_group(projRadio, "Parallel Perspective");

    // Persepctive controls.
    perspPanel = glui->add_panel_to_panel(projPanel, "Perspective");
    perspFovySpin = glui->add_spinner_to_panel( perspPanel, "Angle",
                                           GLUI_SPINNER_FLOAT, &perspFovy,
                                           PERSPECTIVE, controlChanged_cb );
    perspAspSpin = glui->add_spinner_to_panel( perspPanel, "Aspect",
                                           GLUI_SPINNER_FLOAT, &perspAsp,
                                           PERSPECTIVE, controlChanged_cb );
    perspZNrSpin = glui->add_spinner_to_panel( perspPanel, "Near",
                                           GLUI_SPINNER_FLOAT, &perspZNr,
                                           PERSPECTIVE, controlChanged_cb );
    perspZFrSpin = glui->add_spinner_to_panel( perspPanel, "Far",
                                           GLUI_SPINNER_FLOAT, &perspZFr,
                                           PERSPECTIVE, controlChanged_cb );

    // Ortho controls.
    orthPanel = glui->add_panel_to_panel(projPanel, "Parallel Perspective");
    orthLSpin = glui->add_spinner_to_panel( orthPanel, "Left",
                                           GLUI_SPINNER_FLOAT, &orthL,
                                           ORTHO, controlChanged_cb );
    orthRSpin = glui->add_spinner_to_panel( orthPanel, "Right",
                                           GLUI_SPINNER_FLOAT, &orthR,
                                           ORTHO, controlChanged_cb );
    orthBotSpin = glui->add_spinner_to_panel( orthPanel, "Bottom",
                                           GLUI_SPINNER_FLOAT, &orthBot,
                                           ORTHO, controlChanged_cb );
    orthTopSpin = glui->add_spinner_to_panel( orthPanel, "Top",
                                           GLUI_SPINNER_FLOAT, &orthTop,
                                           ORTHO, controlChanged_cb );
    orthNrSpin = glui->add_spinner_to_panel( orthPanel, "Near",
                                           GLUI_SPINNER_FLOAT, &orthNr,
                                           ORTHO, controlChanged_cb );
    orthFrSpin = glui->add_spinner_to_panel( orthPanel, "Far",
                                           GLUI_SPINNER_FLOAT, &orthFr,
                                           ORTHO, controlChanged_cb );
    glui->add_column(true);

    objPanel = glui->add_panel("Control Object");

    GLUI_Rotation *objectRotation = glui->add_rotation_to_panel( objPanel,
                                           "Rotation", rotate, ROTATE,
                                           controlChanged_cb );

    objectRotation->set_spin( 1.0 );

    GLUI_Translation *transX = glui->add_translation_to_panel(objPanel, "X",
                                           GLUI_TRANSLATION_X, &posX,
                                           TRANSLATE, controlChanged_cb);
    transX->set_speed( 1 );

    GLUI_Translation *transY = glui->add_translation_to_panel(objPanel, "Y",
                                          GLUI_TRANSLATION_Y, &posY,
                                          TRANSLATE, controlChanged_cb);
    transY->set_speed( 1 );

    GLUI_Translation *transZ =	glui->add_translation_to_panel(objPanel, "Z",
                                          GLUI_TRANSLATION_Z, &posZ,
                                          TRANSLATE, controlChanged_cb);
    transZ->set_speed( 1 );

    glui->add_column(true);

    lightPanel = glui->add_panel("Control Light");

    GLUI_Rotation *lightRotation = glui->add_rotation_to_panel( lightPanel,
                                           "Rotation", lightsRotate,
                                           ROTATE_LIGHT, controlChanged_cb );
    lightRotation->set_spin( 1.0 );

    eyeRotatePanel = glui->add_panel("Control Eye");

    GLUI_Rotation *eyeRotation = glui->add_rotation_to_panel( eyeRotatePanel,
                                               "Rotation", eyeRotate,
                                               ROTATE_EYE, controlChanged_cb );
    eyeRotation->set_spin( 1.0 );

    // Tell GLUI window which other window to recognize as the main gfx window.
    if ( windowID >= 0 ) {
        glui->set_main_gfx_window( windowID );
    }
}

//------------------ public class methods --------------------------

/**
 * Return the singleton instance.  If it does not exist, create one.
 *
 * @return The singleton instance of the control panel.
 */
ControlPanel *ControlPanel::getInstance() {
    if ( !instance ) {
        instance = new ControlPanel();
    }

    return instance;
}

/**
 * Set the object to be moved.
 *
 * @param o The new object to be movable.
 */
void ControlPanel::setMovableObject3D( Object3D* o ) {
    if ( o != NULL ) {
        movableShape = o;
    }
}

/**
 * Pass control to the class's controlChanged method.
 *
 * @param control_enum_value The value of the control that was changed.
 */
void ControlPanel::controlChanged_cb( int control_enum_value ) {
    getInstance()->controlChanged( control_enum_value );
}

/**
 * Updates the projection according to the new values found in the control
 * panel.
 */
void ControlPanel::updateProjection() {
    float lightPosition[] = { 100.0, 100.0, 100.0, 0.0 };

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMultMatrixf(lightsRotate);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (proj == PROJ_ORTHO) {
        glOrtho(orthL, orthR, orthBot, orthTop, orthNr, orthFr);

        orthLSpin->enable();
        orthRSpin->enable();
        orthBotSpin->enable();
        orthTopSpin->enable();
        orthNrSpin->enable();
        orthFrSpin->enable();

        perspFovySpin->disable();
        perspAspSpin->disable();
        perspZNrSpin->disable();
        perspZFrSpin->disable();

        eyeXSpin->disable();
        eyeYSpin->disable();
        eyeZSpin->disable();
        cenXSpin->disable();
        cenYSpin->disable();
        cenZSpin->disable();
        upXSpin->disable();
        upYSpin->disable();
        upZSpin->disable();
    } else { // perspective
        gluPerspective(perspFovy, perspAsp, perspZNr, perspZFr);

        //glMultMatrixf(eyeRotate);
        gluLookAt(eyeX, eyeY, eyeZ, cenX, cenY, cenZ, upX, upY, upZ);

        perspFovySpin->enable();
        perspAspSpin->enable();
        perspZNrSpin->enable();
        perspZFrSpin->enable();

        orthLSpin->disable();
        orthRSpin->disable();
        orthBotSpin->disable();
        orthTopSpin->disable();
        orthNrSpin->disable();
        orthFrSpin->disable();

        eyeXSpin->enable();
        eyeYSpin->enable();
        eyeZSpin->enable();
        cenXSpin->enable();
        cenYSpin->enable();
        cenZSpin->enable();
        upXSpin->enable();
        upYSpin->enable();
        upZSpin->enable();
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

//-------------------- protected methods -----------------------------

/**
 * Determines what action should be taken based on the change that was made to
 * the control panel's values.
 *
 * @param control_enum_value The value of the control that was changed.
 */
void ControlPanel::controlChanged( int control_enum_value ) {
    switch ( control_enum_value ) {
        case LOOK_AT:
            break;
        case PROJ:
            break;
        case ORTHO:
            break;
        case PERSPECTIVE:
            break;
        case ROTATE:
        	movableShape->setRotation(rotate);
        	break;
        case TRANSLATE:
        	movableShape->setLocation(posX,
                                      posY,
                                      -posZ);
            break;
        case ROTATE_LIGHT:
        	break;
    }

    Scene::getInstance()->redraw_cb();
}
