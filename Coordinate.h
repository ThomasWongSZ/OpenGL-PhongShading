#ifndef COORDINATE_H
#define COORDINATE_H

#include "Model.h"
#include <QOpenGLShaderProgram>
class Coordinate : public Model
{
public:
    Coordinate();
    ~Coordinate();

    virtual void initObject();
    virtual void initTexture();
    virtual void initShader();
    virtual void draw(QOpenGLShaderProgram * shader);

    void drawX();
    void drawY();
    void drawZ();

private:
    uint VBO_X = 0;
    uint VBO_Y = 0;
    uint VBO_Z = 0;
    uint VBO_PyramidX = 0;
    uint VBO_PyramidY = 0;
    uint VBO_PyramidZ = 0;

    float m_verticesX[6] = {
        0.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f
    };

    float m_verticesY[6] = {
        0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f
    };

    float m_verticesZ[6] = {
        0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    };

    // vertices of pyramids
    GLfloat pyramidXVertices[54] =
    {
        1.0f, 0.01f, 0.01f,     // x1
        1.0f, 0.01f, -0.01f,    // x2
        1.0f, -0.01f, -0.01f,   // x3

        1.0f, 0.01f, 0.01f,     // x1
        1.0f, -0.01f, -0.01f,   // x3
        1.0f, -0.01f, 0.01f,    // x4

        1.1f, 0.0f, 0.0f,       // 0
        1.0f, 0.01f, 0.01f,     // x1
        1.0f, -0.01f, 0.01f,    // x4

        1.1f, 0.0f, 0.0f,       // 0
        1.0f, 0.01f, 0.01f,     // x1
        1.0f, 0.01f, -0.01f,    // x2

        1.1f, 0.0f, 0.0f,       // 0
        1.0f, 0.01f, -0.01f,    // x2
        1.0f, -0.01f, -0.01f,   // x3

        1.1f, 0.0f, 0.0f,       // 0
        1.0f, -0.01f, -0.01f,   // x3
        1.0f, -0.01f, 0.01f     // x4
    };

    GLfloat pyramidYVertices[54] =
    {
        0.01f, 1.0f, -0.01f,    // x1
        -0.01f, 1.0f, -0.01f,   // x2
        -0.01f, 1.0f, 0.01f,    // x3

        0.01f, 1.0f, -0.01f,    // x1
        -0.01f, 1.0f, 0.01f,    // x3
        0.01f, 1.0f, 0.01f,     // x4

        0.0f, 1.1f, 0.0f,       // 0
        0.01f, 1.0f, -0.01f,    // x1
        0.01f, 1.0f, 0.01f,     // x4

        0.0f, 1.1f, 0.0f,       // 0
        0.01f, 1.0f, -0.01f,    // x1
        -0.01f, 1.0f, -0.01f,   // x2

        0.0f, 1.1f, 0.0f,       // 0
        -0.01f, 1.0f, -0.01f,   // x2
        -0.01f, 1.0f, 0.01f,    // x3

        0.0f, 1.1f, 0.0f,       // 0
        -0.01f, 1.0f, 0.01f,    // x3
        0.01f, 1.0f, 0.01f      // x4
    };

    GLfloat pyramidZVertices[54] =
    {
        0.01f, 0.01f, 1.0f,     // x1
        -0.01f, 0.01f, 1.0f,    // x2
        -0.01f, -0.01f, 1.0f,   // x3

        0.01f, 0.01f, 1.0f,     // x1
        -0.01f, -0.01f, 1.0f,   // x3
        0.01f, -0.01f, 1.0f,    // x4

        0.0f, 0.0f, 1.1f,       // 0
        0.01f, 0.01f, 1.0f,     // x1
        0.01f, -0.01f, 1.0f,    // x4

        0.0f, 0.0f, 1.1f,       // 0
        0.01f, 0.01f, 1.0f,     // x1
        -0.01f, 0.01f, 1.0f,    // x2

        0.0f, 0.0f, 1.1f,       // 0
        -0.01f, 0.01f, 1.0f,    // x2
        -0.01f, -0.01f, 1.0f,   // x3

        0.0f, 0.0f, 1.1f,       // 0
        -0.01f, -0.01f, 1.0f,   // x3
        0.01f, -0.01f, 1.0f     // x4
    };
};

#endif // COORDINATE_H
