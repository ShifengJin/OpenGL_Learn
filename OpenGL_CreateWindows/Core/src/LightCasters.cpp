#include <string>
#include "LightCasters.h"
#include "stb_image.h"

DirectionalLight::DirectionalLight()
{
    pLightingShader = new Shader("D:/WorkSpace/OpenGLWorkSpace/OpenGL_CreateWindows/Core/Shader/5.1.light_casters.vs", 
        "D:/WorkSpace/OpenGLWorkSpace/OpenGL_CreateWindows/Core/Shader/5.1.light_casters.fs");
    float vertices[] = {
        // positions          // normals           // texture coords
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
    };

    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(cubeVAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    diffuseMap = loadTexture("D:/WorkSpace/OpenGLWorkSpace/container2.png");
    specularMap = loadTexture("D:/WorkSpace/OpenGLWorkSpace/container2_specular.png");

    pLightingShader->SetInt("material.diffuse", 0);
    pLightingShader->SetInt("material.specular", 1);
}

DirectionalLight::~DirectionalLight()
{
    glDeleteTextures(1, &diffuseMap);
    glDeleteTextures(1, &specularMap);
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &cubeVAO);
    delete pLightingShader;
}

void DirectionalLight::SetLightDirection(glm::vec3 & inLightDirection)
{
    this->lightDirection = inLightDirection;
}

void DirectionalLight::SetLightAmbient(glm::vec3 & inLightAmbient)
{
    this->lightAmbient = inLightAmbient;
}

void DirectionalLight::SetLightDiffuse(glm::vec3 & inLightDiffuse)
{
    this->lightDiffuse = inLightDiffuse;
}

void DirectionalLight::SetLightSpecular(glm::vec3 & inLightSpecular)
{
    this->lightSpecular = inLightSpecular;
}

void DirectionalLight::SetCameraPosition(glm::vec3 & inCameraPosition)
{
    this->cameraPosition = inCameraPosition;
}

void DirectionalLight::SetProjection(glm::mat4 & inProjection)
{
    this->projection = inProjection;
}

void DirectionalLight::SetView(glm::mat4 & inView)
{
    this->view = inView;
}

void DirectionalLight::SetModel(glm::mat4 & inModel)
{
    this->model = inModel;
}

void DirectionalLight::DrawInit()
{
    pLightingShader->Use();

    pLightingShader->SetVec3("viewPos", glm::value_ptr(cameraPosition));

    pLightingShader->SetVec3("light.direction", glm::value_ptr(lightDirection));
    pLightingShader->SetVec3("light.ambient", glm::value_ptr(lightAmbient));
    pLightingShader->SetVec3("light.diffuse", glm::value_ptr(lightDiffuse));
    pLightingShader->SetVec3("light.specular", glm::value_ptr(lightSpecular));

    pLightingShader->SetFloat("material.shininess", 32.f);

    pLightingShader->SetMat4("projection", glm::value_ptr(projection));
    pLightingShader->SetMat4("view", glm::value_ptr(view));

    pLightingShader->SetInt("material.diffuse", 0);
    pLightingShader->SetInt("material.specular", 1);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, diffuseMap);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, specularMap);

    glBindVertexArray(cubeVAO);
}

