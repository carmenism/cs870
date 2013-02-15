/**
 * ControlPanel.h - A class to set up user controls and handle changes in them.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on ControlPanel.cpp of demo3.
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/27/2012: Modified to feature more lighting options, textures, and
 *              materials.
 *  10/07/2012: Modified from original to include more controls for 3D objects.
 */
#ifndef CONTROLPANEL_H_
#define CONTROLPANEL_H_

#include "Object3D.h"
#include <string>
#include <GL/glut.h>
#include <GL/glui.h> // or <glui.h>

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

class ControlPanel
{
public:
    //----Singleton Pattern getInstance method----
    static ControlPanel *getInstance();

    //----Methods----
    void initialize(std::string name, int windowID = -1);

    void updateProjection();

    void changeObject();
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
           SCENE_ROTATE,
           SCENE_TRANSLATE,
           SCENE_SCALE,
           LIGHTING,
           DIR_LIGHT_ROTATE,
           PT_LIGHT_TRANSLATE,
           LIGHT_COLOR,
           LIGHT_TYPE,
           OBJECT
         };

    enum { PROJ_PERSPECTIVE,
           PROJ_ORTHO
         };
    enum { LIGHT_POINT,
           LIGHT_DIRECTIONAL
         };
    enum { LIGHT_TYPE_DIFFUSE,
           LIGHT_TYPE_AMBIENT,
           LIGHT_TYPE_SPECULAR
         };
    enum {
        OBJ_CAMERA,
        OBJ_CAMERA_BODY,
        OBJ_CAMERA_LENS,
        OBJ_FILM_CANISTER,
        OBJ_BASEBALL,
        OBJ_PYRAMID,
        OBJ_FRUSTUM,
        OBJ_CUBE,
        OBJ_SPHERE,
        OBJ_CYLINDER,
        OBJ_TETREHEDRON,
        OBJ_BUBBLES,
        OBJ_PIKACHU_PIC,
        OBJ_PIKACHU_WRAP
    };
    // Object-level method for handling changes in controls.
    void controlChanged( int control_enum_value );

    //----Member variables----
    GLUI *glui; //GLUI window

    GLUI_Panel *objectPanel;
    GLUI_Panel *lookAtPanel, *eyePanel, *cenPanel, *upPanel;
    GLUI_Panel *projPanel, *orthPanel, *perspPanel;
    GLUI_Panel *objPanel, *eyeRotatePanel;
    GLUI_Panel *sceneScalePanel, *sceneTransPanel, *lightPropPanel;
    GLUI_Panel *lightPanel, *dLightPanel, *pLightPanel;
    GLUI_Panel *ltColorRPanel, *ltColorGPanel, *ltColorBPanel;

    GLUI_RadioGroup *objectRadio, *projRadio, *lightRadio, *lightTypeRadio;

    GLUI_Rotation *lightRotation;

    GLUI_Spinner *eyeXSpin, *eyeYSpin, *eyeZSpin;
    GLUI_Spinner *cenXSpin, *cenYSpin, *cenZSpin;
    GLUI_Spinner *upXSpin, *upYSpin, *upZSpin;

    GLUI_Spinner *orthLSpin, *orthRSpin, *orthBotSpin, *orthTopSpin;
    GLUI_Spinner *orthNrSpin, *orthFrSpin;

    GLUI_Spinner *perspFovySpin, *perspAspSpin, *perspZNrSpin, *perspZFrSpin;

    GLUI_Spinner *xScaleSpin, *yScaleSpin, *zScaleSpin;

    GLUI_Scrollbar *ltColorR, *ltColorG, *ltColorB;

    GLUI_Translation *ptLtTransXY, *ptLtTransZ;

    float eyeX, eyeY, eyeZ; // lookAt eye values
    float cenX, cenY, cenZ; // lookAt center values
    float upX, upY, upZ;    // lookAt up values

    float perspFovy, perspAsp, perspZNr, perspZFr; // perspective values

    float orthL, orthR, orthBot, orthTop, orthNr, orthFr; // ortho values

    int proj; // value for projection radio button
    int lighting, lightType;

    float lightColor[4];
    float pointLightDiffuseColor[4], directionalLightDiffuseColor[4];
    float pointLightAmbientColor[4], directionalLightAmbientColor[4];
    float pointLightSpecularColor[4], directionalLightSpecularColor[4];

    float sceneRotate[16], sceneTranslate[3], sceneScale[3];
    float pointLightPosition[4];
    float directionalLightRotate[16], directionalLightPosition[16];

    int directionalLightType;
    int pointLightType;
    int objectType;

    int pLight, dLight;

    Object3D* movableShape;
};

#endif /*CONTROLPANEL_H_*/
