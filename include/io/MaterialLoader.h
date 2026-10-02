#pragma once

#include "scene/Material.h"

#include <string>
#include <vector>

// Loads standalone material files (.mtl) and maps them onto Material.
namespace MaterialLoader {

bool load(const std::string& path, std::vector<Material>& outMaterials, std::string& error);

} // namespace MaterialLoader
