#pragma once

#include <cstdint>

struct RenderSettings {
    uint32_t viewportSamplesPerPixel = 1;  // per frame while moving around
    uint32_t maxBounces = 4;
    bool accumulateWhenStill = true;

    uint32_t renderSamplesPerPixel = 1024; // target for the Render button
    uint32_t renderSamplesPerBatch = 16;
};
