#pragma once
#include <string>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <stb_image.h>
#include <Shader.h>
#include <GL/glew.h>


class GLSL_PointSize_FragCoord {

public:

    GLSL_PointSize_FragCoord(std::string Vs, std::string Fs);
    ~GLSL_PointSize_FragCoord();

    void SetViewMatrix(glm::mat4& inViewMatrix);
    void SetProjectionMatrix(glm::mat4& inProjectionMatrix);

    void Draw();

private:
    GLuint VAO;
    GLuint VBO;

    Shader* pShader;

    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;
};

class GLSL_Block_FragDepth {
public:
    GLSL_Block_FragDepth(std::string Vs, std::string Fs,
        std::string texture1Path,
        std::string texture2Path,
        std::string texture3Path,
        std::string texture4Path);
    ~GLSL_Block_FragDepth();

    void SetViewMatrix(glm::mat4& inViewMatrix);
    void SetProjectionMatrix(glm::mat4& inProjectionMatrix);

    void Draw();
private:
    GLuint loadTexture(const char * path);
private:
    GLuint VAO;
    GLuint VBO;

    GLuint uniformBlockIndex;
    GLuint uboMatrices;

    Shader* pShader;

    GLuint texture1;
    GLuint texture2;
    GLuint texture3;
    GLuint texture4;

    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;
};