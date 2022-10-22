#include "GameManager.h"

int main() {
	GameManager gameManager;
	ConsoleControl::ShowConsoleCursor(false);
	gameManager.Setup();
	//while (true) {
		gameManager.Loop();
	//}
}