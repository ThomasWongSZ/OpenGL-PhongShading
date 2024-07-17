#include "LightSource.h"

LightSource::LightSource()
{

}

LightSource::~LightSource(){
    if(VAO || VBO){
        glDeleteBuffers(1, &VAO);
        glDeleteBuffers(1, &VBO);
    }

    delete shader;
}

void LightSource::initObject(){
    //创建VBO和VAO对象，并赋予ID
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    //绑定VBO和VAO对象
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    //为当前绑定到target的缓冲区对象创建一个新的数据存储
    //如果data不是NULL，则使用来自此指针的数据初始化数据存储
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(VAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

void LightSource::initTexture(){}

void LightSource::initShader(){
    shader = new QOpenGLShaderProgram();

    // build and compile our shader program //

    // Object shader
    bool success;
    shader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/light_source.vert");
    shader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/light_source.frag");
    success = shader->link();
    if(!success){
        qDebug() << "ERR:" << shader->log();
    }
}

void LightSource::draw(QOpenGLShaderProgram *shader){
    if(shader){
        shader->bind();
        shader->setUniformValue("matModel", *matModel);
        shader->setUniformValue("matView", *matView);
        shader->setUniformValue("matProj", *matProjection);
    }

    //画对象
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glDrawArrays(GL_TRIANGLES, 0, 36);
}
