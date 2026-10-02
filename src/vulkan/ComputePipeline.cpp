#include "vulkan/ComputePipeline.h"

#include "vulkan/Shader.h"
#include "vulkan/VulkanContext.h"

ComputePipeline::ComputePipeline(VulkanContext& context, const std::string& shaderPath,
                                 VkDescriptorSetLayout setLayout, uint32_t pushConstantSize)
    : m_context(context) {
    // TODO
}

ComputePipeline::~ComputePipeline() {
    // TODO
}

void ComputePipeline::bind(VkCommandBuffer commandBuffer) const {
    // TODO
}

void ComputePipeline::bindDescriptorSet(VkCommandBuffer commandBuffer, VkDescriptorSet set) const {
    // TODO
}

void ComputePipeline::pushConstants(VkCommandBuffer commandBuffer, const void* data, uint32_t size) const {
    // TODO
}

void ComputePipeline::dispatch(VkCommandBuffer commandBuffer, uint32_t groupsX, uint32_t groupsY,
                               uint32_t groupsZ) const {
    // TODO
}
