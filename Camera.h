#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <QVector3D>
class Camera : public QObject
{
    Q_OBJECT
public:
    explicit Camera(QVector3D position, QVector3D target, QVector3D worldup);
    explicit Camera(QVector3D position, QVector3D worldup,float pitch, float yaw);
    ~Camera();

    // direction parameters //
    QVector3D position;     //center position of camera
    QVector3D worldup;      //up direction in world-coordinate

    /**
     * @brief angle between Forward Vector and Z-X plane.unit is radius.
     */
    float pitch;
    /**
     * @brief angle between Forward Vector and Z-Y plane.unit is radius.
     */
    float yaw;
    //by the way, the roll angle is the angle between Right-Vector and X-Z plane

    float senseX = 0.001f;	//sense of mouse
    float senseY = 0.001f;	//sense of mouse
    float speedZ = 0;		//speed of camera
    float speedX = 0;
    float speedY = 0;

    QMatrix4x4 getViewMatrix();
    void updateCameraVectors();
    void processMovement(float deltaX, float deltaY);
    void updateCameraPos();

private:
    QVector3D forward;      //front direction of camera
    QVector3D right;        //right direction of camera
    QVector3D up;           //up direction of camera

};

#endif // CAMERA_H
