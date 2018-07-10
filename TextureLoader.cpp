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

TextureLoader::~TextureLoader()
{
    if(_pImage != NULL)
        delete _pImage;
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
    return !fOk;
}

void TextureLoader::CalculateGazeboImageSize() {
    size_t desired_size = -1;
    size_t calculated_size = 1;
    while ((calculated_size + 1) < desired_size) {
        calculated_size = calculated_size * 2;
    }
    calculated_size += 1; // Gazebo needs (2^n)+1 px size images
    //calculated_size
}

void TextureLoader::PrintImageInfo()
{
    size_t height = _pImage->rows();
    size_t width = _pImage->columns();
    printf("h= %ld w= %ld\n", height, width);
}

bool TextureLoader::LoadToGL()
{
    bool fOk = false;
    if(_blob.length() == 0 || _pImage == NULL)
        return fOk;
    glGenTextures(1, &_textureObject);
    glBindTexture(GL_TEXTURE_2D, _textureObject);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _pImage->columns(), _pImage->rows(), 0, GL_RGBA, GL_UNSIGNED_BYTE, _blob.data());
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

bool TextureLoader::SaveBytesToFile(char* output_filename)
{
    FILE* file = fopen(output_filename, "w");
    if(file == NULL) return false;
    size_t wroteBytes = fwrite(_blob.data(), _blob.length(), 1, file);
    if(wroteBytes != 1)
    {
        fclose(file);
        return false;
    }
    fclose(file);
}

bool TextureLoader::SaveBytesToFile(char* output_filename, void* bytes, size_t size)
{
    FILE* file = fopen(output_filename, "w");
    if(file == NULL) return false;
    size_t wroteBytes = fwrite(bytes, size, 1, file);
    if(wroteBytes != 1)
    {
        fclose(file);
        return false;
    }
    fclose(file);
}
