#include <iostream>
#include "DrawTriangle.h"


DrawTriangle_1::DrawTriangle_1()
{
    const char *vertexShaderSource = ""
        "#version 330 core                             \n"
        "layout (location = 0) in vec3 aPos;            \n"
        "void main()                                    \n"
        "{                                              \n"
        "    gl_Position = vec4(aPos, 1.0);             \n"
        "}";

    const char *fragmentShaderSource = ""
        "#version 330 core                              \n"
        "out vec4 FragColor;                            \n"
        "void main()                                    \n"
        "{                                              \n"
        "    FragColor = vec4(1.f, 0.5f, 0.2f, 1.f);    \n"
        "}";


    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }


    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


    float vertices[] = {
        -0.8f, -0.8f, 0.0f,
         0.8f, -0.8f, 0.0f,
         0.0f,  0.8f, 0.0f
    };
    // 创建buffer
    glGenVertexArrays(1, &vertexArray);
    glGenBuffers(1, &vertexBuffer);

    glBindVertexArray(vertexArray);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

DrawTriangle_1::~DrawTriangle_1()
{
    glDeleteVertexArrays(1, &vertexArray);
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteProgram(shaderProgram);
}

void DrawTriangle_1::Draw()
{
    glUseProgram(shaderProgram);
    glBindVertexArray(vertexArray);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}


DrawTriangle_2::DrawTriangle_2()
{
    const char *vertexShaderSource = ""
        "#version 330 core                             \n"
        "layout (location = 0) in vec3 aPos;            \n"
        "void main()                                    \n"
        "{                                              \n"
        "    gl_Position = vec4(aPos, 1.0);             \n"
        "}";

    const char *fragmentShaderSource = ""
        "#version 330 core                              \n"
        "out vec4 FragColor;                            \n"
        "void main()                                    \n"
        "{                                              \n"
        "    FragColor = vec4(1.f, 0.5f, 0.2f, 1.f);    \n"
        "}";


    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }


    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


    float vertices[] = {
         0.5f,  0.5f, 0.0f,   // 右上角
         0.5f, -0.5f, 0.0f,   // 右下角
        -0.5f, -0.5f, 0.0f,   // 左下角
        -0.5f,  0.5f, 0.0f    // 左上角
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

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

DrawTriangle_2::~DrawTriangle_2()
{
    glDeleteVertexArrays(1, &vertexArray);
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteBuffers(1, &elementBuffer);
    glDeleteProgram(shaderProgram);
}

void DrawTriangle_2::Draw()
{
    glUseProgram(shaderProgram);
    glBindVertexArray(vertexArray);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}



DrawTriangle_3::DrawTriangle_3()
{
    const char *vertexShaderSource = ""
        "#version 330 core                             \n"
        "layout (location = 0) in vec3 aPos;            \n"
        "void main()                                    \n"
        "{                                              \n"
        "    gl_Position = vec4(aPos, 1.0);             \n"
        "}";

    const char *fragmentShaderSource = ""
        "#version 330 core                              \n"
        "out vec4 FragColor;                            \n"
        "uniform vec4 outColor;                         \n"
        "void main()                                    \n"
        "{                                              \n"
        "    FragColor = outColor;                      \n"
        "}";


    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }


    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


    float vertices[] = {
         0.5f, -0.5f, 0.0f,   
        -0.5f, -0.5f, 0.0f,   
         0.0f,  0.5f, 0.0f,   
    };

    // 创建buffer
    glGenVertexArrays(1, &vertexArray);
    glGenBuffers(1, &vertexBuffer);

    glBindVertexArray(vertexArray);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    vertexColorLocation = glGetUniformLocation(shaderProgram, "outColor");
}

DrawTriangle_3::~DrawTriangle_3()
{
    glDeleteVertexArrays(1, &vertexArray);
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteProgram(shaderProgram);
}

void DrawTriangle_3::Draw(float greenValue)
{
    glUseProgram(shaderProgram);
    glBindVertexArray(vertexArray);

    
    glUniform4f(vertexColorLocation, 0.f, greenValue, 0.f, 1.f);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}

DrawTriangle_4::DrawTriangle_4()
{
    const char *vertexShaderSource = ""
        "#version 330 core                              \n"
        "layout (location = 0) in vec3 aPos;            \n"
        "layout (location = 1) in vec3 aColor;          \n"
        "out vec3 ourColor;                             \n"
        "void main()                                    \n"
        "{                                              \n"
        "    gl_Position = vec4(aPos, 1.0);             \n"
        "    ourColor = aColor;                         \n"
        "}";

    const char *fragmentShaderSource = ""
        "#version 330 core                              \n"
        "out vec4 FragColor;                            \n"
        "in vec3 ourColor;                              \n"
        "void main()                                    \n"
        "{                                              \n"
        "    FragColor = vec4(ourColor, 1.0);           \n"
        "}";


    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }


    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


    float vertices[] = {
         0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,
         0.0f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f
    };

    // 创建buffer
    glGenVertexArrays(1, &vertexArray);
    glGenBuffers(1, &vertexBuffer);

    glBindVertexArray(vertexArray);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

DrawTriangle_4::~DrawTriangle_4()
{
    glDeleteVertexArrays(1, &vertexArray);
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteProgram(shaderProgram);
}

void DrawTriangle_4::Draw()
{
    glUseProgram(shaderProgram);
    glBindVertexArray(vertexArray);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}