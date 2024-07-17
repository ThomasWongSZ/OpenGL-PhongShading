#include "DHOpenGLWidget.h"
#include <QtMath>
#include <QDebug>
#include <QTime>
#include <QThread>

DHOpenGLWidget::DHOpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    qDebug() << "QOpenGLWidget TID: " << QThread::currentThreadId();
    m_camera = new Camera(QVector3D(0,5.0f, 5.0f),QVector3D(0,1.0f, 0),radians(-45.0f), radians(180.0f));

    connect(&m_timer, SIGNAL(timeout()), this, SLOT(on_timeout()));
    m_timer.start(100);
}

DHOpenGLWidget::~DHOpenGLWidget(){
    delete m_object;
    delete m_coordinate;
    delete m_lightSource;
}


void DHOpenGLWidget::initializeGL(){
    initializeOpenGLFunctions();    //将函数指针glClearColor等指向实际的显卡中的函数地址
    glEnable(GL_DEPTH_TEST);		//开启深度测试
    glEnable(GL_MULTISAMPLE);

    //让VBO,VAO先休息，不再记录改变
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    m_object = new MainObject();
    m_object->initObject();
    m_object->initShader();
    m_object->initTexture();

    m_coordinate = new Coordinate();
    m_coordinate->initObject();
    m_coordinate->initShader();

    m_lightSource = new LightSource();
    m_lightSource->initObject();
    m_lightSource->initShader();
    m_lightSource->position = QVector3D(-0.5f, 3.0f, 3.0f);

    m_object->lightPoint.position = m_lightSource->position;
    m_object->lightPoint.color = QVector3D(1.0f, 1.0f, 1.0f);     //white
    m_object->lightPoint.ambient = QVector3D(0.2f, 0.2f, 0.2f);
    m_object->lightPoint.diffuse = QVector3D(0.5f, 0.5f, 0.5f);   // darken diffuse light a bit
    m_object->lightPoint.specular = QVector3D(1.0f, 1.0f, 1.0f);
}

void DHOpenGLWidget::resizeGL(int w, int h){
    Q_UNUSED(w);
    Q_UNUSED(h);
    //glViewport(0,0, w, h);
}

/**
 * @brief 默认OpenGL代码应该写在这里
 */
void DHOpenGLWidget::paintGL(){
    //qDebug() << "Paint TID: " << QThread::currentThreadId();
    //在paintGL()函数以外调用绘制函数没有意义，绘制的最终会被paintGL()覆盖

    if(m_display){
        //() << "Draw";
        draw();
    }else{
        //qDebug() << "Clear";
        clear();
    }
}

void DHOpenGLWidget::displayGrapics(bool display)
{
    //qDebug() << "Display";
    m_display = display;
    update();
}

/**
 * @brief 设置线框模式
 * @param wireframe
 */
void DHOpenGLWidget::setWireframe(bool wireframe)
{
    makeCurrent();
    if(wireframe)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    doneCurrent();
    update();
}

/**
 * @brief 设置纹理过滤方式
 * @param linear
 */
void DHOpenGLWidget::setLinearFilter(bool linear){
    makeCurrent();
    if(linear){
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }
    else{
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }
    doneCurrent();
    update();
}

void DHOpenGLWidget::on_timeout()
{
    update();
}

/**
 * @brief 绘制图形
 */
void DHOpenGLWidget::draw(){
    setMVPMatrix();
    m_object->shader->bind();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);                   //设置清除颜色时的状态
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BITS);           //使用 清除颜色时的状态 来清除颜色

    m_object->matModel = &m_matModel;
    m_object->matView = &m_matView;
    m_object->matProjection = &m_matProj;
    m_object->vecCameraPosition = &(m_camera->position);
    m_object->draw(m_object->shader);

    m_lightSource->matModel = &m_matModel_light;
    m_lightSource->matView = &m_matView;
    m_lightSource->matProjection = &m_matProj;
    m_lightSource->draw(m_lightSource->shader);

    if(showWorldAxis){
        //画坐标轴
        m_coordinate->matModel = &m_matModel;
        m_coordinate->matView = &m_matView;
        m_coordinate->matProjection = &m_matProj;

        m_coordinate->drawX();
        m_coordinate->drawY();
        m_coordinate->drawZ();
    }
}

/**
 * @brief 清空图形
 */
void DHOpenGLWidget::clear(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);   //设置清除颜色时的状态
    glClear(GL_COLOR_BUFFER_BIT);           //使用 清除颜色时的状态 来清除颜色
}

void DHOpenGLWidget::setMVPMatrix(){
    // Set Model Matrix
    QMatrix4x4 matTrans;
    QMatrix4x4 matRot;

    matRot.rotate(objectAngleZ, QVector3D(0.0f, 0.0f, 1.0f));
    matRot.rotate(objectAngleX, QVector3D(1.0f, 0.0f, 0.0f));
    matRot.rotate(objectAngleY, QVector3D(0.0f, 1.0f, 0.0f));
    matTrans.translate(QVector3D(0.0f, 0.0f, 0.0f));

    m_matModel = matTrans * matRot;
    m_matView = m_camera->getViewMatrix();

    m_matProj.setToIdentity();
    m_matProj.perspective(45.0f, 800 / 800, 0.1f, 100.f);

    // Light Model Matrix
    matTrans.setToIdentity();
    matTrans.translate(m_lightSource->position);
    m_matModel_light = matTrans;

}

float DHOpenGLWidget::radians(float degree){
    return M_PI * degree / 180;
}

void DHOpenGLWidget::setCamera(Camera *camera){
    this->m_camera = camera;
}
