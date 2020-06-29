#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <vector>
#include "Shader.h"

class Camera1 {
public:

    Camera1();
    ~Camera1();

    void SetModel(glm::mat4 inModel);
    void SetModels(std::vector<glm::mat4> inModels);
    void SetView(glm::mat4 inView);
    void SetProjection(glm::mat4 inProjection);
    void Draw();
    void Draws();
private:
    void init(std::string& vs, std::string& fs, std::string& img1, std::string& img2);
private:

    GLuint         mVertexArray;
    GLuint         mVertexBuffer;

    GLuint         mTexture1, mTexture2;

    std::vector<glm::mat4> models;
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;

    Shader        *ourShader;

};