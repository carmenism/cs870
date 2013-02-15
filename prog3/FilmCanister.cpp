/**
 * FilmCanister.cpp - A class implementation representing a film canister.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/27/2012: Created class.
 */
#include "FilmCanister.h"

FilmCanister::FilmCanister() : Object3D() {
    setLocation(0.0, 0.0, 0.0);
    setRotation(0.0, 0.0, 0.0);
    setColor(new Color(1.0, 1.0, 1.0, 1.0));
    setSize(1.0, 1.0, 1.0);

    Texture *t = new Texture();
    t->loadJPEG( "kodachrome.jpg" );

    Material *plastic = new Material();
    plastic->setAmbient(new Color(0.0, 0.0, 0.0, 1.0));
    plastic->setDiffuse(new Color(0.1, 0.1, 0.1, 1.0));
    plastic->setSpecular(new Color(0.6, 0.6, 0.6, 1.0));
    plastic->setShininess(0.4 * 128);

    Material *yellowPlastic = new Material();
    yellowPlastic->setAmbient(new Color(0.0, 0.0, 0.0, 1.0));
    yellowPlastic->setDiffuse(new Color(0.5, 0.5, 0.0, 1.0));
    yellowPlastic->setSpecular(new Color(0.6, 0.6, 0.5, 1.0));
    yellowPlastic->setShininess(0.25 * 128);

    Material *redPlastic = new Material();
    redPlastic->setAmbient(new Color(0.0, 0.0, 0.0, 1.0));
    redPlastic->setDiffuse(new Color(0.5, 0.0, 0.0, 1.0));
    redPlastic->setSpecular(new Color(0.7, 0.6, 0.6, 1.0));
    redPlastic->setShininess(0.4 * 128);

    Material *filmM = new Material();
    filmM->setAmbient(new Color(0.1, 0.1, 0.1, 1.0));
    filmM->setDiffuse(new Color(0.0, 0.5, 0.0, 1.0));
    filmM->setSpecular(new Color(0.54, 0.38, 0.1, 1.0));
    filmM->setShininess(0.4 * 128);

    label = new EmptyCylinder();
    label->setSize(0.65789, 0.65789, 1.0);
    label->setTexture(t);
    label->setLocation(0, 0, 0.05);
    label->setMaterial(yellowPlastic);

    canister = new Cylinder();
    canister->setSize(0.65, 0.65, 1.1);
    canister->setColor(new Color(0.1, 0.1, 0.1, 1));
    canister->setMaterial(plastic);

    top = new EmptyCylinder();
    top->setSize(canister->getXSize() / 2, canister->getYSize() / 2, 0.5);
    top->setColor(new Color(0.1, 0.1, 0.1, 1));
    top->setMaterial(plastic);
    top->setLocation(0, 0, 0.75);

    cube = new Cube();
    cube->setSize(0.35, canister->getYSize() / 4, 1.1);
    cube->setColor(new Color(0.1, 0.1, 0.1, 1.0));
    cube->setLocation(0.2, 3 * cube->getYSize() / 2, canister->getZSize() / 2);
    cube->setMaterial(plastic);

    cubeLabel = new Cube();
    cubeLabel->setSize(0.38, cube->getYSize() + 0.01, 1);
    cubeLabel->setMaterial(yellowPlastic);
    cubeLabel->setLocation(cube->getX() - 0.05,
                           cube->getY() - 0.001,
                           cube->getZ());
    cubeLabel->setColor(new Color(0.98, 0.69, 0.16));

    labelStripe = new Cube();
    labelStripe->setSize(0.38, 0.006, 0.285);
    labelStripe->setColor(new Color(0.94, 0.15, 0.07, 1.0));
    labelStripe->setMaterial(redPlastic);
    labelStripe->setLocation(cubeLabel->getX(),
                             cube->getY() + cube->getYSize()/2 + 0.002,
                             0.55);

    film = new Cube();
    film->setSize(0.5, 0.01, 0.85);
    film->setColor(new Color(0.35, 0.39, 0.32));
    film->setLocation(cube->getX() + 0.25, cube->getY(), cube->getZ() - 0.05);
    film->setMaterial(filmM);
}

FilmCanister::~FilmCanister() {

}

/**
 * Draws the film canister object at the origin.
 */
void FilmCanister::drawAtOrigin() {
    top->redraw();
    canister->redraw();
    label->redraw();
    cube->redraw();
    cubeLabel->redraw();
    labelStripe->redraw();
    film->redraw();
}
