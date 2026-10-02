#pragma once

#include <glm/glm.hpp>

#include <cstdint>

// std430-compatible structs. Must stay in sync with shaders/common.glsl.

struct GpuTriangle {
    glm::vec4 v0;       // xyz = position, w = unused
    glm::vec4 v1;
    glm::vec4 v2;
    glm::vec4 n0;       // xyz = normal
    glm::vec4 n1;
    glm::vec4 n2;
    glm::vec4 centroid; // xyz = centroid, w = material index (as float bits)
};

struct GpuMaterial {
    glm::vec4 albedo;   // rgb, a = roughness
    glm::vec4 emission; // rgb, a = strength
    glm::vec4 params;   // x = metallic, y = ior, z = transmission, w = unused
};

struct GpuBVHNode {
    glm::vec3 aabbMin;
    uint32_t leftOrFirst;   // left child index, or first triangle if leaf
    glm::vec3 aabbMax;
    uint32_t triangleCount; // 0 = interior node
};

struct GpuCamera {
    glm::vec4 position;
    glm::vec4 forward;
    glm::vec4 right;
    glm::vec4 up;       // w = tan(fov / 2)
};

struct PathTracePushConstants {
    uint32_t frameIndex;
    uint32_t samplesPerPixel;
    uint32_t maxBounces;
    uint32_t accumulatedSamples;
};
