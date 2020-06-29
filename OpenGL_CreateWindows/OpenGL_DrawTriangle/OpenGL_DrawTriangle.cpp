// OpenGL_CreateWindows.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <GL/glew.h>
#include <glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <glfw3native.h>

#include "DrawTriangle.h"

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  // 主版本号
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);  // 次版本号
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);       // 不予许修改窗口尺寸


    int width = 640;
    int height = 480;

    GLFWwindow* window = glfwCreateWindow(width, height, "CreateWindows", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cout << "Failed to glewInit" << std::endl;
        glfwTerminate();
        return -2;
    }

    // DrawTriangle_1 mDrawTriangle_1;
    // DrawTriangle_2 mDrawTriangle_2;
    // DrawTriangle_3 mDrawTriangle_3;
    DrawTriangle_4 mDrawTriangle_4;
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // 设置清空屏幕所用的颜色
        glClear(GL_COLOR_BUFFER_BIT);          // 清空屏幕

        // mDrawTriangle_1.Draw();
        // mDrawTriangle_2.Draw();

        // float timeValue = glfwGetTime();
        // float greenValue = sinf(timeValue) / 2.f + 0.5f;
        // mDrawTriangle_3.Draw(greenValue);

        mDrawTriangle_4.Draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

