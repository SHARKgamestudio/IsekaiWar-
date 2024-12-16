#include "Clock.h"

Clock::Clock(bool start) {
	this->state = start ? Running : Stopped;
	this->time = 0.0f;
}

void Clock::Update(float deltaTime) {
	if (state == Running) {
		time += deltaTime;
	}
}

float Clock::GetTime() {
	return time;
}

Clock::State Clock::GetState() {
	return state;
}

void Clock::Start() {
	time = 0.0f;
	state = Running;
}

void Clock::Stop() {
	state = Stopped;
	time = 0.0f;
}

void Clock::Pause() {
	state = Paused;
}

void Clock::Resume() {
	state = Running;
}

void Clock::Reset() {
	time = 0.0f;
}