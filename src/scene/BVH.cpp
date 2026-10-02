#include "scene/BVH.h"

void BVH::build(const std::vector<GpuTriangle>& triangles) {
    // TODO
}

void BVH::clear() {
    // TODO
}

void BVH::updateNodeBounds(uint32_t nodeIndex) {
    // TODO
}

void BVH::subdivide(uint32_t nodeIndex) {
    // TODO
}

float BVH::findBestSplit(const GpuBVHNode& node, int& axis, float& splitPos) const {
    // TODO
    return 0.0f;
}
