#include "Camera.h"
#include "stb_image.h"

void Camera1::init(std::string & vs, std::string & fs, std::string & img1, std::string & img2)
{
    model = glm::mat4(1.f);
    view = glm::mat4(1.f);
    projection = glm::mat4(1.f);


    ourShader = new Shader(vs.c_str(), fs.c_str());

    float vertices[] = {
        // positions         // texture coords
         -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
          0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
          0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
          0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

    glGenVertexArrays(1, &mVertexArray);
    glGenBuffers(1, &mVertexBuffer);

    glBindVertexArray(mVertexArray);

    glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glGenTextures(1, &mTexture1);
    glBindTexture(GL_TEXTURE_2D, mTexture1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);

    glGenTextures(1, &mTexture2);
    glBindTexture(GL_TEXTURE_2D, mTexture2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);

    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    glBindTexture(GL_TEXTURE_2D, mTexture1);
    unsigned char *data = stbi_load(img1.c_str(), &width, &height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindTexture(GL_TEXTURE_2D, mTexture2);
    data = stbi_load(img2.c_str(), &width, &height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    glBindTexture(GL_TEXTURE_2D, 0);
    ourShader->Use();
    ourShader->SetInt("texture1", 0);
    ourShader->SetInt("texture2", 1);


    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Camera1::Camera1()
{
    std::string vs = "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_CreateWindows\\Core\\Shader\\CoordinateSystems2.vs";
    std::string fs = "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_CreateWindows\\Core\\Shader\\CoordinateSystems2.fs";
    std::string img1 = "D:\\WorkSpace\\OpenGLWorkSpace\\container.jpg";
    std::string img2 = "D:\\WorkSpace\\OpenGLWorkSpace\\awesomeface.png";
    init(vs, fs, img1, img2);
}

Camera1::~Camera1()
{

    glDeleteVertexArrays(1, &mVertexArray);
    glDeleteBuffers(1, &mVertexBuffer);
    glDeleteTextures(1, &mTexture1);
    glDeleteTextures(1, &mTexture2);

    delete ourShader;

}

void Camera1::SetModel(glm::mat4 inModel)
{
    model = inModel;
}

void Camera1::SetModels(std::vector<glm::mat4> inModels)
{
    models.clear();
    for (int i = 0; i < inModels.size(); ++i) {
        glm::mat4 m = inModels[i];
        models.push_back(m);
    }
}

void Camera1::SetView(glm::mat4 inView)
{
    view = inView;
}

void Camera1::SetProjection(glm::mat4 inProjection)
{
    projection = inProjection;
}

void Camera1::Draw()
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, mTexture1);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, mTexture2);

    ourShader->Use();

    ourShader->SetMat4("model", glm::value_ptr(model));
    ourShader->SetMat4("view", glm::value_ptr(view));
    ourShader->SetMat4("projection", glm::value_ptr(projection));

    glBindVertexArray(mVertexArray);
    glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glUseProgram(0);
}

void Camera1::Draws()
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, mTexture1);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, mTexture2);

    ourShader->Use();

    ourShader->SetMat4("view", glm::value_ptr(view));
    ourShader->SetMat4("projection", glm::value_ptr(projection));

    glBindVertexArray(mVertexArray);
    glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer);

    for (int i = 0; i < models.size(); ++i) {
        ourShader->SetMat4("model", glm::value_ptr(models[i]));
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }


    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glUseProgram(0);
}