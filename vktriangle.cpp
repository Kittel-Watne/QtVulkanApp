#include "vktriangle.h"


VkTriangle::VkTriangle() : VisualObject()
{

    Vertex vA{ -0.5f, 0.0f, 0.0f,   0.2f, 0.2f, 0.8f,    0.0f, 0.0f };//A
    Vertex vB{ 0.5f, 0.5f, 0.0f,    0.1f, 0.1f, 0.7f,    0.0f, 0.0f };//B
    Vertex vC{ 0.5f, -0.5f, 0.0f,   0.8f, 0.8f, 0.7f,    0.0f, 0.0f };//C
    Vertex vD{ 1.5f, 0.0f, 0.0f,    0.25f, 0.25f, 0.85f, 0.0f, 0.0f };//D
    Vertex vE{ -1.5f, 0.5f, 0.0f,   0.2f, 0.2f, 0.8f,    0.0f, 0.0f };//E
    Vertex vF{ -1.5f, -0.5f, 0.0f,  0.8f, 0.8f, 0.7f,    0.0f, 0.0f };//F
    Vertex vG{ 0.5f, 0.0f, 0.5f,    0.2f, 0.2f, 0.8f,    0.0f, 0.0f };//G
    Vertex vH{ 0.5f, 0.0f, -0.5f,   0.2f, 0.2f, 0.8f,    0.0f, 0.0f };//H
    Vertex vI{ -1.25f, 0.0f, 0.0f,  0.25f, 0.25f, 0.85f, 0.0f, 0.0f };//I



    mVertices.push_back(vA);
    mVertices.push_back(vB);
    mVertices.push_back(vG);

    mVertices.push_back(vA);
    mVertices.push_back(vB);
    mVertices.push_back(vH);

    mVertices.push_back(vD);
    mVertices.push_back(vB);
    mVertices.push_back(vG);

    mVertices.push_back(vD);
    mVertices.push_back(vB);
    mVertices.push_back(vH);
    //
    mVertices.push_back(vA);
    mVertices.push_back(vG);
    mVertices.push_back(vC);

    mVertices.push_back(vA);
    mVertices.push_back(vH);
    mVertices.push_back(vC);

    mVertices.push_back(vD);
    mVertices.push_back(vG);
    mVertices.push_back(vC);

    mVertices.push_back(vD);
    mVertices.push_back(vH);
    mVertices.push_back(vC);
    //
    mVertices.push_back(vE);
    mVertices.push_back(vI);
    mVertices.push_back(vA);

    mVertices.push_back(vF);
    mVertices.push_back(vA);
    mVertices.push_back(vI);
}

