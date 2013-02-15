/**
 * SquareFrustum.h - A class implementation representing a square frustum.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *
 * UNH CS 870, fall 2012
 *
 * History
 *  10/27/2012: Created class.
 */
#ifndef SQUAREFRUSTUM_H_
#define SQUAREFRUSTUM_H_

#include "Object3D.h"

class SquareFrustum: public Object3D {
public:
    SquareFrustum();
    virtual ~SquareFrustum();

    void drawAtOrigin();
    void drawNormal( float * p1, float * p2, float * p3 );

    void setTopSquareLength( float t );
    float getTopSquareLength();

    void setBottomSquareLength( float b );
    float getBottomSquareLength();
private:
    float bottomSquareLength;
    float topSquareLength;
};

#endif /* SQUAREFRUSTUM_H_ */
