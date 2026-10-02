#include "vulkan/Buffer.h"

#include "vulkan/VulkanContext.h"

Buffer::Buffer(VulkanContext& context, VkDeviceSize size, VkBufferUsageFlags usage,
               VkMemoryPropertyFlags properties)
    : m_context(&context), m_size(size) {
    // TODO
}

Buffer::~Buffer() {
    destroy();
}

Buffer::Buffer(Buffer&& other) noexcept {
    // TODO
}

Buffer& Buffer::operator=(Buffer&& other) noexcept {
    // TODO
    return *this;
}

void* Buffer::map() {
    // TODO
    return nullptr;
}

void Buffer::unmap() {
    // TODO
}

void Buffer::write(const void* data, VkDeviceSize size, VkDeviceSize offset) {
    // TODO
}

void Buffer::uploadStaged(const void* data, VkDeviceSize size) {
    // TODO
}

void Buffer::destroy() {
    // TODO
}
