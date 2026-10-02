#pragma once

#include <vulkan/vulkan.h>

#include <cstdint>
#include <vector>

class DescriptorSetLayoutBuilder {
public:
    DescriptorSetLayoutBuilder& addBinding(uint32_t binding, VkDescriptorType type,
                                           VkShaderStageFlags stages);
    VkDescriptorSetLayout build(VkDevice device) const;

private:
    std::vector<VkDescriptorSetLayoutBinding> m_bindings;
};

class DescriptorAllocator {
public:
    void init(VkDevice device, uint32_t maxSets, const std::vector<VkDescriptorPoolSize>& poolSizes);
    VkDescriptorSet allocate(VkDescriptorSetLayout layout);
    void reset();
    void destroy();

private:
    VkDevice m_device = VK_NULL_HANDLE;
    VkDescriptorPool m_pool = VK_NULL_HANDLE;
};

class DescriptorWriter {
public:
    DescriptorWriter& writeBuffer(uint32_t binding, VkBuffer buffer, VkDeviceSize size,
                                  VkDescriptorType type);
    DescriptorWriter& writeImage(uint32_t binding, VkImageView view, VkSampler sampler,
                                 VkImageLayout layout, VkDescriptorType type);
    void update(VkDevice device, VkDescriptorSet set);
    void clear();

private:
    std::vector<VkDescriptorBufferInfo> m_bufferInfos;
    std::vector<VkDescriptorImageInfo> m_imageInfos;
    std::vector<VkWriteDescriptorSet> m_writes;
};
