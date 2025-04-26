#include "VisualObject.h"

VisualObject::VisualObject()
{
    mMatrix.setToIdentity();
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
    //Barysentric changes to Y will be added here most likely
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
