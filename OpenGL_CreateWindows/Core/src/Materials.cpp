#include "..\include\Materials.h"

Materials::Materials()
{
    
    pLightCubeShader = new Shader("D:/WorkSpace/OpenGLWorkSpace/OpenGL_CreateWindows/Core/Shader/1.light_cube.vs",
        "D:/WorkSpace/OpenGLWorkSpace/OpenGL_CreateWindows/Core/Shader/1.light_cube.fs");
    pLightingShader = new Shader("D:/WorkSpace/OpenGLWorkSpace/OpenGL_CreateWindows/Core/Shader/3.1.materials.vs",
        "D:/WorkSpace/OpenGLWorkSpace/OpenGL_CreateWindows/Core/Shader/3.1.materials.fs");

    float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
    };

    glGenVertexArrays(1, &objectVertexArray);
    glGenBuffers(1, &vertexBuffer);

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(objectVertexArray);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glGenVertexArrays(1, &lightVertexArray);
    glBindVertexArray(lightVertexArray);

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

Materials::~Materials()
{
    glDeleteVertexArrays(1, &objectVertexArray);
    glDeleteVertexArrays(1, &lightVertexArray);
    glDeleteBuffers(1, &vertexBuffer);

    delete pLightingShader;
    delete pLightCubeShader;
}

void Materials::SetLightAmbient(glm::vec3 & inAmbient)
{
    lightAmbient = inAmbient;
}

void Materials::SetLightDiffuse(glm::vec3 & inDiffuse)
{
    lightDiffuse = inDiffuse;
}

void Materials::SetLightSpecular(glm::vec3 & inSpecular)
{
    lightSpecular = inSpecular;
}

void Materials::SetMaterialAmbient(glm::vec3 & inAmbient)
{
    materialAmbient = inAmbient;
}

void Materials::SetMaterialDiffuse(glm::vec3 & inDiffuse)
{
    materialDiffuse = inDiffuse;
}

void Materials::SetMaterialSpecular(glm::vec3 & inSpecular)
{
    materialSpecular = inSpecular;
}

void Materials::SetMaterialShininess(float inShininess)
{
    materialShininess = inShininess;
}

void Materials::SetProjection(glm::mat4 & inProjection)
{
    projection = inProjection;
}

void Materials::SetView(glm::mat4 & inView)
{
    view = inView;
}

void Materials::SetModelObject(glm::mat4 & inModelObject)
{
    modelObject = inModelObject;
}

void Materials::SetModelLight(glm::mat4 & inModelLight)
{
    modelLight = inModelLight;
}

void Materials::DrawObject(glm::vec3 lightPos, glm::vec3 viewPos)
{
    pLightingShader->Use();
    glBindVertexArray(objectVertexArray);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    pLightingShader->SetVec3("viewPos", glm::value_ptr(viewPos));
    pLightingShader->SetVec3("light.position", glm::value_ptr(lightPos));
    pLightingShader->SetVec3("light.ambient", glm::value_ptr(lightAmbient));
    pLightingShader->SetVec3("light.diffuse", glm::value_ptr(lightDiffuse));
    pLightingShader->SetVec3("light.specular", glm::value_ptr(lightSpecular));

    pLightingShader->SetVec3("material.ambient", glm::value_ptr(materialAmbient));
    pLightingShader->SetVec3("material.diffuse", glm::value_ptr(materialDiffuse));
    pLightingShader->SetVec3("material.specular", glm::value_ptr(materialSpecular));
    pLightingShader->SetFloat("material.shininess", materialShininess);

    pLightingShader->SetMat4("projection", glm::value_ptr(projection));
    pLightingShader->SetMat4("view", glm::value_ptr(view));
    pLightingShader->SetMat4("model", glm::value_ptr(modelObject));

    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}

void Materials::DrawLight()
{
    pLightCubeShader->Use();
    glBindVertexArray(objectVertexArray);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

    pLightCubeShader->SetMat4("projection", glm::value_ptr(projection));
    pLightCubeShader->SetMat4("view", glm::value_ptr(view));
    pLightCubeShader->SetMat4("model", glm::value_ptr(modelLight));

    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}
