#pragma once
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"

#define NR_POINT_LIGHTS 4
#define CUBENUMBER 10

typedef struct _DIRLIGHT_ {
    glm::vec3 direction;
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
}DirLightParameter;

typedef struct _POINTLIGHT_ {
    glm::vec3 position;
    float constant;
    float linear;
    float quadratic;
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    glm::vec3 color;
}PointLightParameter;

typedef struct _SPOTLIGHT_ {
    glm::vec3 position;
    glm::vec3 direction;
    float cutOff;
    float outerCutOff;

    float constant;
    float linear;
    float quadratic;

    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
}SpotLightParameter;

typedef struct _MultipleLight_ {
    glm::vec4            clearColor;
    DirLightParameter    mDirLight;
    PointLightParameter  mPointLights[NR_POINT_LIGHTS];
    SpotLightParameter   mSpotLight;
}MultipleLightParameter;


typedef enum _MULTIPLELIGHTTYPE_ {
    MULTIPLELIGHT_SRC = 0,
    MULTIPLELIGHT_DESERT,
    MULTIPLELIGHT_FACTORY,
    MULTIPLELIGHT_HORROR,
    MULTIPLELIGHT_BIOCHEMICALLAB,
    MULTIPLELIGHT_NUMBER,
}MULTIPLELIGHTTYPE;

// ƽ�й�
class DirectionalLight {

public:
    DirectionalLight();
    ~DirectionalLight();

    void SetLightDirection(glm::vec3& inLightDirection);
    void SetLightAmbient(glm::vec3& inLightAmbient);
    void SetLightDiffuse(glm::vec3& inLightDiffuse);
    void SetLightSpecular(glm::vec3& inLightSpecular);

    void SetCameraPosition(glm::vec3& inCameraPosition);
    void SetProjection(glm::mat4& inProjection);
    void SetView(glm::mat4& inView);


    void DrawInit();
    void SetModel(glm::mat4& inModel);
    void Draw();
private:
    GLuint loadTexture(char const* path);


private:
    Shader *         pLightingShader;

    GLuint           VBO;
    GLuint           cubeVAO;

    GLuint           diffuseMap;         //������
    GLuint           specularMap;         //���淴��

    glm::vec3        lightDirection;      //ƽ�й�ķ���
    glm::vec3        lightAmbient;        //ƽ�й����ɫ
    glm::vec3        lightDiffuse;        //ƽ�й���������ɫ
    glm::vec3        lightSpecular;       //ƽ�й⾵�淴����ɫ

    glm::vec3        cameraPosition;      //�ӽǵ�λ��
    glm::mat4        projection;          //ͶӰ����
    glm::mat4        view;                //��ͼ����
    glm::mat4        model;               //ģ�;���

};
// ���Դ
class PointLight {
public:
    PointLight();
    ~PointLight();

    void SetLightPosition(glm::vec3& inLightPosition);
    void SetLightAmbient(glm::vec3& inLightAmbient);
    void SetLightDiffuse(glm::vec3& inLightDiffuse);
    void SetLightSpecular(glm::vec3& inLightSpecular);
    void SetLightParameter(float inLightConstant, float inLightLinear, float inLightQuadratic);

    void SetCameraPosition(glm::vec3& inCameraPosition);
    void SetProjection(glm::mat4& inProjection);
    void SetView(glm::mat4& inView);

    void SetLightModel(glm::mat4& inLightModel);

    void DrawInit();
    void SetModel(glm::mat4& inModel);
    void Draw();

    void DrawLight();
private:
    GLuint loadTexture(char const* path);


private:
    Shader *         pLightingShader;
    Shader *         pLightCubeShader;

    GLuint           VBO;
    GLuint           cubeVAO;
    GLuint           lightCubeVAO;

    GLuint           diffuseMap;         //������
    GLuint           specularMap;         //���淴��

