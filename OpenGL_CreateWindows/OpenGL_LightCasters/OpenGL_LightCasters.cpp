// OpenGL_CreateWindows.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <vector>
#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <glfw3native.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "CameraFPS.h"
#include "LightCasters.h"


CameraFPS gCameraFPS(glm::vec3(0.f, 0.f, 3.f));
float lastX = 640 / 2.f;
float lastY = 480 / 2.f;
bool firstMouse = true;
float deltaTime = 0.f;
float lastFrame = 0.f;

glm::vec3 lightPos(1.2f, 1.f, 2.f);
#define ON 1
#define OFF 0
#define DIRECTIONALIGHT OFF
#define POINTLIGHT OFF
#define SPOTLIGHT OFF
#define MULTIPLELIGHT ON

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
#if DIRECTIONALIGHT
    DirectionalLight* pDirectionLight = new DirectionalLight();
#endif
#if POINTLIGHT
    PointLight* pPointLight = new PointLight();
#endif
#if SPOTLIGHT
    SpotLight* pSpotLight = new SpotLight();
#endif
    glm::vec3 cubePositions[] = {
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

#if MULTIPLELIGHT
    std::string diffuseImagePath = "D:/WorkSpace/OpenGLWorkSpace/container2.png";
    std::string specularImagePath = "D:/WorkSpace/OpenGLWorkSpace/container2_specular.png";
    // MULTIPLELIGHT_SRC = 0,
    // MULTIPLELIGHT_DESERT,
    // MULTIPLELIGHT_FACTORY,
    // MULTIPLELIGHT_HORROR,
    // MULTIPLELIGHT_BIOCHEMICALLAB,
    MultipleLight* pMultipleLight = new MultipleLight(diffuseImagePath, 
        specularImagePath, MULTIPLELIGHT_SRC);
#endif

    while (!glfwWindowShouldClose(window)) {

        float currentFrame = (float)glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(window);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // 设置清空屏幕所用的颜色

        glm::mat4 projection = glm::perspective(glm::radians(gCameraFPS.Zoom), (float)640 / (float)480, 0.1f, 100.f);
        glm::mat4 view = gCameraFPS.GetViewMatrix();
#if DIRECTIONALIGHT
        pDirectionLight->SetProjection(projection);
        pDirectionLight->SetView(view);


        pDirectionLight->SetCameraPosition(gCameraFPS.Position);
        glm::vec3 lightDirection(-0.2f, -1.f, -0.3f);
        glm::vec3 lightAmbient(0.2f, 0.2f, 0.2f);
        glm::vec3 lightDiffuse(0.5f, 0.5f, 0.5f);
        glm::vec3 lightSpecular(1.f, 1.f, 1.f);
        pDirectionLight->SetLightDirection(lightDirection);
        pDirectionLight->SetLightAmbient(lightAmbient);
        pDirectionLight->SetLightDiffuse(lightDiffuse);
        pDirectionLight->SetLightSpecular(lightSpecular);
       

        pDirectionLight->DrawInit();
        for(int i = 0; i < 10; ++ i){
            glm::mat4 model = glm::mat4(1.f);
            model = glm::translate(model, cubePositions[i]);
            float angle = 20.f * i;
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.f, 0.3f, 0.5f));
            pDirectionLight->SetModel(model);

            pDirectionLight->Draw();
        }
#endif
#if POINTLIGHT
        pPointLight->SetProjection(projection);
        pPointLight->SetView(view);


        pPointLight->SetCameraPosition(gCameraFPS.Position);
        glm::vec3 lightAmbient(0.2f, 0.2f, 0.2f);
        glm::vec3 lightDiffuse(0.5f, 0.5f, 0.5f);
        glm::vec3 lightSpecular(1.f, 1.f, 1.f);
        pPointLight->SetLightPosition(lightPos);
        pPointLight->SetLightParameter(1.f, 0.09f, 0.032f);
        pPointLight->SetLightAmbient(lightAmbient);
        pPointLight->SetLightDiffuse(lightDiffuse);
        pPointLight->SetLightSpecular(lightSpecular);


        pPointLight->DrawInit();
        for (int i = 0; i < 10; ++i) {
            glm::mat4 model = glm::mat4(1.f);
            model = glm::translate(model, cubePositions[i]);
            float angle = 20.f * i;
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.f, 0.3f, 0.5f));
            pPointLight->SetModel(model);

            pPointLight->Draw();
        }

        glm::mat4 lightModel = glm::mat4(1.f);
        lightModel = glm::translate(lightModel, lightPos);
        lightModel = glm::scale(lightModel, glm::vec3(0.1));

        pPointLight->SetLightModel(lightModel);
        pPointLight->DrawLight();
#endif
#if SPOTLIGHT
        pSpotLight->SetProjection(projection);
        pSpotLight->SetView(view);


        pSpotLight->SetCameraPosition(gCameraFPS.Position);
        glm::vec3 lightAmbient(0.2f, 0.2f, 0.2f);
        glm::vec3 lightDiffuse(0.5f, 0.5f, 0.5f);
        glm::vec3 lightSpecular(1.f, 1.f, 1.f);

        pSpotLight->SetLightPosition(gCameraFPS.Position);

        pSpotLight->SetLightParameter(1.f, 0.09f, 0.032f);
        pSpotLight->SetLightAmbient(lightAmbient);
        pSpotLight->SetLightDiffuse(lightDiffuse);
        pSpotLight->SetLightSpecular(lightSpecular);
        pSpotLight->SetLightCutOff(glm::cos(glm::radians(12.5f)));
        pSpotLight->SetLightCutOff(glm::cos(glm::radians(17.5f)));
        pSpotLight->SetLightDirection(gCameraFPS.Front);

        pSpotLight->DrawInit();
        for (int i = 0; i < 10; ++i) {
            glm::mat4 model = glm::mat4(1.f);
            model = glm::translate(model, cubePositions[i]);
            float angle = 20.f * i;
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.f, 0.3f, 0.5f));
            pSpotLight->SetModel(model);

            pSpotLight->Draw();
        }

        glm::mat4 lightModel = glm::mat4(1.f);
        lightModel = glm::translate(lightModel, gCameraFPS.Position);
        lightModel = glm::scale(lightModel, glm::vec3(0.1));

        pSpotLight->SetLightModel(lightModel);
        pSpotLight->DrawLight();
#endif
#if MULTIPLELIGHT
        pMultipleLight->SetCameraPosition(gCameraFPS.Position);
        pMultipleLight->SetCameraFront(gCameraFPS.Front);
        pMultipleLight->SetProjection(projection);
        pMultipleLight->SetView(view);

        pMultipleLight->Draw();

#endif
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
#if DIRECTIONALIGHT
    delete pDirectionLight;
#endif
#if POINTLIGHT
    delete pPointLight;
#endif
#if SPOTLIGHT
    delete pSpotLight;
#endif
#if MULTIPLELIGHT
    delete pMultipleLight;
#endif

    glfwTerminate();
    return 0;
}

