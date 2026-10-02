#include "scene/Scene.h"

#include "io/MaterialLoader.h"
#include "io/ObjLoader.h"

void Scene::clear() {
    // TODO
}

void Scene::clearObjects() {
    // TODO
}

uint32_t Scene::addMaterial(const Material& material) {
    // TODO
    return 0;
}

void Scene::addMesh(const Mesh& mesh) {
    // TODO
}

void Scene::addStageMesh(const Mesh& mesh) {
    // TODO
}

bool Scene::loadObj(const std::string& path, std::string& error) {
    // TODO
    return false;
}

bool Scene::loadMaterials(const std::string& path, std::string& error) {
    // TODO
    return false;
}

void Scene::setStage(StageType type) {
    // TODO
}

void Scene::build() {
    // TODO
}

std::vector<GpuMaterial> Scene::gpuMaterials() const {
    // TODO
    return {};
}
