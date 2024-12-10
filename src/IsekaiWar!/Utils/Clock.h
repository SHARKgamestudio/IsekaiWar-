#pragma once

#pragma region External Dependencies

#include <iostream>
#include <chrono>
#include <thread>

#pragma endregion

//ChatGPT

class Clock {
private:
    bool running;
    long long elapsed_time;
    std::chrono::high_resolution_clock::time_point start_time;

public:
    Clock();

    void Start();
    void Pause();
    void Resume();
    long long GetElapsedTime();
};