#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace ImageWriter {

bool writePng(const std::string& path, uint32_t width, uint32_t height,
              const std::vector<uint8_t>& rgba8);
bool writeHdr(const std::string& path, uint32_t width, uint32_t height,
              const std::vector<float>& rgba32f);

std::string timestampedFilename(const std::string& directory, const std::string& extension);

} // namespace ImageWriter
