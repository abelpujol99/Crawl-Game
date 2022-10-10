#pragma once
#include <vector>
#include <iostream>
#include <mutex>
#include "ConsoleControl.h"

using namespace std;

class Input
{
private:
	vector<int>* inputsRead = new vector<int>();
	mutex* inputsReadMutex = new mutex();
public:
	void Listener();

	int LastInput();

	bool GetKey(int keycode);
	

};

