#include "InputTimer.h"

InputTimer::InputTimer() {
	targetTime = 0;
}

void InputTimer::Run() {
	RestartTimer();
	while (true) {

	}
}

void InputTimer::RestartTimer() {
	targetTime = clock() + INPUT_TIME;
}

bool InputTimer::CheckInput() {
	if (clock() >= targetTime) {
		RestartTimer();
		return true;
	}
	return false;
}
