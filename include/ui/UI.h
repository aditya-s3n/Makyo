#pragma once

#include "renderer/RenderSettings.h"
#include "scene/Stage.h"

#include <vulkan/vulkan.h>

#include <cstdint>
#include <string>

class VulkanContext;
class Window;

// Values the UI edits plus one-shot requests the Application consumes each frame.
struct UIState {
    RenderSettings settings;
    StageType stage = StageType::Floor;

    std::string objPath;
    std::string materialPath;
    std::string statusMessage;

    bool stageChanged = false;
    bool loadObjRequested = false;
    bool loadMaterialRequested = false;
    bool renderRequested = false;
    bool cancelRenderRequested = false;
    bool saveRequested = false;
    bool settingsChanged = false;

    void clearRequests();
};

struct RenderStats {
    float frameTimeMs = 0.0f;
    uint32_t accumulatedSamples = 0;
    float renderProgress = 0.0f;
    bool rendering = false;
};

// Dear ImGui control panel.
class UI {
public:
    UI(VulkanContext& context, Window& window, VkFormat swapchainFormat, uint32_t imageCount);
    ~UI();

    UI(const UI&) = delete;
    UI& operator=(const UI&) = delete;

    void beginFrame();
    void draw(UIState& state, const RenderStats& stats);
    void render(VkCommandBuffer commandBuffer);

    bool wantsMouse() const;
    bool wantsKeyboard() const;

private:
    void createDescriptorPool();
    void drawScenePanel(UIState& state);
    void drawViewportPanel(UIState& state);
    void drawRenderPanel(UIState& state, const RenderStats& stats);
    void drawStats(const RenderStats& stats);

    VulkanContext& m_context;
    VkDescriptorPool m_descriptorPool = VK_NULL_HANDLE;
};
