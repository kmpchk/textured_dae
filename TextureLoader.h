//
// Created by optio32 on 06.07.18.
//

#ifndef UNTITLED_TEXTURELOADER_H
#define UNTITLED_TEXTURELOADER_H

#include <Magick++/Image.h>
#include <GL/glew.h>

void TextureLoad();
class TextureLoader
{
public:
    TextureLoader(char* texture_filename);
    bool Load();

private:
    Magick::Image* _pImage = NULL;
    Magick::Blob _blob;
    GLuint _textureObject;
    char _szFileName[80] = {0};
};

#endif //UNTITLED_TEXTURELOADER_H
