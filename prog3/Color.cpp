/**
 * Color.cpp - A class abstraction for gl color specification. This only uses
 *  the float version, but it could be extended if it ever proved useful to be
 *  more generic.  It supports rgb and rgba.
 *
 * @author Carmen St. Jean (crr8, carmen@cs.unh.edu)
 *         Based on Color.cpp by Dan Bergeron.
 *
 * UNH CS 870, fall 2012
 *
 * History:
 *  10/27/2012: Added getFloatArray method.
 *  10/07/2012: Modified slightly to incorporate into homework assignment.
 *  09/24/2012: For now this is little more than a struct.
 */
#include "Color.h"

//------------- simple constructors -----------------------
Color::Color() {
    r = g = b = 0.0f;
    a = 1.0f;
}

Color::Color( float red, float green, float blue, float alpha ) {
    // Should check that values are in the range [0,1]
    r = red;
    g = green;
    b = blue;
    a = alpha;

    arr = new float[4]();
}

/**
 * Not really needed since this is default behavior
 */
Color::Color( const Color& col ) {
    r = col.r;
    g = col.g;
    b = col.b;
    a = col.a;
}

/**
 * Returns an array of four floats representing this color object.
 *
 * @return An array of four floats {r, g, b, a}.
 */
float * Color::getFloatArray() {
    arr[0] = r;
    arr[1] = g;
    arr[2] = b;
    arr[3] = a;

    return arr;
}
