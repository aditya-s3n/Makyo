#pragma once

#include "renderer/GpuTypes.h"

#include <cstdint>
#include <vector>

// Bounding volume hierarchy over the scene triangles, traversed in pathtrace.comp.
class BVH {
public:
    void build(const std::vector<GpuTriangle>& triangles);
    void clear();

    const std::vector<GpuBVHNode>& nodes() const { return m_nodes; }
    const std::vector<uint32_t>& triangleIndices() const { return m_triangleIndices; }

private:
    void updateNodeBounds(uint32_t nodeIndex);
    void subdivide(uint32_t nodeIndex);
    float findBestSplit(const GpuBVHNode& node, int& axis, float& splitPos) const;

    const std::vector<GpuTriangle>* m_triangles = nullptr;
    std::vector<GpuBVHNode> m_nodes;
    std::vector<uint32_t> m_triangleIndices;
};
