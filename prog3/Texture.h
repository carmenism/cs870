/*
 * Texture.h -- Object-oriented version of David Henry's texture loader
 *
 * Created by Matt Plumlee 10/26/2008
 */

#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <GL/glut.h>

#include "Color.h"

class Texture //could derive this from Addressable eventually...
{
    public:
        Texture();
        ~Texture();

        GLuint  getId();
        GLsizei getWidth();
        GLsizei getHeight();

        void enable();
        void disable();

        bool loadJPEG( std::string filename );

        void setMagFilterValue(int v);
        int getMagFilterValue();

        void setMinFilterValue(int v);
        int getMinFilterValue();

        void setWrapSValue(int v);
        int getWrapSValue();

        void setWrapTValue(int v);
        int getWrapTValue();

        void setBorderColor(Color *c);
        Color * getBorderColor();
    protected:
        bool readJPEGfromFile( std::string filename );

        GLuint  textureID;
        GLsizei width, height;
        GLenum  format;
        GLint   internalFormat;
        GLubyte *texels;

        GLint magFilterValue;
        GLint minFilterValue;
        GLint wrapSValue;
        GLint wrapTValue;
        Color *borderColor;
};

#endif
