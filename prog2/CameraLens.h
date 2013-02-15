/**
 * CameraLens.h - A class implementation representing the lens of a camera.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/07/2012: Created class.
 */
#ifndef CAMERALENS_H_
#define CAMERALENS_H_

#include "Object3D.h"
#include "Cylinder.h"
#include "Sphere.h"

class CameraLens: public Object3D {
public:
	CameraLens();
	virtual ~CameraLens();
	void redraw();
private:
	Cylinder *lensBody, *apertureControl, *focusControl;
	Sphere *lensGlass;
};

#endif /* CAMERALENS_H_ */
