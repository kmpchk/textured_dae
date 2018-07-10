//
// Created by optio32 on 06.07.18.
//

#include "ModelLoader.h"
#include <assimp/Importer.hpp>
#include <assimp/Exporter.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <cstdio>
#include <glm/vec3.hpp>
#include "Utils.h"

Model::Model() {}
Model::~Model() {}

void Model::load(const std::string& path)
{
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_JoinIdenticalVertices | aiProcess_GenNormals);
    if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        printf("error:= %s\n", importer.GetErrorString());
        return;
    }
    _directory = getFileDirectory(path);
    _modelName = getFileName(path);

    processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode* node, const aiScene* scene)
{
    for(unsigned int i = 0; i < node->mNumMeshes; i++){
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
        _meshes.push_back(processMesh(mesh, scene));
    }

    for(unsigned int i = 0; i < node->mNumChildren; i++)
        processNode(node->mChildren[i], scene);
}

Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene)
{
    std::vector<Vertex> vertices;
    std::vector<unsigned> indices;
    std::vector<Texture> textures;

    for(unsigned int i = 0; i < mesh->mNumVertices; i++){
        Vertex vertex;

        Vector3f vector3f;

        vector3f.x = mesh->mVertices[i].x;
        vector3f.y = mesh->mVertices[i].y;
        vector3f.z = mesh->mVertices[i].z;
        vertex.position = vector3f;

        vector3f.x = mesh->mNormals[i].x;
        vector3f.y = mesh->mNormals[i].y;
        vector3f.z = mesh->mNormals[i].z;
        vertex.normal = vector3f;

        if(mesh->mTextureCoords[0]){
            Vector2f vector2f;
            vector2f.x = mesh->mTextureCoords[0][i].x;
            vector2f.y = mesh->mTextureCoords[0][i].y;
            vertex.uvCoordinate = vector2f;

        }else
            vertex.uvCoordinate = Vector2f(0.0f, 0.0f);

        vertices.push_back(vertex);
    }

    for ( GLuint i = 0; i < mesh->mNumFaces; i++ ){
        aiFace face = mesh->mFaces[i];
        for ( GLuint j = 0; j < face.mNumIndices; j++ )
            indices.push_back(face.mIndices[j]);
    }

    if(mesh->mMaterialIndex >= 0){
        aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

        // Diffuse map
        std::vector<Texture> diffuseMaps = loadMaterialTextures( material, aiTextureType_DIFFUSE, "texture_diffuse" );
        textures.insert( textures.end( ), diffuseMaps.begin( ), diffuseMaps.end( ) );

        // Specular maps
        std::vector<Texture> specularMaps = loadMaterialTextures( material, aiTextureType_SPECULAR, "texture_specular" );
        textures.insert( textures.end( ), specularMaps.begin( ), specularMaps.end( ) );
    }

    return Mesh(vertices, indices, textures);
}

std::vector<Texture> Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName)
{
    std::vector<Texture> textures;

    for(unsigned int i = 0; i < mat->GetTextureCount(type); i++)
    {
        aiString str;
        mat->GetTexture(type, i, &str);

        Texture texture;
        //texture.id = *RessourceManager::TextureManager::get(directory + "/" + str.C_Str());
        texture.type = typeName;
        texture.path = str;
        textures.push_back(texture);
    }
    return textures;
}

void Model::printfModelInfo()
{
    for (int i = 0; i < _meshes[0]._vertices.size(); ++i)
    {
        Vertex* f = &_meshes[0]._vertices[i];
        printf("U:= %g V:= %g\n", f->uvCoordinate.x, f->uvCoordinate.y);
    }
    printf("meshes count:= %d\n", _meshes.size());
    //printf("textures count:= %d\n", _meshes[0]._textures.size());
    //printf("%s\n", _meshes[0]._textures[0].path.C_Str());
    //printf("name:= %s\n", _modelName.c_str());
    //printf("directory:= %s\n", _directory.c_str());
    //printf("vert:= %d\n", _meshes[0]._vertices.size());
}

Mesh* Model::getMeshesInfo()
{

    /*for (size_t i = 0; i < _meshes.size(); ++i)
    {
        printf("%d", _meshes[i]);
    }*/
}