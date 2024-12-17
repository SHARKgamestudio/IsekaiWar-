#pragma once

class IntervalClock {
private:
    float elapseTime;

public:
    float maxTime;

    IntervalClock(float maxTime);

    bool Update(float deltaTime);
    void Restart();
};