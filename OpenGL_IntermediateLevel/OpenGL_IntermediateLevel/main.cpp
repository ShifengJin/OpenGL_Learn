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
#include "stb_image.h"
#include "CameraFPS.h"
#include "Model.h"
#include "Mesh.h"
#include "Shader.h"


CameraFPS gCameraFPS(glm::vec3(0.f, 0.f, 3.f));
float lastX = 640 / 2.f;
float lastY = 480 / 2.f;
bool firstMouse = true;
float deltaTime = 0.f;
float lastFrame = 0.f;

glm::vec3 lightPos(1.2f, 1.f, 2.f);

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    if (firstMouse) {
        lastX = (float)xpos;
        lastY = (float)ypos;
        firstMouse = false;
    }

    float xoffset = (float)xpos - lastX;
    float yoffset = lastY - (float)ypos;
    lastX = (float)xpos;
    lastY = (float)ypos;

    gCameraFPS.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    gCameraFPS.ProcessMouseScroll((float)yoffset);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
    float cameraSpeed = 2.5f * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        gCameraFPS.ProcessKeyboard(FORWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        gCameraFPS.ProcessKeyboard(BACKWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        gCameraFPS.ProcessKeyboard(LEFT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        gCameraFPS.ProcessKeyboard(RIGHT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
        gCameraFPS.ProcessKeyboard(UP, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
        gCameraFPS.ProcessKeyboard(DOWN, deltaTime);
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

    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cout << "Failed to glewInit" << std::endl;
        glfwTerminate();
        return -2;
    }

    stbi_set_flip_vertically_on_load(true);

    glEnable(GL_DEPTH_TEST);

    Shader ourShader(
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_IntermediateLevel\\Core\\Shader\\1.model_loading.vs", 
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_IntermediateLevel\\Core\\Shader\\1.model_loading.fs");
    // 此处必须为相对路径
    Model ourModel("../../nanosuit/nanosuit.obj");
    
    while (!glfwWindowShouldClose(window)) {

        float currentFrame = (float)glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;


        processInput(window);

        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);  // 设置清空屏幕所用的颜色
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        ourShader.Use();
        glm::mat4 projection = glm::perspective(glm::radians(gCameraFPS.Zoom),
            (float)width / (float)height, 0.1f, 1000.f);
        glm::mat4 view = gCameraFPS.GetViewMatrix();

        ourShader.SetMat4("projection", glm::value_ptr(projection));
        ourShader.SetMat4("view", glm::value_ptr(view));

        ourShader.SetVec3("viewPos", glm::value_ptr(gCameraFPS.Position));
        glm::vec3 direction(0.f, 0.f, -1.f);
        ourShader.SetVec3("dirLight.direction", glm::value_ptr(direction));

        glm::vec3 ambient(0.5f, 0.5f, 0.5f);
        ourShader.SetVec3("dirLight.ambient", glm::value_ptr(ambient));

        glm::vec3 diffuse(0.4f, 0.4f, 0.4f);
        ourShader.SetVec3("dirLight.diffuse", glm::value_ptr(diffuse));
        glm::vec3 specular(0.5f, 0.5f, 0.5f);
        ourShader.SetVec3("dirLight.specular", glm::value_ptr(specular));


        glm::mat4 model = glm::mat4(1.f);
        model = glm::translate(model, glm::vec3(0.f, -10.f, -30.f));
        model = glm::scale(model, glm::vec3(1.f, 1.f, 1.f));
        ourShader.SetMat4("model", glm::value_ptr(model));
        ourModel.Draw(ourShader);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

