// OpenGL_CreateWindows.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <GL/glew.h>
#include <glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <glfw3native.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Transformations.h"

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

    Transformation1 mTransformation1;


    while (!glfwWindowShouldClose(window)) {
        processInput(window);


        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // 设置清空屏幕所用的颜色
        glClear(GL_COLOR_BUFFER_BIT);          // 清空屏幕
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
        glEnable(GL_DEPTH_TEST);

        glm::mat4 transformBase = glm::mat4(1.f);
        transformBase = glm::translate(transformBase, glm::vec3(0.5f, 0.0f, 0.f));
        transformBase = glm::rotate(transformBase, (float)glfwGetTime(), glm::vec3(1.f, 1.f, 0.f));

        // ********** 前边的图, 不旋转不平移 **********
        glm::mat4 transform_front = glm::mat4(1.f);
        // transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.f, 0.f, 1.f));
        // transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
        // 先旋转再平移
        transform_front = glm::translate(transform_front, glm::vec3(0.0f, 0.0f, -0.5f));
        // transform_front = glm::rotate(transform_front, glm::radians(0.f), glm::vec3(0.f, 0.f, 0.f));
        transform_front = transformBase * transform_front;
        // transform_front = transform_front * transformBase;
        mTransformation1.Draw(transform_front);

        // ********** 后边的图, x 旋转180 z平移 0.5 **********
        glm::mat4 transform_back = glm::mat4(1.f);
        // 先旋转再平移
        transform_back = glm::translate(transform_back, glm::vec3(0.0f, 0.0f, 0.5f));
        transform_back = glm::rotate(transform_back, glm::radians(180.f), glm::vec3(1.f, 0.f, 0.f));
        transform_back = transformBase * transform_back;
        // transform_back = transform_back * transformBase;
        mTransformation1.Draw(transform_back);

        // ********** 上边的图, x 旋转90 y平移 0.5 **********
        glm::mat4 transform_up = glm::mat4(1.f);
        // 先旋转再平移
        transform_up = glm::translate(transform_up, glm::vec3(0.0f, 0.5f, 0.0f));
        transform_up = glm::rotate(transform_up, glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f));
        transform_up = transformBase * transform_up;
        // transform_up = transform_up * transformBase;
        mTransformation1.Draw(transform_up);

        // ********** 下边的图, x 旋转-90 y平移 -0.5 **********
        glm::mat4 transform_down = glm::mat4(1.f);
        // 先旋转再平移
        transform_down = glm::translate(transform_down, glm::vec3(0.0f, -0.5f, 0.0f));
        transform_down = glm::rotate(transform_down, glm::radians(-90.f), glm::vec3(1.f, 0.f, 0.f));
        transform_down = transformBase * transform_down;
        // transform_down = transform_down * transformBase;
        mTransformation1.Draw(transform_down);

        // ********** 左边的图, y 旋转-90 x平移 -0.5 **********
        glm::mat4 transform_left = glm::mat4(1.f);
        // 先旋转再平移
        transform_left = glm::translate(transform_left, glm::vec3(-0.5f, 0.f, 0.0f));
        transform_left = glm::rotate(transform_left, glm::radians(-90.f), glm::vec3(0.f, 1.f, 0.f));
        transform_left = transformBase * transform_left;
        //transform_left = transform_left * transformBase;
        mTransformation1.Draw(transform_left);

        // ********** 右边的图, y 旋转90 x平移 0.5 **********
        glm::mat4 transform_right = glm::mat4(1.f);
        // 先旋转再平移
        transform_right = glm::translate(transform_right, glm::vec3(0.5f, 0.f, 0.0f));
        transform_right = glm::rotate(transform_right, glm::radians(90.f), glm::vec3(0.f, 1.f, 0.f));
        transform_right = transformBase * transform_right;
        //transform_right = transform_right * transformBase;
        mTransformation1.Draw(transform_right);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

