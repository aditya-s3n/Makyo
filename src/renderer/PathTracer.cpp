#include "renderer/PathTracer.h"

#include "renderer/SceneBuffers.h"
#include "vulkan/Buffer.h"
#include "vulkan/ComputePipeline.h"
#include "vulkan/Image.h"
#include "vulkan/VulkanContext.h"

PathTracer::PathTracer(VulkanContext& context, uint32_t width, uint32_t height)
    : m_context(context), m_width(width), m_height(height) {
    // TODO
}

PathTracer::~PathTracer() {
    // TODO
}

void PathTracer::resize(uint32_t width, uint32_t height) {
    // TODO
}

void PathTracer::setScene(const SceneBuffers& sceneBuffers) {
    // TODO
}

void PathTracer::resetAccumulation() {
    // TODO
}

void PathTracer::record(VkCommandBuffer commandBuffer, const GpuCamera& camera,
                        uint32_t samplesPerPixel, uint32_t maxBounces) {
    // TODO
}

Image& PathTracer::outputImage() {
    return *m_accumulationImage;
}

void PathTracer::createImages() {
    // TODO
}

void PathTracer::createDescriptors() {
    // TODO
}

void PathTracer::updateDescriptors() {
    // TODO
}
