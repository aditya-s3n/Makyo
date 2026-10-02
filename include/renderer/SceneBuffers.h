#pragma once

#include "vulkan/Buffer.h"

#include <memory>

class VulkanContext;
class Scene;

// GPU storage buffers for a built Scene.
class SceneBuffers {
public:
    explicit SceneBuffers(VulkanContext& context);

    void upload(const Scene& scene);

    const Buffer* triangles() const { return m_triangles.get(); }
    const Buffer* triangleIndices() const { return m_triangleIndices.get(); }
    const Buffer* bvhNodes() const { return m_bvhNodes.get(); }
    const Buffer* materials() const { return m_materials.get(); }

private:
    VulkanContext& m_context;
    std::unique_ptr<Buffer> m_triangles;
    std::unique_ptr<Buffer> m_triangleIndices;
    std::unique_ptr<Buffer> m_bvhNodes;
    std::unique_ptr<Buffer> m_materials;
};
