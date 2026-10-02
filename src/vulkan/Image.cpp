#include "vulkan/Image.h"

#include "vulkan/VulkanContext.h"

Image::Image(VulkanContext& context, uint32_t width, uint32_t height, VkFormat format,
             VkImageUsageFlags usage)
    : m_context(context), m_format(format), m_width(width), m_height(height) {
    // TODO
}

Image::~Image() {
    // TODO
}

void Image::transitionLayout(VkCommandBuffer commandBuffer, VkImageLayout newLayout) {
    // TODO
}

void Image::copyToBuffer(VkCommandBuffer commandBuffer, VkBuffer destination) {
    // TODO
}

void Image::createImage(VkImageUsageFlags usage) {
    // TODO
}

void Image::createView() {
    // TODO
}

void Image::createSampler() {
    // TODO
}
