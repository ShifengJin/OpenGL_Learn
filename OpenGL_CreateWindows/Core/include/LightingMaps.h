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

    glm::vec3    lightPosition;          // ��Դ��λ��
    glm::vec3    viewPos;                // �����λ��

    glm::vec3    lightAmbient;           // ��Դ����ɫ
    glm::vec3    lightDiffuse;           // ��Դ���������ɫ
    glm::vec3    lightSpecular;          // ��Դ�Ծ��淴�����ɫ

    glm::vec3    materialSpecular;       // ���ʾ��淴�����ɫ
    float        shininess;              // ���

    glm::mat4    projectionMatrix;             // ͶӰ����
    glm::mat4    viewMatrix;                   // ��ͼ����
    glm::mat4    modelMatrix;                  // ģ�;���
    glm::mat4    lightModelMatrix;             // ��Դ����

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

    glm::vec3    lightPosition;          // ��Դ��λ��
    glm::vec3    viewPos;                // �����λ��

    glm::vec3    lightAmbient;           // ��Դ����ɫ
    glm::vec3    lightDiffuse;           // ��Դ���������ɫ
    glm::vec3    lightSpecular;          // ��Դ�Ծ��淴�����ɫ

    float        shininess;              // ���

    glm::mat4    projectionMatrix;             // ͶӰ����
    glm::mat4    viewMatrix;                   // ��ͼ����
    glm::mat4    modelMatrix;                  // ģ�;���
    glm::mat4    lightModelMatrix;             // ��Դ����

    GLuint       diffuseMapTexture;
    GLuint       specularTexture;

};
