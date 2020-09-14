#include <time.h>

#include "OpenGL_Instancing.h"

Instancing::Instancing(std::string vs, std::string fs)
{
    pShader = new Shader(vs.c_str(), fs.c_str());
    glm::vec2 translations[100];
    int index = 0;
    float offset = 0.1f;
    for (int y = -10; y < 10; y += 2) {
        for (int x = -10; x < 10; x += 2) {
            glm::vec2 translation;
            translation.x = (float)x / 10.f + offset;
            translation.y = (float)y / 10.f + offset;
            translations[index++] = translation;
        }
    }

    glGenBuffers(1, &instanceVBO);
    glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * 100, &translations[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    float quadVertices[] = {
        -0.05f,  0.05f, 1.f, 0.f, 0.f,
         0.05f, -0.05f, 0.f, 1.f, 0.f,
        -0.05f, -0.05f, 0.f, 0.f, 1.f,

        -0.05f,  0.05f, 1.f, 0.f, 0.f,
         0.05f, -0.05f, 0.f, 1.f, 0.f,
         0.05f,  0.05f, 0.f, 1.f, 1.f
    };
    glGenVertexArrays(1, &quadVAO);
    glGenBuffers(1, &quadVBO);
    glBindVertexArray(quadVAO);
    glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));

    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glVertexAttribDivisor(2, 1);
}

Instancing::~Instancing()
{
    glDeleteBuffers(1, &instanceVBO);
    glDeleteBuffers(1, &quadVBO);
    glDeleteVertexArrays(1, &quadVAO);
}

void Instancing::Draw()
{
    glClearColor(0.1f, 0.2f, 0.3f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    pShader->Use();
    glBindVertexArray(quadVAO);
    glDrawArraysInstanced(GL_TRIANGLES, 0, 6, 100);
    glBindVertexArray(0);
}

InstancingAsteroids::InstancingAsteroids(std::string vs, std::string fs, std::string modelRockPath, std::string modelPlanetPath)
{
    pShader = new Shader(vs.c_str(), fs.c_str());

    pRockModel = new Model(modelRockPath);
    pPlanetModel = new Model(modelPlanetPath);

    amount = 1000;
    modelMatrices = new glm::mat4[amount];
    float radius = 50.f;
    float offset = 2.5f;
    srand(time(NULL));
    for (unsigned int i = 0; i < amount; ++i) {
        glm::mat4 model = glm::mat4(1.f);

        float angle = (float)i / (float)amount * 360.f;
        float displacement = (rand() % (int)(2 * offset * 100)) / 100.f - offset;
        float x = sin(angle) * radius + displacement;
        displacement = (rand() % (int)(2 * offset * 100)) / 100.f - offset;
        float y = displacement * 0.4f;
        displacement = (rand() % (int)(2 * offset * 100)) / 100.f - offset;
        float z = cos(angle) * radius + displacement;
        model = glm::translate(model, glm::vec3(x, y, z));

        float scale = (rand() % 20) / 100.f + 0.05f;
        model = glm::scale(model, glm::vec3(scale));

        float rotAngle = (rand() % 360);
        model = glm::rotate(model, rotAngle, glm::vec3(0.4f, 0.6f, 0.8f));

        modelMatrices[i] = model;
    }

}

InstancingAsteroids::~InstancingAsteroids()
{
    delete pShader;
    delete pRockModel;
    delete pPlanetModel;
    delete[] modelMatrices;
}

void InstancingAsteroids::SetProjection(glm::mat4 & inProjection)
{
    projection = inProjection;
}

void InstancingAsteroids::SetView(glm::mat4 & inView)
{
    view = inView;
}

void InstancingAsteroids::Draw()
{
    glClearColor(0.1f, 0.2f, 0.3f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    pShader->Use();
    pShader->SetMat4("projection", glm::value_ptr(projection));
    pShader->SetMat4("view", glm::value_ptr(view));

    glm::mat4 model = glm::mat4(1.f);
    model = glm::translate(model, glm::vec3(0.f, -3.f, 0.f));
    model = glm::scale(model, glm::vec3(4.f, 4.f, 4.f));
    pShader->SetMat4("model", glm::value_ptr(model));
    pPlanetModel->Draw(*pShader);

    for (unsigned int i = 0; i < amount; ++i) {
        pShader->SetMat4("model", glm::value_ptr(modelMatrices[i]));
        pRockModel->Draw(*pShader);
    }
}

AsteroidsInstanced::AsteroidsInstanced(std::string asteroidsVs, std::string asteroidsFs, std::string planetVs, std::string planetFs, std::string rockPath, std::string planetPath)
{
    pAsteroidShader = new Shader(asteroidsVs.c_str(), asteroidsFs.c_str());
    pPlanetShader = new Shader(planetVs.c_str(), planetFs.c_str());

    pRockModel = new Model(rockPath);
    pPlanetModel = new Model(planetPath);

    amount = 100000;
    modelMatrices = new glm::mat4[amount];
    srand(time(NULL));
    float radius = 150.f;
    float offset = 25.f;
    for (unsigned int i = 0; i < amount; ++i) {
        glm::mat4 model = glm::mat4(1.f);

        float angle = (float)i / (float)amount * 360.f;
        float displacement = (rand() % (int)(2 * offset * 100)) / 100.f - offset;
        float x = sin(angle) * radius + displacement;
        displacement = (rand() % (int)(2 * offset * 100)) / 100.f - offset;
        float y = displacement * 0.4f;
        displacement = (rand() % (int)(2 * offset * 100)) / 100.f - offset;
        float z = cos(angle) * radius + displacement;
        model = glm::translate(model, glm::vec3(x, y, z));

        float scale = (rand() % 20) / 100.f + 0.05f;
        model = glm::scale(model, glm::vec3(scale));

        float rotAngle = (rand() % 360);
        model = glm::rotate(model, rotAngle, glm::vec3(0.4f, 0.6f, 0.8f));

        modelMatrices[i] = model;
    }

    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, amount * sizeof(glm::mat4), &modelMatrices[0], GL_STATIC_DRAW);

    for (unsigned int i = 0; i < pRockModel->meshes.size(); ++i) {
        GLuint VAO = pRockModel->meshes[i].VAO;
        glBindVertexArray(VAO);
        glEnableVertexAttribArray(3);
        glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)0);

        glEnableVertexAttribArray(4);
        glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(glm::vec4)));

        glEnableVertexAttribArray(5);
        glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(2 * sizeof(glm::vec4)));

        glEnableVertexAttribArray(6);
        glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(3 * sizeof(glm::vec4)));

        glVertexAttribDivisor(3, 1);
        glVertexAttribDivisor(4, 1);
        glVertexAttribDivisor(5, 1);
        glVertexAttribDivisor(6, 1);
        glBindVertexArray(0);
    }
}

