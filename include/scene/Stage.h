#pragma once

class Scene;

// The environment the loaded objects sit in, picked from the UI dropdown.
enum class StageType {
    Floor,
    Box,
};

const char* stageTypeName(StageType type);

namespace Stage {

void build(StageType type, Scene& scene);
void buildFloor(Scene& scene);
void buildBox(Scene& scene);

} // namespace Stage
