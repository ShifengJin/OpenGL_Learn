#include "OpenGL_GLSL.h"

GLSL_PointSize_FragCoord::GLSL_PointSize_FragCoord(std::string Vs, std::string Fs)
{
    pShader = new Shader(Vs.c_str(), Fs.c_str());

    float points[24]{
        1.f,  1.f,  1.f,
        1.f,  1.f, -1.f,
        1.f, -1.f,  1.f,
        1.f, -1.f, -1.f,
       -1.f,  1.f,  1.f,
       -1.f,  1.f, -1.f,
       -1.f, -1.f,  1.f,
       -1.f, -1.f, -1.f
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
}

GLSL_PointSize_FragCoord::~GLSL_PointSize_FragCoord()
{
    delete pShader;
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void GLSL_PointSize_FragCoord::SetViewMatrix(glm::mat4 & inViewMatrix)
{
    viewMatrix = inViewMatrix;
}

void GLSL_PointSize_FragCoord::SetProjectionMatrix(glm::mat4 & inProjectionMatrix)
{
    projectionMatrix = inProjectionMatrix;
}

void GLSL_PointSize_FragCoord::Draw()
{
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_PROGRAM_POINT_SIZE);


    pShader->Use();
    glm::mat4 model = glm::mat4(1.f);

    pShader->SetMat4("model", glm::value_ptr(model));
    pShader->SetMat4("view", glm::value_ptr(viewMatrix));
    pShader->SetMat4("projection", glm::value_ptr(projectionMatrix));

    glBindVertexArray(VAO);
    glDrawArrays(GL_POINTS, 0, 8);

    glBindVertexArray(0);
    glUseProgram(0);
    glDisable(GL_PROGRAM_POINT_SIZE);
}

GLSL_Block_FragDepth::GLSL_Block_FragDepth(std::string Vs, std::string Fs,
    std::string texture1Path,
    std::string texture2Path,
    std::string texture3Path,
    std::string texture4Path)
{
    pShader = new Shader(Vs.c_str(), Fs.c_str());

    float Vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, // Bottom-left
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f, // bottom-right   
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, // bottom-left
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left
        // Front face         
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f, // top-right
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f, // top-right
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, // top-left
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left
        // Left face          
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-right
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-left
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-left
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-left
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-right
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-right
        // Right face         
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-left
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-right
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right      
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-right
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-left
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left    
        // Bottom face        
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // top-right
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f, // top-left
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-left
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-left
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-right
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // top-right
        // Top face           
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right     
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f  // bottom-left    
        
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));

    uniformBlockIndex = glGetUniformBlockIndex(pShader->ID, "Matrices");
    glUniformBlockBinding(pShader->ID, uniformBlockIndex, 0);
    glGenBuffers(1, &uboMatrices);
    glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
    glBufferData(GL_UNIFORM_BUFFER, 2 * sizeof(glm::mat4), NULL, GL_STATIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    //define the range of the buffer that links to a uniform binding point
    glBindBufferRange(GL_UNIFORM_BUFFER, 0, uboMatrices, 0, 2 * sizeof(glm::mat4));

    texture1 = loadTexture(texture1Path.c_str());
    texture2 = loadTexture(texture2Path.c_str());
    texture3 = loadTexture(texture3Path.c_str());
    texture4 = loadTexture(texture4Path.c_str());
    
    pShader->Use();
    pShader->SetInt("texture1", 0);
    pShader->SetInt("texture2", 1);
    pShader->SetInt("texture3", 2);
    pShader->SetInt("texture4", 3);
}

GLSL_Block_FragDepth::~GLSL_Block_FragDepth()
{
    delete pShader;

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &uboMatrices);
    glDeleteTextures(1, &texture1);
    glDeleteTextures(1, &texture2);
    glDeleteTextures(1, &texture3);
    glDeleteTextures(1, &texture4);
}

void GLSL_Block_FragDepth::SetViewMatrix(glm::mat4 & inViewMatrix)
{
    viewMatrix = inViewMatrix;
}

void GLSL_Block_FragDepth::SetProjectionMatrix(glm::mat4 & inProjectionMatrix)
{
    projectionMatrix = inProjectionMatrix;
}

void GLSL_Block_FragDepth::Draw()
{
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
    glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(viewMatrix));
    glBindBuffer(GL_UNIFORM_BUFFER, 0);

    glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(projectionMatrix));
    glBindBuffer(GL_UNIFORM_BUFFER, 0);

    pShader->Use();


    glBindVertexArray(VAO);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture1);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);
    
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, texture3);
    
    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D, texture4);

    glm::mat4 model = glm::mat4(1.f);
    model = glm::translate(model, glm::vec3(-0.75f, 0.75f, 0.f));
    pShader->SetMat4("model", glm::value_ptr(model));
    glDrawArrays(GL_TRIANGLES, 0, 36);

    model = glm::mat4(1.f);
    model = glm::translate(model, glm::vec3(0.75f, 0.75f, 0.f));
    pShader->SetMat4("model", glm::value_ptr(model));
    glDrawArrays(GL_TRIANGLES, 0, 36);
    
    
    model = glm::mat4(1.f);
    model = glm::translate(model, glm::vec3(-0.75f, -0.75f, 0.f));
    pShader->SetMat4("model", glm::value_ptr(model));
    glDrawArrays(GL_TRIANGLES, 0, 36);
    
    
    model = glm::mat4(1.f);
    model = glm::translate(model, glm::vec3(0.75f, -0.75f, 0.f));
    pShader->SetMat4("model", glm::value_ptr(model));
    glDrawArrays(GL_TRIANGLES, 0, 36);

    glBindVertexArray(0);
    glUseProgram(0);
}

GLuint GLSL_Block_FragDepth::loadTexture(const char * path)
{
    GLuint textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data) {
        GLenum format;
        if (nrComponents == 1) {
            format = GL_RED;
        }
        else if (nrComponents == 3) {
            format = GL_RGB;
        }
        else if (nrComponents == 4) {
            format = GL_RGBA;
        }

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0,
            format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        stbi_image_free(data);

    }
    else {
        stbi_image_free(data);
    }

    return textureID;
}