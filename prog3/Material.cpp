/**
 * Material.cpp - A class implementation representing material properties of a
 * 3D object.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/27/2012: Created class.
 */
#include "Material.h"

Material::Material() {
    ambient = new Color(0.2, 0.2, 0.2, 1.0);
    diffuse = new Color(0.8, 0.8, 0.8, 1.0);
    specular = new Color(0.0, 0.0, 0.0, 1.0);
    emission = new Color(0.0, 0.0, 0.0, 1.0);

    shininess[0] = 0.0;
}

Material::~Material() {
}

/**
 * Sets the ambient property of the material according to the color specified.
 *
 * @param The new ambient color.
 */
void Material::setAmbient(Color *a) {
    ambient = a;
}

/**
 * Returns the ambient color property for this material.
 *
 * @return The ambient Color object.
 */
Color * Material::getAmbient() {
    return ambient;
}

/**
 * Sets the diffuse property of the material according to the color specified.
 *
 * @param The new diffuse color.
 */
void Material::setDiffuse(Color *d) {
    diffuse = d;
}

/**
 * Returns the diffuse color property for this material.
 *
 * @return The diffuse Color object.
 */
Color * Material::getDiffuse() {
    return diffuse;
}

/**
 * Sets the specular property of the material according to the color specified.
 *
 * @param The new specular color.
 */
void Material::setSpecular(Color *s) {
    specular = s;
}

/**
 * Returns the specular color property for this material.
 *
 * @return The specular Color object.
 */
Color * Material::getSpecular() {
    return specular;
}

/**
 * Sets the emission property of the material according to the color specified.
 *
 * @param The new emission color.
 */
void Material::setEmission(Color *e) {
    emission = e;
}

/**
 * Returns the emission color property for this material.
 *
 * @return The emission Color object.
 */
Color * Material::getEmission() {
    return emission;
}

/**
 * Sets the shininess for this material according to the specified float.
 *
 * @param s The new shininess parameter.
 */
void Material::setShininess(float s) {
    shininess[0] = s;
}

/**
 * Returns the shininess value for this material.
 *
 * @return The shininess, a float value.
 */
float Material::getShininess() {
    return shininess[0];
}

/**
 * Redraws the texture.
 */
void Material::redraw() {
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient->getFloatArray());
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse->getFloatArray());
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular->getFloatArray());
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, emission->getFloatArray());
}
