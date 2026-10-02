#pragma once

#include <vulkan/vulkan.h>

#include <cstdint>

class VulkanContext;

// 2D image used as the path tracer's accumulation / output target.
class Image {
public:
    Image(VulkanContext& context, uint32_t width, uint32_t height, VkFormat format,
          VkImageUsageFlags usage);
    ~Image();

    Image(const Image&) = delete;
    Image& operator=(const Image&) = delete;

    void transitionLayout(VkCommandBuffer commandBuffer, VkImageLayout newLayout);
    void copyToBuffer(VkCommandBuffer commandBuffer, VkBuffer destination);

    VkImage handle() const { return m_image; }
    VkImageView view() const { return m_view; }
    VkSampler sampler() const { return m_sampler; }
    VkFormat format() const { return m_format; }
    VkImageLayout layout() const { return m_layout; }
    uint32_t width() const { return m_width; }
    uint32_t height() const { return m_height; }

private:
    void createImage(VkImageUsageFlags usage);
    void createView();
    void createSampler();

    VulkanContext& m_context;
    VkImage m_image = VK_NULL_HANDLE;
    VkDeviceMemory m_memory = VK_NULL_HANDLE;
    VkImageView m_view = VK_NULL_HANDLE;
    VkSampler m_sampler = VK_NULL_HANDLE;
    VkFormat m_format = VK_FORMAT_UNDEFINED;
    VkImageLayout m_layout = VK_IMAGE_LAYOUT_UNDEFINED;
    uint32_t m_width = 0;
    uint32_t m_height = 0;
};
