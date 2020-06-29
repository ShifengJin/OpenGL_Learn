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
#include "Camera.h"

#define ONLYLOOKAT 0
#define MOVE 0
#define MOVEANDROTATE 1

#if MOVE
glm::vec3 cameraPos = glm::vec3(0.f, 0.f, 3.f);
glm::vec3 cameraFront = glm::vec3(0.f, 0.f, -1.f);
glm::vec3 cameraUp = glm::vec3(0.f, 1.f, 0.f);
float deltaTime = 0.f;
float lastFrame = 0.f;
#endif

#if MOVEANDROTATE
glm::vec3 cameraPos = glm::vec3(0.f, 0.f, 3.f);
glm::vec3 cameraFront = glm::vec3(0.f, 0.f, -1.f);
glm::vec3 cameraUp = glm::vec3(0.f, 1.f, 0.f);
bool firstMouse = true;
float yaw = -90.f;
float pitch = 0.f;
float lastX = 640.f / 2.f;
float lastY = 480.f / 2.f;
float fov = 45.f;
float deltaTime = 0.f;
float lastFrame = 0.f;

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.f) {
        pitch = 89.f;
    }
    if (pitch < -89.f) {
        pitch = -89.f;
    }

    glm::vec3 front;
    front.x = cos(glm::radians(yaw) * cos(glm::radians(pitch)));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(front);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    fov -= (float)yoffset;
    if (fov < 1.f) {
        fov = 1.f;
    }
    if (fov > 45.f) {
        fov = 45.f;
    }
}
#endif

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
#if MOVE | MOVEANDROTATE
    float cameraSpeed = 2.5f * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        cameraPos += cameraSpeed * cameraFront;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        cameraPos -= cameraSpeed * cameraFront;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    }
#endif
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
#if MOVEANDROTATE
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
#endif


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
    Camera1* pCamera1 = new Camera1();
    pCamera1->SetModels(models);
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // 设置清空屏幕所用的颜色
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);


        models.clear();
        for (unsigned int i = 0; i < cubePositions.size(); ++i) {
            glm::mat4 model = glm::mat4(1.f);
            float angle = 20.f * i;
            model = glm::translate(model, cubePositions[i]);
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.f, 0.f, 0.f));
            //model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(1.f, 1.0f, 1.0f));
            models.push_back(model);
        }
        pCamera1->SetModels(models);
#if ONLYLOOKAT
        float radius = 10.f;
        float camX = sin(glfwGetTime()) * radius;
        float camZ = cos(glfwGetTime()) * radius;
        glm::mat4 view = glm::mat4(1.0f);
        view = glm::lookAt(glm::vec3(camX, 0.f, camZ), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 1.f, 0.f));
        pCamera1->SetView(view);
        glm::mat4 projection = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
        pCamera1->SetProjection(projection);
#endif
#if MOVE
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        glm::mat4 view = glm::mat4(1.0f);
        view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        pCamera1->SetView(view);
        glm::mat4 projection = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
        pCamera1->SetProjection(projection);
#endif
#if MOVEANDROTATE
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        // std::cout << "***************************" << std::endl;
        // for (int i = 0; i < 4; ++i) {
        //     std::cout << view[i][0] << ", " << view[i][1] << ", " << view[i][2] << ", " << view[i][3] << std::endl;
        // }
        pCamera1->SetView(view);
        glm::mat4 projection = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(fov), (float)width / (float)height, 0.1f, 100.0f);
        pCamera1->SetProjection(projection);
#endif


        pCamera1->Draws();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    //delete pCoordinateSystems1;
    delete pCamera1;
    glfwTerminate();
    return 0;
}

