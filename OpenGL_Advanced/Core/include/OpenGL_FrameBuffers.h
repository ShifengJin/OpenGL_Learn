#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <string>

#include <Shader.h>
#include <stb_image.h>

class FrameBuffer {
public:
    FrameBuffer(int width, int height, std::string fbVs, std::string fbFs, std::string fbsVs, std::string fbsFs, std::string planeImagePath, std::string cubeImagePath);

    ~FrameBuffer();

    void SetProjectionMatrix(glm::mat4& inProjectionMatrix);
    void SetViewMatrix(glm::mat4& inViewMatrix);


    void Draw();

private:
    GLuint loadTexture(char const* path);
private:
    Shader* pShader;
    Shader* pScreenShader;
    int width, height;

    GLuint cubeVAO;
    GLuint cubeVBO;
    GLuint planeVAO;
    GLuint planeVBO;
    GLuint quadVAO;
    GLuint quadVBO;

    GLuint cubeTexture;
    GLuint floorTexture;

    GLuint framebuffer;
    GLuint textureColorbuffer;
    GLuint rbo;

    glm::mat4 projectionMatrix;
    glm::mat4 viewMatrix;

};
