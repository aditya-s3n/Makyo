#pragma once

#include <memory>

class Window;
class Input;
class VulkanContext;
class Renderer;
class Scene;
class Camera;
class UI;
struct UIState;

// Owns every subsystem and drives the main loop.
class Application {
public:
    Application();
    ~Application();

    void run();

private:
    void init();
    void mainLoop();
    void update(float deltaTime);
    void handleUIRequests();
    void cleanup();

    std::unique_ptr<Window> m_window;
    std::unique_ptr<Input> m_input;
    std::unique_ptr<VulkanContext> m_context;
    std::unique_ptr<Scene> m_scene;
    std::unique_ptr<Camera> m_camera;
    std::unique_ptr<Renderer> m_renderer;
    std::unique_ptr<UI> m_ui;
    std::unique_ptr<UIState> m_uiState;
};
