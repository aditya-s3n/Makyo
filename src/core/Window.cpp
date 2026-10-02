#include "core/Window.h"

#include <GLFW/glfw3.h>

Window::Window(int width, int height, const std::string& title) {
    // TODO
}

Window::~Window() {
    // TODO
}

bool Window::shouldClose() const {
    // TODO
    return false;
}

void Window::pollEvents() {
    // TODO
}

void Window::waitWhileMinimized() {
    // TODO
}

void Window::getFramebufferSize(int& width, int& height) const {
    // TODO
}

bool Window::wasResized() const {
    return m_resized;
}

void Window::resetResizedFlag() {
    m_resized = false;
}

void Window::setFileDropCallback(FileDropCallback callback) {
    // TODO
}

void Window::framebufferResizeCallback(GLFWwindow* window, int width, int height) {
    // TODO
}

void Window::dropCallback(GLFWwindow* window, int count, const char** paths) {
    // TODO
}
