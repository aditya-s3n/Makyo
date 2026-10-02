#pragma once

#include <glm/glm.hpp>

struct GLFWwindow;

// Polls keyboard / mouse state each frame for camera movement.
class Input {
public:
    explicit Input(GLFWwindow* window);

    void update();

    bool isKeyDown(int key) const;
    bool isMouseButtonDown(int button) const;

    glm::vec2 mouseDelta() const;
    float scrollDelta() const;

    void setCursorCaptured(bool captured);

private:
    static void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);

    GLFWwindow* m_window = nullptr;
    glm::vec2 m_lastMousePos{0.0f};
    glm::vec2 m_mouseDelta{0.0f};
    float m_scrollDelta = 0.0f;
    bool m_firstMouse = true;
};
