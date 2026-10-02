#include "vulkan/Shader.h"

namespace Shader {

std::vector<char> readSpirv(const std::string& path) {
    // TODO
    return {};
}

VkShaderModule createModule(VkDevice device, const std::vector<char>& code) {
    // TODO
    return VK_NULL_HANDLE;
}

VkShaderModule loadModule(VkDevice device, const std::string& path) {
    // TODO
    return VK_NULL_HANDLE;
}

} // namespace Shader
