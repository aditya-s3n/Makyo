#include "vulkan/GraphicsPipeline.h"

#include "vulkan/Shader.h"
#include "vulkan/VulkanContext.h"

GraphicsPipeline::GraphicsPipeline(VulkanContext& context, const std::string& vertPath,
                                   const std::string& fragPath, VkFormat colorFormat,
                                   VkDescriptorSetLayout setLayout, uint32_t pushConstantSize)
    : m_context(context) {
    // TODO
}

GraphicsPipeline::~GraphicsPipeline() {
    // TODO
}

void GraphicsPipeline::bind(VkCommandBuffer commandBuffer) const {
    // TODO
}

void GraphicsPipeline::bindDescriptorSet(VkCommandBuffer commandBuffer, VkDescriptorSet set) const {
    // TODO
}

void GraphicsPipeline::pushConstants(VkCommandBuffer commandBuffer, const void* data, uint32_t size) const {
    // TODO
}
