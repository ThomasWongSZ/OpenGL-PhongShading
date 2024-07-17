#ifndef STRUCTPROTOCOL_H
#define STRUCTPROTOCOL_H

#include <QVector3D>
struct LightPoint{
    QVector3D position;

    QVector3D color;
    QVector3D ambient;
    QVector3D diffuse;
    QVector3D specular;
};
#endif // STRUCTPROTOCOL_H
