#pragma once

#include <vulkan/vulkan.h>

#include <cstdint>
#include <string>

class VulkanContext;

// Fullscreen-triangle pipeline that draws the path traced image to the swapchain
// (dynamic rendering, no render pass). Tonemapping / gamma will live here later.
class GraphicsPipeline {
public:
    GraphicsPipeline(VulkanContext& context, const std::string& vertPath,
                     const std::string& fragPath, VkFormat colorFormat,
                     VkDescriptorSetLayout setLayout, uint32_t pushConstantSize);
    ~GraphicsPipeline();

    GraphicsPipeline(const GraphicsPipeline&) = delete;
    GraphicsPipeline& operator=(const GraphicsPipeline&) = delete;

    void bind(VkCommandBuffer commandBuffer) const;
    void bindDescriptorSet(VkCommandBuffer commandBuffer, VkDescriptorSet set) const;
    void pushConstants(VkCommandBuffer commandBuffer, const void* data, uint32_t size) const;

    VkPipeline handle() const { return m_pipeline; }
    VkPipelineLayout layout() const { return m_layout; }

private:
    VulkanContext& m_context;
    VkPipeline m_pipeline = VK_NULL_HANDLE;
    VkPipelineLayout m_layout = VK_NULL_HANDLE;
};
