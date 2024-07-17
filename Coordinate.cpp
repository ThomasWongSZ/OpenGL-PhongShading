#define AXIS_X 0
#define AXIS_Y 1
#define AXIS_Z 2

#include "Coordinate.h"

Coordinate::Coordinate()
{
}

Coordinate::~Coordinate(){
    if(VBO_X || VBO_Y || VBO_Z){
        glDeleteBuffers(1, &VBO_X);
        glDeleteBuffers(1, &VBO_Y);
        glDeleteBuffers(1, &VBO_Z);
    }

    delete shader;
}

void Coordinate::initObject(){

    glGenBuffers(1, &VBO_X);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_X);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_verticesX), m_verticesX, GL_STATIC_DRAW);

    glGenBuffers(1, &VBO_PyramidX);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_PyramidX);
    glBufferData(GL_ARRAY_BUFFER, sizeof(pyramidXVertices), pyramidXVertices, GL_STATIC_DRAW);

    glGenBuffers(1, &VBO_Y);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_Y);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_verticesY), m_verticesY, GL_STATIC_DRAW);

    glGenBuffers(1, &VBO_PyramidY);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_PyramidY);
    glBufferData(GL_ARRAY_BUFFER, sizeof(pyramidYVertices), pyramidYVertices, GL_STATIC_DRAW);

    glGenBuffers(1, &VBO_Z);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_Z);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_verticesZ), m_verticesZ, GL_STATIC_DRAW);

    glGenBuffers(1, &VBO_PyramidZ);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_PyramidZ);
    glBufferData(GL_ARRAY_BUFFER, sizeof(pyramidZVertices), pyramidYVertices, GL_STATIC_DRAW);

}

void Coordinate::initTexture(){}

void Coordinate::initShader(){

   shader = new QOpenGLShaderProgram();

   // Coordinate X shader
   uint success = 0;
   this->shader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/Coordinate.vert");
   this->shader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/Coordinate.frag");
   success = this->shader->link();
   if(!success){
       qDebug() << "ERR:" << shader->log();
   }
}

void Coordinate::draw(QOpenGLShaderProgram *shader){Q_UNUSED(shader)}


void Coordinate::drawX()
{
    if(this->shader){
        shader->bind();
        shader->setUniformValue("matView", *matView);
        shader->setUniformValue("matProj", *matProjection);
        shader->setUniformValue("axisType", AXIS_X);
    }

    glBindBuffer(GL_ARRAY_BUFFER, VBO_X);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_LINES, 0, 2);

    // pyramid
    glBindBuffer(GL_ARRAY_BUFFER, VBO_PyramidX);
    glBufferData(GL_ARRAY_BUFFER, 216, pyramidXVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, 18);

}

void Coordinate::drawY()
{
    if(this->shader){
        shader->bind();
        shader->setUniformValue("matView", *matView);
        shader->setUniformValue("matProj", *matProjection);
        shader->setUniformValue("axisType", AXIS_Y);
    }

    glBindBuffer(GL_ARRAY_BUFFER, VBO_Y);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_LINES, 0, 2);

    // pyramid
    glBindBuffer(GL_ARRAY_BUFFER, VBO_PyramidY);
    glBufferData(GL_ARRAY_BUFFER, 216, pyramidYVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, 18);
}

void Coordinate::drawZ()
{  
    if(this->shader){
        shader->bind();
        shader->setUniformValue("matView", *matView);
        shader->setUniformValue("matProj", *matProjection);
        shader->setUniformValue("axisType", AXIS_Z);
    }

    glBindBuffer(GL_ARRAY_BUFFER, VBO_Z);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_LINES, 0, 2);

    // pyramid
    glBindBuffer(GL_ARRAY_BUFFER, VBO_PyramidZ);
    glBufferData(GL_ARRAY_BUFFER, 216, pyramidZVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, 18);
}

