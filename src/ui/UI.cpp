#include "ui/UI.h"

#include "core/Window.h"
#include "vulkan/VulkanContext.h"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_vulkan.h>

void UIState::clearRequests() {
    stageChanged = false;
    loadObjRequested = false;
    loadMaterialRequested = false;
    renderRequested = false;
    cancelRenderRequested = false;
    saveRequested = false;
    settingsChanged = false;
}

UI::UI(VulkanContext& context, Window& window, VkFormat swapchainFormat, uint32_t imageCount)
    : m_context(context) {
    // TODO
}

UI::~UI() {
    // TODO
}

void UI::beginFrame() {
    // TODO
}

void UI::draw(UIState& state, const RenderStats& stats) {
    // TODO
}

void UI::render(VkCommandBuffer commandBuffer) {
    // TODO
}

bool UI::wantsMouse() const {
    // TODO
    return false;
}

bool UI::wantsKeyboard() const {
    // TODO
    return false;
}

void UI::createDescriptorPool() {
    // TODO
}

void UI::drawScenePanel(UIState& state) {
    // TODO: stage dropdown (Floor / Box), OBJ + material load
}

void UI::drawViewportPanel(UIState& state) {
    // TODO: viewport spp, max bounces
}

void UI::drawRenderPanel(UIState& state, const RenderStats& stats) {
    // TODO: Render button, target spp, progress, save
}

void UI::drawStats(const RenderStats& stats) {
    // TODO
}
