#ifndef DHOPENGLWIDGET_H
#define DHOPENGLWIDGET_H

#include "Camera.h"
#include "Coordinate.h"
#include "MainObject.h"
#include "LightSource.h"
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QTimer>
class DHOpenGLWidget : public QOpenGLWidget, QOpenGLFunctions_3_3_Core
{
    Q_OBJECT
public:
    explicit DHOpenGLWidget(QWidget *parent = nullptr);
    ~DHOpenGLWidget();

    void displayGrapics(bool display);
    void setWireframe(bool wireframe);
    void setLinearFilter(bool linear);
    float radians(float degree);

    void setCamera(Camera * camera);
    void setMVPMatrix();

    float objectAngleX = 0;
    float objectAngleY = 0;
    float objectAngleZ = 0;
    bool showWorldAxis = true;
public slots:
    void on_timeout();
protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();

private:
    bool m_display = true;
    QTimer m_timer;

    QMatrix4x4 m_matModel;    //摆好所有物体
    QMatrix4x4 m_matView;     //所有物体移动到适合位置（往Camera的反方向移动）
    QMatrix4x4 m_matProj;     //投影到NDC坐标空间

    QMatrix4x4 m_matModel_light;

    Camera * m_camera = nullptr;
    Coordinate * m_coordinate = nullptr;
    MainObject * m_object = nullptr;
    LightSource * m_lightSource = nullptr;

    void draw();
    void clear();

signals:

};

#endif // DHOPENGLWIDGET_H
