#include "WorldAxis.h"

WorldAxis::WorldAxis()
{
    float width = 0.01f;

    //X axis
    mVertices.push_back(Vertex{0.f, 0.f, 0.f,       1.f, 0.f, 0.f,    0.f, 0.f });
    mVertices.push_back(Vertex{100.f, 0.f, 0.f,     1.f, 0.f, 0.f,    0.f, 0.f });
    mVertices.push_back(Vertex{0.f, width, 0.f,     1.f, 0.f, 0.f,    0.f, 0.f });
    mVertices.push_back(Vertex{0.f, width, 0.f,     1.f, 0.f, 0.f,    0.f, 0.f });
    mVertices.push_back(Vertex{100.f, 0.f, 0.f,     1.f, 0.f, 0.f,    0.f, 0.f });
    mVertices.push_back(Vertex{100.f, width, 0.f,     1.f, 0.f, 0.f,    0.f, 0.f });

    //Y axis
    mVertices.push_back(Vertex{0.f, 0.f, 0.f,       0.f, 1.f, 0.f,    0.f, 0.f });
    mVertices.push_back(Vertex{0.f, 100.f, 0.f,     0.f, 1.f, 0.f,    0.f, 0.f });
    mVertices.push_back(Vertex{width, 0.f, 0.f,     0.f, 1.f, 0.f,    0.f, 0.f });
    mVertices.push_back(Vertex{width, 0.f, 0.f,     0.f, 1.f, 0.f,    0.f, 0.f });
    mVertices.push_back(Vertex{0.f, 100.f, 0.f,     0.f, 1.f, 0.f,    0.f, 0.f });
    mVertices.push_back(Vertex{width, 100.f, 0.f,     0.f, 1.f, 0.f,    0.f, 0.f });

    //Z axis
    mVertices.push_back(Vertex{0.f, 0.f, 0.f,       0.f, 0.f, 1.f,    0.f, 0.f });
    mVertices.push_back(Vertex{0.f, 0.f, 100.f,     0.f, 0.f, 1.f,    0.f, 0.f });
    mVertices.push_back(Vertex{0.f, width, 0.f,     0.f, 0.f, 1.f,    0.f, 0.f });
    mVertices.push_back(Vertex{0.f, width, 0.f,     0.f, 0.f, 1.f,    0.f, 0.f });
    mVertices.push_back(Vertex{0.f, 0.f, 100.f,     0.f, 0.f, 1.f,    0.f, 0.f });
    mVertices.push_back(Vertex{0.f, width, 100.f,     0.f, 0.f, 1.f,    0.f, 0.f });

    mMatrix.setToIdentity();
}

