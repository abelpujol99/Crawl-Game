#include "GameManager.h"

int main() {
	GameManager gameManager;
	gameManager.Setup();
	while (!gameManager.CheckExit()) {
		gameManager.Loop();
	}
}