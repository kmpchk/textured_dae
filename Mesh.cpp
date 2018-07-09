//
// Created by optio32 on 09.07.18.
//

#include "Mesh.h"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned> indices, std::vector<Texture> textures)
{
    _vertices = vertices;
    _indices = indices;
    _textures = textures;
}

Mesh::~Mesh()
{

}