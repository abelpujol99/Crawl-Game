#include "GameManager.h"

int main() {
	GameManager gameManager;
	gameManager.Setup();
	while (true) {
		system("cls");
		gameManager.Loop();
	}
}