//
// Created by optio32 on 06.07.18.
//

#ifndef UNTITLED_MODELLOADER_H
#define UNTITLED_MODELLOADER_H

#include <string>
#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/Exporter.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <GL/glew.h>
#include "Mesh.h"

//void ModelLoad(char* model_filename);

class Model
{
    std::vector<Mesh> _meshes;
    std::string _directory;
    std::string _modelName;

public:

    void loadModel(const std::string& path);

    void printfModelInfo();

private:


    Mesh* getMeshesInfo();

    void processNode(aiNode *node, const aiScene *scene);

    Mesh processMesh(aiMesh *mesh, const aiScene *scene);

    std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
};


#endif //UNTITLED_MODELLOADER_H
