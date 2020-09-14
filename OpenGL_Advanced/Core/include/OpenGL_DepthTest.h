#pragma once
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <stb_image.h>
#include <Shader.h>
#include <GL/glew.h>

class DepthTest {

public:
    DepthTest(std::string vsPath, std::string fsPath, std::string image1Path, std::string image2Path);
    ~DepthTest();

    void SetCubeModel(glm::mat4& inCubeModel1, glm::mat4& inCubeModel2);
    void SetPlaneModel(glm::mat4& inPlaneModel);
    void SetView(glm::mat4& inView);
    void SetProjection(glm::mat4& inProjection);

    void Draw();
private:
    GLuint loadTexture(char const *path);
private:
    Shader* pShader;

    GLuint cubeVAO;
    GLuint cubeVBO;

    GLuint planeVAO;
    GLuint planeVBO;

    GLuint cubeTexture;
    GLuint floorTexture;

    glm::mat4 cubeModel1;
    glm::mat4 cubeModel2;
    glm::mat4 planeModel;
    glm::mat4 view;
    glm::mat4 projection;

};
