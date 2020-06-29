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



    glm::vec3 lightAmbient;   // �������յ���ɫ
    glm::vec3 lightDiffuse;   // ���������
    glm::vec3 lightSpecular;  // �������

    glm::vec3 materialAmbient;  // ���ʵ���ɫ
    glm::vec3 materialDiffuse;  // �������������ɫ
    glm::vec3 materialSpecular; // ���ʾ�����յ���ɫ
    float     materialShininess;// Ӱ�쾵��߹��ɢ��/�뾶
};

