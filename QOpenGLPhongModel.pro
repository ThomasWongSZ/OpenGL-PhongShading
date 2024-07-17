QT += core gui
QT += opengl            #for QOpenGLShaderProgram
#QT += openglwidgets     #for QOpenGLWidget
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Camera.cpp \
    Coordinate.cpp \
    DHOpenGLWidget.cpp \
    MainObject.cpp \
    Model.cpp \
    main.cpp \
    MainWindow.cpp \
    LightSource.cpp

HEADERS += \
    Camera.h \
    Coordinate.h \
    DHOpenGLWidget.h \
    MainObject.h \
    MainWindow.h \
    Model.h \
    LightSource.h \
    StructProtocol.h

FORMS += \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
