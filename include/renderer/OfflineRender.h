#pragma once

#include <cstdint>

// State machine for the Render button: locks the camera, accumulates batches
// until the target samples per pixel is reached, then the frame gets saved.
class OfflineRender {
public:
    enum class State { Idle, Rendering, Finished };

    void start(uint32_t targetSamples, uint32_t samplesPerBatch);
    void cancel();
    void reset();

    uint32_t nextBatchSize() const;
    void onBatchComplete(uint32_t samples);

    State state() const { return m_state; }
    bool isActive() const { return m_state == State::Rendering; }
    float progress() const;

private:
    State m_state = State::Idle;
    uint32_t m_targetSamples = 0;
    uint32_t m_samplesPerBatch = 0;
    uint32_t m_completedSamples = 0;
};
