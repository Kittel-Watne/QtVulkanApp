#ifndef VISUALOBJECT_H
#define VISUALOBJECT_H

#include <QVulkanWindow>
#include <vector>
#include "Vertex.h"

class VisualObject
{
public:
    VisualObject();

    void move(float x, float y = 0.0f, float z = 0.0f);
    void scale(float s);
    void rotate(float t, float x, float y, float z);

	//Setters and Getters
    inline std::vector<Vertex> getVertices() { return mVertices; }
    inline VkBuffer& getBuffer() { return mBuffer; }
    inline VkDeviceMemory& getBufferMemory() { return mBufferMemory; }
    inline void setBuffer(VkBuffer bufferIn) { mBuffer = bufferIn; }
    inline void setBufferMemory(VkDeviceMemory bufferMemoryIn) { mBufferMemory = bufferMemoryIn; }
    inline void setName(std::string name) { mName = name; }
    inline std::string getName() const { return mName; }
    inline int getDrawType() const { return drawType; }
    inline QMatrix4x4 getMatrix() const {return mMatrix;}
	inline std::vector<Vertex> getVertices() const { return mVertices; }

protected:
    std::vector<Vertex> mVertices;
    QMatrix4x4 mMatrix;
    std::string mName;

    VkDeviceMemory mBufferMemory{ VK_NULL_HANDLE };
    VkBuffer mBuffer{ VK_NULL_HANDLE };
    //VkPrimitiveTopology mTopology{ VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST }; //not used

    int drawType{ 0 }; // 0 = fill, 1 = line
};

#endif // VISUALOBJECT_H

