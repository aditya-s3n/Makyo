#pragma once

#include "renderer/GpuTypes.h"

#include <glm/glm.hpp>

class Input;

// Fly camera for the real-time viewport (WASD + right-mouse look).
class Camera {
public:
    Camera(const glm::vec3& position = {0.0f, 1.0f, 4.0f}, float yaw = -90.0f,
           float pitch = 0.0f, float fovDegrees = 60.0f);

    void update(const Input& input, float deltaTime);
    void setAspect(float aspect);
    void lookAt(const glm::vec3& target);

    bool hasMoved() const { return m_moved; }
    void clearMoved() { m_moved = false; }

    GpuCamera gpuData() const;

    glm::vec3 position() const { return m_position; }
    glm::vec3 forward() const { return m_forward; }

    float moveSpeed = 3.0f;
    float lookSensitivity = 0.1f;

private:
    void updateVectors();

    glm::vec3 m_position;
    glm::vec3 m_forward{0.0f, 0.0f, -1.0f};
    glm::vec3 m_right{1.0f, 0.0f, 0.0f};
    glm::vec3 m_up{0.0f, 1.0f, 0.0f};
    float m_yaw;
    float m_pitch;
    float m_fov;
    float m_aspect = 16.0f / 9.0f;
    bool m_moved = true;
};
