#include "IntervalClock.h"

IntervalClock::IntervalClock(float maxTime) {
	this->maxTime = maxTime;
	elapseTime = 0;
};

bool IntervalClock::UpdateLogic(float deltaTime) {
	elapseTime += deltaTime;

	if (elapseTime > maxTime) {
		elapseTime = 0;
		return true;
	}
	return false;
}

void IntervalClock::Restart() {
	elapseTime = 0;
}