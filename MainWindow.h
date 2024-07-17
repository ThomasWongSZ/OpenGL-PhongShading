#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Camera.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actClear_triggered();

    void on_actDraw_Rect_triggered();

    void on_actWireframe_triggered();

    void on_actionLinearFilter_toggled(bool arg1);

    void on_hSlider_CamYaw_valueChanged(int value);

    void on_hSlider_CamPitch_valueChanged(int value);

    void on_hSlider_CamPosZ_valueChanged(int value);

    void on_hSlider_CamPosY_valueChanged(int value);

    void on_hSlider_CamPosX_valueChanged(int value);

    void on_hSlider_ObjYaw_valueChanged(int value);

    void on_hSlider_ObjPitch_valueChanged(int value);

    void on_hSlider_ObjRoll_valueChanged(int value);

    void on_cbx_worldAxis_toggled(bool checked);

private:
    Ui::MainWindow *ui;

    Camera * m_camera = nullptr;
    float radians(float degree);
};
#endif // MAINWINDOW_H
