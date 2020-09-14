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

class ShadowMappingBase {
public:
    ShadowMappingBase(int viewWidth, int viewHeight);
    ~ShadowMappingBase();

    void SetLightProjection(glm::mat4& inLightProjection) {
        lightProjection = inLightProjection;
    }
    void SetLightView(glm::mat4& inLightView) {
        lightView = inLightView;
    }
    void SetProjection(glm::mat4& inProjection) {
        projection = inProjection;
    }
    void SetView(glm::mat4& inView) {
        view = inView;
    }
    void SetCameraPosition(glm::vec3& inCameraPosition) {
        cameraPosition = inCameraPosition;
    }
    void SetLightPos(glm::vec3& inLightPos) {
        lightPos = inLightPos;
    }
    void SetNearFar(float inNear, float inFar) {
        near_plane = inNear;
        far_plane = inFar;
    }
    void SetShadowSize(int inShadowWidth, int inShadowHeight) {
        shadowWidth = inShadowWidth;
        shadowHeight = inShadowHeight;
    }
    void Draw();
private:
    void renderCube();
    void renderQuad();
    void renderScene(Shader* inpShader);
    GLuint loadTexture(char const* path);
private:
    Shader* pShader;
    Shader* pSimpleDepthShader;
    Shader* pDebugDepthQuad;

    GLuint planeVAO, planeVBO;
    GLuint woodTexture;
    GLuint cubeVAO, cubeVBO;
    GLuint quadVAO, quadVBO;

    GLuint depthMapFBO, depthMap;
    int shadowWidth, shadowHeight;
    int srcWidth, srcHeight;

    glm::mat4 lightProjection;
    glm::mat4 lightView;

    glm::mat4 projection;
    glm::mat4 view;
    glm::vec3 cameraPosition;
    glm::vec3 lightPos;

    float near_plane, far_plane;
};

