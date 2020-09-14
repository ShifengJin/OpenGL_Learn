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
#include <glm/gtx/string_cast.hpp>
#include "stb_image.h"
#include "CameraFPS.h"
#include "Model.h"
#include "Mesh.h"
#include "Shader.h"

#if 0
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
#else

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

// 鼠标左键为模型旋转
// 鼠标右键为相机移动
#define MouseSensitivity 0.01f
static bool isMouseLeftButtonPressed = false;
static bool isMouseLeftButtonFirstPressed = false;
static bool isMouseRightButtonPressed = false;
static bool isMouseRightButtonFirstPressed = false;
double leftMouseButton_x_pre = 0.f;
double leftMouseButton_y_pre = 0.f;
double leftMouseButton_x_cur = 0.f;
double leftMouseButton_y_cur = 0.f;
double rightMouseButton_x_pre = 0.f;
double rightMouseButton_y_pre = 0.f;
double rightMouseButton_x_cur = 0.f;
double rightMouseButton_y_cur = 0.f;

glm::mat4 gModelMatrix = glm::mat4(1.f);
glm::mat4 gViewMatrix = glm::mat4(1.f);

float gRadius = 30.f;
glm::vec3 gEye = glm::vec3(0.f, 0.f, gRadius);
glm::vec3 gCenter = glm::vec3(0.f, 0.f, 0.f);
glm::vec3 gUp = glm::vec3(0.f, 1.f, 0.f);

glm::vec3 gModelPosition = glm::vec3(0.f, 0.f, 0.f);

glm::mat4 MatrixRT_RxR(glm::mat4 leftMat4, glm::mat4 rightMat4) {
    glm::mat3 RotateMatrix3 = glm::mat3(leftMat4);

    glm::mat3 resultMatrix = glm::mat3(1.f);

    glm::mat3 modelMatrix3 = glm::mat3(rightMat4);

    resultMatrix = RotateMatrix3 * modelMatrix3;

    glm::mat4 result = glm::mat4(
        glm::vec4(resultMatrix[0], 0.f),
        glm::vec4(resultMatrix[1], 0.f),
        glm::vec4(resultMatrix[2], 0.f),
        gModelMatrix[3]);
    return result;
}

glm::mat4 MatrixRT_RxR1(glm::mat4 leftMat4, glm::mat4 rightMat4) {
    glm::mat3 RotateMatrix3 = glm::mat3(leftMat4);

    glm::mat3 resultMatrix = glm::mat3(1.f);

    glm::mat3 modelMatrix3 = glm::mat3(rightMat4);

    resultMatrix = RotateMatrix3 * modelMatrix3;

    glm::mat4 result = glm::mat4(
        glm::vec4(resultMatrix[0], 0.f),
        glm::vec4(resultMatrix[1], 0.f),
        glm::vec4(resultMatrix[2], 0.f),
        leftMat4[3]);
    return result;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (action == GLFW_PRESS) {
        switch (button) {
        case GLFW_MOUSE_BUTTON_LEFT:
            isMouseLeftButtonPressed = true;
            isMouseLeftButtonFirstPressed = true;
            break;
        case GLFW_MOUSE_BUTTON_MIDDLE:
            break;
        case GLFW_MOUSE_BUTTON_RIGHT:
            isMouseRightButtonPressed = true;
            isMouseRightButtonFirstPressed = true;
            break;
        default:
            break;
        }
    }
    else if (action == GLFW_RELEASE) {
        switch (button) {
        case GLFW_MOUSE_BUTTON_LEFT:
            isMouseLeftButtonPressed = false;
            break;
        case GLFW_MOUSE_BUTTON_MIDDLE:
            break;
        case GLFW_MOUSE_BUTTON_RIGHT:
            isMouseRightButtonPressed = false;
            break;
        default:
            break;
        }
    }
}

