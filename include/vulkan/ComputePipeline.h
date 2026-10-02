#pragma once

#include <vulkan/vulkan.h>

#include <cstdint>
#include <string>

class VulkanContext;

class ComputePipeline {
public:
    ComputePipeline(VulkanContext& context, const std::string& shaderPath,
                    VkDescriptorSetLayout setLayout, uint32_t pushConstantSize);
    ~ComputePipeline();

    ComputePipeline(const ComputePipeline&) = delete;
    ComputePipeline& operator=(const ComputePipeline&) = delete;

    void bind(VkCommandBuffer commandBuffer) const;
    void bindDescriptorSet(VkCommandBuffer commandBuffer, VkDescriptorSet set) const;
    void pushConstants(VkCommandBuffer commandBuffer, const void* data, uint32_t size) const;
    void dispatch(VkCommandBuffer commandBuffer, uint32_t groupsX, uint32_t groupsY,
                  uint32_t groupsZ = 1) const;

    VkPipeline handle() const { return m_pipeline; }
    VkPipelineLayout layout() const { return m_layout; }

private:
    VulkanContext& m_context;
    VkPipeline m_pipeline = VK_NULL_HANDLE;
    VkPipelineLayout m_layout = VK_NULL_HANDLE;
};
