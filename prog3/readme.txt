Carmen St. Jean
crr8
Program 3

Features of my program:

- Materials
  * Chrome-like material for the silver parts of the camera.
  * Rubber-like material for the camera lens focus and aperture controls of the camera.
  * Cloth-like material for the black part of the camera body.
  * Plastic-like material for the main portion of the camera lens, the shutter button, and the film canister.
  * Jade-like material for the greenish cylinder.
  * Ruby-like material for the red misshapen sphere.
  * See-through glass-like material for glass of camera lens and bubbles.
  * Default dull material for pikachu pictures, baseball, and all other shapes.
  
- Textures
  * The film canister features a Kodachrome label around a cylinder.  This was done using texture defaults (GL_LINEAR_MIPMAP_LINEAR for mag filter, GL_LINEAR for min filter, GL_REPEAT for wrap s and wrap t, black border color).
  * The pyramid features a brick texture using the texture defaults.
  * The cube features an Escher tessellation texture using the texture defaults.
  * The baseball features a baseball texture image around a sphere. The properties used here were GL_NEAREST for mag and min filters, GL_REPEAT for wrap s and wrap t, and white for border color.  Without these settings, a seam was apparent on the image and it didn't look anything like a real baseball.
  * The pikachu wrapping paper features a repeated image of pikachu using the defaults for texture parameters.
  * The pikachu picture features a single clamped image of pikachu using the properties of GL_LINEAR_MIPMAP_LINEAR for mag filter, GL_LINEAR for min filter, and GL_CLAMP for wrap s and wrap t.
  
- Extra features
  * The film canister is an unnecessarily complicated shape!
  * Changed Sphere class to use gluSphere.  Now it is texturable.
  * Converted Cylinder class to use gluCylinder so it can have textures.  The gluCylinder does not contain a top or a bottom, so it is more like a tube.  I built myself a complete cylinder from gluCylinder and two gluDisk objects.
  * Changed my Cube class to use six flat faces drawn using GL_QUAD vertices.  Now it is texturable.
  * Created a SquareFrustum class to draw six faces using GL_QUAD vertices with correct normals.  The SquareFrustum class can also use textures. 
  * I implemented GL_TEXTURE_BORDER_COLOR.