    glm::vec3        lightPosition;
    glm::vec3        lightAmbient;        //ƽ�й����ɫ
    glm::vec3        lightDiffuse;        //ƽ�й���������ɫ
    glm::vec3        lightSpecular;       //ƽ�й⾵�淴����ɫ

    float            lightConstant;
    float            lightLinear;
    float            lightQuadratic;

    glm::vec3        cameraPosition;      //�ӽǵ�λ��
    glm::mat4        projection;          //ͶӰ����
    glm::mat4        view;                //��ͼ����
    glm::mat4        model;               //ģ�;���

    glm::mat4        lightModel;

};
// �۹�
class SpotLight {
public:
    SpotLight();
    ~SpotLight();

    void SetLightPosition(glm::vec3& inLightPosition);
    void SetLightAmbient(glm::vec3& inLightAmbient);
    void SetLightDiffuse(glm::vec3& inLightDiffuse);
    void SetLightSpecular(glm::vec3& inLightSpecular);
    void SetLightDirection(glm::vec3& inLightDirection);
    void SetLightParameter(float inLightConstant, float inLightLinear, float inLightQuadratic);
    void SetLightCutOff(float inLightCutOff);
    void SetLightOuterCutOff(float inLightOuterCutOff);

    void SetCameraPosition(glm::vec3& inCameraPosition);
    void SetProjection(glm::mat4& inProjection);
    void SetView(glm::mat4& inView);

    void SetLightModel(glm::mat4& inLightModel);

    void DrawInit();
    void SetModel(glm::mat4& inModel);
    void Draw();

    void DrawLight();
private:
    GLuint loadTexture(char const* path);


private:
    Shader *         pLightingShader;
    Shader *         pLightCubeShader;

    GLuint           VBO;
    GLuint           cubeVAO;
    GLuint           lightCubeVAO;

    GLuint           diffuseMap;         //������
    GLuint           specularMap;         //���淴��

    glm::vec3        lightPosition;       // ��Դ��λ��
    glm::vec3        lightDirection;      // ���յķ���
    float            lightCutOff;         // ��ļн�
    float            lightOuterCutOff;
    glm::vec3        lightAmbient;        //ƽ�й����ɫ
    glm::vec3        lightDiffuse;        //ƽ�й���������ɫ
    glm::vec3        lightSpecular;       //ƽ�й⾵�淴����ɫ

    float            lightConstant;
    float            lightLinear;
    float            lightQuadratic;

    glm::vec3        cameraPosition;      //�ӽǵ�λ��
    glm::mat4        projection;          //ͶӰ����
    glm::mat4        view;                //��ͼ����
    glm::mat4        model;               //ģ�;���

    glm::mat4        lightModel;

};
// ���Դ
class MultipleLight {
public:
    MultipleLight(std::string diffuseImagePath, std::string specularImagePath, MULTIPLELIGHTTYPE type);
    ~MultipleLight();

    void SetCameraPosition(glm::vec3& cameraPosition);
    void SetCameraFront(glm::vec3& cameraFront);
    void SetProjection(glm::mat4& projection);
    void SetView(glm::mat4& view);

    void Draw();

private:

    glm::vec3 cameraPosition;
    glm::vec3 cameraFront;
    glm::mat4 projection;
    glm::mat4 view;

    Shader*  pLightingShader;
    Shader*  pLightCubeShader;

    GLuint loadTexture(char const * path);
    GLuint VBO;
    GLuint cubeVAO;
    GLuint lightCubeVAO;

    GLuint diffuseMap;
    GLuint specularMap;

    glm::vec3 cubePositions[CUBENUMBER];
    glm::vec3 pointLightPositions[NR_POINT_LIGHTS];
    glm::vec3 pointLightColors[NR_POINT_LIGHTS];
    MULTIPLELIGHTTYPE type;
    MultipleLightParameter mMultipleLightParameter[MULTIPLELIGHT_NUMBER];
};
