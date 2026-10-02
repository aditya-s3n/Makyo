#pragma once

#include <vulkan/vulkan.h>

#include <string>
#include <vector>

namespace Shader {

std::vector<char> readSpirv(const std::string& path);
VkShaderModule createModule(VkDevice device, const std::vector<char>& code);
VkShaderModule loadModule(VkDevice device, const std::string& path);

} // namespace Shader
