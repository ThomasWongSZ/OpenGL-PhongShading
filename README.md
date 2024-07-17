# OpenGL - Phong Shading
使用QtCreator开发，皆在演示使用QOpenGLWidget的使用方法和GLSL实现PhongShading的方法。
使用方法：
1. 运行程序。
2. 上方的菜单栏提供了绘制图形/清除图形，线框模式等命令，点击后调用了不同的opengl命令。
3. 右侧有各物件的姿态控制，调整各角度可以使它们沿着自己的X,Y或Z轴旋转。

框架：
QMainWindow实现菜单栏，并加入一个QOpenGLWidget。
场景有4个物体：摄像机，正方体，光源，坐标轴。光源用一个白色的正方体显示。
正方体，光源，坐标轴都继承自Model类，它们有自己的shader，用于绘制不同的效果。
