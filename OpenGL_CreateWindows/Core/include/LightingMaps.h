#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <vector>
#include "Shader.h"


class LightingMaps1 {
public:
    LightingMaps1();
    ~LightingMaps1();

    void DrawLight();
    void DrawModel();
    void BindTextureToMaterialDiffuse();

    void SetLightPosition(glm::vec3& inLightPosition);
    void SetViewPos(glm::vec3& inViewPos);
    void SetLightAmbient(glm::vec3& inLightAmbient);
    void SetLightDiffuse(glm::vec3& inLightDiffuse);
    void SetLightSpecular(glm::vec3& inLightSpecular);
    void SetMaterialSpecular(glm::vec3& inMaterialSpecular);
    void SetShininess(float inShininess);

    void SetProjectionMatrix(glm::mat4& inProjectionMatrix);
    void SetViewMatrix(glm::mat4& inViewMatrix);
    void SetModelMatrix(glm::mat4& inModelMatrix);
    void SetLightModelMatrix(glm::mat4& inLightModelMatrix);

    void SetMaterialDiffuse(int inMaterialDiffuse);
private:

    GLuint loadTexture(char const * imagePath);


private:
    Shader*      pLightingShader;
    Shader*      pLightCubeShader;

    GLuint       VBO, cubeVAO, lightCubeVAO;

    glm::vec3    lightPosition;          // 光源的位置
    glm::vec3    viewPos;                // 相机的位置

    glm::vec3    lightAmbient;           // 光源的颜色
    glm::vec3    lightDiffuse;           // 光源漫反射的颜色
    glm::vec3    lightSpecular;          // 光源对镜面反射的颜色

    glm::vec3    materialSpecular;       // 材质镜面反射的颜色
    float        shininess;              // 光斑

    glm::mat4    projectionMatrix;             // 投影矩阵
    glm::mat4    viewMatrix;                   // 视图矩阵
    glm::mat4    modelMatrix;                  // 模型矩阵
    glm::mat4    lightModelMatrix;             // 光源矩阵

    int          materialDiffuse;

    GLuint       diffuseMapTexture;

};


class LightingMaps2 {
public:
    LightingMaps2();
    ~LightingMaps2();

    void DrawLight();
    void DrawModel();
    void BindTextureToMaterialDiffuse();

    void SetLightPosition(glm::vec3& inLightPosition);
    void SetViewPos(glm::vec3& inViewPos);
    void SetLightAmbient(glm::vec3& inLightAmbient);
    void SetLightDiffuse(glm::vec3& inLightDiffuse);
    void SetLightSpecular(glm::vec3& inLightSpecular);
    void SetShininess(float inShininess);

    void SetProjectionMatrix(glm::mat4& inProjectionMatrix);
    void SetViewMatrix(glm::mat4& inViewMatrix);
    void SetModelMatrix(glm::mat4& inModelMatrix);
    void SetLightModelMatrix(glm::mat4& inLightModelMatrix);

private:

    GLuint loadTexture(char const * imagePath);


private:
    Shader*      pLightingShader;
    Shader*      pLightCubeShader;

    GLuint       VBO, cubeVAO, lightCubeVAO;

    glm::vec3    lightPosition;          // 光源的位置
    glm::vec3    viewPos;                // 相机的位置

    glm::vec3    lightAmbient;           // 光源的颜色
    glm::vec3    lightDiffuse;           // 光源漫反射的颜色
    glm::vec3    lightSpecular;          // 光源对镜面反射的颜色

    float        shininess;              // 光斑

    glm::mat4    projectionMatrix;             // 投影矩阵
    glm::mat4    viewMatrix;                   // 视图矩阵
    glm::mat4    modelMatrix;                  // 模型矩阵
    glm::mat4    lightModelMatrix;             // 光源矩阵

    GLuint       diffuseMapTexture;
    GLuint       specularTexture;

};
