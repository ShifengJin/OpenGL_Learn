#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <vector>
#include "Shader.h"

class Color1 {
public:
    Color1();
    ~Color1();

    void SetObjectColor(glm::vec3& inObjectColor);
    void SetLightColor(glm::vec3& inLightColor);
    void SetProjection(glm::mat4& inProjection);
    void SetView(glm::mat4& inView);
    void SetModelObject(glm::mat4& inModelObject);
    void SetModelLight(glm::mat4& inModelLight);

    void DrawObject();
    void DrawLight();


private:

    Shader   *light1Shader;
    Shader   *objectShader;

    GLuint    vertexBuffer;
    GLuint    objectVertexArray;
    GLuint    lightVertexArray;

    glm::vec3 objectColor;
    glm::vec3 lightColor;

    glm::mat4 projection;
    glm::mat4 view;
    glm::mat4 modelObject;
    glm::mat4 modelLight;

};

class Color2 {
public:
    Color2();
    ~Color2();

    void SetObjectColor(glm::vec3& inObjectColor);
    void SetLightColor(glm::vec3& inLightColor);
    void SetProjection(glm::mat4& inProjection);
    void SetView(glm::mat4& inView);
    void SetModelObject(glm::mat4& inModelObject);
    void SetModelLight(glm::mat4& inModelLight);

    void DrawObject(glm::vec3 lightPos);
    void DrawObject2(glm::vec3 lightPos, glm::vec3 viewPos);
    void DrawLight();


private:

    Shader   *light1Shader;
    Shader   *objectShader;

    GLuint    vertexBuffer;
    GLuint    objectVertexArray;
    GLuint    lightVertexArray;

    glm::vec3 objectColor;
    glm::vec3 lightColor;


    glm::mat4 projection;
    glm::mat4 view;
    glm::mat4 modelObject;
    glm::mat4 modelLight;

};