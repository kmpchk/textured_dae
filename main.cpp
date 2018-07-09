#include <iostream>
#include <assimp/Importer.hpp>
#include <assimp/Exporter.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <GL/freeglut.h>
#include "ModelLoader.h"

int main(int argc, char** argv)
{
    /*glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tutorial 01");
    glutDisplayFunc(RenderSceneCB);

    GLenum res = glewInit();
    if (res != GLEW_OK) {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    Vector3f vertices[1];
    vertices[0] = Vector3f(0.0f, 0.0f, 0.0f);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glutMainLoop();*/

    Model* model = new Model();
    model->loadModel(argv[1]);
    model->printfModelInfo();

    //printf("input model:= %s\n", argv[1]);

    return 0;
}