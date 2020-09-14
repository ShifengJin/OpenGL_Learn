#include <iostream>
#include <GL/glew.h>
#include <glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <glfw3native.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <CameraFPS.h>

#include "OpenGL_DepthTest.h"
#include "OpenGL_StencilTesting.h"
#include "OpenGL_Blending.h"
#include "OpenGL_FaceCulling.h"
#include "OpenGL_FrameBuffers.h"
#include "OpenGL_CubemapsSkybox.h"
#include "OpenGL_GLSL.h"
#include "OpenGL_Geometry.h"
#include "OpenGL_Instancing.h"
#include "OpenGL_AntiAliasing.h"




#define DEPTHTEST 0
#define STENCILTEST 0
#define BLENDING 0
#define BLENDINGSORTED 0
#define FACECULLING 0
#define FRAMEBUFFER 0
#define CUBEMAPSSKYBOX 0
#define POINTSIZEFRAGCOORD 0
#define BLOCKFRAGDEPTH 0
#define GEOMETRY 0
#define GEOMETRYSHADEREXPLODING 0
#define GEOMETRYNORMAL 0
#define INSTANCING 0
#define INSTANCINGASTEROIDS 0
#define ASTEROIDSINSTANCED 0
#define ANTIALIASING 0
#define ANTIALIASINGOFFSCREEN 1


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

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  // 主版本号
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);  // 次版本号
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);       // 不予许修改窗口尺寸

    glfwWindowHint(GLFW_SAMPLES, 4);

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
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetScrollCallback(window, scroll_callback);

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cout << "Failed to glewInit" << std::endl;
        glfwTerminate();
        return -2;
    }
#if DEPTHTEST
    DepthTest* pDepthTest = new DepthTest(
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_Advanced\\Core\\Shader\\1.1.depth_testing.vs", 
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_Advanced\\Core\\Shader\\1.1.depth_testing.fs",
        "D:\\WorkSpace\\OpenGLWorkSpace\\marble.jpg", "D:\\WorkSpace\\OpenGLWorkSpace\\metal.jpg");
#endif

#if STENCILTEST
    StencilTesting *pStencilTesting = new StencilTesting(
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_Advanced\\Core\\Shader\\2.stencil_testing.vs",
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_Advanced\\Core\\Shader\\2.stencil_testing.fs",
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_Advanced\\Core\\Shader\\2.stencil_testing.vs",
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_Advanced\\Core\\Shader\\2.stencil_single_color.fs",
        "D:\\WorkSpace\\OpenGLWorkSpace\\marble.jpg", "D:\\WorkSpace\\OpenGLWorkSpace\\metal.jpg");
#endif
#if BLENDING
    Blending *pBlending = new Blending(
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_Advanced\\Core\\Shader\\3.1.blending.vs",
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_Advanced\\Core\\Shader\\3.1.blending.fs", 
        "D:\\WorkSpace\\OpenGLWorkSpace\\marble.jpg", 
        "D:\\WorkSpace\\OpenGLWorkSpace\\metal.jpg", 
        "D:\\WorkSpace\\OpenGLWorkSpace\\grass.png");
#endif

#if BLENDINGSORTED
    BlendingSorted* pBlendingSorted = new BlendingSorted(
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_Advanced\\Core\\Shader\\3.2.blending.vs",
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_Advanced\\Core\\Shader\\3.2.blending.fs",
        "D:\\WorkSpace\\OpenGLWorkSpace\\marble.jpg",
        "D:\\WorkSpace\\OpenGLWorkSpace\\metal.jpg",
        "D:\\WorkSpace\\OpenGLWorkSpace\\blending_transparent_window.png");
#endif
#if FACECULLING
    FaceCulling* pFaceCulling = new FaceCulling(
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_Advanced\\Core\\Shader\\3.2.blending.vs",
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_Advanced\\Core\\Shader\\3.2.blending.fs",
        "D:\\WorkSpace\\OpenGLWorkSpace\\marble.jpg",
        "D:\\WorkSpace\\OpenGLWorkSpace\\wall.jpg"
    );
