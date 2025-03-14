#ifndef UNIFORMTRANSFORMATIONS_H
#define UNIFORMTRANSFORMATIONS_H

#include <QMatrix4x4>

//For later use in the shader
class UniformTransformations
{
public:
    UniformTransformations();

    QMatrix4x4 mView{};
    QMatrix4x4 mProjection{};
};

#endif // UNIFORMTRANSFORMATIONS_H
