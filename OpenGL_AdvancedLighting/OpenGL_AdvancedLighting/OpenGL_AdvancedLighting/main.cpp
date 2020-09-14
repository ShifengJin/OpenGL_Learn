#include <iostream>
#include <GL/glew.h>
#include <glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <glfw3native.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "CameraFPS.h"
#include "AdvancedLighting.h"
#include "ShadowMappingDepth.h"

CameraFPS gCameraFPS(glm::vec3(0.f, 0.f, 3.f));
float lastX = 640 / 2.f;
float lastY = 480 / 2.f;
bool isMouseLeftButtonPressed = false;
bool isMouseLeftButtonFirstPressed = false;
bool firstMouse = true;
float deltaTime = 0.f;
float lastFrame = 0.f;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void mouse_callback(GLFWwindow* window, double xpos, double ypos);

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

void processInput(GLFWwindow* window);


#define ADVANCEDLIGHTING 0
#define GAMMACORRECTION 0
#define SHADOWMAPPINGDEPTH 0
#define SHADOWMAPPINGBASE 1

#if ADVANCEDLIGHTING
bool blinn = false;
bool blinnKeyPressed = false;
#endif
#if GAMMACORRECTION
bool gammaEnabled = false;
bool gammaKeyPressed = false;
#endif


glm::vec3 lightPos(0.f, 0.f, 0.f);

int main() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    glfwWindowHint(GLFW_SAMPLES, 4);

    int width = 640;
    int height = 480;

    GLFWwindow* window = glfwCreateWindow(width, height, "Windows", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetScrollCallback(window, scroll_callback);

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cout << "Failed to glewInit" << std::endl;
        glfwTerminate();
        return -2;
    }

#if ADVANCEDLIGHTING
    AdvancedLighting* pAdvancedLighting = new AdvancedLighting(
        "../../Core/Shader/1.advanced_lighting.vs",
        "../../Core/Shader/1.advanced_lighting.fs",
        "../../../container.jpg"
    );
#endif
#if GAMMACORRECTION
    GammaCorrection* pGammaCorrection = new GammaCorrection(
        "../../Core/Shader/2.gamma_correction.vs",
        "../../Core/Shader/2.gamma_correction.fs",
        "../../../container.jpg");
#endif
#if SHADOWMAPPINGDEPTH
    ShadowMappingDepth* pShadowMappingDepth = new ShadowMappingDepth(
        "../../Core/Shader/3.1.1.shadow_mapping_depth.vs",
        "../../Core/Shader/3.1.1.shadow_mapping_depth.fs",
        "../../Core/Shader/3.1.1.debug_quad.vs",
        "../../Core/Shader/3.1.1.debug_quad_depth.fs",
        "../../../container.jpg", 1024, 1024, width, height
    );
#endif
#if SHADOWMAPPINGBASE
    ShadowMappingBase* pShadowMappingBase = new ShadowMappingBase(width, height);
    pShadowMappingBase->SetShadowSize(1024, 1024);
    glm::vec3 lightPos(-2.f, 8.f, -1.f);
    pShadowMappingBase->SetLightPos(lightPos);
    float near_plane = 0.1f;
    float far_plane = 100.f;
    pShadowMappingBase->SetNearFar(near_plane, far_plane);

    glm::mat4 lightProjection = glm::ortho(-10.f, 10.f, -10.f, 10.f, near_plane, far_plane);
    glm::mat4 lightView = glm::lookAt(lightPos, glm::vec3(0.f), glm::vec3(0.f, 1.f, 0.f));
    pShadowMappingBase->SetLightProjection(lightProjection);
    pShadowMappingBase->SetLightView(lightView);
#endif


    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window)) {
        float currentFrame = (float)glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        processInput(window);
        glm::mat4 projection = glm::perspective(glm::radians(gCameraFPS.Zoom), (float)640 / (float)480, 0.1f, 1000.f);

        glm::mat4 view = gCameraFPS.GetViewMatrix();

#if ADVANCEDLIGHTING
        pAdvancedLighting->SetBlinn(blinn);
        pAdvancedLighting->SetCameraPosition(gCameraFPS.Position);
        pAdvancedLighting->SetLightPos(lightPos);
        pAdvancedLighting->SetProjection(projection);
        pAdvancedLighting->SetView(view);
        pAdvancedLighting->Draw();
        std::cout << (blinn ? "Blinn-Phong" : "Phong") << std::endl;

#endif
#if GAMMACORRECTION
        pGammaCorrection->SetEnableGamma(gammaEnabled);
        pGammaCorrection->SetProjection(projection);
        pGammaCorrection->SetCameraPosition(gCameraFPS.Position);
        pGammaCorrection->SetView(view);
        pGammaCorrection->Draw();
#endif
#if SHADOWMAPPINGDEPTH
        glm::vec3 lightPos(-2.f, 4.f, -1.f);
        pShadowMappingDepth->SetLightPos(lightPos);
        pShadowMappingDepth->SetNearFarPlane(1.f, 7.5f);
        glm::mat4 lightProjection = glm::ortho(-10.f, 10.f, -10.f, 10.f, 1.f, 7.5f);
        glm::mat4 lightView = glm::lookAt(lightPos, glm::vec3(0.f), glm::vec3(0.f, 1.f, 0.f));
        pShadowMappingDepth->SetLightProjection(lightProjection);
        pShadowMappingDepth->SetLightView(lightView);
        pShadowMappingDepth->Draw();
#endif
#if SHADOWMAPPINGBASE
        pShadowMappingBase->SetProjection(projection);
        pShadowMappingBase->SetView(view);
        pShadowMappingBase->SetCameraPosition(gCameraFPS.Position);
        pShadowMappingBase->Draw();
#endif
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

#if ADVANCEDLIGHTING
    delete pAdvancedLighting;
#endif
#if GAMMACORRECTION
    delete pGammaCorrection;
#endif
#if SHADOWMAPPINGDEPTH
    delete pShadowMappingDepth;
#endif
#if SHADOWMAPPINGBASE
    delete pShadowMappingBase;
#endif
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    if (isMouseLeftButtonPressed) {
        if (isMouseLeftButtonFirstPressed) {
            isMouseLeftButtonFirstPressed = false;
            lastX = xpos;
            lastY = ypos;
        }

        float xoffset = (float)xpos - lastX;
        float yoffset = lastY - (float)ypos;
        lastX = (float)xpos;
        lastY = (float)ypos;
        gCameraFPS.ProcessMouseMovement(xoffset, yoffset);
    }
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (action == GLFW_PRESS) {
        switch (button) {
        case GLFW_MOUSE_BUTTON_LEFT:
            isMouseLeftButtonPressed = true;
            isMouseLeftButtonFirstPressed = true;
            break;
        default:
            break;
        }
    }
    if (action == GLFW_RELEASE) {
        switch (button){
            case GLFW_MOUSE_BUTTON_LEFT:
                isMouseLeftButtonPressed = false;
                break;
            default:
                break;
        }
    }
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
#if ADVANCEDLIGHTING
    if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS && !blinnKeyPressed) {
        blinn = !blinn;
        blinnKeyPressed = true;
    }
    if (glfwGetKey(window, GLFW_KEY_B) == GLFW_RELEASE) {
        blinnKeyPressed = false;
    }
#endif
#if GAMMACORRECTION
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && !gammaKeyPressed) {
        gammaEnabled = !gammaEnabled;
        gammaKeyPressed = true;
    }
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE) {
        gammaKeyPressed = false;
    }
#endif
}