#endif
#if FRAMEBUFFER
    FrameBuffer* pFrameBuffer = new FrameBuffer(
        width, height,
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_Advanced\\Core\\Shader\\5.1.framebuffers.vs",
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_Advanced\\Core\\Shader\\5.1.framebuffers.fs",
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_Advanced\\Core\\Shader\\5.1.framebuffers_screen.vs",
        "D:\\WorkSpace\\OpenGLWorkSpace\\OpenGL_Advanced\\Core\\Shader\\5.1.framebuffers_screen.fs",
        "D:\\WorkSpace\\OpenGLWorkSpace\\metal.jpg", 
        "D:\\WorkSpace\\OpenGLWorkSpace\\container.jpg"
    );
#endif
#if CUBEMAPSSKYBOX
    SkyBox* pSkyBox = new SkyBox(
        // "../Core/Shader/6.1.cubemaps.vs",
        // "../Core/Shader/6.1.cubemaps.fs",
        // "../Core/Shader/6.1.skybox.vs",
        // "../Core/Shader/6.1.skybox.fs",
        // "../Core/Shader/6.2.cubemaps.vs",
        // "../Core/Shader/6.2.cubemaps.fs",
        // "../Core/Shader/6.2.skybox.vs",
        // "../Core/Shader/6.2.skybox.fs",
        "../Core/Shader/6.2.cubemaps.vs",
        "../Core/Shader/6.3.refract.fs",
        "../Core/Shader/6.2.skybox.vs",
        "../Core/Shader/6.2.skybox.fs",
        "../../container.jpg",
        "../../skybox"
    );
#endif
#if POINTSIZEFRAGCOORD
    GLSL_PointSize_FragCoord* pPointSizeFragCoord = new GLSL_PointSize_FragCoord(
        "../Core/Shader/6.4.1.pointSizeFragCoord.vs",
        "../Core/Shader/6.4.1.pointSizeFragCoord.fs"
    );
#endif
#if BLOCKFRAGDEPTH
    GLSL_Block_FragDepth* pBlockFragDepth = new GLSL_Block_FragDepth(
        "../Core/Shader/6.4.2.BlockFragDepth.vs", "../Core/Shader/6.4.2.BlockFragDepth.fs",
        "../../container.jpg", 
        "../../container2.png", 
        "../../marble.jpg", 
        "../../metal.jpg");

#endif
#if GEOMETRY
    Geometry* pGeometry = new Geometry(
        "../Core/Shader/9.1.geometry_shader.vs", 
        "../Core/Shader/9.1.geometry_shader.gs",
        "../Core/Shader/9.1.geometry_shader.fs"
    );
#endif
#if GEOMETRYSHADEREXPLODING
    GeometryShaderExploding* pGeometryShaderExploding = new GeometryShaderExploding(
        "../Core/Shader/9.2.geometry_shader.vs",
        "../Core/Shader/9.2.geometry_shader.gs",
        "../Core/Shader/9.2.geometry_shader.fs",
        "../../nanosuit/nanosuit.obj"
    );
#endif
#if GEOMETRYNORMAL
    GeometryShaderNormals* pGeometryShaderNormals = new GeometryShaderNormals(
        "../Core/Shader/9.3.default.vs",
        "../Core/Shader/9.3.default.fs",
        "../Core/Shader/9.3.normal_visualization.vs",
        "../Core/Shader/9.3.normal_visualization.fs",
        "../Core/Shader/9.3.normal_visualization.gs",
        "../../nanosuit/nanosuit.obj"
    );
#endif
#if INSTANCING
    Instancing* pInstancing = new Instancing(
        "../Core/Shader/10.1.instancing.vs",
        "../Core/Shader/10.1.instancing.fs");
#endif
#if INSTANCINGASTEROIDS
    InstancingAsteroids* pInstancingAsteroids = new InstancingAsteroids(
        "../Core/Shader/10.2.instancing.vs",
        "../Core/Shader/10.2.instancing.fs",
        "../../rock/rock.obj",
        "../../planet/planet.obj"
    );
