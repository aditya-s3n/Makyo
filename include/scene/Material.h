#pragma once

#include <glm/glm.hpp>

#include <string>

struct Material {
    std::string name = "default";
    glm::vec3 albedo{0.8f};
    glm::vec3 emission{0.0f};
    float emissionStrength = 0.0f;
    float roughness = 1.0f;
    float metallic = 0.0f;
    float ior = 1.5f;
    float transmission = 0.0f;
};
