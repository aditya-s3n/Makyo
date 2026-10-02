#include "scene/Stage.h"

#include "scene/Scene.h"

const char* stageTypeName(StageType type) {
    switch (type) {
    case StageType::Floor: return "Floor";
    case StageType::Box:   return "Box";
    }
    return "Unknown";
}

namespace Stage {

void build(StageType type, Scene& scene) {
    // TODO
}

void buildFloor(Scene& scene) {
    // TODO
}

void buildBox(Scene& scene) {
    // TODO
}

} // namespace Stage
