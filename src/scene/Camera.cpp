#include "scene/Camera.h"

#include "core/Input.h"

Camera::Camera(const glm::vec3& position, float yaw, float pitch, float fovDegrees)
    : m_position(position), m_yaw(yaw), m_pitch(pitch), m_fov(fovDegrees) {
    // TODO
}

void Camera::update(const Input& input, float deltaTime) {
    // TODO
}

void Camera::setAspect(float aspect) {
    // TODO
}

void Camera::lookAt(const glm::vec3& target) {
    // TODO
}

GpuCamera Camera::gpuData() const {
    // TODO
    return {};
}

void Camera::updateVectors() {
    // TODO
}
