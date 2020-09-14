#pragma once
#include <string>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <stb_image.h>
#include <Shader.h>
#include <GL/glew.h>

class SkyBox {
public:
    SkyBox(std::string cubemapsVs, std::string cubemapsFs,
           std::string skyboxVs, std::string skyboxFs,
           std::string cubeImage, std::string skyboxRoot);
    ~SkyBox();

    void SetViewMatrix(glm::mat4& inViewMatrix);
    void SetProjectionMatrix(glm::mat4& inProjectionMatrix);
    void SetCameraPosition(glm::vec3& inCameraPosition);

    void Draw();
private:
    GLuint loadTexture(const char* path);
    GLuint loadCubemap(std::vector<std::string> faces, std::string root);
private:
    GLuint cubeVAO;
    GLuint cubeVBO;
    GLuint skyboxVAO;
    GLuint skyboxVBO;

    GLuint cubeTexture;
    GLuint cubemapTexture;

    Shader* pShader;
    Shader* pSkyboxShader;

    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;
    glm::vec3 cameraPosition;
};
