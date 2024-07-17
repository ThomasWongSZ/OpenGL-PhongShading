#define MAINWINDOW_WIDTH 1280
#define MAINWINDOW_HEIGHT 960

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QtMath>
#include <QThread>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    qDebug() << "Main TID: " << QThread::currentThreadId();
    ui->setupUi(this);
    this->resize(MAINWINDOW_WIDTH, MAINWINDOW_HEIGHT);

    float yaw = radians(ui->hSlider_CamYaw->value() / 1000.0f);
    float pitch = radians(ui->hSlider_CamPitch->value() / 1000.0f);
    float camPosX = ui->hSlider_CamPosX->value();
    float camPosY = ui->hSlider_CamPosY->value();
    float camPosZ = ui->hSlider_CamPosZ->value();

    this->m_camera = new Camera(QVector3D(camPosX,camPosY, camPosZ),QVector3D(0,1.0f, 0), pitch, yaw);
    ui->openGLWidget->setCamera(this->m_camera);
    ui->openGLWidget->objectAngleX = ui->hSlider_ObjPitch->value() / 1000.0f;
    ui->openGLWidget->objectAngleY = ui->hSlider_ObjYaw->value() / 1000.0f;
    ui->openGLWidget->objectAngleZ = ui->hSlider_ObjRoll->value() / 1000.0f;
}

MainWindow::~MainWindow()
{
    delete ui;
}

float MainWindow::radians(float degree){
    return M_PI * degree / 180;
}


void MainWindow::on_actClear_triggered()
{
    ui->openGLWidget->displayGrapics(false);
}


void MainWindow::on_actDraw_Rect_triggered()
{
    ui->openGLWidget->displayGrapics(true);
}


void MainWindow::on_actWireframe_triggered()
{
    ui->openGLWidget->setWireframe(ui->actWireframe->isChecked());
}

void MainWindow::on_actionLinearFilter_toggled(bool arg1)
{
    ui->openGLWidget->setLinearFilter(arg1);
}


void MainWindow::on_hSlider_CamYaw_valueChanged(int value)
{
    m_camera->yaw = radians(value / 1000.0f);
    m_camera->updateCameraVectors();
}

void MainWindow::on_hSlider_CamPitch_valueChanged(int value)
{
    m_camera->pitch = radians(value / 1000.0f);
    m_camera->updateCameraVectors();
}


void MainWindow::on_hSlider_CamPosZ_valueChanged(int value)
{
    m_camera->position.setZ(value);
}


void MainWindow::on_hSlider_CamPosY_valueChanged(int value)
{
    m_camera->position.setY(value);
}


void MainWindow::on_hSlider_CamPosX_valueChanged(int value)
{
    m_camera->position.setX(value);
}


void MainWindow::on_hSlider_ObjYaw_valueChanged(int value)
{
    ui->openGLWidget->objectAngleY = value / 1000.0f;
}


void MainWindow::on_hSlider_ObjPitch_valueChanged(int value)
{
    ui->openGLWidget->objectAngleX = value / 1000.0f;
}


void MainWindow::on_hSlider_ObjRoll_valueChanged(int value)
{
    ui->openGLWidget->objectAngleZ = value / 1000.0f;
}


void MainWindow::on_cbx_worldAxis_toggled(bool checked)
{
    ui->openGLWidget->showWorldAxis = checked;
}