void DirectionalLight::Draw()
{
    pLightingShader->SetMat4("model", glm::value_ptr(model));
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

GLuint DirectionalLight::loadTexture(char const * path)
{
    GLuint textureID;

    glGenTextures(1, &textureID);

    int width, height, nrComponents;

    unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data) {
        GLenum format;
        switch (nrComponents) {
        case 1:
            format = GL_RED;
            break;
        case 3:
            format = GL_RGB;
            break;
        case 4:
            format = GL_RGBA;
            break;
        }

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        stbi_image_free(data);
    }
    else {
        std::cout << "Texture failed to load at path : " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}

PointLight::PointLight()
{
    pLightingShader = new Shader("D:/WorkSpace/OpenGLWorkSpace/OpenGL_CreateWindows/Core/Shader/5.2.light_casters.vs",
        "D:/WorkSpace/OpenGLWorkSpace/OpenGL_CreateWindows/Core/Shader/5.2.light_casters.fs");

    pLightCubeShader = new Shader("D:/WorkSpace/OpenGLWorkSpace/OpenGL_CreateWindows/Core/Shader/1.light_cube.vs",
        "D:/WorkSpace/OpenGLWorkSpace/OpenGL_CreateWindows/Core/Shader/1.light_cube.fs");


    float vertices[] = {
        // positions          // normals           // texture coords
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
    };

    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(cubeVAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glGenVertexArrays(1, &lightCubeVAO);
    glBindVertexArray(lightCubeVAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    diffuseMap = loadTexture("D:/WorkSpace/OpenGLWorkSpace/container2.png");
    specularMap = loadTexture("D:/WorkSpace/OpenGLWorkSpace/container2_specular.png");

    pLightingShader->SetInt("material.diffuse", 0);
    pLightingShader->SetInt("material.specular", 1);
}

PointLight::~PointLight()
{
    glDeleteTextures(1, &diffuseMap);
    glDeleteTextures(1, &specularMap);
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &lightCubeVAO);
    glDeleteVertexArrays(1, &cubeVAO);
    delete pLightingShader;
    delete pLightCubeShader;
}

void PointLight::SetLightPosition(glm::vec3 & inLightPosition)
{
    this->lightPosition = inLightPosition;
}

void PointLight::SetLightAmbient(glm::vec3 & inLightAmbient)
{
    this->lightAmbient = inLightAmbient;
}

void PointLight::SetLightDiffuse(glm::vec3 & inLightDiffuse)
{
    this->lightDiffuse = inLightDiffuse;
}

void PointLight::SetLightSpecular(glm::vec3 & inLightSpecular)
{
    this->lightSpecular = inLightSpecular;
}

void PointLight::SetLightParameter(float inLightConstant, float inLightLinear, float inLightQuadratic)
{
    this->lightConstant = inLightConstant;
    this->lightLinear = inLightLinear;
    this->lightQuadratic = inLightQuadratic;
}

void PointLight::SetCameraPosition(glm::vec3 & inCameraPosition)
{
    this->cameraPosition = inCameraPosition;
}

void PointLight::SetProjection(glm::mat4 & inProjection)
{
    this->projection = inProjection;
}

void PointLight::SetView(glm::mat4 & inView)
{
    this->view = inView;
}

void PointLight::SetLightModel(glm::mat4 & inLightModel)
{
    this->lightModel = inLightModel;
}

void PointLight::SetModel(glm::mat4 & inModel)
{
    this->model = inModel;
}

void PointLight::DrawInit()
{
    pLightingShader->Use();

    pLightingShader->SetVec3("viewPos", glm::value_ptr(cameraPosition));

    pLightingShader->SetVec3("light.position", glm::value_ptr(lightPosition));
    pLightingShader->SetVec3("light.ambient", glm::value_ptr(lightAmbient));
    pLightingShader->SetVec3("light.diffuse", glm::value_ptr(lightDiffuse));
    pLightingShader->SetVec3("light.specular", glm::value_ptr(lightSpecular));

    pLightingShader->SetFloat("light.constant", lightConstant);
    pLightingShader->SetFloat("light.linear", lightLinear);
    pLightingShader->SetFloat("light.quadratic", lightQuadratic);

    pLightingShader->SetFloat("material.shininess", 32.f);

    pLightingShader->SetMat4("projection", glm::value_ptr(projection));
    pLightingShader->SetMat4("view", glm::value_ptr(view));

    pLightingShader->SetInt("material.diffuse", 0);
    pLightingShader->SetInt("material.specular", 1);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, diffuseMap);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, specularMap);

    glBindVertexArray(cubeVAO);
}

