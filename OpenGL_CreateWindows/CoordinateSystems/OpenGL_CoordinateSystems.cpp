// OpenGL_CreateWindows.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <vector>
#include <iostream>
#include <GL/glew.h>
#include <glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <glfw3native.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "CoordinateSystems.h"

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
    std::vector<glm::vec3> cubePositions = {
        glm::vec3(0.0f,  0.0f,  0.0f),
        glm::vec3(2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3(2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3(1.3f, -2.0f, -2.5f),
        glm::vec3(1.5f,  2.0f, -2.5f),
        glm::vec3(1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };

    std::vector<glm::mat4> models;


    for (unsigned int i = 0; i < cubePositions.size(); ++i) {
        glm::mat4 model = glm::mat4(1.f);
        float angle = 20.f * i;
        model = glm::translate(model, cubePositions[i]);
        model = glm::rotate(model, glm::radians(angle), glm::vec3(1.f, 0.f, 0.f));
        models.push_back(model);
    }

    //CoordinateSystems1* pCoordinateSystems1 = new CoordinateSystems1();
    CoordinateSystems2* pCoordinateSystems2 = new CoordinateSystems2();
    pCoordinateSystems2->SetModels(models);
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

#if 0
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // 设置清空屏幕所用的颜色
        glClear(GL_COLOR_BUFFER_BIT);          // 清空屏幕
        // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // glEnable(GL_DEPTH_TEST);

        glm::mat4 model = glm::mat4(1.f);
        glm::mat4 view = glm::mat4(1.f);
        glm::mat4 projection = glm::mat4(1.f);

        model = glm::rotate(model, glm::radians(-55.f), glm::vec3(1.f, 0.f, 0.f));
        view = glm::translate(view, glm::vec3(1.f, 1.0f, -3.0f));

        projection = glm::perspective(glm::radians(45.f), (float)width / (float)height, 0.1f, 100.f);

        pCoordinateSystems1->SetModel(model);
        pCoordinateSystems1->SetView(view);
        pCoordinateSystems1->SetProjection(projection);

        pCoordinateSystems1->Draw();
#endif

#if 0
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // 设置清空屏幕所用的颜色
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);
        glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 projection = glm::mat4(1.0f);
        model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.f));
        projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);

        pCoordinateSystems2->SetModel(model);
        pCoordinateSystems2->SetView(view);
        pCoordinateSystems2->SetProjection(projection);

        pCoordinateSystems2->Draw();
#endif

#if 1
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // 设置清空屏幕所用的颜色
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);
        glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 projection = glm::mat4(1.0f);
       
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.f));
        projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
        models.clear();
        for (unsigned int i = 0; i < cubePositions.size(); ++i) {
            glm::mat4 model = glm::mat4(1.f);
            float angle = 20.f * i;
            model = glm::translate(model, cubePositions[i]);
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.f, 0.f, 0.f));
            model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(1.f, 1.0f, 1.0f));
            models.push_back(model);
        }
        pCoordinateSystems2->SetModels(models);
        pCoordinateSystems2->SetView(view);
        pCoordinateSystems2->SetProjection(projection);

        pCoordinateSystems2->Draws();
#endif
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    //delete pCoordinateSystems1;
    delete pCoordinateSystems2;
    glfwTerminate();
    return 0;
}

