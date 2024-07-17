#include "Model.h"

Model::Model()
{
    this->initializeOpenGLFunctions();
}

Model::~Model(){}

void Model::initObject(){}

void Model::initTexture(){}

void Model::initShader(){}

void Model::draw(QOpenGLShaderProgram * shader){Q_UNUSED(shader)}
