#ifndef MODEL_H
#define MODEL_H

#include <QOpenGLExtraFunctions>
#include <QOpenGLShaderProgram>
#include <QMatrix4x4>
class Model : public QOpenGLExtraFunctions
{
public:
    Model();
    virtual ~Model();

    virtual void initObject();
    virtual void initTexture();
    virtual void initShader();
    virtual void draw(QOpenGLShaderProgram * shader);

    QMatrix4x4 * matModel = nullptr;
    QMatrix4x4 * matView = nullptr;
    QMatrix4x4 * matProjection = nullptr;
    QVector3D * vecCameraPosition = nullptr;

    QOpenGLShaderProgram * shader = nullptr;
};

#endif // MODEL_H
