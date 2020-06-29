#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <vector>
#include "Shader.h"

class Materials {
public:
    Materials();
    ~Materials();

    void SetLightAmbient(glm::vec3& inAmbient);
    void SetLightDiffuse(glm::vec3& inDiffuse);
    void SetLightSpecular(glm::vec3& inSpecular);

    void SetMaterialAmbient(glm::vec3& inAmbient);
    void SetMaterialDiffuse(glm::vec3& inDiffuse);
    void SetMaterialSpecular(glm::vec3& inSpecular);
    void SetMaterialShininess(float inShininess);

    void SetProjection(glm::mat4& inProjection);
    void SetView(glm::mat4& inView);
    void SetModelObject(glm::mat4& inModelObject);
    void SetModelLight(glm::mat4& inModelLight);

    void DrawObject(glm::vec3 lightPos, glm::vec3 viewPos);
    void DrawLight();

private:
    Shader *   pLightingShader;
    Shader *   pLightCubeShader;


    GLuint    vertexBuffer;
    GLuint    objectVertexArray;
    GLuint    lightVertexArray;


    glm::mat4 projection;
    glm::mat4 view;
    glm::mat4 modelObject;
    glm::mat4 modelLight;



    glm::vec3 lightAmbient;   // 环境光照的颜色
    glm::vec3 lightDiffuse;   // 漫反射光照
    glm::vec3 lightSpecular;  // 镜面光照

    glm::vec3 materialAmbient;  // 材质的颜色
    glm::vec3 materialDiffuse;  // 材质漫反射的颜色
    glm::vec3 materialSpecular; // 材质镜面光照的颜色
    float     materialShininess;// 影响镜面高光的散射/半径
};

