#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <Shader.h>

class AntiAliasingMsaa {
public:
    AntiAliasingMsaa(std::string Vs, std::string Fs);
    ~AntiAliasingMsaa();

    void SetProjection(glm::mat4& inProjection);
    void SetView(glm::mat4& inView);

    void Draw();

private:
    Shader* pShader;

    GLuint cubeVAO;
    GLuint cubeVBO;
    glm::mat4 projection;
    glm::mat4 view;
};

class AntiAliasingOffscreen {
public:
    AntiAliasingOffscreen(std::string antiAliasingVs, std::string antiAliasingFs,
                          std::string postVs, std::string postFs, int width, int height);
    ~AntiAliasingOffscreen();

    void SetProjection(glm::mat4& inProjection);
    void SetView(glm::mat4& inView);

    void Draw();
private:

    glm::mat4 projection;
    glm::mat4 view;

    GLuint cubeVAO;
    GLuint cubeVBO;

    GLuint quadVAO;
    GLuint quadVBO;

    GLuint framebuffer;
    GLuint textureColorBufferMultiSampled;
    GLuint rbo;

    GLuint intermediateFBO;
    GLuint screenTexture;

    Shader* pShader;
    Shader* pScreenShader;

    int mWidth, mHeight;
};