#endif
#if ASTEROIDSINSTANCED
    AsteroidsInstanced* pAsteroidsInstanced = new AsteroidsInstanced(
        "../Core/Shader/10.3.asteroids.vs",
        "../Core/Shader/10.3.asteroids.fs",
        "../Core/Shader/10.3.planet.vs",
        "../Core/Shader/10.3.planet.fs",
        "../../rock/rock.obj",
        "../../planet/planet.obj"
    );
#endif
#if ANTIALIASING
    AntiAliasingMsaa* pAntiAliasingMsaa = new AntiAliasingMsaa(
        "../Core/Shader/11.1.anti_aliasing.vs",
        "../Core/Shader/11.1.anti_aliasing.fs"
    );
#endif
#if ANTIALIASINGOFFSCREEN
    AntiAliasingOffscreen* pAntiAliasingOffscreen = new AntiAliasingOffscreen(
        "../Core/Shader/11.2.anti_aliasing.vs",
        "../Core/Shader/11.2.anti_aliasing.fs",
        "../Core/Shader/11.2.aa_post.vs",
        "../Core/Shader/11.2.aa_post.fs",
        width, height);
#endif


    glEnable(GL_DEPTH_TEST);
    // glDepthFunc(GL_ALWAYS);
    // glDepthFunc(GL_LESS);
    
#if STENCILTEST
    glEnable(GL_STENCIL_TEST);
    glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
#endif
#if BLENDINGSORTED
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
#endif
#if FACECULLING
    glEnable(GL_CULL_FACE); // 

    glFrontFace(GL_CCW);   // GL_CCW(默认值)，它代表的是逆时针的环绕顺序  GL_CW 代表的是顺时针顺序
    glCullFace(GL_FRONT);  // 剔除前面

    // glEnable(GL_CULL_FACE);
    // glCullFace(GL_BACK);
    // glFrontFace(GL_CW);

    // glEnable(GL_CULL_FACE);
    // glCullFace(GL_FRONT);
