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
 *  10/27/2012: Modified to feature more lighting options, textures, and
 *              materials.
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
    lighting = 0;
    glui = 0;
    movableShape = NULL;

    eyeX = 3.0;
    eyeY = 3.0;
    eyeZ = 4.0;

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

    orthL = -3.0;
    orthR = 3.0;
    orthBot = -2.25;
    orthTop = 2.25;
    orthNr = -5.0;
    orthFr = 5.0;

    pLight = 1;
    dLight = 1;

    float defRotate[] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
    float defTranslate[] = { 0, 0, 0 };
    float defScale[] = { 1, 1, 1 };

    float defDirectionalLightPosition[] = { 9.0, 9.0, -9.0, 0.0 };
    float defPointLightPosition[] = { -4.3125, 2.4375, 10.0, 1.0 };

    float defLightDiffuseColor[] = { 1.0, 1.0, 1.0, 1.0 };
    float defLightAmbientColor[] = { 0.0, 0.0, 0.0, 1.0 };
    float defLightSpecularColor[] = { 1.0, 1.0, 1.0, 1.0 };
    float defRedColor[] = { 1.0, 0.75, 0.75, 1.0 };
    float defAmbientRedColor[] = { 0.15, 0.01, 0.01, 1.0 };

    for (int i = 0; i < 16; i++) {
        sceneRotate[i]            = defRotate[i];
        directionalLightRotate[i] = defRotate[i];
    }

    for (int i = 0; i < 3; i++) {
        sceneTranslate[i] = defTranslate[i];
        sceneScale[i] = defScale[i];
    }

    for (int i = 0; i < 4; i++) {
        pointLightPosition[i] = defPointLightPosition[i];
        directionalLightPosition[i] = defDirectionalLightPosition[i];

        lightColor[i] = defLightDiffuseColor[i];

        pointLightDiffuseColor[i]       = defLightDiffuseColor[i];
        directionalLightDiffuseColor[i] = defRedColor[i];

        pointLightAmbientColor[i]       = defLightAmbientColor[i];
        directionalLightAmbientColor[i] = defAmbientRedColor[i];

        pointLightSpecularColor[i]       = defLightSpecularColor[i];
        directionalLightSpecularColor[i] = defRedColor[i];
    }

    proj = PROJ_PERSPECTIVE;

    directionalLightType = LIGHT_TYPE_DIFFUSE;
    pointLightType = LIGHT_TYPE_DIFFUSE;

    lightType = pointLightType;
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

    objectPanel = glui->add_panel("Object in Scene");

    objectRadio = glui->add_radiogroup_to_panel(objectPanel, &objectType,
                                                OBJECT,
                                                controlChanged_cb);
    glui->add_radiobutton_to_group(objectRadio, "Camera");
    glui->add_radiobutton_to_group(objectRadio, "Camera Body");
    glui->add_radiobutton_to_group(objectRadio, "Camera Lens");
    glui->add_radiobutton_to_group(objectRadio, "Film Canister");
    glui->add_radiobutton_to_group(objectRadio, "Baseball");
    glui->add_radiobutton_to_group(objectRadio, "Pyramid");
    glui->add_radiobutton_to_group(objectRadio, "Frustum");
    glui->add_radiobutton_to_group(objectRadio, "Cube");
    glui->add_radiobutton_to_group(objectRadio, "Sphere");
    glui->add_radiobutton_to_group(objectRadio, "Cylinder");
    glui->add_radiobutton_to_group(objectRadio, "Tetrahedron");
    glui->add_radiobutton_to_group(objectRadio, "Bubbles");
    glui->add_radiobutton_to_group(objectRadio, "Pikachu (Clamped)");
    glui->add_radiobutton_to_group(objectRadio, "Pikachu (Repeated)");

    // Scene controls
    objPanel = glui->add_panel("Scene Transformations");

    GLUI_Rotation *sceneRotation = glui->add_rotation_to_panel( objPanel,
                                           "Rotation", sceneRotate,
                                           SCENE_ROTATE, controlChanged_cb );

    sceneRotation->set_spin( 0.90 );

    sceneTransPanel = glui->add_panel_to_panel(objPanel, "Translation");

    GLUI_Translation *sceneTransXY = glui->add_translation_to_panel(
                                           sceneTransPanel,
                                           "XY", GLUI_TRANSLATION_XY,
                                           sceneTranslate, SCENE_TRANSLATE,
                                           controlChanged_cb);
    sceneTransXY->set_speed( 0.25 );

    glui->add_column_to_panel(sceneTransPanel, false);

    GLUI_Translation *sceneTransZ =    glui->add_translation_to_panel(
                                          sceneTransPanel,
                                          "Z", GLUI_TRANSLATION_Z,
                                          &sceneTranslate[2], SCENE_TRANSLATE,
                                          controlChanged_cb);
    sceneTransZ->set_speed( 0.25 );

    sceneScalePanel = glui->add_panel_to_panel(objPanel, "Scale");
    xScaleSpin = glui->add_spinner_to_panel( sceneScalePanel, "X",
                                             GLUI_SPINNER_FLOAT, &sceneScale[0],
                                             SCENE_SCALE, controlChanged_cb );
    yScaleSpin = glui->add_spinner_to_panel( sceneScalePanel, "Y",
                                             GLUI_SPINNER_FLOAT, &sceneScale[1],
                                             SCENE_SCALE, controlChanged_cb );
    zScaleSpin = glui->add_spinner_to_panel( sceneScalePanel, "Z",
                                             GLUI_SPINNER_FLOAT, &sceneScale[2],
                                             SCENE_SCALE, controlChanged_cb );

    glui->add_column(true);

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

    // Projection controls.
    projPanel = glui->add_panel("Projection");

    // Choose between orth and perspective.
    projRadio = glui->add_radiogroup_to_panel(projPanel, &proj, PROJ,
                                           controlChanged_cb);
    glui->add_radiobutton_to_group(projRadio, "Perspective");
    glui->add_radiobutton_to_group(projRadio, "Parallel Perspective");

    // Perspective controls.
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

    // Point light controls
    lightPanel = glui->add_panel("Lighting");

    glui->add_checkbox_to_panel( lightPanel, "Point Light", &pLight,
                            LIGHTING, controlChanged_cb );
    glui->add_checkbox_to_panel( lightPanel, "Directional Light", &dLight,
                            LIGHTING, controlChanged_cb );

    dLightPanel = glui->add_panel_to_panel(lightPanel, "Directional");

    lightRotation = glui->add_rotation_to_panel(dLightPanel, "Rotation",
                                                directionalLightRotate,
                                                DIR_LIGHT_ROTATE,
                                                controlChanged_cb);
    lightRotation->set_spin( 0.45 );


    pLightPanel = glui->add_panel_to_panel(lightPanel, "Point");

    ptLtTransXY = glui->add_translation_to_panel(pLightPanel, "XY",
                                          GLUI_TRANSLATION_XY,
                                          pointLightPosition,
                                          PT_LIGHT_TRANSLATE,
                                          controlChanged_cb);
    ptLtTransXY->set_speed( 0.0625 );

    glui->add_column_to_panel(pLightPanel, false);

    ptLtTransZ = glui->add_translation_to_panel(pLightPanel, "Z",
                                              GLUI_TRANSLATION_Z,
                                              &pointLightPosition[2],
                                              PT_LIGHT_TRANSLATE,
                                              controlChanged_cb);
    ptLtTransZ->set_speed( 0.0625 );

    lightPropPanel = glui->add_panel_to_panel(lightPanel, "Color");

    lightRadio = glui->add_radiogroup_to_panel(lightPropPanel, &lighting,
                                               LIGHTING,
                                               controlChanged_cb);
    glui->add_radiobutton_to_group(lightRadio, "Point");
    glui->add_radiobutton_to_group(lightRadio, "Directional");

    ltColorRPanel = glui->add_panel_to_panel(lightPropPanel, "Red");
    ltColorR = new GLUI_Scrollbar( ltColorRPanel, "R", GLUI_SCROLL_HORIZONTAL,
                                   &lightColor[0], LIGHT_COLOR,
                                      controlChanged_cb );

    ltColorR->set_float_limits( 0.0, 1.0 );
    ltColorGPanel = glui->add_panel_to_panel(lightPropPanel, "Green");
    ltColorG = new GLUI_Scrollbar( ltColorGPanel, "G", GLUI_SCROLL_HORIZONTAL,
                                   &lightColor[1], LIGHT_COLOR,
                                   controlChanged_cb );
    ltColorG->set_float_limits( 0.0, 1.0 );
    ltColorBPanel = glui->add_panel_to_panel(lightPropPanel, "Blue");
    ltColorB = new GLUI_Scrollbar( ltColorBPanel, "B", GLUI_SCROLL_HORIZONTAL,
                                      &lightColor[2], LIGHT_COLOR,
                                      controlChanged_cb );
    ltColorB->set_float_limits( 0.0, 1.0 );

    lightTypeRadio = glui->add_radiogroup_to_panel(lightPropPanel, &lightType,
                                                   LIGHT_TYPE,
                                                   controlChanged_cb);
    glui->add_radiobutton_to_group(lightTypeRadio, "Diffuse");
    glui->add_radiobutton_to_group(lightTypeRadio, "Ambient");
    glui->add_radiobutton_to_group(lightTypeRadio, "Specular");

    orthLSpin->disable();
    orthRSpin->disable();
    orthBotSpin->disable();
    orthTopSpin->disable();
    orthNrSpin->disable();
    orthFrSpin->disable();

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
    // POINT
    glLightfv(GL_LIGHT0, GL_DIFFUSE, pointLightDiffuseColor);
    glLightfv(GL_LIGHT0, GL_AMBIENT, pointLightAmbientColor);
    glLightfv(GL_LIGHT0, GL_SPECULAR, pointLightSpecularColor);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
        glLightfv(GL_LIGHT0, GL_POSITION, pointLightPosition);
    glPopMatrix();

    // DIRECTIONAL
    glLightfv(GL_LIGHT1, GL_DIFFUSE, directionalLightDiffuseColor);
    glLightfv(GL_LIGHT1, GL_AMBIENT, directionalLightAmbientColor);
    glLightfv(GL_LIGHT1, GL_SPECULAR, directionalLightSpecularColor);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
        glMultMatrixf(directionalLightRotate);
        glLightfv(GL_LIGHT1, GL_POSITION, directionalLightPosition);
    glPopMatrix();


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (proj == PROJ_ORTHO) {
        glOrtho(orthL, orthR, orthBot, orthTop, orthNr, orthFr);
    } else { // perspective
        gluPerspective(perspFovy, perspAsp, perspZNr, perspZFr);
        gluLookAt(eyeX, eyeY, eyeZ, cenX, cenY, cenZ, upX, upY, upZ);
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
        case OBJECT:
            changeObject();
            break;
        case LOOK_AT:
            break;
        case LIGHT_COLOR:
            float * target;

            if (lighting == LIGHT_POINT) {
                if (pointLightType == LIGHT_TYPE_DIFFUSE) {
                    target = pointLightDiffuseColor;
                } else if (pointLightType == LIGHT_TYPE_AMBIENT) {
                    target = pointLightAmbientColor;
                } else { // specular
                    target = pointLightSpecularColor;
                }
            } else { // directional
                if (directionalLightType == LIGHT_TYPE_DIFFUSE) {
                    target = directionalLightDiffuseColor;
                } else if (directionalLightType == LIGHT_TYPE_AMBIENT) {
                    target = directionalLightAmbientColor;
                } else { // specular
                    target = directionalLightSpecularColor;
                }
            }

            for (int i = 0; i < 4; i++) {
                target[i] = lightColor[i];
            }

            break;
        case LIGHT_TYPE:
            if (lighting == LIGHT_POINT) {
                pointLightType = lightType;
            } else { // directional
                directionalLightType = lightType;
            }
        case LIGHTING:
            float * source;

            if (pLight == 1) {
                glEnable(GL_LIGHT0);
            } else {
                glDisable(GL_LIGHT0);
            }

            if (dLight == 1) {
                glEnable(GL_LIGHT1);
            } else {
                glDisable(GL_LIGHT1);
            }

            if (lighting == LIGHT_POINT) {
                lightTypeRadio->set_int_val(pointLightType);

                if (pointLightType == LIGHT_TYPE_DIFFUSE) {
                    source = pointLightDiffuseColor;
                } else if (pointLightType == LIGHT_TYPE_AMBIENT) {
                    source = pointLightAmbientColor;
                } else { // specular
                    source = pointLightSpecularColor;
                }
            } else { // directional
                lightTypeRadio->set_int_val(directionalLightType);

                if (directionalLightType == LIGHT_TYPE_DIFFUSE) {
                    source = directionalLightDiffuseColor;
                } else if (directionalLightType == LIGHT_TYPE_AMBIENT) {
                    source = directionalLightAmbientColor;
                } else { // specular
                    source = directionalLightSpecularColor;
                }
            }

            ltColorR->set_float_val( source[0] );
            ltColorG->set_float_val( source[1] );
            ltColorB->set_float_val( source[2] );

            break;
        case PROJ:
            if (proj == PROJ_ORTHO) {
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
            break;
        case ORTHO:
            break;
        case PERSPECTIVE:
            break;
        case SCENE_ROTATE:
            Scene::getInstance()->setRotation(sceneRotate);
            break;
        case SCENE_TRANSLATE:
            Scene::getInstance()->setTranslation(sceneTranslate);
            break;
        case SCENE_SCALE:
            Scene::getInstance()->setScale(sceneScale);
        case DIR_LIGHT_ROTATE:
            break;
        case PT_LIGHT_TRANSLATE:

            break;
    }

    Scene::getInstance()->redraw_cb();
}

