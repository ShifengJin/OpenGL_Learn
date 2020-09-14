#pragma once

#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <stb_image.h>
#include <Shader.h>
#include <GL/glew.h>


class StencilTesting {

public:
    StencilTesting(std::string stencilVs, std::string stencilFs,
        std::string singleColorVs, std::string singleColorFs,
        std::string image1Path, std::string image2Path);

    ~StencilTesting();

    void SetView(glm::mat4& inView);
    void SetProjection(glm::mat4& inProjection);

    void SetCubeModel(glm::mat4& inCubeModel1, glm::mat4& inCubeModel2);
    void SetFloorModel(glm::mat4& inFloorModel);

    void DrawModel();
    void DrawStencil();

private:
    GLuint loadTexture(char const * path);

private:
    Shader *pStencilShader;
    Shader *pSingleColorShader;

    GLuint cubeVAO;
    GLuint cubeVBO;
    GLuint planeVAO;
    GLuint planeVBO;

    GLuint cubeTexture;
    GLuint floorTexture;

    glm::mat4 view;
    glm::mat4 projection;

    glm::mat4 floorModel;
    glm::mat4 cubeModel1;
    glm::mat4 cubeModel2;


};