AsteroidsInstanced::~AsteroidsInstanced()
{
    glDeleteBuffers(1, &buffer);
    
    delete pAsteroidShader;
    delete pPlanetShader;
    delete pRockModel;
    delete pPlanetModel;
    delete[] modelMatrices;
}

void AsteroidsInstanced::SetProjection(glm::mat4 & inProjection)
{
    projection = inProjection;
}

void AsteroidsInstanced::SetView(glm::mat4 & inView)
{
    view = inView;
}

void AsteroidsInstanced::Draw()
{
    glClearColor(0.1f, 0.2f, 0.3f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    pPlanetShader->Use();
    pPlanetShader->SetMat4("projection", glm::value_ptr(projection));
    pPlanetShader->SetMat4("view", glm::value_ptr(view));
    glm::mat4 model = glm::mat4(1.f);
    model = glm::translate(model, glm::vec3(0.f, -3.f, 0.f));
    model = glm::scale(model, glm::vec3(4.f, 4.f, 4.f));
    pPlanetShader->SetMat4("model", glm::value_ptr(model));
    pPlanetModel->Draw(*pPlanetShader);

    pAsteroidShader->Use();
    pAsteroidShader->SetMat4("projection", glm::value_ptr(projection));
    pAsteroidShader->SetMat4("view", glm::value_ptr(view));
    pAsteroidShader->SetInt("texture_diffuse1", 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, pRockModel->textures_loaded[0].id);
    for (unsigned int i = 0; i < pRockModel->meshes.size(); ++i) {
        glBindVertexArray(pRockModel->meshes[i].VAO);
        glDrawElementsInstanced(GL_TRIANGLES, pRockModel->meshes[i].indices.size(), GL_UNSIGNED_INT, 0, amount);
        glBindVertexArray(0);
    }


}

