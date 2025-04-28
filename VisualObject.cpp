#include "VisualObject.h"

VisualObject::VisualObject()
{
    mMatrix.setToIdentity();
}

void VisualObject::setHeight(float i){
    float prevY = mMatrix.column(3).y();
    mMatrix.translate(0, i - prevY, 0);
}

void VisualObject::move(float x, float y, float z)
{
    mMatrix.translate(x, y, z);
}

void VisualObject::scale(float s)
{
    mMatrix.scale(s);
}

void VisualObject::rotate(float t, float x, float y, float z)
{
    mMatrix.rotate(t, x, y, z);
}

void VisualObject::update()
{
    move(mSpeedX, 0, mSpeedZ);
}
QVector3D VisualObject::getPosition(){
    return mMatrix.column(3).toVector3D();
}

void VisualObject::setSpeedX(float newSpeed){
    mSpeedX = newSpeed;
}
void VisualObject::setSpeedZ(float newSpeed){
    mSpeedZ = newSpeed;
}
void VisualObject::setDrawType(int typeValue){
    if (typeValue == 0){
        drawType = 0;
        return;
    }
    if (typeValue == 1){
        drawType = 1;
        return;
    }
    return;
}
