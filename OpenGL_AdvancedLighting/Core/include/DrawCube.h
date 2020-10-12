#pragma once

#include <iostream>
#include <string>
#include "Shader.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class DrawCube {

public:
    DrawCube();
    ~DrawCube();

    void SetProjection(glm::mat4& inProjection) {
        projection = inProjection;
    }
    void SetView(glm::mat4& inView) {
        view = inView;
    }
    void SetModel(glm::mat4& inModel) {
        model = inModel;
    }

    void SetColor(glm::vec3& inColor) {
        color = inColor;
    }

    void Draw();


private:

    Shader* pShader;

    glm::mat4 projection;
    glm::mat4 view;
    glm::mat4 model;

    glm::vec3 color;

    GLuint vao;
    GLuint vbo;
};