#endif
    while (!glfwWindowShouldClose(window)) {

        float currentFrame = (float)glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(window);

        glm::mat4 projection = glm::perspective(glm::radians(gCameraFPS.Zoom), (float)640 / (float)480, 0.1f, 1000.f);
        glm::mat4 view = gCameraFPS.GetViewMatrix();
#if DEPTHTEST
        pDepthTest->SetView(view);
        pDepthTest->SetProjection(projection);

        glm::mat4 cubeModel1 = glm::mat4(1.f);
        cubeModel1 = glm::translate(cubeModel1, glm::vec3(-1.f, 0.001f, -1.f));

        glm::mat4 cubeModel2 = glm::mat4(1.f);
        cubeModel2 = glm::translate(cubeModel2, glm::vec3(2.f, 0.001f, 0.f));
        
        glm::mat4 planeModel = glm::mat4(1.f);
        
        pDepthTest->SetCubeModel(cubeModel1, cubeModel2);
        pDepthTest->SetPlaneModel(planeModel);

        pDepthTest->Draw();
#endif
#if STENCILTEST
        pStencilTesting->SetView(view);
        pStencilTesting->SetProjection(projection);
        glm::mat4 floorModel = glm::mat4(1.f);
        glm::mat4 cubeModel1 = glm::mat4(1.f);
        glm::mat4 cubeModel2 = glm::mat4(1.f);
        cubeModel1 = glm::translate(cubeModel1, glm::vec3(-1.f, 0.f, -1.f));
        cubeModel2 = glm::translate(cubeModel2, glm::vec3(2.f, 0.f, 0.f));
        pStencilTesting->SetCubeModel(cubeModel1, cubeModel2);
        pStencilTesting->SetFloorModel(floorModel);

        pStencilTesting->DrawModel();
        pStencilTesting->DrawStencil();

#endif
#if BLENDING
        pBlending->SetProjectionMatrix(projection);
        pBlending->SetViewMatrix(view);
        pBlending->Draw();
#endif
#if BLENDINGSORTED
        pBlendingSorted->SetProjectionMatrix(projection);
        pBlendingSorted->SetViewMatrix(view);
        pBlendingSorted->Draw(gCameraFPS.Position);
        
#endif
#if FACECULLING
        pFaceCulling->SetProjectionMatrix(projection);
        pFaceCulling->SetViewMatrix(view);
        pFaceCulling->Draw();
#endif
#if FRAMEBUFFER
        pFrameBuffer->SetProjectionMatrix(projection);
        pFrameBuffer->SetViewMatrix(view);
        pFrameBuffer->Draw();
#endif
#if CUBEMAPSSKYBOX
        pSkyBox->SetCameraPosition(gCameraFPS.Position);
        pSkyBox->SetProjectionMatrix(projection);
        pSkyBox->SetViewMatrix(view);
        pSkyBox->Draw();
#endif

#if POINTSIZEFRAGCOORD
        pPointSizeFragCoord->SetProjectionMatrix(projection);
        pPointSizeFragCoord->SetViewMatrix(view);
        pPointSizeFragCoord->Draw();
#endif
#if BLOCKFRAGDEPTH
        pBlockFragDepth->SetViewMatrix(view);
        pBlockFragDepth->SetProjectionMatrix(projection);
        pBlockFragDepth->Draw();
#endif
#if GEOMETRY
        pGeometry->Draw();
#endif
#if GEOMETRYSHADEREXPLODING
        pGeometryShaderExploding->SetProjection(projection);
        pGeometryShaderExploding->SetView(view);
        glm::mat4 model = glm::mat4(1.0f);
        pGeometryShaderExploding->SetModel(model);
        pGeometryShaderExploding->SetTime(currentFrame);
        pGeometryShaderExploding->Draw();
#endif
#if GEOMETRYNORMAL
        pGeometryShaderNormals->SetProjection(projection);
        pGeometryShaderNormals->SetView(view);
        glm::mat4 model = glm::mat4(1.f);
        pGeometryShaderNormals->SetModel(model);
        pGeometryShaderNormals->Draw();
#endif
#if INSTANCING
        pInstancing->Draw();
#endif
#if INSTANCINGASTEROIDS
        pInstancingAsteroids->SetProjection(projection);
        pInstancingAsteroids->SetView(view);
        pInstancingAsteroids->Draw();
#endif
#if ASTEROIDSINSTANCED
        pAsteroidsInstanced->SetProjection(projection);
        pAsteroidsInstanced->SetView(view);
        pAsteroidsInstanced->Draw();
#endif
#if ANTIALIASING
        pAntiAliasingMsaa->SetProjection(projection);
        pAntiAliasingMsaa->SetView(view);
        pAntiAliasingMsaa->Draw();
#endif
#if ANTIALIASINGOFFSCREEN
        pAntiAliasingOffscreen->SetProjection(projection);
        pAntiAliasingOffscreen->SetView(view);
        pAntiAliasingOffscreen->Draw();
#endif
        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    glfwTerminate();
#if DEPTHTEST
    delete pDepthTest;
#endif
#if STENCILTEST
    delete pStencilTesting;
#endif
#if BLENDING
    delete pBlending;
#endif
#if FACECULLING
    delete pFaceCulling;
#endif
#if FRAMEBUFFER
    delete pFrameBuffer;
#endif
#if CUBEMAPSSKYBOX
    delete pSkyBox;
#endif
#if BLOCKFRAGDEPTH
    delete pBlockFragDepth;
#endif
#if GEOMETRY
    delete pGeometry;
#endif
#if GEOMETRYSHADEREXPLODING
    delete pGeometryShaderExploding;
#endif
#if GEOMETRYNORMAL
    delete pGeometryShaderNormals;
#endif
#if INSTANCING
    delete pInstancing;
#endif
#if INSTANCINGASTEROIDS
    delete pInstancingAsteroids;
#endif
#if ASTEROIDSINSTANCED
    delete pAsteroidsInstanced;
#endif
#if ANTIALIASING
    delete pAntiAliasingMsaa;
#endif
#if ANTIALIASINGOFFSCREEN
    delete pAntiAliasingOffscreen;
#endif
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
    if (action == GLFW_PRESS)
    {
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
        switch (button) {
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
}