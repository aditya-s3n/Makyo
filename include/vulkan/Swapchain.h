#pragma once

#include <vulkan/vulkan.h>

#include <cstdint>
#include <vector>

class VulkanContext;
class Window;

class Swapchain {
public:
    Swapchain(VulkanContext& context, Window& window);
    ~Swapchain();

    Swapchain(const Swapchain&) = delete;
    Swapchain& operator=(const Swapchain&) = delete;

    void recreate();

    VkResult acquireNextImage(VkSemaphore imageAvailable, uint32_t& imageIndex);
    VkResult present(VkSemaphore renderFinished, uint32_t imageIndex);

    VkFormat imageFormat() const { return m_imageFormat; }
    VkExtent2D extent() const { return m_extent; }
    uint32_t imageCount() const { return static_cast<uint32_t>(m_images.size()); }
    VkImage image(uint32_t index) const { return m_images[index]; }
    VkImageView imageView(uint32_t index) const { return m_imageViews[index]; }

private:
    void create();
    void createImageViews();
    void cleanup();

    VkSurfaceFormatKHR chooseSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& formats) const;
    VkPresentModeKHR choosePresentMode(const std::vector<VkPresentModeKHR>& modes) const;
    VkExtent2D chooseExtent(const VkSurfaceCapabilitiesKHR& capabilities) const;

    VulkanContext& m_context;
    Window& m_window;

    VkSwapchainKHR m_swapchain = VK_NULL_HANDLE;
    VkFormat m_imageFormat = VK_FORMAT_UNDEFINED;
    VkExtent2D m_extent{};
    std::vector<VkImage> m_images;
    std::vector<VkImageView> m_imageViews;
};
