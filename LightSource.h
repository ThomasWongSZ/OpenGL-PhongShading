#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include "Model.h"
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QVector3D>
class LightSource : public Model
{
public:
    LightSource();
    ~LightSource();

    virtual void initObject();
    virtual void initTexture();
    virtual void initShader();
    virtual void draw(QOpenGLShaderProgram *shader);

    uint VAO = 0;
    uint VBO = 0;
    QVector3D position;

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[288] = {
        // positions          // normals           // texture coords
        -0.1f, -0.1f, -0.1f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
        0.1f, -0.1f, -0.1f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
        0.1f,  0.1f, -0.1f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
        0.1f,  0.1f, -0.1f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
        -0.1f,  0.1f, -0.1f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
        -0.1f, -0.1f, -0.1f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,

        -0.1f, -0.1f,  0.1f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
        0.1f, -0.1f,  0.1f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
        0.1f,  0.1f,  0.1f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
        0.1f,  0.1f,  0.1f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
        -0.1f,  0.1f,  0.1f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
        -0.1f, -0.1f,  0.1f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

        -0.1f,  0.1f,  0.1f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        -0.1f,  0.1f, -0.1f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
        -0.1f, -0.1f, -0.1f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.1f, -0.1f, -0.1f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.1f, -0.1f,  0.1f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
        -0.1f,  0.1f,  0.1f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

        0.1f,  0.1f,  0.1f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        0.1f,  0.1f, -0.1f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
        0.1f, -0.1f, -0.1f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        0.1f, -0.1f, -0.1f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        0.1f, -0.1f,  0.1f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
        0.1f,  0.1f,  0.1f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

        -0.1f, -0.1f, -0.1f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
        0.1f, -0.1f, -0.1f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
        0.1f, -0.1f,  0.1f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
        0.1f, -0.1f,  0.1f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
        -0.1f, -0.1f,  0.1f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
        -0.1f, -0.1f, -0.1f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

        -0.1f,  0.1f, -0.1f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
        0.1f,  0.1f, -0.1f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
        0.1f,  0.1f,  0.1f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
        0.1f,  0.1f,  0.1f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
        -0.1f,  0.1f,  0.1f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
        -0.1f,  0.1f, -0.1f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
    };

};

#endif // LIGHTSOURCE_H
