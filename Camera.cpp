#include "Camera.h"
#include <qmath.h>
#include <QMatrix4x4>
/**
 * @brief Initialize the camera's Forward Vector by target coordinate and camera coordinate
 * @param position
 * @param target
 * @param worldup
 * @param parent
 */
Camera::Camera(QVector3D position, QVector3D target, QVector3D worldup)
{
    this->position  = position;
    this->worldup = worldup;
    this->forward = (target - position).normalized();

    this->right = QVector3D::crossProduct(forward, worldup).normalized();
    this->up = QVector3D::crossProduct(forward, right).normalized();      //should be right cross forwad?
}

/**
 * @brief Initialize the camera's Forward Vector by airplane angle
 * @param position
 * @param worldup
 * @param pitch     angle between Forward Vector and Z-X plane
 * @param yaw       angle between Forward Vector and Z-Y plane
 * @param parent
 */
Camera::Camera(QVector3D position, QVector3D worldup, float pitch, float yaw){
    this->position = position;
    this->worldup = worldup;
    this->pitch = pitch;
    this->yaw = yaw;

    this->forward.setX(qCos(pitch) * qSin(yaw));
    this->forward.setY(qSin(pitch));
    this->forward.setZ(qCos(pitch) * qCos(yaw));

    this->right = QVector3D::crossProduct(this->forward, this->worldup).normalized();
    this->up = QVector3D::crossProduct(this->forward, this->right).normalized();

}

Camera::~Camera(){}

/**
 * @brief Return the view matrix of this camera.You could change the view of this camera by changing the direction parameters
 * @return
 */
QMatrix4x4 Camera::getViewMatrix(){
    QMatrix4x4 matView;
    matView.setToIdentity();
    matView.lookAt(this->position, this->position + this->forward, this->worldup);
    return matView;
}

void Camera::updateCameraVectors(){
    this->forward.setX(qCos(pitch) * qSin(yaw));
    this->forward.setY(qSin(pitch));
    this->forward.setZ(qCos(pitch) * qCos(yaw));

    this->right = QVector3D::crossProduct(this->forward, this->worldup).normalized();
    this->up = QVector3D::crossProduct(this->forward, this->right).normalized();
}

void Camera::processMovement(float deltaX, float deltaY){
    pitch -= deltaY * senseX;
    yaw -= deltaX * senseY;
    updateCameraVectors();
}

void Camera::updateCameraPos(){
    position += forward * speedZ * 0.01f + right * speedX * 0.01f + up * speedY;
}


