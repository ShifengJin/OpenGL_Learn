#pragma once

#include "Shader.h"
#include <GL\glew.h>

class Transformation1 {

public:
    Transformation1();
    ~Transformation1();

    void Draw(glm::mat4 &transform);

private:
    GLuint vertexShader = 0;
    GLuint fragmentShader = 0;

    GLuint vertexArray = 0;
    GLuint vertexBuffer = 0;
    GLuint elementBuffer = 0;

    GLuint texture1;
    GLuint texture2;

    int width, height, nrChannels;
    GLuint transformId;

    unsigned char *data;
public:
    Shader *ourShader = NULL;
};

