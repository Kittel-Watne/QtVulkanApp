#ifndef CAMERA_H
#define CAMERA_H
#include <QMatrix4x4>

class Camera
{
private:
    QVector3D mEye{0.0, 0.0, 0.0};  // Camera position
    QVector3D mAt{0.0, 0.0, -1.0};   // Forward vector
    QVector3D mUp{0.0, 1.0, 0.0};   // Up vector

    QMatrix4x4 mProjectionMatrix{};
    QMatrix4x4 mViewMatrix{};

public:
    Camera();
    ~Camera() { }

    void init();
    void perspective(int degrees, double aspect, double nearplane, double farplane);
    void lookAt(const QVector3D& eye, const QVector3D& at, const QVector3D& up);

    void translate(float dx, float dy, float dz);
    void rotate(float t, float x, float y, float z);
    QMatrix4x4 cMatrix();
};

#endif // CAMERA_H
