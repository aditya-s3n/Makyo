#include "vulkan/VulkanContext.h"

#include "core/Window.h"

bool QueueFamilyIndices::isComplete() const {
    return graphicsCompute.has_value() && present.has_value();
}

VulkanContext::VulkanContext(Window& window) {
    // TODO
}

VulkanContext::~VulkanContext() {
    // TODO
}

VkCommandBuffer VulkanContext::beginSingleTimeCommands() const {
    // TODO
    return VK_NULL_HANDLE;
}

void VulkanContext::endSingleTimeCommands(VkCommandBuffer commandBuffer) const {
    // TODO
}

uint32_t VulkanContext::findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties) const {
    // TODO
    return 0;
}

void VulkanContext::waitIdle() const {
    // TODO
}

void VulkanContext::createInstance() {
    // TODO
}

void VulkanContext::setupDebugMessenger() {
    // TODO
}

void VulkanContext::createSurface(Window& window) {
    // TODO
}

void VulkanContext::pickPhysicalDevice() {
    // TODO
}

void VulkanContext::createLogicalDevice() {
    // TODO
}

void VulkanContext::createCommandPool() {
    // TODO
}

bool VulkanContext::isDeviceSuitable(VkPhysicalDevice device) const {
    // TODO
    return false;
}

bool VulkanContext::checkDeviceExtensionSupport(VkPhysicalDevice device) const {
    // TODO
    return false;
}

bool VulkanContext::checkValidationLayerSupport() const {
    // TODO
    return false;
}

QueueFamilyIndices VulkanContext::findQueueFamilies(VkPhysicalDevice device) const {
    // TODO
    return {};
}

std::vector<const char*> VulkanContext::getRequiredExtensions() const {
    // TODO
    return {};
}
