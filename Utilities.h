#ifndef UTILITIES_H
#define UTILITIES_H

#include <QVulkanFunctions>
#include <QMatrix4x4>

//Utility function for alignment:
static inline VkDeviceSize aligned(VkDeviceSize v, VkDeviceSize byteAlign)
{
    return (v + byteAlign - 1) & ~(byteAlign - 1);
}

//Utility struct for handling buffers
struct BufferHandle
{
    VkDeviceMemory mBufferMemory{ VK_NULL_HANDLE };
    VkBuffer mBuffer{ VK_NULL_HANDLE };
};

//Utility struct for handling uniform transformations
struct UniformTransformations
{
    float mView[16]{};
    float mProjection[16]{};
};

#endif // UTILITIES_H
