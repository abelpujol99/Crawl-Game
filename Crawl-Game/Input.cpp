#include "Input.h"

void Input::Listener() {
	bool exit = false;
	while (exit == false)
	{
		int keycode = ConsoleControl::WaitForReadNextKey();

		inputsReadMutex->lock();
		
		inputsRead->push_back(keycode);

		inputsReadMutex->unlock();
	}
}

int Input::LastInput() {

	if (!inputsRead->empty()) {

		inputsReadMutex->lock();

		int lastInput = *(inputsRead->end() - 1);
		inputsRead->pop_back();

		inputsReadMutex->unlock();

		return lastInput;
	}
	return 0;
}

bool Input::GetKey(int keycode)
{
	inputsReadMutex->lock();

	bool isDetected = false;
	auto it = inputsRead->begin();
	while (it != inputsRead->end() && !isDetected) {
		isDetected = *it == keycode;
	}

	inputsReadMutex->unlock();

	return isDetected;
}