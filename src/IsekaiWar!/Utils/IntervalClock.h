#pragma once

class IntervalClock {
private:
    float elapseTime;

public:
    float maxTime;

    IntervalClock(float maxTime);

    bool UpdateLogic(float deltaTime);
    void Restart();
};