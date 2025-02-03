#include "vktrianglesurface.h"
#include <fstream>
VkTriangleSurface::VkTriangleSurface() : VisualObject()
{
    Vertex v1{0.0f,   0.0f,  0.0f,   1.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    Vertex v2{1.0f,   0.0f,  0.0f,   0.0f, 1.0f, 0.0f, 0.0f, 0.0f};
    Vertex v3{0.0f,   1.0f,  0.0f,   0.0f, 0.0f, 1.0f, 0.0f, 0.0f};
    Vertex v4{1.0f,   1.0f,  0.0f,   1.0f, 1.0f, 0.0f, 0.0f, 0.0f};
    mVertices.push_back(v1);
    mVertices.push_back(v2);
    mVertices.push_back(v3);
    mVertices.push_back(v3);
    mVertices.push_back(v2);
    mVertices.push_back(v4);
}


VkTriangleSurface::VkTriangleSurface(const std::string &filename)
{
    qDebug() << "HERE!!!!\n";
    std::ifstream inn(filename);
    if (!inn.is_open())
        return;
    // read input from math part of compulsory
    int n;
    Vertex v;
    //This one is used for the Apesadel
    //std::vector<Vertex> preFormatVertices;

    inn >> n;
    qDebug() << n;
    for (int i=0; i<n; i++)
    {
        inn >> v;
        //This one is used for the Apesadel
        //preFormatVertices.push_back(v);

        mVertices.push_back(v);
        qDebug() << v.x << v.y << v.z;
    }
    inn.close();

    n = sqrt(n);

    //This is to order the matrices properly for the Apesadel
/*
    for (int i = 0; i<n-1; i++) {
        for(int j = 1; j<n; j++) {
            mVertices.push_back(preFormatVertices[i*n + j]);
            mVertices.push_back(preFormatVertices[i*n + j - 1 + n]);
            mVertices.push_back(preFormatVertices[i*n + j - 1]);

            mVertices.push_back(preFormatVertices[i*n + j]);
            mVertices.push_back(preFormatVertices[i*n + j + n]);
            mVertices.push_back(preFormatVertices[i*n + j - 1 + n]);
        }
    }
*/
}
