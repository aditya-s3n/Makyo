#include "vulkan/Descriptors.h"

DescriptorSetLayoutBuilder& DescriptorSetLayoutBuilder::addBinding(uint32_t binding, VkDescriptorType type,
                                                                   VkShaderStageFlags stages) {
    // TODO
    return *this;
}

VkDescriptorSetLayout DescriptorSetLayoutBuilder::build(VkDevice device) const {
    // TODO
    return VK_NULL_HANDLE;
}

void DescriptorAllocator::init(VkDevice device, uint32_t maxSets,
                               const std::vector<VkDescriptorPoolSize>& poolSizes) {
    // TODO
}

VkDescriptorSet DescriptorAllocator::allocate(VkDescriptorSetLayout layout) {
    // TODO
    return VK_NULL_HANDLE;
}

void DescriptorAllocator::reset() {
    // TODO
}

void DescriptorAllocator::destroy() {
    // TODO
}

DescriptorWriter& DescriptorWriter::writeBuffer(uint32_t binding, VkBuffer buffer, VkDeviceSize size,
                                                VkDescriptorType type) {
    // TODO
    return *this;
}

DescriptorWriter& DescriptorWriter::writeImage(uint32_t binding, VkImageView view, VkSampler sampler,
                                               VkImageLayout layout, VkDescriptorType type) {
    // TODO
    return *this;
}

void DescriptorWriter::update(VkDevice device, VkDescriptorSet set) {
    // TODO
}

void DescriptorWriter::clear() {
    // TODO
}
