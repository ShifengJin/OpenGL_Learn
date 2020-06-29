#include "Color.h"

Color1::Color1()
{
    light1Shader = new Shader("D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_CreateWindows\\Core\\Shader\\1.light_cube.vs", 
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_CreateWindows\\Core\\Shader\\1.light_cube.fs");
    objectShader = new Shader("D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_CreateWindows\\Core\\Shader\\1.colors.vs", 
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_CreateWindows\\Core\\Shader\\1.colors.fs");

    float vertices[] = {
        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,

        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,

         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,

        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
    };

    glGenVertexArrays(1, &objectVertexArray);
    glGenBuffers(1, &vertexBuffer);

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(objectVertexArray);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glGenVertexArrays(1, &lightVertexArray);
    glBindVertexArray(lightVertexArray);

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

Color1::~Color1()
{
    glDeleteVertexArrays(1, &objectVertexArray);
    glDeleteVertexArrays(1, &lightVertexArray);
    glDeleteBuffers(1, &vertexBuffer);

    delete objectShader;
    delete light1Shader;
}

void Color1::SetObjectColor(glm::vec3 & inObjectColor)
{
    objectColor = inObjectColor;
}

void Color1::SetLightColor(glm::vec3 & inLightColor)
{
    lightColor = inLightColor;
}

void Color1::SetProjection(glm::mat4 & inProjection)
{
    projection = inProjection;
}

void Color1::SetView(glm::mat4 & inView)
{
    view = inView;
}

void Color1::SetModelObject(glm::mat4 & inModelObject)
{
    modelObject = inModelObject;
}

void Color1::SetModelLight(glm::mat4 & inModelLight)
{
    modelLight = inModelLight;
}

void Color1::DrawObject()
{
    objectShader->Use();
    glBindVertexArray(objectVertexArray);
    objectShader->SetVec3("objectColor", glm::value_ptr(objectColor));
    objectShader->SetVec3("lightColor", glm::value_ptr(lightColor));
    objectShader->SetMat4("projection", glm::value_ptr(projection));
    objectShader->SetMat4("view", glm::value_ptr(view));
    objectShader->SetMat4("model", glm::value_ptr(modelObject));
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);

}

void Color1::DrawLight()
{
    light1Shader->Use();
    light1Shader->SetMat4("projection", glm::value_ptr(projection));
    light1Shader->SetMat4("view", glm::value_ptr(view));
    light1Shader->SetMat4("model", glm::value_ptr(modelLight));

    glBindVertexArray(lightVertexArray);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}


Color2::Color2()
{
    light1Shader = new Shader("D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_CreateWindows\\Core\\Shader\\1.light_cube.vs",
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_CreateWindows\\Core\\Shader\\1.light_cube.fs");
    // objectShader = new Shader("D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_CreateWindows\\Core\\Shader\\2.1.basic_lighting.vs",
    //     "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_CreateWindows\\Core\\Shader\\2.1.basic_lighting.fs");
    // objectShader = new Shader("D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_CreateWindows\\Core\\Shader\\2.2.basic_lighting.vs",
    //     "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_CreateWindows\\Core\\Shader\\2.2.basic_lighting.fs");
    objectShader = new Shader("D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_CreateWindows\\Core\\Shader\\2.3.basic_lighting.vs",
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_CreateWindows\\Core\\Shader\\2.3.basic_lighting.fs");
    // objectShader = new Shader("D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_CreateWindows\\Core\\Shader\\2.4.basic_lighting.vs",
    //     "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_CreateWindows\\Core\\Shader\\2.4.basic_lighting.fs");

    float vertices[] = {
        // 后面                // 法线指向z轴的负方向
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        // 前面                // 法线指向z轴的正方向
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        // 左面                // 法线指向x轴的负方向
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        // 右面                 // 法线指向x轴的正方向
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         // 下面               // 法线指向 y轴的负方向
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
        // 上面                // 法线指向 y轴的正方向
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

Color2::~Color2()
{
    glDeleteVertexArrays(1, &objectVertexArray);
    glDeleteVertexArrays(1, &lightVertexArray);
    glDeleteBuffers(1, &vertexBuffer);

    delete objectShader;
    delete light1Shader;
}

void Color2::SetObjectColor(glm::vec3 & inObjectColor)
{
    objectColor = inObjectColor;
}

void Color2::SetLightColor(glm::vec3 & inLightColor)
{
    lightColor = inLightColor;
}

void Color2::SetProjection(glm::mat4 & inProjection)
{
    projection = inProjection;
}

void Color2::SetView(glm::mat4 & inView)
{
    view = inView;
}

void Color2::SetModelObject(glm::mat4 & inModelObject)
{
    modelObject = inModelObject;
}

void Color2::SetModelLight(glm::mat4 & inModelLight)
{
    modelLight = inModelLight;
}

void Color2::DrawObject(glm::vec3 lightPos)
{
    objectShader->Use();
    glBindVertexArray(objectVertexArray); 
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    objectShader->SetVec3("objectColor", glm::value_ptr(objectColor));
    objectShader->SetVec3("lightColor", glm::value_ptr(lightColor));
    objectShader->SetVec3("lightPos", glm::value_ptr(lightPos));
    objectShader->SetMat4("projection", glm::value_ptr(projection));
    objectShader->SetMat4("view", glm::value_ptr(view));
    objectShader->SetMat4("model", glm::value_ptr(modelObject));
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);

}

void Color2::DrawObject2(glm::vec3 lightPos, glm::vec3 viewPos)
{
    objectShader->Use();
    glBindVertexArray(objectVertexArray);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    objectShader->SetVec3("objectColor", glm::value_ptr(objectColor));
    objectShader->SetVec3("lightColor", glm::value_ptr(lightColor));
    objectShader->SetVec3("lightPos", glm::value_ptr(lightPos));
    objectShader->SetVec3("viewPos", glm::value_ptr(viewPos));
    objectShader->SetMat4("projection", glm::value_ptr(projection));
    objectShader->SetMat4("view", glm::value_ptr(view));
    objectShader->SetMat4("model", glm::value_ptr(modelObject));
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}

void Color2::DrawLight()
{
    light1Shader->Use();
    light1Shader->SetMat4("projection", glm::value_ptr(projection));
    light1Shader->SetMat4("view", glm::value_ptr(view));
    light1Shader->SetMat4("model", glm::value_ptr(modelLight));

    glBindVertexArray(lightVertexArray);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}
