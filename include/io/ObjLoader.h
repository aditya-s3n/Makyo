#pragma once

#include "scene/Material.h"
#include "scene/Mesh.h"

#include <string>
#include <vector>

struct ObjLoadResult {
    bool success = false;
    std::string error;
    std::vector<Mesh> meshes;
    std::vector<Material> materials; // from the .mtl referenced by the .obj, if any
};

namespace ObjLoader {

ObjLoadResult load(const std::string& path);

} // namespace ObjLoader
