//
// Created by optio32 on 06.07.18.
//

#include "TextureLoader.h"
#include <cstdio>
#include <cstring>

TextureLoader::TextureLoader(char* texture_filename)
{
    memcpy(_szFileName, texture_filename, strlen(texture_filename) + 1);
}

bool TextureLoader::Load()
{
    bool fOk = false;
    try
    {
        _pImage = new Magick::Image(_szFileName);
        _pImage->write(&_blob, "RGBA");
    }
    catch(Magick::Error& error)
    {
        printf("error loading texture %d\n", error.what());
        return fOk;
    }
    glGenTextures(1, &_textureObject);
    glBindTexture(GL_TEXTURE_2D, _textureObject);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _pImage->columns(), _pImage->rows(), 0, GL_RGBA, GL_UNSIGNED_BYTE, _blob.data());
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    return !fOk;
}

