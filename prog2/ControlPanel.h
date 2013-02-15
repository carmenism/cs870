/**
 * ControlPanel.h - A class to set up user controls and handle changes in them.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on ControlPanel.cpp of demo3.
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/07/2012: Modified from original to include more controls for 3D objects.
 */
#ifndef CONTROLPANEL_H_
#define CONTROLPANEL_H_

#include "Object3D.h"
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
    void setMovableObject3D( Object3D* s );

    void updateProjection();
protected: 
    //----Singleton Pattern parts----
    ControlPanel();
    static ControlPanel *instance;

    //----Callback for when controls change, enum to tell them apart.---
    // Callback to register w/ GLUI, and call object-level method
    static void controlChanged_cb( int control_enum_value );
    enum { LOOK_AT,
           ORTHO,
           PERSPECTIVE,
           PROJ,
           ROTATE,
           TRANSLATE,
           ROTATE_LIGHT,
           ROTATE_EYE
         };

    enum { PROJ_PERSPECTIVE,
           PROJ_ORTHO
         };
    // Object-level method for handling changes in controls.
    void controlChanged( int control_enum_value );

    //----Member variables----
    GLUI *glui; //GLUI window
    int lighting;
    float scrollValue;
    float scrollValue2;

    GLUI_Panel *lookAtPanel, *eyePanel, *cenPanel, *upPanel;
    GLUI_Panel *projPanel, *orthPanel, *perspPanel;
    GLUI_Panel *objPanel, *lightPanel, *eyeRotatePanel;

    GLUI_RadioGroup *projRadio;

    GLUI_Spinner *eyeXSpin, *eyeYSpin, *eyeZSpin;
    GLUI_Spinner *cenXSpin, *cenYSpin, *cenZSpin;
    GLUI_Spinner *upXSpin, *upYSpin, *upZSpin;

    GLUI_Spinner *orthLSpin, *orthRSpin, *orthBotSpin, *orthTopSpin;
    GLUI_Spinner *orthNrSpin, *orthFrSpin;

    GLUI_Spinner *perspFovySpin, *perspAspSpin, *perspZNrSpin, *perspZFrSpin;

    float eyeX, eyeY, eyeZ; // lookAt eye values
    float cenX, cenY, cenZ; // lookAt center values
    float upX, upY, upZ;    // lookAt up values

    float perspFovy, perspAsp, perspZNr, perspZFr; // perspective values

    float orthL, orthR, orthBot, orthTop, orthNr, orthFr; // ortho values

    int proj; // value for projection radio button

    float rotate[16], lightsRotate[16], eyeRotate[16];
    float posX, posY, posZ;

    Object3D* movableShape;
};

#endif /*CONTROLPANEL_H_*/
