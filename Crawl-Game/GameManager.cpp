#include "GameManager.h"

GameManager::GameManager()
{
	threadManager = new ThreadManager();
	input = new Input();
	gameUI = new GameUI();
	player = new Player();
}

GameManager::~GameManager()
{
	delete threadManager;
	delete input;
	delete gameUI;
	delete player;
}

void GameManager::Loop()
{
	char lastChar = input->LastInput();
	if (lastChar != 0) {
		exit = lastChar == KB_ESCAPE;
		cout << lastChar << endl;
	}
}

void GameManager::Setup()
{
	threadManager->StartInputThread(input);
}

bool GameManager::CheckExit()
{
	return exit;
} 