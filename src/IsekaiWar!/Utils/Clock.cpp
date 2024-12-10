#include "Clock.h"

Clock::Clock() : running(false), elapsed_time(0) {}

void Clock::Start() {
    start_time = std::chrono::high_resolution_clock::now();
    running = true;
}

void Clock::Pause() {
    if (running) {
        auto current_time = std::chrono::high_resolution_clock::now();
        elapsed_time += std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count();
        running = false;
    }
}

void Clock::Resume() {
    if (!running) {
        start_time = std::chrono::high_resolution_clock::now();
        running = true;
    }
}

long long Clock::GetElapsedTime() {
    if (running) {
        auto current_time = std::chrono::high_resolution_clock::now();
        return elapsed_time + std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count();
    }
    else {
        return elapsed_time;
    }
}