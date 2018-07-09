//
// Created by optio32 on 09.07.18.
//

#ifndef UNTITLED_MESH_H
#define UNTITLED_MESH_H

#include <string>
#include <assimp/types.h>
#include "math_3d.h"

struct Vertex
{
    Vector3f position;
    Vector3f normal;
    Vector2f uvCoordinate;
};

struct Texture
{
    unsigned id;
    std::string type;
    aiString path;
};

class Mesh
{
public:
    std::vector<Vertex> _vertices;
    std::vector<unsigned>  _indices;
    std::vector<Texture> _textures;

    Mesh(std::vector<Vertex> vertices, std::vector<unsigned> indices, std::vector<Texture> textures);

    ~Mesh();

};


#endif //UNTITLED_MESH_H
