#pragma once
#include <iostream>
#include <string>
#include "Shader.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class ShadowMappingDepth {
public:

    ShadowMappingDepth(std::string shadowMappingDepthVS, std::string shadowMappingDepthFS,
        std::string debugQuadVS, std::string debugQuadFS,
        std::string texturePath,
        int inShadowWidth, int inShadowHeight, int inSrcWidth, int inSrcHeight);
    ~ShadowMappingDepth();

    void SetNearFarPlane(float inNear, float inFar);
    void SetLightPos(glm::vec3 & inLightPos);
    void SetLightProjection(glm::mat4& inLightProjection);
    void SetLightView(glm::mat4& inLightView);

    void Draw();
private:
    GLuint loadTexture(const char* path);
    void renderScene(Shader* pShader);
    void renderCube();
    void renderQuad();
private:
    Shader* pSimpleDepthShader;
    Shader* pDebugDepthQuad;

    GLuint planeVBO;
    GLuint planeVAO;
    GLuint texture;

    GLuint cubeVAO = 0;
    GLuint cubeVBO = 0;
    GLuint quadVAO = 0;
    GLuint quadVBO = 0;

    GLuint depthMap;
    GLuint depthMapFBO;

    glm::vec3 lightPos;
    glm::mat4 lightProjection, lightView;
    glm::mat4 lightSpaceMatrix;
    float nearPlane, farPlane;

    int srcWidth, srcHeight;
    int shadowWidth, shadowHeight;
};

class Shadow {
public:
    Shadow(int inShadowWidth, int inShadowHeight, int inSrcWidth, int inSrcHeight);
    void Draw();
    ~Shadow();

    void SetLightProjection(glm::mat4& inLightProjection) { lightProjection = inLightProjection; }
    void SetLightView(glm::mat4& inLightView) { lightView = inLightView; }
    void SetProjection(glm::mat4& inProjection) { projection = inProjection; }
    void SetView(glm::mat4& inView) { view = inView; }
    void SetCameraPosition(glm::vec3& inCameraPosition) { cameraPosition = inCameraPosition; }
    void SetLightPos(glm::vec3& inLightPos) { lightPos = inLightPos; }
    void SetNearFar(float nearV, float farV) { near_plane = nearV; far_plane = farV; }

private:

    GLuint loadTexture(const char* path);
    void renderScene(Shader *shader);
    void renderCube();
    void renderQuad();

private:

    int shadowWidth, shadowHeight;
    int srcWidth, srcHeight;

    Shader* pShader;
    Shader* pSimpleDepthShader;
    Shader* pDebugDepthQuad;

    GLuint planeVAO;
    GLuint planeVBO;
    GLuint woodTexture;
    GLuint depthMapFBO;
    GLuint depthMap;

    unsigned int cubeVAO = 0;
    unsigned int cubeVBO = 0;
    unsigned int quadVAO = 0;
    unsigned int quadVBO;

    glm::mat4 lightProjection;
    glm::mat4 lightView;
    glm::mat4 projection;
    glm::mat4 view;
    glm::vec3 cameraPosition;
    glm::vec3 lightPos;
    glm::mat4 lightSpaceMatrix;
    float near_plane;
    float far_plane;
};