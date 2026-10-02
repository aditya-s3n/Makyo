#include "io/ImageWriter.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

namespace ImageWriter {

bool writePng(const std::string& path, uint32_t width, uint32_t height,
              const std::vector<uint8_t>& rgba8) {
    // TODO
    return false;
}

bool writeHdr(const std::string& path, uint32_t width, uint32_t height,
              const std::vector<float>& rgba32f) {
    // TODO
    return false;
}

std::string timestampedFilename(const std::string& directory, const std::string& extension) {
    // TODO
    return {};
}

} // namespace ImageWriter
