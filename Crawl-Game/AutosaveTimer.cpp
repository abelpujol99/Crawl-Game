#include "AutosaveTimer.h"

AutosaveTimer::AutosaveTimer() {
	targetTime = 0;
}

void AutosaveTimer::Run() {
	RestartTimer();
	while (true) {

	}
}

void AutosaveTimer::RestartTimer() {
	targetTime = clock() + AUTOSAVE_SECONDS * CLOCKS_PER_SEC;
}

bool AutosaveTimer::CheckSave() {
	if (clock() >= targetTime) {
		RestartTimer();
		return true;
	}
	return false;
}
