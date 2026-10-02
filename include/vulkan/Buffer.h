#pragma once

#include <vulkan/vulkan.h>

class VulkanContext;

// VkBuffer + memory. Used for scene data (triangles, BVH, materials) and readback.
class Buffer {
public:
    Buffer(VulkanContext& context, VkDeviceSize size, VkBufferUsageFlags usage,
           VkMemoryPropertyFlags properties);
    ~Buffer();

    Buffer(const Buffer&) = delete;
    Buffer& operator=(const Buffer&) = delete;
    Buffer(Buffer&& other) noexcept;
    Buffer& operator=(Buffer&& other) noexcept;

    // Host-visible buffers only.
    void* map();
    void unmap();
    void write(const void* data, VkDeviceSize size, VkDeviceSize offset = 0);

    // Device-local buffers: copies through a temporary staging buffer.
    void uploadStaged(const void* data, VkDeviceSize size);

    VkBuffer handle() const { return m_buffer; }
    VkDeviceSize size() const { return m_size; }

private:
    void destroy();

    VulkanContext* m_context = nullptr;
    VkBuffer m_buffer = VK_NULL_HANDLE;
    VkDeviceMemory m_memory = VK_NULL_HANDLE;
    VkDeviceSize m_size = 0;
    void* m_mapped = nullptr;
};
