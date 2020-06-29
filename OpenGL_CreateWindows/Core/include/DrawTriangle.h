#pragma once

#include <GL\glew.h>
/*
 * 画一个三角形
 */
class DrawTriangle_1 {

public:
    DrawTriangle_1();
    ~DrawTriangle_1();

    void Draw();

private:
    GLuint vertexShader = 0;
    GLuint fragmentShader = 0;
    GLuint shaderProgram = 0;

    GLuint vertexArray = 0;
    GLuint vertexBuffer = 0;
};

/*
 * 画两个三角形,组成一个正方形
 */
class DrawTriangle_2 {

public:
    DrawTriangle_2();
    ~DrawTriangle_2();

    void Draw();

private:
    GLuint vertexShader = 0;
    GLuint fragmentShader = 0;
    GLuint shaderProgram = 0;

    GLuint vertexArray = 0;
    GLuint vertexBuffer = 0;
    GLuint elementBuffer = 0;
};

/*
 * 通过uniform 修改三角形颜色
 */
class DrawTriangle_3 {

public:
    DrawTriangle_3();
    ~DrawTriangle_3();

    void Draw(float greenValue);

private:
    GLuint vertexShader = 0;
    GLuint fragmentShader = 0;
    GLuint shaderProgram = 0;

    GLuint vertexArray = 0;
    GLuint vertexBuffer = 0;

    GLuint vertexColorLocation = 0;
};

class DrawTriangle_4 {

public:
    DrawTriangle_4();
    ~DrawTriangle_4();

    void Draw();

private:
    GLuint vertexShader = 0;
    GLuint fragmentShader = 0;
    GLuint shaderProgram = 0;

    GLuint vertexArray = 0;
    GLuint vertexBuffer = 0;

    GLuint vertexColorLocation = 0;
};