void mouse_move_callback(GLFWwindow* window, double xpos, double ypos) {

    if (isMouseLeftButtonPressed) {
        leftMouseButton_x_pre = leftMouseButton_x_cur;
        leftMouseButton_y_pre = leftMouseButton_y_cur;
        leftMouseButton_x_cur = xpos;
        leftMouseButton_y_cur = ypos;

        if (isMouseLeftButtonFirstPressed) {
            isMouseLeftButtonFirstPressed = false;
            leftMouseButton_x_pre = xpos;
            leftMouseButton_y_pre = ypos;
            leftMouseButton_x_cur = xpos;
            leftMouseButton_y_cur = ypos;
        }
        float xoffset = (leftMouseButton_x_cur - leftMouseButton_x_pre) * MouseSensitivity;
        float yoffset = (leftMouseButton_y_cur - leftMouseButton_y_pre) * MouseSensitivity;

        glm::mat4 xRotateMatrix = glm::mat4(1.f);
        xRotateMatrix = glm::rotate(xRotateMatrix, yoffset, glm::vec3(1.f, 0.f, 0.f));

        glm::mat4 yRotateMatrix = glm::mat4(1.f);
        yRotateMatrix = glm::rotate(yRotateMatrix, xoffset, glm::vec3(0.f, 1.f, 0.f));

        // 相机坐标系下旋转的角度
        glm::mat4 cameraSystemRotate = glm::inverse(gViewMatrix) * yRotateMatrix * xRotateMatrix * gViewMatrix;
        gModelMatrix = MatrixRT_RxR(cameraSystemRotate, gModelMatrix);
    }

    if (isMouseRightButtonPressed) {
        rightMouseButton_x_pre = rightMouseButton_x_cur;
        rightMouseButton_y_pre = rightMouseButton_y_cur;
        rightMouseButton_x_cur = xpos;
        rightMouseButton_y_cur = ypos;
        if (isMouseRightButtonFirstPressed) {
            isMouseRightButtonFirstPressed = false;
            rightMouseButton_x_pre = xpos;
            rightMouseButton_y_pre = ypos;
            rightMouseButton_x_cur = xpos;
            rightMouseButton_y_cur = ypos;
        }
        float xoffset = (rightMouseButton_x_cur - rightMouseButton_x_pre) * MouseSensitivity;
        float yoffset = (rightMouseButton_y_cur - rightMouseButton_y_pre) * MouseSensitivity;

        glm::mat4 xRotateMatrix = glm::mat4(1.f);
        xRotateMatrix = glm::rotate(xRotateMatrix, yoffset, glm::vec3(1.f, 0.f, 0.f));

        glm::mat4 yRotateMatrix = glm::mat4(1.f);
        yRotateMatrix = glm::rotate(yRotateMatrix, xoffset, glm::vec3(0.f, 1.f, 0.f));

#if 1
        glm::mat4 cameraSystemRotate = glm::inverse(gViewMatrix) * yRotateMatrix * xRotateMatrix * gViewMatrix;
        glm::mat4 t = gViewMatrix * cameraSystemRotate;
        std::cout << "cameraSystemRotate : " << std::endl;
        std::cout << glm::to_string(cameraSystemRotate) << std::endl;
        gViewMatrix = MatrixRT_RxR1(gViewMatrix, cameraSystemRotate);
        std::cout << glm::to_string(gViewMatrix) << std::endl;
#else

        glm::mat4 cameraSystemRotate = glm::inverse(gViewMatrix) * yRotateMatrix * xRotateMatrix * gViewMatrix;
        gViewMatrix = cameraSystemRotate * glm::inverse(gViewMatrix);
        gViewMatrix = glm::inverse(gViewMatrix);
        std::cout << "gViewMatrix : " << std::endl;
        std::cout << glm::to_string(gViewMatrix) << std::endl;
#endif
    }
}

int main() {
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
    glfwSetCursorPosCallback(window, mouse_move_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cout << "Failed to glewInit" << std::endl;
        glfwTerminate();
        return -2;
    }
    glEnable(GL_DEPTH_TEST);

    Shader ourShader(
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_IntermediateLevel\\Core\\Shader\\2.model_loading.vs",
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_IntermediateLevel\\Core\\Shader\\2.model_loading.fs");

    // 此处必须为相对路径
    // Model ourModel("../../nanosuit/nanosuit.obj");
    Model ourModel("../../11/arrow.obj");

    glm::mat4 projection = glm::perspective(45.f, (float)width / (float)height, 0.1f, 1000.f);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << projection[i][j] << "f, ";
        }
        std::cout << std::endl;
    }

    gModelMatrix = glm::translate(gModelMatrix, gModelPosition);
    gModelMatrix = glm::scale(gModelMatrix, glm::vec3(1.f, 1.f, 1.f));
    std::cout << glm::to_string(gModelMatrix) << std::endl;

    gCenter = gModelPosition;
    gEye = glm::vec3(gCenter.x, gCenter.y, gCenter.z + gRadius);    
    gViewMatrix = glm::lookAt(gEye, gCenter, gUp);


    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << gViewMatrix[i][j] << "f, ";
        }
        std::cout << std::endl;
    }

    ourShader.Use();

    ourShader.SetMat4("projection", glm::value_ptr(projection));
    while (!glfwWindowShouldClose(window)) {

        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);  // 设置清空屏幕所用的颜色
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ourShader.Use();
        ourShader.SetMat4("view", glm::value_ptr(gViewMatrix));

        ourShader.SetVec3("viewPos", glm::value_ptr(gEye));
        glm::vec3 direction(0.f, 0.f, -1.f);
        ourShader.SetVec3("dirLight.direction", glm::value_ptr(direction));

        glm::vec3 ambient(0.5f, 0.5f, 0.5f);
        ourShader.SetVec3("dirLight.ambient", glm::value_ptr(ambient));

        glm::vec3 diffuse(0.4f, 0.4f, 0.4f);
        ourShader.SetVec3("dirLight.diffuse", glm::value_ptr(diffuse));
        glm::vec3 specular(1.f, 1.f, 1.f);
        ourShader.SetVec3("dirLight.specular", glm::value_ptr(specular));


        ourShader.SetMat4("model", glm::value_ptr(gModelMatrix));
        ourModel.Draw(ourShader);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

#endif