void PointLight::Draw()
{
    pLightingShader->SetMat4("model", glm::value_ptr(model));
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

void PointLight::DrawLight()
{
    pLightCubeShader->Use();
    pLightCubeShader->SetMat4("projection", glm::value_ptr(projection));
    pLightCubeShader->SetMat4("view", glm::value_ptr(view));
    pLightCubeShader->SetMat4("model", glm::value_ptr(lightModel));
    glBindVertexArray(lightCubeVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

GLuint PointLight::loadTexture(char const * path)
{
    GLuint textureID;

    glGenTextures(1, &textureID);

    int width, height, nrComponents;

    unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data) {
        GLenum format;
        switch (nrComponents) {
        case 1:
            format = GL_RED;
            break;
        case 3:
            format = GL_RGB;
            break;
        case 4:
            format = GL_RGBA;
            break;
        }

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        stbi_image_free(data);
    }
    else {
        std::cout << "Texture failed to load at path : " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}


SpotLight::SpotLight()
{
#if 0
    pLightingShader = new Shader(
        "D:/WorkSpace/OpenGLWorkSpace/OpenGL_CreateWindows/Core/Shader/5.3.light_casters.vs",
        "D:/WorkSpace/OpenGLWorkSpace/OpenGL_CreateWindows/Core/Shader/5.3.light_casters.fs");
#else
    pLightingShader = new Shader(
        "D:/WorkSpace/OpenGLWorkSpace/OpenGL_CreateWindows/Core/Shader/5.4.light_casters.vs",
        "D:/WorkSpace/OpenGLWorkSpace/OpenGL_CreateWindows/Core/Shader/5.4.light_casters.fs");
#endif
    pLightCubeShader = new Shader(
        "D:/WorkSpace/OpenGLWorkSpace/OpenGL_CreateWindows/Core/Shader/1.light_cube.vs",
        "D:/WorkSpace/OpenGLWorkSpace/OpenGL_CreateWindows/Core/Shader/1.light_cube.fs");


    float vertices[] = {
        // positions          // normals           // texture coords
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
    };

    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(cubeVAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glGenVertexArrays(1, &lightCubeVAO);
    glBindVertexArray(lightCubeVAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    diffuseMap = loadTexture("D:/WorkSpace/OpenGLWorkSpace/container2.png");
    specularMap = loadTexture("D:/WorkSpace/OpenGLWorkSpace/container2_specular.png");

    pLightingShader->SetInt("material.diffuse", 0);
    pLightingShader->SetInt("material.specular", 1);
}

SpotLight::~SpotLight()
{
    glDeleteTextures(1, &diffuseMap);
    glDeleteTextures(1, &specularMap);
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &lightCubeVAO);
    glDeleteVertexArrays(1, &cubeVAO);
    delete pLightingShader;
    delete pLightCubeShader;
}

void SpotLight::SetLightPosition(glm::vec3 & inLightPosition)
{
    this->lightPosition = inLightPosition;
}

void SpotLight::SetLightAmbient(glm::vec3 & inLightAmbient)
{
    this->lightAmbient = inLightAmbient;
}

void SpotLight::SetLightDiffuse(glm::vec3 & inLightDiffuse)
{
    this->lightDiffuse = inLightDiffuse;
}

void SpotLight::SetLightSpecular(glm::vec3 & inLightSpecular)
{
    this->lightSpecular = inLightSpecular;
}

void SpotLight::SetLightDirection(glm::vec3 & inLightDirection)
{
    this->lightDirection = inLightDirection;
}

void SpotLight::SetLightParameter(float inLightConstant, float inLightLinear, float inLightQuadratic)
{
    this->lightConstant = inLightConstant;
    this->lightLinear = inLightLinear;
    this->lightQuadratic = inLightQuadratic;
}

void SpotLight::SetLightCutOff(float inLightCutOff)
{
    this->lightCutOff = inLightCutOff;
}

void SpotLight::SetLightOuterCutOff(float inLightOuterCutOff)
{
    this->lightOuterCutOff = inLightOuterCutOff;
}

void SpotLight::SetCameraPosition(glm::vec3 & inCameraPosition)
{
    this->cameraPosition = inCameraPosition;
}

void SpotLight::SetProjection(glm::mat4 & inProjection)
{
    this->projection = inProjection;
}

void SpotLight::SetView(glm::mat4 & inView)
{
    this->view = inView;
}

void SpotLight::SetLightModel(glm::mat4 & inLightModel)
{
    this->lightModel = inLightModel;
}

void SpotLight::SetModel(glm::mat4 & inModel)
{
    this->model = inModel;
}

void SpotLight::DrawInit()
{
    pLightingShader->Use();

    pLightingShader->SetVec3("viewPos", glm::value_ptr(cameraPosition));

    pLightingShader->SetVec3("light.position", glm::value_ptr(lightPosition));
    pLightingShader->SetVec3("light.direction", glm::value_ptr(lightDirection));
    pLightingShader->SetFloat("light.cutOff", lightCutOff);
    pLightingShader->SetFloat("light.outerCutOff", lightOuterCutOff);

    pLightingShader->SetVec3("light.ambient", glm::value_ptr(lightAmbient));
    pLightingShader->SetVec3("light.diffuse", glm::value_ptr(lightDiffuse));
    pLightingShader->SetVec3("light.specular", glm::value_ptr(lightSpecular));

    pLightingShader->SetFloat("light.constant", lightConstant);
    pLightingShader->SetFloat("light.linear", lightLinear);
    pLightingShader->SetFloat("light.quadratic", lightQuadratic);

    pLightingShader->SetFloat("material.shininess", 32.f);

    pLightingShader->SetMat4("projection", glm::value_ptr(projection));
    pLightingShader->SetMat4("view", glm::value_ptr(view));

    pLightingShader->SetInt("material.diffuse", 0);
    pLightingShader->SetInt("material.specular", 1);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, diffuseMap);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, specularMap);

    glBindVertexArray(cubeVAO);
}

void SpotLight::Draw()
{
    pLightingShader->SetMat4("model", glm::value_ptr(model));
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

void SpotLight::DrawLight()
{
    pLightCubeShader->Use();
    pLightCubeShader->SetMat4("projection", glm::value_ptr(projection));
    pLightCubeShader->SetMat4("view", glm::value_ptr(view));
    pLightCubeShader->SetMat4("model", glm::value_ptr(lightModel));
    glBindVertexArray(lightCubeVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

GLuint SpotLight::loadTexture(char const * path)
{
    GLuint textureID;

    glGenTextures(1, &textureID);

    int width, height, nrComponents;

    unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data) {
        GLenum format;
        switch (nrComponents) {
        case 1:
            format = GL_RED;
            break;
        case 3:
            format = GL_RGB;
            break;
        case 4:
            format = GL_RGBA;
            break;
        }

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        stbi_image_free(data);
    }
    else {
        std::cout << "Texture failed to load at path : " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}

MultipleLight::MultipleLight(std::string diffuseImagePath, std::string specularImagePath, MULTIPLELIGHTTYPE type)
{
    cubePositions[0] = glm::vec3(0.0f, 0.0f, 0.0f);
    cubePositions[1] = glm::vec3(2.0f, 5.0f, -15.0f);
    cubePositions[2] = glm::vec3(-1.5f, -2.2f, -2.5f);
    cubePositions[3] = glm::vec3(-3.8f, -2.0f, -12.3f);
    cubePositions[4] = glm::vec3(2.4f, -0.4f, -3.5f);
    cubePositions[5] = glm::vec3(-1.7f, 3.0f, -7.5f);
    cubePositions[6] = glm::vec3(1.3f, -2.0f, -2.5f);
    cubePositions[7] = glm::vec3(1.5f, 2.0f, -2.5f);
    cubePositions[8] = glm::vec3(1.5f, 0.2f, -1.5f);
    cubePositions[9] = glm::vec3(-1.3f, 1.0f, -1.5f);

    pointLightPositions[0] = glm::vec3(0.7f, 0.2f, 2.0f);
    pointLightPositions[1] = glm::vec3(2.3f, -3.3f, -4.0f);
    pointLightPositions[2] = glm::vec3(-4.0f, 2.0f, -12.0f);
    pointLightPositions[3] = glm::vec3(0.0f, 0.0f, -3.0f);

    
    switch (type) {
        case MULTIPLELIGHT_SRC: {
            // dirLight
            mMultipleLightParameter[MULTIPLELIGHT_SRC].clearColor = glm::vec4(0.f, 0.f, 0.f, 0.f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mDirLight.direction = glm::vec3(-0.2f, -1.0f, -0.3f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mDirLight.ambient = glm::vec3(0.05f, 0.05f, 0.05f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mDirLight.diffuse = glm::vec3(0.4f, 0.4f, 0.4f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mDirLight.specular = glm::vec3(0.5f, 0.5f, 0.5f);
            // spotLight
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.ambient = glm::vec3(0.0f, 0.0f, 0.0f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.diffuse = glm::vec3(1.0f, 1.0f, 1.0f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.specular = glm::vec3(1.0f, 1.0f, 1.0f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.constant = 1.f;
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.linear = 0.09f;
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.quadratic = 0.032f;
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.cutOff = glm::cos(glm::radians(12.5f));
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.outerCutOff = glm::cos(glm::radians(15.0f));

            // point light
            pointLightColors[0] = glm::vec3(1.f, 1.f, 1.f);
            pointLightColors[1] = glm::vec3(1.f, 1.f, 1.f);
            pointLightColors[2] = glm::vec3(1.f, 1.f, 1.f);
            pointLightColors[3] = glm::vec3(1.f, 1.f, 1.f);
            for (int i = 0; i < NR_POINT_LIGHTS; ++i) {
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].position = pointLightPositions[i];
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].ambient = glm::vec3(0.05f, 0.05f, 0.05f);
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].diffuse = glm::vec3(0.8f, 0.8f, 0.8f);
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].specular = glm::vec3(1.0f, 1.0f, 1.0f);
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].constant = 1.f;
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].linear = 0.09f;
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].quadratic = 0.032f;
            }
        }; break;
        case MULTIPLELIGHT_DESERT: {
            // dirLight
            mMultipleLightParameter[MULTIPLELIGHT_SRC].clearColor = glm::vec4(0.75f, 0.52f, 0.3f, 1.0f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mDirLight.direction = glm::vec3(-0.2f, -1.0f, -0.3f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mDirLight.ambient = glm::vec3(0.3f, 0.24f, 0.14f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mDirLight.diffuse = glm::vec3(0.7f, 0.42f, 0.26f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mDirLight.specular = glm::vec3(0.5f, 0.5f, 0.5f);

            // spotLight
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.ambient = glm::vec3(0.0f, 0.0f, 0.0f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.diffuse = glm::vec3(0.8f, 0.8f, 0.0f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.specular = glm::vec3(0.8f, 0.8f, 0.0f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.constant = 1.f;
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.linear = 0.09f;
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.quadratic = 0.032f;
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.cutOff = glm::cos(glm::radians(12.5f));
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.outerCutOff = glm::cos(glm::radians(13.0f));
            pointLightColors[0] = glm::vec3(1.0f, 0.6f, 0.0f);
            pointLightColors[1] = glm::vec3(1.0f, 0.0f, 0.0f);
            pointLightColors[2] = glm::vec3(1.0f, 1.0, 0.0);
            pointLightColors[3] = glm::vec3(0.2f, 0.2f, 1.0f);
            // point light
            for (int i = 0; i < NR_POINT_LIGHTS; ++i) {
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].position = pointLightPositions[i];
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].ambient = pointLightColors[i] * 0.1f;
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].diffuse = pointLightColors[i];
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].specular = pointLightColors[i];
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].constant = 1.f;
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].linear = 0.09f;
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].quadratic = 0.032f;
            }
        }; break;
        case MULTIPLELIGHT_FACTORY: {
            // dirLight
            mMultipleLightParameter[MULTIPLELIGHT_SRC].clearColor = glm::vec4(0.1f, 0.1f, 0.1f, 1.0f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mDirLight.direction = glm::vec3(-0.2f, -1.0f, -0.3f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mDirLight.ambient = glm::vec3(0.05f, 0.05f, 0.1f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mDirLight.diffuse = glm::vec3(0.2f, 0.2f, 0.7f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mDirLight.specular = glm::vec3(0.7f, 0.7f, 0.7f);

            // spotLight
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.ambient = glm::vec3(0.0f, 0.0f, 0.0f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.diffuse = glm::vec3(1.0f, 1.0f, 1.0f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.specular = glm::vec3(1.0f, 1.0f, 1.0f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.constant = 1.f;
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.linear = 0.009f;
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.quadratic = 0.0032f;
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.cutOff = glm::cos(glm::radians(10.f));
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.outerCutOff = glm::cos(glm::radians(12.5f));

            pointLightColors[0] = glm::vec3(0.2f, 0.2f, 0.6f);
            pointLightColors[1] = glm::vec3(0.3f, 0.3f, 0.7f);
            pointLightColors[2] = glm::vec3(0.0f, 0.0f, 0.3f);
            pointLightColors[3] = glm::vec3(0.4f, 0.4f, 0.4f);
            // point light
            for (int i = 0; i < NR_POINT_LIGHTS; ++i) {
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].position = pointLightPositions[i];
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].ambient = pointLightColors[i] * 0.1f;
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].diffuse = pointLightColors[i];
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].specular = pointLightColors[i];
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].constant = 1.f;
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].linear = 0.09f;
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].quadratic = 0.032f;
            }
        }; break;
        case MULTIPLELIGHT_HORROR :{
            // dirLight
            mMultipleLightParameter[MULTIPLELIGHT_SRC].clearColor = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mDirLight.direction = glm::vec3(-0.2f, -1.0f, -0.3f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mDirLight.ambient = glm::vec3(0.0f, 0.0f, 0.0f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mDirLight.diffuse = glm::vec3(0.05f, 0.05f, 0.05);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mDirLight.specular = glm::vec3(0.2f, 0.2f, 0.2f);

            // spotLight
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.ambient = glm::vec3(0.0f, 0.0f, 0.0f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.diffuse = glm::vec3(1.0f, 1.0f, 1.0f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.specular = glm::vec3(1.0f, 1.0f, 1.0f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.constant = 1.f;
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.linear = 0.09f;
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.quadratic = 0.032f;
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.cutOff = glm::cos(glm::radians(10.f));
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.outerCutOff = glm::cos(glm::radians(15.f));
            
            pointLightColors[0] = glm::vec3(0.1f, 0.1f, 0.1f);
            pointLightColors[1] = glm::vec3(0.1f, 0.1f, 0.1f);
            pointLightColors[2] = glm::vec3(0.1f, 0.1f, 0.1f);
            pointLightColors[3] = glm::vec3(0.3f, 0.1f, 0.1f);

            // point light
            for (int i = 0; i < NR_POINT_LIGHTS; ++i) {
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].position = pointLightPositions[i];
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].ambient = pointLightColors[i] * 0.1f;
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].diffuse = pointLightColors[i];
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].specular = pointLightColors[i];
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].constant = 1.f;
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].linear = 0.14f;
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].quadratic = 0.07f;
            }
        }; break;
        case MULTIPLELIGHT_BIOCHEMICALLAB: {
            // dirLight
            mMultipleLightParameter[MULTIPLELIGHT_SRC].clearColor = glm::vec4(0.9f, 0.9f, 0.9f, 1.0f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mDirLight.direction = glm::vec3(-0.2f, -1.0f, -0.3f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mDirLight.ambient = glm::vec3(0.5f, 0.5f, 0.5f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mDirLight.diffuse = glm::vec3(1.0f, 1.0f, 1.0f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mDirLight.specular = glm::vec3(1.0f, 1.0f, 1.0f);

            // spotLight
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.ambient = glm::vec3(0.0f, 0.0f, 0.0f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.diffuse = glm::vec3(0.0f, 1.0f, 0.0f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.specular = glm::vec3(0.0f, 1.0f, 0.0f);
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.constant = 1.f;
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.linear = 0.07f;
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.quadratic = 0.017f;
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.cutOff = glm::cos(glm::radians(7.f));
            mMultipleLightParameter[MULTIPLELIGHT_SRC].mSpotLight.outerCutOff = glm::cos(glm::radians(10.f));
            
            pointLightColors[0] = glm::vec3(0.4f, 0.7f, 0.1f);
            pointLightColors[1] = glm::vec3(0.4f, 0.7f, 0.1f);
            pointLightColors[2] = glm::vec3(0.4f, 0.7f, 0.1f);
            pointLightColors[3] = glm::vec3(0.4f, 0.7f, 0.1f);

            // point light
            for (int i = 0; i < NR_POINT_LIGHTS; ++i) {
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].position = pointLightPositions[i];
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].ambient = pointLightColors[i] * 0.1f;
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].diffuse = pointLightColors[i];
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].specular = pointLightColors[i];
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].constant = 1.f;
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].linear = 0.07f;
                mMultipleLightParameter[MULTIPLELIGHT_SRC].mPointLights[i].quadratic = 0.017f;
            }
        }; break;
        default:
            break;
    }
    
    
    pLightingShader = new Shader(
            "D:/WorkSpace/OpenGLWorkSpace/OpenGL_CreateWindows/Core/Shader/5.5.light_casters.vs",
            "D:/WorkSpace/OpenGLWorkSpace/OpenGL_CreateWindows/Core/Shader/5.5.light_casters.fs");

    pLightCubeShader = new Shader(
        "D:/WorkSpace/OpenGLWorkSpace/OpenGL_CreateWindows/Core/Shader/5.4.light_cube.vs",
        "D:/WorkSpace/OpenGLWorkSpace/OpenGL_CreateWindows/Core/Shader/5.4.light_cube.fs"
    );
    float vertices[] = {
        // positions          // normals           // texture coords
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
    };
    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(cubeVAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glGenVertexArrays(1, &lightCubeVAO);
    glBindVertexArray(lightCubeVAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    diffuseMap = loadTexture(diffuseImagePath.c_str());
    specularMap = loadTexture(specularImagePath.c_str());

    pLightingShader->Use();
    pLightingShader->SetInt("material.diffuse", 0);
    pLightingShader->SetInt("material.specular", 1);
}

MultipleLight::~MultipleLight()
{
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &cubeVAO);
    glDeleteVertexArrays(1, &lightCubeVAO);

    glDeleteTextures(1, &specularMap);
    glDeleteTextures(1, &diffuseMap);

    delete pLightingShader;
    delete pLightCubeShader;
}

void MultipleLight::SetCameraPosition(glm::vec3 & cameraPosition)
{
    this->cameraPosition = cameraPosition;
    for(int i = 0; i < MULTIPLELIGHT_NUMBER; ++ i){
        mMultipleLightParameter[i].mSpotLight.position = cameraPosition;
    }
}

void MultipleLight::SetCameraFront(glm::vec3 & cameraFront)
{
    this->cameraFront = cameraFront;
    for (int i = 0; i < MULTIPLELIGHT_NUMBER; ++i) {
        mMultipleLightParameter[i].mSpotLight.direction = cameraFront;
    }
}

void MultipleLight::SetProjection(glm::mat4 & projection)
{
    this->projection = projection;
}

void MultipleLight::SetView(glm::mat4 & view)
{
    this->view = view;
}

void MultipleLight::Draw()
{
    glClearColor(
        mMultipleLightParameter[type].clearColor.x, mMultipleLightParameter[type].clearColor.y,
        mMultipleLightParameter[type].clearColor.z, mMultipleLightParameter[type].clearColor.w);

    pLightingShader->Use();
    pLightingShader->SetVec3("viewPos", glm::value_ptr(cameraPosition));
    pLightingShader->SetFloat("material.shininess", 32.f);

    pLightingShader->SetVec3("dirLight.direction", 
        glm::value_ptr(mMultipleLightParameter[type].mDirLight.direction));
    pLightingShader->SetVec3("dirLight.ambient", 
        glm::value_ptr(mMultipleLightParameter[type].mDirLight.ambient));
    pLightingShader->SetVec3("dirLight.diffuse", 
        glm::value_ptr(mMultipleLightParameter[type].mDirLight.diffuse));
    pLightingShader->SetVec3("dirLight.specular", 
        glm::value_ptr(mMultipleLightParameter[type].mDirLight.specular));

    for (int i = 0; i < NR_POINT_LIGHTS; ++i) {
        std::string numStr = std::to_string(i);
        std::string str1 = "pointLights[" + numStr + "].";
        std::string name = str1 + "position";
        pLightingShader->SetVec3(name, 
            glm::value_ptr(mMultipleLightParameter[type].mPointLights[i].position));

        name = str1 + "ambient";
        pLightingShader->SetVec3(name,
            glm::value_ptr(mMultipleLightParameter[type].mPointLights[i].ambient));

        name = str1 + "diffuse";
        pLightingShader->SetVec3(name,
            glm::value_ptr(mMultipleLightParameter[type].mPointLights[i].diffuse));

        name = str1 + "specular";
        pLightingShader->SetVec3(name,
            glm::value_ptr(mMultipleLightParameter[type].mPointLights[i].specular));

        name = str1 + "constant";
        pLightingShader->SetFloat(name,
            mMultipleLightParameter[type].mPointLights[i].constant);

        name = str1 + "linear";
        pLightingShader->SetFloat(name,
            mMultipleLightParameter[type].mPointLights[i].linear);

        name = str1 + "quadratic";
        pLightingShader->SetFloat(name,
            mMultipleLightParameter[type].mPointLights[i].quadratic);
    }
    
    // spotLight
    pLightingShader->SetVec3("spotLight.position", 
        glm::value_ptr(mMultipleLightParameter[type].mSpotLight.position));
    pLightingShader->SetVec3("spotLight.direction", 
        glm::value_ptr(mMultipleLightParameter[type].mSpotLight.direction));
    pLightingShader->SetVec3("spotLight.ambient", 
        glm::value_ptr(mMultipleLightParameter[type].mSpotLight.ambient));
    pLightingShader->SetVec3("spotLight.diffuse", 
        glm::value_ptr(mMultipleLightParameter[type].mSpotLight.diffuse));
    pLightingShader->SetVec3("spotLight.specular", 
        glm::value_ptr(mMultipleLightParameter[type].mSpotLight.specular));
    pLightingShader->SetFloat("spotLight.constant", 
        mMultipleLightParameter[type].mSpotLight.constant);
    pLightingShader->SetFloat("spotLight.linear", 
        mMultipleLightParameter[type].mSpotLight.linear);
    pLightingShader->SetFloat("spotLight.quadratic", 
        mMultipleLightParameter[type].mSpotLight.quadratic);
    pLightingShader->SetFloat("spotLight.cutOff", 
        mMultipleLightParameter[type].mSpotLight.cutOff);
    pLightingShader->SetFloat("spotLight.outerCutOff", 
        mMultipleLightParameter[type].mSpotLight.outerCutOff);



    pLightingShader->SetMat4("projection", glm::value_ptr(projection));
    pLightingShader->SetMat4("view", glm::value_ptr(view));

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, diffuseMap);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, specularMap);

    glBindVertexArray(cubeVAO);
    for (unsigned int i = 0; i < CUBENUMBER; ++i) {
        glm::mat4 model = glm::mat4(1.f);
        model = glm::translate(model, cubePositions[i]);
        float angle = 20.f * i;
        model = glm::rotate(model, glm::radians(angle), glm::vec3(1.f, 0.3f, 0.5f));
        pLightingShader->SetMat4("model", glm::value_ptr(model));
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }

    pLightCubeShader->Use();
    pLightCubeShader->SetMat4("projection", glm::value_ptr(projection));
    pLightCubeShader->SetMat4("view", glm::value_ptr(view));

    glBindVertexArray(lightCubeVAO);
    for (unsigned int i = 0; i < NR_POINT_LIGHTS; ++i) {
        pLightCubeShader->SetVec3("aColor", glm::value_ptr(pointLightColors[i]));
        glm::mat4 model = glm::mat4(1.f);
        model = glm::translate(model, pointLightPositions[i]);
        model = glm::scale(model, glm::vec3(0.2f));
        pLightCubeShader->SetMat4("model", glm::value_ptr(model));
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
}

GLuint MultipleLight::loadTexture(char const * path)
{
    GLuint textureID;

    glGenTextures(1, &textureID);

    int width, height, nrComponents;

    unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data) {
        GLenum format;
        switch (nrComponents) {
        case 1:
            format = GL_RED;
            break;
        case 3:
            format = GL_RGB;
            break;
        case 4:
            format = GL_RGBA;
            break;
        }

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        stbi_image_free(data);
    }
    else {
        std::cout << "Texture failed to load at path : " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}