void ControlPanel::changeObject() {
    Scene *scene = Scene::getInstance();

    scene->clear();

    Axis3D *axes = new Axis3D();
    scene->addObject3D(axes);

    switch ( objectType ) {
        case OBJ_CAMERA: {
            Camera *cam = new Camera();
            scene->addObject3D(cam);

            break;
        } case OBJ_CAMERA_BODY: {
            CameraBody *cb = new CameraBody();
            scene->addObject3D(cb);

            break;
        } case OBJ_CAMERA_LENS: {
            CameraLens *cl = new CameraLens();
            scene->addObject3D(cl);

            break;
        } case OBJ_FILM_CANISTER: {
            FilmCanister *film = new FilmCanister();
            film->setRotation(270.0, 0, -30);

            scene->addObject3D(film);

            break;
        } case OBJ_BASEBALL: {
            Baseball *bb = new Baseball();
            bb->setSize(1.5, 1.5, 1.5);
            scene->addObject3D(bb);

            break;
        } case OBJ_PYRAMID: {
            Texture *brick = new Texture();
            brick->loadJPEG("brick.jpg");

            SquareFrustum *pyramid = new SquareFrustum();
            pyramid->setTopSquareLength(0.01);
            pyramid->setSize(0.75, 0.75 * 1.5, 0.75);
            pyramid->setLocation(0, 0.5, 0);
            pyramid->setTexture(brick);
            scene->addObject3D(pyramid);

            break;
        } case OBJ_FRUSTUM: {
            SquareFrustum *sf = new SquareFrustum();
            sf->setSize(0.5, 0.5, 0.5);
            sf->setColor(new Color(1.0, 1.0, 0.0, 1.0));
            scene->addObject3D(sf);

            break;
        } case OBJ_CUBE: {
            Texture *tess = new Texture();
            tess->loadJPEG("tessellation.jpg");

            Cube *cube = new Cube();
            cube->setRotation(0.0, 45.0, 45.0);
            cube->setSize(1.5, 1.5, 1.5);
            cube->setTexture(tess);
            scene->addObject3D(cube);

            break;
        } case OBJ_SPHERE: {
            Material *ruby = new Material();
            ruby->setAmbient(new Color(0.1745, 0.01175, 0.01175, 1.0));
            ruby->setDiffuse(new Color(0.61424, 0.04136, 0.04136, 1.0));
            ruby->setSpecular(new Color(0.727811, 0.626959, 0.626959, 1.0));
            ruby->setShininess(0.6 * 128);

            Sphere *sphere = new Sphere();
            sphere->setColor(new Color(0.61424, 0.04136, 0.04136, 1.0));
            sphere->setMaterial(ruby);
            scene->addObject3D(sphere);

            break;
        } case OBJ_TETREHEDRON: {
            Tetrahedron *t = new Tetrahedron();
            t->setSize(0.5, 0.5, 0.5);
            t->setRotation(-15, -15, 0);
            t->setColor(new Color(0.0, 0.60, 0.88, 1.0));
            scene->addObject3D(t);

            break;
        } case OBJ_CYLINDER: {
            Material *jade = new Material();
            jade->setAmbient(new Color(0.135, 0.2225, 0.1575, 1.0));
            jade->setDiffuse(new Color(0.54, 0.89, 0.63, 1.0));
            jade->setSpecular(new Color(0.316228, 0.316228, 0.316228, 1.0));
            jade->setShininess(0.1 * 128);

            Cylinder *cyl = new Cylinder();
            cyl->setSize(1, 1, 1);
            cyl->setRotation(270, 0, 0);
            cyl->setColor(new Color(0.54, 0.89, 0.63, 1.0));
            cyl->setMaterial(jade);
            scene->addObject3D(cyl);

            break;
        } case OBJ_BUBBLES: {
            Material *glass = new Material();
            glass->setShininess(128.0);
            glass->setAmbient(new Color(0.0, 0.0, 0.0, 1.0));
            glass->setEmission(new Color(0.0, 0.0, 0.0, 1.0));
            glass->setSpecular(new Color(1.0, 1.0, 1.0, 1.0));

            Sphere *sphere = new Sphere();
            sphere->setSize(0.75, 0.75, 0.75);
            sphere->setColor(new Color(0.93, 0.88, 0.90, 0.25));
            sphere->setMaterial(glass);
            scene->addObject3D(sphere);

            sphere = new Sphere();
            sphere->setLocation(0.5, 0.75, 0.5);
            sphere->setSize(0.5, 0.5, 0.5);
            sphere->setColor(new Color(0.99, 0.99, 0.99, 0.25));
            sphere->setMaterial(glass);
            scene->addObject3D(sphere);

            sphere = new Sphere();
            sphere->setLocation(0, 0.5, 1);
            sphere->setSize(0.85, 0.85, 0.85);
            sphere->setColor(new Color(0.99, 0.99, 0.99, 0.25));
            sphere->setMaterial(glass);
            scene->addObject3D(sphere);

            break;
        } case OBJ_PIKACHU_PIC: {
            PikachuPicture *pikachu1 = new PikachuPicture();
            scene->addObject3D(pikachu1);

            break;
        } case OBJ_PIKACHU_WRAP: {
            PikachuWrappingPaper *pikachu2 = new PikachuWrappingPaper();
            pikachu2->setColor(new Color(1.0, 1.0, 1.0, 1.0));
            scene->addObject3D(pikachu2);

            break;
        }
    }
}
