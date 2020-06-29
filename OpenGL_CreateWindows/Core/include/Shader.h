#pragma once

#include "GL\glew.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
public:
    // ����ID
    unsigned int ID;

    // ���캯�� ��ȡ��������ɫ��
    Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = NULL);

   // ʹ��/�������
    void Use();

    // uniform ���ߺ���
    void SetBool(const std::string &name, bool value) const;
    void SetInt(const std::string &name, int value) const;
    void SetFloat(const std::string &name, float value) const;
    void SetVec2(const std::string &name, float* value);

    void SetVec2(const std::string &name, float x, float y);
    void SetVec3(const std::string &name, float* value);

    void SetVec3(const std::string &name, float x, float y, float z);

    void SetVec4(const std::string &name, float* value);

    void SetVec4(const std::string &name, float x, float y, float z, float w);

    void SetMat2(const std::string &name, float* mat2x2);

    void SetMat3(const std::string &name, float* mat3x3);

    void SetMat4(const std::string &name, float* mat4x4);

private:
    void checkCompileErrors(GLuint shader, std::string type);
};
