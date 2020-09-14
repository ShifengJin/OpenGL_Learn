#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <string>

#include <Shader.h>
#include <stb_image.h>

class Blending {
public:
    Blending(std::string vsPath, std::string fsPath, std::string marblePath, std::string metalPath, std::string grassPath);
    ~Blending();

    void SetProjectionMatrix(glm::mat4& inProjectionMatrix);
    void SetViewMatrix(glm::mat4& inViewMatrix);

    void Draw();

private:
    GLuint loadTexture(char const* path);


private:

    Shader* pShader;

    glm::mat4 projectionMatrix;
    glm::mat4 viewMatrix;


    GLuint cubeVAO, cubeVBO;
    GLuint planeVAO, planeVBO;
    GLuint transparentVAO, transparentVBO;

    GLuint cubeTexture;
    GLuint floorTexture;
    GLuint transparentTexture;
};


class BlendingSorted {
public:
    BlendingSorted(std::string vsPath, std::string fsPath, std::string marblePath, std::string metalPath, std::string windowPath);
    ~BlendingSorted();

    void SetProjectionMatrix(glm::mat4& inProjectionMatrix);
    void SetViewMatrix(glm::mat4& inViewMatrix);

    void Draw(glm::vec3& cameraPosition);

private:
    GLuint loadTexture(char const* path);


private:

    Shader* pShader;

    glm::mat4 projectionMatrix;
    glm::mat4 viewMatrix;


    GLuint cubeVAO, cubeVBO;
    GLuint planeVAO, planeVBO;
    GLuint transparentVAO, transparentVBO;

    GLuint cubeTexture;
    GLuint floorTexture;
    GLuint transparentTexture;
};
