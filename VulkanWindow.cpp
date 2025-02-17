#include "VulkanWindow.h"
#include "Renderer.h"
#include <QKeyEvent>

VulkanWindow::VulkanWindow()
{
    mSelectedObject = nullptr;
}

QVulkanWindowRenderer* VulkanWindow::createRenderer()
{
    //Makes a new instance of the RenderWindow (our Renderer) class
    mRenderWindow = new Renderer(this, true); // last true == try MSAA
    return mRenderWindow;
}

void VulkanWindow::setCameraSpeed(float value)
{
    mCameraSpeed += value;

    //Keep within some min and max values
    if(mCameraSpeed < 0.01f)
        mCameraSpeed = 0.01f;
    if (mCameraSpeed > 0.3f)
        mCameraSpeed = 0.3f;
}

void VulkanWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_G)
    {
        //dynamic_cast<RenderWindow*>(mRenderWindow)->mObjects.at(mIndex)->move(-0.1f);
        if(mSelectedObject)
        {
            qDebug("Move object");
            mSelectedObject->move(-0.1f);
        }
    }
    if(event->key() == Qt::Key_F)
    {
        qDebug("Scaling object");
        dynamic_cast<Renderer*>(mRenderWindow)->mObjects.at(mIndex)->scale(0.9f);
    }
    if (event->key() == Qt::Key_Escape)
    {
        QCoreApplication::quit();       //Shuts down the whole program
    }

    if (event->key() == Qt::Key_0)
        mIndex = 0;
    if (event->key() == Qt::Key_1)
        mIndex = 1;

    //****** Camera control ******** //
    if(event->key() == Qt::Key_W)
    {
        dynamic_cast<Renderer*>(mRenderWindow)->mCamera.translate(0.0f, 0.0f, mCameraSpeed);
    }
    if(event->key() == Qt::Key_S)
    {
        dynamic_cast<Renderer*>(mRenderWindow)->mCamera.translate(0.0f, 0.0f, -mCameraSpeed);
    }
    if(event->key() == Qt::Key_A)
    {
        dynamic_cast<Renderer*>(mRenderWindow)->mCamera.translate(mCameraSpeed, 0.0f, 0.0f);
    }
    if(event->key() == Qt::Key_D)
    {
        dynamic_cast<Renderer*>(mRenderWindow)->mCamera.translate(-mCameraSpeed, 0.0f, 0.0f);
    }
    if(event->key() == Qt::Key_Q)   //Down
    {
        dynamic_cast<Renderer*>(mRenderWindow)->mCamera.translate(0.0f, mCameraSpeed, 0.0f);
    }
    if(event->key() == Qt::Key_E)   //Up
    {
        dynamic_cast<Renderer*>(mRenderWindow)->mCamera.translate(0.0f, -mCameraSpeed, 0.0f);
    }
    /**********************/

    if(event->key() == Qt::Key_R)
    {
        dynamic_cast<Renderer*>(mRenderWindow)->mCamera.rotate(45, 0.0f, 0.0f, 1.0f);
    }

    //    You get the keyboard input like this
    if(event->key() == Qt::Key_W)
    {
        mInput.W = true;
    }
    if(event->key() == Qt::Key_S)
    {
        mInput.S = true;
    }
    if(event->key() == Qt::Key_D)
    {
        mInput.D = true;
    }
    if(event->key() == Qt::Key_A)
    {
        mInput.A = true;
    }
    if(event->key() == Qt::Key_Q)
    {
        mInput.Q = true;
    }
    if(event->key() == Qt::Key_E)
    {
        mInput.E = true;
    }
    if(event->key() == Qt::Key_Z)
    {
    }
    if(event->key() == Qt::Key_X)
    {
    }
    if(event->key() == Qt::Key_Up)
    {
        mInput.UP = true;
    }
    if(event->key() == Qt::Key_Down)
    {
        mInput.DOWN = true;
    }
    if(event->key() == Qt::Key_Left)
    {
        mInput.LEFT = true;
    }
    if(event->key() == Qt::Key_Right)
    {
        mInput.RIGHT = true;
    }
}

void VulkanWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W)
    {
        mInput.W = false;
    }
    if(event->key() == Qt::Key_S)
    {
        mInput.S = false;
    }
    if(event->key() == Qt::Key_D)
    {
        mInput.D = false;
    }
    if(event->key() == Qt::Key_A)
    {
        mInput.A = false;
    }
    if(event->key() == Qt::Key_Q)
    {
        mInput.Q = false;
    }
    if(event->key() == Qt::Key_E)
    {
        mInput.E = false;
    }
    if(event->key() == Qt::Key_Z)
    {
    }
    if(event->key() == Qt::Key_X)
    {
    }
    if(event->key() == Qt::Key_Up)
    {
        mInput.UP = false;
    }
    if(event->key() == Qt::Key_Down)
    {
        mInput.DOWN = false;
    }
    if(event->key() == Qt::Key_Left)
    {
        mInput.LEFT = false;
    }
    if(event->key() == Qt::Key_Right)
    {
        mInput.RIGHT = false;
    }
}

void VulkanWindow::wheelEvent(QWheelEvent *event)
{
    //QWheelEvent gives an x and y value in a QPoint
    //Y == Vertical scroll, X = Horizontal scroll
    QPoint numDegrees = event->angleDelta();

    //if RMB, change the speed of the camera
    if (mInput.RMB)
    {
        if (numDegrees.y() < 1)
            setCameraSpeed(-0.002f);
        if (numDegrees.y() > 1)
            setCameraSpeed(0.002f);
    }
    qDebug("CameraSpeed: %f", mCameraSpeed);
}

void VulkanWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
        mInput.RMB = true;
    if (event->button() == Qt::LeftButton)
        mInput.LMB = true;
    if (event->button() == Qt::MiddleButton)
        mInput.MMB = true;
}

void VulkanWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
        mInput.RMB = false;
    if (event->button() == Qt::LeftButton)
        mInput.LMB = false;
    if (event->button() == Qt::MiddleButton)
        mInput.MMB = false;
}

void VulkanWindow::mouseMoveEvent(QMouseEvent *event)
{
    // qDebug("X: %d, mouselast: %d" , event->pos().x(), mMouseXlast);

    if (mInput.RMB)
    {
        if(event->pos().x() - mMouseXlast > 0)
            dynamic_cast<Renderer*>(mRenderWindow)->mCamera.rotate(1.0f, 0.0f, 1.0f, 0.0f);

        if(event->pos().x() - mMouseXlast < 0)
            dynamic_cast<Renderer*>(mRenderWindow)->mCamera.rotate(-1.0f, 0.0f, 1.0f, 0.0f);

        mMouseXlast = event->pos().x();
    }
}
