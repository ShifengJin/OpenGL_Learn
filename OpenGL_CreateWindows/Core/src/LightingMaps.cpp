#include "LightingMaps.h"
#include "stb_image.h"

LightingMaps1::LightingMaps1()
{
    pLightingShader = new Shader("D:/WorkSpace/OpenGLWorkSpace/OpenGL_CreateWindows/Core/Shader/4.1.lighting_maps.vs", "D:/WorkSpace/OpenGLWorkSpace/OpenGL_CreateWindows/Core/Shader/4.1.lighting_maps.fs");
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

    diffuseMapTexture = loadTexture("D:/WorkSpace/OpenGLWorkSpace/container2.png");
}

LightingMaps1::~LightingMaps1()
{
    glDeleteTextures(1, &diffuseMapTexture);
    glDeleteVertexArrays(1, &cubeVAO);
    glDeleteVertexArrays(1, &lightCubeVAO);
    glDeleteBuffers(1, &VBO);
    delete pLightingShader;
    delete pLightCubeShader;
}

void LightingMaps1::DrawLight()
{
    pLightCubeShader->Use();
    pLightCubeShader->SetMat4("projection", glm::value_ptr(projectionMatrix));
    pLightCubeShader->SetMat4("view", glm::value_ptr(viewMatrix));
    pLightCubeShader->SetMat4("model", glm::value_ptr(lightModelMatrix));
    glBindVertexArray(lightCubeVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
    glUseProgram(0);
}

void LightingMaps1::DrawModel()
{
    pLightingShader->Use();
    pLightingShader->SetVec3("light.position", glm::value_ptr(lightPosition));
    pLightingShader->SetVec3("viewPos", glm::value_ptr(viewPos));
    pLightingShader->SetVec3("light.ambient", glm::value_ptr(lightAmbient));
    pLightingShader->SetVec3("light.diffuse", glm::value_ptr(lightDiffuse));
    pLightingShader->SetVec3("light.specular", glm::value_ptr(lightSpecular));
    pLightingShader->SetVec3("material.specular", glm::value_ptr(materialSpecular));
    pLightingShader->SetFloat("material.shininess", shininess);
    pLightingShader->SetInt("material.diffuse", 2);
    pLightingShader->SetMat4("projection", glm::value_ptr(projectionMatrix));
    pLightingShader->SetMat4("view", glm::value_ptr(viewMatrix));
    pLightingShader->SetMat4("model", glm::value_ptr(modelMatrix));

    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, diffuseMapTexture);

    glBindVertexArray(cubeVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    glBindVertexArray(0);
    glActiveTexture(0);
    glUseProgram(0);
}

void LightingMaps1::BindTextureToMaterialDiffuse()
{
    pLightingShader->Use();
    pLightingShader->SetInt("material.diffuse", materialDiffuse);
}

void LightingMaps1::SetLightPosition(glm::vec3 & inLightPosition)
{
    this->lightPosition = inLightPosition;
}

void LightingMaps1::SetViewPos(glm::vec3 & inViewPos)
{
    this->viewPos = inViewPos;
}

void LightingMaps1::SetLightAmbient(glm::vec3 & inLightAmbient)
{
    this->lightAmbient = inLightAmbient;
}

void LightingMaps1::SetLightDiffuse(glm::vec3 & inLightDiffuse)
{
    this->lightDiffuse = inLightDiffuse;
}

void LightingMaps1::SetLightSpecular(glm::vec3 & inLightSpecular)
{
    this->lightSpecular = inLightSpecular;
}

void LightingMaps1::SetMaterialSpecular(glm::vec3 & inMaterialSpecular)
{
    this->materialSpecular = inMaterialSpecular;
}

void LightingMaps1::SetShininess(float inShininess)
{
    this->shininess = inShininess;
}

void LightingMaps1::SetProjectionMatrix(glm::mat4 & inProjectionMatrix)
{
    this->projectionMatrix = inProjectionMatrix;
}

void LightingMaps1::SetViewMatrix(glm::mat4 & inViewMatrix)
{
    this->viewMatrix = inViewMatrix;
}

void LightingMaps1::SetModelMatrix(glm::mat4 & inModelMatrix)
{
    this->modelMatrix = inModelMatrix;
}

void LightingMaps1::SetLightModelMatrix(glm::mat4 & inLightModelMatrix)
{
    this->lightModelMatrix = inLightModelMatrix;
}

void LightingMaps1::SetMaterialDiffuse(int inMaterialDiffuse)
{
    this->materialDiffuse = inMaterialDiffuse;
}

GLuint LightingMaps1::loadTexture(char const * imagePath)
{
    GLuint textureID;

    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char* data = stbi_load(imagePath, &width, &height, &nrComponents, 0);
    if (data) {
        GLenum format;
        if (nrComponents == 1) {
            format = GL_RED;
        }
        else if (nrComponents == 3) {
            format = GL_RGB;
        }
        else if (nrComponents == 4) {
            format = GL_RGBA;
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
        std::cout << "Texture failed to load at path : " << imagePath << std::endl;
        stbi_image_free(data);
    }


    return textureID;
}


LightingMaps2::LightingMaps2()
{
    pLightingShader = new Shader("D:/WorkSpace/OpenGLWorkSpace/OpenGL_CreateWindows/Core/Shader/4.2.lighting_maps.vs", "D:/WorkSpace/OpenGLWorkSpace/OpenGL_CreateWindows/Core/Shader/4.2.lighting_maps.fs");
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

    diffuseMapTexture = loadTexture("D:/WorkSpace/OpenGLWorkSpace/container2.png");
    specularTexture = loadTexture("D:/WorkSpace/OpenGLWorkSpace/container2_specular.png");
    //specularTexture = loadTexture("D:/WorkSpace/OpenGLWorkSpace/lighting_maps_specular_color.png");
    
}

LightingMaps2::~LightingMaps2()
{
    glDeleteTextures(1, &diffuseMapTexture);
    glDeleteTextures(1, &specularTexture);
    glDeleteVertexArrays(1, &cubeVAO);
    glDeleteVertexArrays(1, &lightCubeVAO);
    glDeleteBuffers(1, &VBO);
    delete pLightingShader;
    delete pLightCubeShader;
}

void LightingMaps2::DrawLight()
{
    pLightCubeShader->Use();
    pLightCubeShader->SetMat4("projection", glm::value_ptr(projectionMatrix));
    pLightCubeShader->SetMat4("view", glm::value_ptr(viewMatrix));
    pLightCubeShader->SetMat4("model", glm::value_ptr(lightModelMatrix));
    glBindVertexArray(lightCubeVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
    glUseProgram(0);
}

void LightingMaps2::DrawModel()
{
    pLightingShader->Use();
    pLightingShader->SetVec3("light.position", glm::value_ptr(lightPosition));
    pLightingShader->SetVec3("viewPos", glm::value_ptr(viewPos));
    pLightingShader->SetVec3("light.ambient", glm::value_ptr(lightAmbient));
    pLightingShader->SetVec3("light.diffuse", glm::value_ptr(lightDiffuse));
    pLightingShader->SetVec3("light.specular", glm::value_ptr(lightSpecular));

    pLightingShader->SetFloat("material.shininess", shininess);
    pLightingShader->SetInt("material.diffuse", 0);
    pLightingShader->SetInt("material.specular", 1);
    pLightingShader->SetMat4("projection", glm::value_ptr(projectionMatrix));
    pLightingShader->SetMat4("view", glm::value_ptr(viewMatrix));
    pLightingShader->SetMat4("model", glm::value_ptr(modelMatrix));

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, diffuseMapTexture);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, specularTexture);

    glBindVertexArray(cubeVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    glBindVertexArray(0);
    glActiveTexture(0);
    glUseProgram(0);
}

void LightingMaps2::SetLightPosition(glm::vec3 & inLightPosition)
{
    this->lightPosition = inLightPosition;
}

void LightingMaps2::SetViewPos(glm::vec3 & inViewPos)
{
    this->viewPos = inViewPos;
}

void LightingMaps2::SetLightAmbient(glm::vec3 & inLightAmbient)
{
    this->lightAmbient = inLightAmbient;
}

void LightingMaps2::SetLightDiffuse(glm::vec3 & inLightDiffuse)
{
    this->lightDiffuse = inLightDiffuse;
}

void LightingMaps2::SetLightSpecular(glm::vec3 & inLightSpecular)
{
    this->lightSpecular = inLightSpecular;
}

void LightingMaps2::SetShininess(float inShininess)
{
    this->shininess = inShininess;
}

void LightingMaps2::SetProjectionMatrix(glm::mat4 & inProjectionMatrix)
{
    this->projectionMatrix = inProjectionMatrix;
}

void LightingMaps2::SetViewMatrix(glm::mat4 & inViewMatrix)
{
    this->viewMatrix = inViewMatrix;
}

void LightingMaps2::SetModelMatrix(glm::mat4 & inModelMatrix)
{
    this->modelMatrix = inModelMatrix;
}

void LightingMaps2::SetLightModelMatrix(glm::mat4 & inLightModelMatrix)
{
    this->lightModelMatrix = inLightModelMatrix;
}

GLuint LightingMaps2::loadTexture(char const * imagePath)
{
    GLuint textureID;

    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char* data = stbi_load(imagePath, &width, &height, &nrComponents, 0);
    if (data) {
        GLenum format;
        if (nrComponents == 1) {
            format = GL_RED;
        }
        else if (nrComponents == 3) {
            format = GL_RGB;
        }
        else if (nrComponents == 4) {
            format = GL_RGBA;
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
        std::cout << "Texture failed to load at path : " << imagePath << std::endl;
        stbi_image_free(data);
    }


    return textureID;
}
