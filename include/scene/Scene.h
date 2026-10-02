#pragma once

#include "renderer/GpuTypes.h"
#include "scene/BVH.h"
#include "scene/Material.h"
#include "scene/Mesh.h"
#include "scene/Stage.h"

#include <cstdint>
#include <string>
#include <vector>

// CPU-side scene: user-loaded objects + the stage (floor / box).
class Scene {
public:
    void clear();
    void clearObjects();

    uint32_t addMaterial(const Material& material);
    void addMesh(const Mesh& mesh);
    void addStageMesh(const Mesh& mesh);

    bool loadObj(const std::string& path, std::string& error);
    bool loadMaterials(const std::string& path, std::string& error);

    void setStage(StageType type);
    StageType stage() const { return m_stage; }

    // Flattens meshes into GPU triangles and rebuilds the BVH.
    void build();

    bool isDirty() const { return m_dirty; }
    void clearDirty() { m_dirty = false; }

    const std::vector<Mesh>& meshes() const { return m_meshes; }
    const std::vector<Material>& materials() const { return m_materials; }
    const std::vector<GpuTriangle>& triangles() const { return m_triangles; }
    std::vector<GpuMaterial> gpuMaterials() const;
    const BVH& bvh() const { return m_bvh; }

private:
    std::vector<Mesh> m_meshes;
    std::vector<Mesh> m_stageMeshes;
    std::vector<Material> m_materials;
    std::vector<GpuTriangle> m_triangles;
    BVH m_bvh;
    StageType m_stage = StageType::Floor;
    bool m_dirty = true;
};
