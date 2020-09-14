#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <stb_image.h>
#include <Shader.h>
#include <Model.h>
#include <GL/glew.h>

class Instancing {
public:
    Instancing(std::string vs, std::string fs);
    ~Instancing();

    void Draw();

private:
    Shader* pShader;
    GLuint instanceVBO;
    GLuint quadVAO, quadVBO;
};

class InstancingAsteroids {
public:
    InstancingAsteroids(std::string vs, std::string fs,
        std::string modelRockPath, std::string modelPlanetPath);

    ~InstancingAsteroids();

    void SetProjection(glm::mat4& inProjection);
    void SetView(glm::mat4& inView);
    void Draw();

private:
    glm::mat4 projection;
    glm::mat4 view;
    int amount = 1000;
    glm::mat4* modelMatrices;

    Shader* pShader;
    Model* pPlanetModel;
    Model* pRockModel;
};

class AsteroidsInstanced {
public:
    AsteroidsInstanced(std::string asteroidsVs, std::string asteroidsFs,
        std::string planetVs, std::string planetFs,
        std::string rockPath, std::string planetPath);
    ~AsteroidsInstanced();

    void SetProjection(glm::mat4& inProjection);
    void SetView(glm::mat4& inView);

    void Draw();

private:
    glm::mat4 projection;
    glm::mat4 view;

    int amount = 100000;
    glm::mat4* modelMatrices;

    Shader* pAsteroidShader;
    Shader* pPlanetShader;
    Model* pRockModel;
    Model* pPlanetModel;

    GLuint buffer;

};
