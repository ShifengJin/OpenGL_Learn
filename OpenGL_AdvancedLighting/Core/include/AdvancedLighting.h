#pragma once
#include <iostream>
#include <string>
#include "Shader.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class AdvancedLighting {
public:
    AdvancedLighting() {

    }
    AdvancedLighting(std::string vs, std::string fs, std::string texturePath);
    virtual ~AdvancedLighting();

    void SetProjection(glm::mat4& inProjection);
    void SetView(glm::mat4& inView);
    void SetCameraPosition(glm::vec3& inCameraPosition);
    void SetLightPos(glm::vec3& inLightPos);
    void SetBlinn(int inBlinn);

    void Draw();
protected:
    GLuint loadTexture(std::string texturePath);
protected:
    Shader* pShader;

    GLuint planeVAO;
    GLuint planeVBO;

    GLuint floorTexture;

    glm::mat4 projection;
    glm::mat4 view;
    glm::vec3 cameraPosition;
    glm::vec3 lightPos;
    int       blinn;
};

class GammaCorrection : public AdvancedLighting
{
public:
    GammaCorrection(std::string vs, std::string fs, std::string texturePath);
    ~GammaCorrection();

    void SetEnableGamma(bool isGammaEnable);

    void Draw();

private:
    GLuint loadTexture(char const * path, bool gammaCorrection);

private:
    glm::vec3 lightPositions[4];
    glm::vec3 lightColors[4];

    GLuint floorTextureGammaCorrected;

    bool gammaEnabled = false;
};