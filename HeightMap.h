#ifndef HEIGHTMAP_H
#define HEIGHTMAP_H

#include "VisualObject.h"
#include <string>

class HeightMap : public VisualObject
{
public:
    HeightMap();

    void makeTerrain(std::string heightMapImage);

    void makeTerrain(unsigned char* textureData, int width, int height);

    QVector3D locatePoint(QVector3D point);

    QVector3D cartesianToBarycentric2(QVector2D p, QVector2D a, QVector2D b, QVector2D c);

private:
	int mWidth{ 0 };
	int mHeight{ 0 };
	int mChannels{ 0 };
    float startX;
    float startZ;
    unsigned short mArrayWidth;
    unsigned short mArrayDepth;
};

#endif // HEIGHTMAP_H
