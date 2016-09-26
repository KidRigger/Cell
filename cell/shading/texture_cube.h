#ifndef CELL_SHADING_TEXTURE_CUBE_H
#define CELL_SHADING_TEXTURE_CUBE_H

#include "texture.h"

#include <GL/glew.h>

#include <vector>

namespace Cell
{
    class TextureCube
    {
    public:
        unsigned int ID;
        // TODO(Joey): these should be private and only accessed w/ getters/setters s.t. we can 
        // directly change the texture state where relevant from within the setters.
        GLenum Format = GL_RGBA;                 // NOTE(Joey): the format each texel is stored in
        GLenum Type   = GL_UNSIGNED_BYTE;
        GLenum FilterMin = GL_LINEAR; // NOTE(Joey): what filter method to use during minification
        GLenum FilterMax = GL_LINEAR;               // NOTE(Joey): what filter method to use during magnification
        GLenum WrapS = GL_CLAMP_TO_EDGE;            // NOTE(Joey): wrapping method of the S coordinate
        GLenum WrapT = GL_CLAMP_TO_EDGE;            // NOTE(Joey): wrapping method of the T coordinate
        bool   Mipmapping = false;

        unsigned int FaceWidth  = 0;
        unsigned int FaceHeight = 0;
    private:
    public:
        TextureCube();
        ~TextureCube();

        // NOTE(Joey): default initialize all cubemap faces w/ default values
        void DefaultInitialize(unsigned int width, unsigned int height, GLenum format, GLenum type);

        // NOTE(Joey): cubemap texture generation per face
        void GenerateFace(GLenum face, unsigned int width, unsigned int height, GLenum format, GLenum type, unsigned char *data);
        //void Generate(unsigned int width, unsigned int height, GLenum dataFormat, GLenum type, std::vector<Texture> faces);
        void SetMipFace(GLenum face, unsigned int width, unsigned int height, GLenum format, GLenum type, unsigned int mipLevel, unsigned char *data);

        // NOTE(Joey): resize (note that its values will be uninitialized)
        void Resize(unsigned int width, unsigned int height);

        void Bind(int unit = -1);
        void Unbind();
    };
}
#endif