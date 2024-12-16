#pragma once

class IntervalClock {
private:
    float elapseTime;
    float maxTime;

public:
    IntervalClock(float maxTime);

    bool Update(float deltaTime);
    void Restart();
};