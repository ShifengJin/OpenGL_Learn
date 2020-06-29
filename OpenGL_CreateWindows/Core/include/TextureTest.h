#pragma once

#include <GL\glew.h>

#include "Shader.h"



#define TEST0 0
// 尝试用不同的纹理环绕方式，设定一个从0.0f到2.0f范围内的（而不是原来的0.0f到1.0f）纹理坐标。
#define TEST1 0
// 在矩形上只显示纹理图像的中间一部分，修改纹理坐标，达到能看见单个的像素的效果。尝试使用GL_NEAREST的纹理过滤方式让像素显示得更清晰
#define TEST2 0
// 使用一个uniform变量作为mix函数的第三个参数来改变两个纹理可见度，使用上和下键来改变箱子或笑脸的可见度
#define TEST3 1


class Texture_1 {

public:
    Texture_1();
    ~Texture_1();

    void Draw();

private:
    GLuint vertexShader = 0;
    GLuint fragmentShader = 0;

    GLuint vertexArray = 0;
    GLuint vertexBuffer = 0;
    GLuint elementBuffer = 0;

    GLuint texture;

    int width, height, nrChannels;

    unsigned char *data;

    Shader *ourShader = NULL;
};


class Texture_2 {

public:
    Texture_2();
    ~Texture_2();

    void Draw();

private:
    GLuint vertexShader = 0;
    GLuint fragmentShader = 0;

    GLuint vertexArray = 0;
    GLuint vertexBuffer = 0;
    GLuint elementBuffer = 0;

    GLuint texture1;
    GLuint texture2;

    int width, height, nrChannels;

    unsigned char *data;
public:
    Shader *ourShader = NULL;
};