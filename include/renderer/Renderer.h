#pragma once

#include "renderer/OfflineRender.h"

#include <vulkan/vulkan.h>

#include <array>
#include <cstdint>
#include <memory>
#include <string>

class VulkanContext;
class Window;
class Swapchain;
class PathTracer;
class SceneBuffers;
class GraphicsPipeline;
class Scene;
class Camera;
class UI;
struct RenderSettings;

// Per-frame orchestration: path trace -> display pass -> UI -> present.
class Renderer {
public:
    static constexpr uint32_t MAX_FRAMES_IN_FLIGHT = 2;

    Renderer(VulkanContext& context, Window& window);
    ~Renderer();

    void uploadScene(const Scene& scene);
    void drawFrame(Camera& camera, const RenderSettings& settings, UI& ui);
    void resetAccumulation();

    void startOfflineRender(const RenderSettings& settings);
    void cancelOfflineRender();
    const OfflineRender& offlineRender() const { return m_offlineRender; }

    bool saveFrame(const std::string& path);

    Swapchain& swapchain();
    uint32_t accumulatedSamples() const;

private:
    void createDisplayPipeline();
    void createCommandBuffers();
    void createSyncObjects();
    void destroySyncObjects();
    void recreateSwapchain();

    void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex, Camera& camera,
                             const RenderSettings& settings, UI& ui);

    VulkanContext& m_context;
    Window& m_window;

    std::unique_ptr<Swapchain> m_swapchain;
    std::unique_ptr<PathTracer> m_pathTracer;
    std::unique_ptr<SceneBuffers> m_sceneBuffers;
    std::unique_ptr<GraphicsPipeline> m_displayPipeline;
    VkDescriptorSetLayout m_displaySetLayout = VK_NULL_HANDLE;
    VkDescriptorSet m_displaySet = VK_NULL_HANDLE;

    OfflineRender m_offlineRender;

    std::array<VkCommandBuffer, MAX_FRAMES_IN_FLIGHT> m_commandBuffers{};
    std::array<VkSemaphore, MAX_FRAMES_IN_FLIGHT> m_imageAvailable{};
    std::array<VkSemaphore, MAX_FRAMES_IN_FLIGHT> m_renderFinished{};
    std::array<VkFence, MAX_FRAMES_IN_FLIGHT> m_inFlight{};
    uint32_t m_currentFrame = 0;
};
