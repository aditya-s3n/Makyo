#include "core/Input.h"

#include <GLFW/glfw3.h>

Input::Input(GLFWwindow* window) : m_window(window) {
    // TODO
}

void Input::update() {
    // TODO
}

bool Input::isKeyDown(int key) const {
    // TODO
    return false;
}

bool Input::isMouseButtonDown(int button) const {
    // TODO
    return false;
}

glm::vec2 Input::mouseDelta() const {
    return m_mouseDelta;
}

float Input::scrollDelta() const {
    return m_scrollDelta;
}

void Input::setCursorCaptured(bool captured) {
    // TODO
}

void Input::scrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
    // TODO
}
