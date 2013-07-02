/**
 * Material.h - A class implementation representing material properties of a 3D
 * object.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/27/2012: Created class.
 */
#ifndef MATERIAL_H_
#define MATERIAL_H_

#include <GL/glut.h>

#include "Color.h"

class Material {
public:
    Material();
    virtual ~Material();

    void redraw();

    void setAmbient(Color *a);
    Color * getAmbient();

    void setSpecular(Color *s);
    Color * getSpecular();

    void setDiffuse(Color *d);
    Color * getDiffuse();

    void setEmission(Color *e);
    Color * getEmission();

    void setShininess(float s);
    float getShininess();
private:
    Color *ambient, *specular, *diffuse, *emission;
    float shininess[1];
};

#endif /* MATERIAL_H_ */
