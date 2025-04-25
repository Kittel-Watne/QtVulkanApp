#include "playerobject.h"

PlayerObject::PlayerObject() : VisualObject() {
    Vertex v1{ 0.1f,  -0.1f,  0.1f,   1.0f, 0.0f, 0.0f,  1.0f, 1.0f};
    Vertex v2{ 0.1f,  -0.1f,  -0.1f,   0.0f, 1.0f, 0.0f,  1.0f, 1.0f };
    Vertex v3{ -0.1f,  -0.1f,  -0.1f,   0.0f, 0.0f, 1.0f,  0.0f, 1.0f };
    Vertex v4{ -0.1f,  -0.1f,  0.1f,   1.0f, 1.0f, 0.0f,  0.0f, 1.0f };
    Vertex v5{ 0.1f,  0.1f,  0.1f,   1.0f, 0.0f, 0.0f,  1.0f, 0.0f};
    Vertex v6{ 0.1f,  0.1f,  -0.1f,   0.0f, 1.0f, 0.0f,  1.0f, 0.0f };
    Vertex v7{ -0.1f,  0.1f,  -0.1f,   0.0f, 0.0f, 1.0f,  0.0f, 0.0f };
    Vertex v8{ -0.1f,  0.1f,  0.1f,   1.0f, 1.0f, 0.0f,  0.0f, 0.0f };

    //Pushing vertices
    mVertices.push_back(v1);
    mVertices.push_back(v2);
    mVertices.push_back(v3);
    mVertices.push_back(v4);
    mVertices.push_back(v5);
    mVertices.push_back(v6);
    mVertices.push_back(v7);
    mVertices.push_back(v8);

    //Front
    mIndices.push_back(0);
    mIndices.push_back(4);
    mIndices.push_back(7);
    mIndices.push_back(0);
    mIndices.push_back(7);
    mIndices.push_back(3);

    //Right
    mIndices.push_back(1);
    mIndices.push_back(5);
    mIndices.push_back(4);
    mIndices.push_back(0);
    mIndices.push_back(1);
    mIndices.push_back(4);

    //Back
    mIndices.push_back(2);
    mIndices.push_back(6);
    mIndices.push_back(5);
    mIndices.push_back(1);
    mIndices.push_back(2);
    mIndices.push_back(5);

    //Left
    mIndices.push_back(3);
    mIndices.push_back(7);
    mIndices.push_back(6);
    mIndices.push_back(2);
    mIndices.push_back(3);
    mIndices.push_back(6);

    //Bottom
    mIndices.push_back(0);
    mIndices.push_back(3);
    mIndices.push_back(1);
    mIndices.push_back(1);
    mIndices.push_back(3);
    mIndices.push_back(2);

    //top
    mIndices.push_back(4);
    mIndices.push_back(7);
    mIndices.push_back(5);
    mIndices.push_back(5);
    mIndices.push_back(7);
    mIndices.push_back(6);
}
