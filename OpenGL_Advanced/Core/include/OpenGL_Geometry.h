#pragma once

#include <string>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <stb_image.h>
#include <Shader.h>
#include <Model.h>
#include <GL/glew.h>

class Geometry {
public:
    Geometry(std::string vs, std::string gs, std::string fs);
    ~Geometry();

    void Draw();


private:
    GLuint VAO, VBO;
    Shader* pShader;
};

class GeometryShaderExploding {
public:
    GeometryShaderExploding(std::string vs,
        std::string gs, std::string fs, std::string modelPath);
    ~GeometryShaderExploding();

    void SetProjection(glm::mat4& inProjection);
    void SetView(glm::mat4& inView);
    void SetModel(glm::mat4& inModel);

    void SetTime(float inTime);

    void Draw();

private:
    Shader* pShader;
    Model*  pModel;

    glm::mat4 projection;
    glm::mat4 view;
    glm::mat4 model;
    float time;
};

class GeometryShaderNormals {
public:
    GeometryShaderNormals(std::string defaultVs, std::string defaultFs,
        std::string normalVisualizationVs, 
        std::string normalVisualizationFs,
        std::string normalVisualizationGs,
        std::string modelPath);
    ~GeometryShaderNormals();

    void SetProjection(glm::mat4& inProjection);
    void SetView(glm::mat4& inView);
    void SetModel(glm::mat4& inModel);

    void Draw();

private:
    glm::mat4 projection;
    glm::mat4 view;
    glm::mat4 model;

    Shader* pShader;
    Shader* pNormalShader;
    Model* pModel;
};

