#pragma once

#include <glm/glm.hpp>

#include <cstdint>
#include <string>
#include <vector>

struct Vertex {
    glm::vec3 position{0.0f};
    glm::vec3 normal{0.0f};
    glm::vec2 uv{0.0f};
};

struct Mesh {
    std::string name;
    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;
    uint32_t materialIndex = 0;
    glm::mat4 transform{1.0f};

    glm::vec3 boundsMin{0.0f};
    glm::vec3 boundsMax{0.0f};

    void computeBounds();
    void computeNormals();
    void normalizeToUnitSize();
};
