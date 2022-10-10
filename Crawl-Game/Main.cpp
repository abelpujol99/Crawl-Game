#include "Input.h"
#include "ThreadManager.h"

int main() {
	ThreadManager* threadManager = new ThreadManager();
	Input* input = new Input();
	
	threadManager->StartInputThread(input);
	

	while (true) {
		char lastChar = input->LastInput();
		if (lastChar != 0) {
			cout << lastChar << endl;
		}
	}
}