#pragma once

#include <GL\glew.h>

#include "Shader.h"



#define TEST0 0
// �����ò�ͬ�������Ʒ�ʽ���趨һ����0.0f��2.0f��Χ�ڵģ�������ԭ����0.0f��1.0f���������ꡣ
#define TEST1 0
// �ھ�����ֻ��ʾ����ͼ����м�һ���֣��޸��������꣬�ﵽ�ܿ������������ص�Ч��������ʹ��GL_NEAREST��������˷�ʽ��������ʾ�ø�����
#define TEST2 0
// ʹ��һ��uniform������Ϊmix�����ĵ������������ı���������ɼ��ȣ�ʹ���Ϻ��¼����ı����ӻ�Ц���Ŀɼ���
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