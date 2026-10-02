#include "renderer/Renderer.h"

#include "core/Window.h"
#include "renderer/PathTracer.h"
#include "renderer/RenderSettings.h"
#include "renderer/SceneBuffers.h"
#include "scene/Camera.h"
#include "scene/Scene.h"
#include "ui/UI.h"
#include "vulkan/GraphicsPipeline.h"
#include "vulkan/Swapchain.h"
#include "vulkan/VulkanContext.h"

Renderer::Renderer(VulkanContext& context, Window& window)
    : m_context(context), m_window(window) {
    // TODO
}

Renderer::~Renderer() {
    // TODO
}

void Renderer::uploadScene(const Scene& scene) {
    // TODO
}

void Renderer::drawFrame(Camera& camera, const RenderSettings& settings, UI& ui) {
    // TODO
}

void Renderer::resetAccumulation() {
    // TODO
}

void Renderer::startOfflineRender(const RenderSettings& settings) {
    // TODO
}

void Renderer::cancelOfflineRender() {
    // TODO
}

bool Renderer::saveFrame(const std::string& path) {
    // TODO
    return false;
}

Swapchain& Renderer::swapchain() {
    return *m_swapchain;
}

uint32_t Renderer::accumulatedSamples() const {
    // TODO
    return 0;
}

void Renderer::createDisplayPipeline() {
    // TODO
}

void Renderer::createCommandBuffers() {
    // TODO
}

void Renderer::createSyncObjects() {
    // TODO
}

void Renderer::destroySyncObjects() {
    // TODO
}

void Renderer::recreateSwapchain() {
    // TODO
}

void Renderer::recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex, Camera& camera,
                                   const RenderSettings& settings, UI& ui) {
    // TODO
}
