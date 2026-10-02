#include "vulkan/Swapchain.h"

#include "core/Window.h"
#include "vulkan/VulkanContext.h"

Swapchain::Swapchain(VulkanContext& context, Window& window)
    : m_context(context), m_window(window) {
    // TODO
}

Swapchain::~Swapchain() {
    // TODO
}

void Swapchain::recreate() {
    // TODO
}

VkResult Swapchain::acquireNextImage(VkSemaphore imageAvailable, uint32_t& imageIndex) {
    // TODO
    return VK_SUCCESS;
}

VkResult Swapchain::present(VkSemaphore renderFinished, uint32_t imageIndex) {
    // TODO
    return VK_SUCCESS;
}

void Swapchain::create() {
    // TODO
}

void Swapchain::createImageViews() {
    // TODO
}

void Swapchain::cleanup() {
    // TODO
}

VkSurfaceFormatKHR Swapchain::chooseSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& formats) const {
    // TODO
    return {};
}

VkPresentModeKHR Swapchain::choosePresentMode(const std::vector<VkPresentModeKHR>& modes) const {
    // TODO
    return VK_PRESENT_MODE_FIFO_KHR;
}

VkExtent2D Swapchain::chooseExtent(const VkSurfaceCapabilitiesKHR& capabilities) const {
    // TODO
    return {};
}
