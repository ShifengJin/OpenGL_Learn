#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <string>

#include <Shader.h>
#include <stb_image.h>

class FaceCulling {
public:
    FaceCulling(std::string vsPath, std::string fsPath, std::string marblePath, std::string wallPath);
    ~FaceCulling();

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

    GLuint cubeTexture;
    GLuint floorTexture;
};