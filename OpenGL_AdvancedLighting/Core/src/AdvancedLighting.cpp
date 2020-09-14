#include "AdvancedLighting.h"
#include "stb_image.h"

AdvancedLighting::AdvancedLighting(std::string vs, std::string fs, std::string texturePath)
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    pShader = new Shader(vs.c_str(), fs.c_str());

    float planeVertices[] = {
        // positions            // normals         // texcoords
         10.0f, -0.5f,  10.0f,  0.0f, 1.0f, 0.0f,  10.0f,  0.0f,
        -10.0f, -0.5f,  10.0f,  0.0f, 1.0f, 0.0f,   0.0f,  0.0f,
        -10.0f, -0.5f, -10.0f,  0.0f, 1.0f, 0.0f,   0.0f, 10.0f,

         10.0f, -0.5f,  10.0f,  0.0f, 1.0f, 0.0f,  10.0f,  0.0f,
        -10.0f, -0.5f, -10.0f,  0.0f, 1.0f, 0.0f,   0.0f, 10.0f,
         10.0f, -0.5f, -10.0f,  0.0f, 1.0f, 0.0f,  10.0f, 10.0f
    };
    glGenVertexArrays(1, &planeVAO);
    glGenBuffers(1, &planeVBO);
    glBindVertexArray(planeVAO);
    glBindBuffer(GL_ARRAY_BUFFER, planeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), planeVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glBindVertexArray(0);
    floorTexture = 0;
    floorTexture = loadTexture(texturePath);

    pShader->Use();
    pShader->SetInt("texture1", 0);
}

AdvancedLighting::~AdvancedLighting()
{
    delete pShader;
    glDeleteVertexArrays(1, &planeVAO);
    glDeleteBuffers(1, &planeVBO);
    glDeleteTextures(1, &floorTexture);
}

void AdvancedLighting::SetProjection(glm::mat4 & inProjection)
{
    projection = inProjection;
}

void AdvancedLighting::SetView(glm::mat4 & inView)
{
    view = inView;
}

void AdvancedLighting::SetCameraPosition(glm::vec3 & inCameraPosition)
{
    cameraPosition = inCameraPosition;
}

void AdvancedLighting::SetLightPos(glm::vec3 & inLightPos)
{
    lightPos = inLightPos;
}

void AdvancedLighting::SetBlinn(int inBlinn)
{
    blinn = inBlinn;
}

void AdvancedLighting::Draw()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    pShader->SetMat4("projection", glm::value_ptr(projection));
    pShader->SetMat4("view", glm::value_ptr(view));

    pShader->SetVec3("viewPos", glm::value_ptr(cameraPosition));
    pShader->SetVec3("lightPos", glm::value_ptr(lightPos));
    pShader->SetInt("blinn", blinn);

    glBindVertexArray(planeVAO);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, floorTexture);
    glDrawArrays(GL_TRIANGLES, 0, 6);

}

GLuint AdvancedLighting::loadTexture(std::string texturePath)
{
    GLuint textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char* data = stbi_load(texturePath.c_str(), &width, &height, &nrComponents, 0);
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

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

        stbi_image_free(data);

    }
    else {
        std::cout << "Texture failed to load at path : " << texturePath << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}

GammaCorrection::GammaCorrection(std::string vs, std::string fs, std::string texturePath)
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    pShader = new Shader(vs.c_str(), fs.c_str());

    float planeVertices[] = {
        // positions            // normals         // texcoords
         10.0f, -0.5f,  10.0f,  0.0f, 1.0f, 0.0f,  10.0f,  0.0f,
        -10.0f, -0.5f,  10.0f,  0.0f, 1.0f, 0.0f,   0.0f,  0.0f,
        -10.0f, -0.5f, -10.0f,  0.0f, 1.0f, 0.0f,   0.0f, 10.0f,

         10.0f, -0.5f,  10.0f,  0.0f, 1.0f, 0.0f,  10.0f,  0.0f,
        -10.0f, -0.5f, -10.0f,  0.0f, 1.0f, 0.0f,   0.0f, 10.0f,
         10.0f, -0.5f, -10.0f,  0.0f, 1.0f, 0.0f,  10.0f, 10.0f
    };
    glGenVertexArrays(1, &planeVAO);
    glGenBuffers(1, &planeVBO);
    glBindVertexArray(planeVAO);
    glBindBuffer(GL_ARRAY_BUFFER, planeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), planeVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glBindVertexArray(0);


    floorTexture = loadTexture(texturePath.c_str(), false);
    floorTextureGammaCorrected = loadTexture(texturePath.c_str(), true);
    pShader->Use();
    pShader->SetInt("floorTexture", 0);

    lightPositions[0] = glm::vec3(-3.0f, 0.f, 0.f);
    lightPositions[1] = glm::vec3(-1.0f, 0.f, 0.f);
    lightPositions[2] = glm::vec3( 1.0f, 0.f, 0.f);
    lightPositions[3] = glm::vec3( 3.0f, 0.f, 0.f);

    lightColors[0] = glm::vec3(0.25f);
    lightColors[1] = glm::vec3(0.50f);
    lightColors[2] = glm::vec3(0.75f);
    lightColors[3] = glm::vec3(1.00f);
}

GammaCorrection::~GammaCorrection()
{
    delete pShader;
    glDeleteVertexArrays(1, &planeVAO);
    glDeleteBuffers(1, &planeVBO);
    glDeleteTextures(1, &floorTexture);
    glDeleteTextures(1, &floorTextureGammaCorrected);
}

void GammaCorrection::SetEnableGamma(bool isGammaEnable)
{
    gammaEnabled = isGammaEnable;
}

void GammaCorrection::Draw()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    pShader->Use();
    pShader->SetMat4("projection", glm::value_ptr(projection));
    pShader->SetMat4("view", glm::value_ptr(view));
    glUniform3fv(glGetUniformLocation(pShader->ID, "lightPositions"), 4, &lightPositions[0][0]);
    glUniform3fv(glGetUniformLocation(pShader->ID, "lightColors"), 4, &lightColors[0][0]);
    pShader->SetVec3("viewPos", glm::value_ptr(cameraPosition));
    pShader->SetInt("gamma", gammaEnabled);

    glBindVertexArray(planeVAO);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, gammaEnabled ? floorTextureGammaCorrected : floorTexture);
    // glBindTexture(GL_TEXTURE_2D, floorTexture);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

GLuint GammaCorrection::loadTexture(char const * path, bool gammaCorrection)
{
    GLuint textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);

    if (data) {
        GLenum internalFormat;
        GLenum dataFormat;
        if (nrComponents == 1) {
            internalFormat = dataFormat = GL_RED;
        }
        else if (nrComponents == 3) {
            internalFormat = gammaCorrection ? GL_SRGB : GL_RGB;
            dataFormat = GL_RGB;
        }
        else if (nrComponents == 4) {
            internalFormat = gammaCorrection ? GL_SRGB_ALPHA : GL_RGBA;
            dataFormat = GL_RGBA;
        }
        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, dataFormat, GL_UNSIGNED_BYTE, data);
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
