#pragma once

#include "renderer/GpuTypes.h"
#include "vulkan/Descriptors.h"

#include <vulkan/vulkan.h>

#include <cstdint>
#include <memory>

class VulkanContext;
class ComputePipeline;
class Image;
class Buffer;
class SceneBuffers;

// Records the compute dispatch that traces paths and accumulates into an HDR image.
class PathTracer {
public:
    PathTracer(VulkanContext& context, uint32_t width, uint32_t height);
    ~PathTracer();

    void resize(uint32_t width, uint32_t height);
    void setScene(const SceneBuffers& sceneBuffers);
    void resetAccumulation();

    void record(VkCommandBuffer commandBuffer, const GpuCamera& camera,
                uint32_t samplesPerPixel, uint32_t maxBounces);

    Image& outputImage();
    uint32_t accumulatedSamples() const { return m_accumulatedSamples; }

private:
    void createImages();
    void createDescriptors();
    void updateDescriptors();

    VulkanContext& m_context;
    uint32_t m_width;
    uint32_t m_height;

    std::unique_ptr<Image> m_accumulationImage;
    std::unique_ptr<Buffer> m_cameraBuffer;
    std::unique_ptr<ComputePipeline> m_pipeline;
    const SceneBuffers* m_sceneBuffers = nullptr;

    VkDescriptorSetLayout m_setLayout = VK_NULL_HANDLE;
    DescriptorAllocator m_descriptorAllocator;
    VkDescriptorSet m_descriptorSet = VK_NULL_HANDLE;

    uint32_t m_frameIndex = 0;
    uint32_t m_accumulatedSamples = 0;
};
