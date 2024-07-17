#define TEX_CHANNEL_SURFACE 0
#include "MainObject.h"

MainObject::MainObject(){
}

MainObject::~MainObject(){
    if(VAO || VBO || EBO ){
        glDeleteBuffers(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
    }

    delete shader;
}

void MainObject::initObject(){
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

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

void MainObject::initTexture(){
    //加载纹理
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);      //设置透明度
    // m_texContainer = new QOpenGLTexture(QImage(":/images/images/container2.png").mirrored());    //图片的y轴0点在左上角，要反转一下
    // m_texContainer->bind(TEX_CHANNEL_SURFACE);   //将纹理绑定到0通道上(GLSL里的uniform Sampler2D texture的值默认也是0）

    // if(shader){
    //     qDebug() << "texture was bound to 0";
    //     shader->bind();           //要bind后才能setUniform
    //     shader->setUniformValue("texSurface", TEX_CHANNEL_SURFACE);
    // }

    // //纹理环绕方式
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

    // //纹理过滤(texture filtering)
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void MainObject::initShader(){
    shader = new QOpenGLShaderProgram();

    // build and compile our shader program //

    // Object shader
    bool success;
    shader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/shapes.vert");
    shader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/shapes.frag");
    success = shader->link();
    if(!success){
        qDebug() << "ERR:" << shader->log();
    }
}

void MainObject::draw(QOpenGLShaderProgram *shader){
    if(shader){
        shader->bind();
        shader->setUniformValue("matModel", *matModel);
        shader->setUniformValue("matView", *matView);
        shader->setUniformValue("matProj", *matProjection);
        shader->setUniformValue("cameraPos", *vecCameraPosition);

        shader->setUniformValue("lightPoint.position", lightPoint.position);
        shader->setUniformValue("lightPoint.color", lightPoint.color);
        shader->setUniformValue("lightPoint.ambient", lightPoint.ambient);
        shader->setUniformValue("lightPoint.diffuse", lightPoint.diffuse);
        shader->setUniformValue("lightPoint.specular", lightPoint.specular);

        shader->setUniformValue("material.ambient", 1.0f, 0.5f, 0.31f);
        shader->setUniformValue("material.diffuse", 1.0f, 0.5f, 0.31f);
        shader->setUniformValue("material.specular", 0.5f, 0.5f, 0.5f);
        shader->setUniformValue("material.shininess", 32.0f);
    }
    //m_texContainer->bind(TEX_CHANNEL_SURFACE);

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
