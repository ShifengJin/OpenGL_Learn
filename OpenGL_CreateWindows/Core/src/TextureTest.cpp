#include <iostream>
#include "stb_image.h"
#include "TextureTest.h"

Texture_1::Texture_1()
{
    ourShader = new Shader("D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_CreateWindows\\Core\\Shader\\texture_1.vs", 
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_CreateWindows\\Core\\Shader\\texture_1.fs");

    float vertices[] = {
        // position             // colors      // texture coords
        0.5f,  0.5f, 0.0f,    1.f, 0.f, 0.f,    1.f, 1.f,    // top right
        0.5f, -0.5f, 0.0f,    0.f, 1.f, 0.f,    1.f, 0.f,    // bottom right
       -0.5f, -0.5f, 0.0f,    0.f, 0.f, 1.f,    0.f, 0.f,    // bottom left
       -0.5f,  0.5f, 0.0f,    1.f, 1.f, 0.f,    0.f, 1.f     // top left
    };
    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    
    // 创建buffer
    glGenVertexArrays(1, &vertexArray);
    glGenBuffers(1, &vertexBuffer);
    glGenBuffers(1, &elementBuffer);

    glBindVertexArray(vertexArray);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);


    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    // GL_REPEAT             对纹理的默认行为。重复纹理图像。
    // GL_MIRRORED_REPEAT    和GL_REPEAT一样，但每次重复图片是镜像放置的。
    // GL_CLAMP_TO_EDGE	     纹理坐标会被约束在0到1之间，超出的部分会重复纹理坐标的边缘，产生一种边缘被拉伸的效果。
    // GL_CLAMP_TO_BORDER    超出的坐标为用户指定的边缘颜色。
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    data = NULL;
    data = stbi_load("D:\\WorkSpace\\OpenGLWorkSpace\\container.jpg", &width, &height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    glBindTexture(GL_TEXTURE_2D, 0);
    
    // glBindBuffer(GL_ARRAY_BUFFER, 0);
    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Texture_1::~Texture_1()
{
    glDeleteVertexArrays(1, &vertexArray);
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteBuffers(1, &elementBuffer);

    glDeleteTextures(1, &texture);
    delete ourShader;
}

void Texture_1::Draw()
{
    ourShader->Use();

    glBindVertexArray(vertexArray);
    glBindTexture(GL_TEXTURE_2D, texture);
    // glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);


    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    // glBindBuffer(GL_ARRAY_BUFFER, 0);
    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindVertexArray(0);

}

Texture_2::Texture_2()
{
#if !TEST3
    ourShader = new Shader("D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_CreateWindows\\Core\\Shader\\texture_2.vs",
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_CreateWindows\\Core\\Shader\\texture_2.fs");
#endif
#if TEST3
    ourShader = new Shader("D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_CreateWindows\\Core\\Shader\\texture_3.vs",
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_CreateWindows\\Core\\Shader\\texture_3.fs");
#endif
#if TEST0 || TEST3
    float vertices[] = {
        // position             // colors      // texture coords
        0.5f,  0.5f, 0.0f,    1.f, 0.f, 0.f,    1.f, 1.f,    // top right
        0.5f, -0.5f, 0.0f,    0.f, 1.f, 0.f,    1.f, 0.f,    // bottom right
       -0.5f, -0.5f, 0.0f,    0.f, 0.f, 1.f,    0.f, 0.f,    // bottom left
       -0.5f,  0.5f, 0.0f,    1.f, 1.f, 0.f,    0.f, 1.f     // top left
    };
#endif
#if TEST1
    float vertices[] = {
        // position             // colors      // texture coords
        0.5f,  0.5f, 0.0f,    1.f, 0.f, 0.f,    2.f, 2.f,    // top right
        0.5f, -0.5f, 0.0f,    0.f, 1.f, 0.f,    2.f, 0.f,    // bottom right
       -0.5f, -0.5f, 0.0f,    0.f, 0.f, 1.f,    0.f, 0.f,    // bottom left
       -0.5f,  0.5f, 0.0f,    1.f, 1.f, 0.f,    0.f, 2.f     // top left
    };
#endif
#if TEST2
    float vertices[] = {
        // position             // colors      // texture coords
        0.5f,  0.5f, 0.0f,    1.f, 0.f, 0.f,    0.55f, 0.55f,    // top right
        0.5f, -0.5f, 0.0f,    0.f, 1.f, 0.f,    0.55f, 0.45f,    // bottom right
       -0.5f, -0.5f, 0.0f,    0.f, 0.f, 1.f,    0.45f, 0.45f,    // bottom left
       -0.5f,  0.5f, 0.0f,    1.f, 1.f, 0.f,    0.45f, 0.55f     // top left
    };
#endif
    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };


    // 创建buffer
    glGenVertexArrays(1, &vertexArray);
    glGenBuffers(1, &vertexBuffer);
    glGenBuffers(1, &elementBuffer);

    glBindVertexArray(vertexArray);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);


    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    // GL_REPEAT             对纹理的默认行为。重复纹理图像。
    // GL_MIRRORED_REPEAT    和GL_REPEAT一样，但每次重复图片是镜像放置的。
    // GL_CLAMP_TO_EDGE	     纹理坐标会被约束在0到1之间，超出的部分会重复纹理坐标的边缘，产生一种边缘被拉伸的效果。
    // GL_CLAMP_TO_BORDER    超出的坐标为用户指定的边缘颜色。
#if TEST0
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
#endif
#if TEST1
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
#endif
#if TEST2
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// GL_NEAREST
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
#endif



    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
#if !TEST2
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
#endif
#if TEST2
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
#endif

    glBindTexture(GL_TEXTURE_2D, texture1);
    data = NULL;
    stbi_set_flip_vertically_on_load(true);
    data = stbi_load("D:\\WorkSpace\\OpenGLWorkSpace\\container.jpg", &width, &height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    glBindTexture(GL_TEXTURE_2D, 0);

    glBindTexture(GL_TEXTURE_2D, texture2);

    data = NULL;
    data = stbi_load("D:\\WorkSpace\\OpenGLWorkSpace\\awesomeface.png", &width, &height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    glBindTexture(GL_TEXTURE_2D, 0);

    // glBindBuffer(GL_ARRAY_BUFFER, 0);
    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    ourShader->Use();
    ourShader->SetInt("texture1", 0);
    ourShader->SetInt("texture2", 1);
}

Texture_2::~Texture_2()
{
    glDeleteVertexArrays(1, &vertexArray);
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteBuffers(1, &elementBuffer);

    glDeleteTextures(1, &texture2);
    glDeleteTextures(1, &texture1);
    delete ourShader;
}

void Texture_2::Draw()
{
    ourShader->Use();

    glBindVertexArray(vertexArray);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, 0);
    glBindVertexArray(0);
}