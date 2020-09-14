#include "..\include\OpenGL_Geometry.h"

Geometry::Geometry(std::string vs, std::string gs, std::string fs)
{
    pShader = new Shader(vs.c_str(), fs.c_str(), gs.c_str());

    float points[20] = {
        -0.5f,  0.5f, 1.f, 0.f, 0.f,
         0.5f,  0.5f, 0.f, 1.f, 0.f,
         0.5f, -0.5f, 0.f, 0.f, 0.f,
        -0.5f, -0.5f, 1.f, 1.f, 0.f
    };

    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
    glBindVertexArray(0);
}

Geometry::~Geometry()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    delete pShader;
}

void Geometry::Draw()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    pShader->Use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_POINTS, 0, 4);
}

GeometryShaderExploding::GeometryShaderExploding(std::string vs, std::string gs, std::string fs, std::string modelPath)
{
    pShader = new Shader(vs.c_str(), fs.c_str(), gs.c_str());
    pModel = new Model(modelPath);
}

GeometryShaderExploding::~GeometryShaderExploding()
{
    delete pShader;
    delete pModel;
}

void GeometryShaderExploding::SetProjection(glm::mat4 & inProjection)
{
    projection = inProjection;
}

void GeometryShaderExploding::SetView(glm::mat4 & inView)
{
    view = inView;
}

void GeometryShaderExploding::SetModel(glm::mat4 & inModel)
{
    model = inModel;
}

void GeometryShaderExploding::SetTime(float inTime)
{
    time = inTime;
}

void GeometryShaderExploding::Draw()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    pShader->Use();
    pShader->SetMat4("projection", glm::value_ptr(projection));
    pShader->SetMat4("view", glm::value_ptr(view));
    pShader->SetMat4("model", glm::value_ptr(model));
    pShader->SetFloat("time", time);
    pModel->Draw(*pShader);
}

GeometryShaderNormals::GeometryShaderNormals(std::string defaultVs, std::string defaultFs, std::string normalVisualizationVs, std::string normalVisualizationFs, std::string normalVisualizationGs, std::string modelPath)
{
    pShader = new Shader(defaultVs.c_str(), defaultFs.c_str());
    pNormalShader = new Shader(normalVisualizationVs.c_str(),
        normalVisualizationFs.c_str(),
        normalVisualizationGs.c_str());
    pModel = new Model(modelPath);
}

GeometryShaderNormals::~GeometryShaderNormals()
{
    delete pShader;
    delete pNormalShader;
    delete pModel;
}

void GeometryShaderNormals::SetProjection(glm::mat4 & inProjection)
{
    projection = inProjection;
}

void GeometryShaderNormals::SetView(glm::mat4 & inView)
{
    view = inView;
}

void GeometryShaderNormals::SetModel(glm::mat4 & inModel)
{
    model = inModel;
}

void GeometryShaderNormals::Draw()
{
    glClearColor(0.1f, 0.2f, 0.3f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    pShader->Use();
    pShader->SetMat4("projection", glm::value_ptr(projection));
    pShader->SetMat4("view", glm::value_ptr(view));
    pShader->SetMat4("model", glm::value_ptr(model));

    pModel->Draw(*pShader);

    pNormalShader->Use();
    pNormalShader->SetMat4("projection", glm::value_ptr(projection));
    pNormalShader->SetMat4("view", glm::value_ptr(view));
    pNormalShader->SetMat4("model", glm::value_ptr(model));
    pModel->Draw(*pNormalShader);
    
}
