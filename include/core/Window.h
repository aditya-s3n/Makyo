#pragma once

#include <functional>
#include <string>
#include <vector>

struct GLFWwindow;

// Thin GLFW wrapper: window creation, resize tracking and file drag-and-drop.
class Window {
public:
    using FileDropCallback = std::function<void(const std::vector<std::string>&)>;

    Window(int width, int height, const std::string& title);
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    bool shouldClose() const;
    void pollEvents();
    void waitWhileMinimized();

    void getFramebufferSize(int& width, int& height) const;
    bool wasResized() const;
    void resetResizedFlag();

    void setFileDropCallback(FileDropCallback callback);

    GLFWwindow* handle() const { return m_window; }

private:
    static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
    static void dropCallback(GLFWwindow* window, int count, const char** paths);

    GLFWwindow* m_window = nullptr;
    bool m_resized = false;
    FileDropCallback m_dropCallback;
};
