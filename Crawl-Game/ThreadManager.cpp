#include "ThreadManager.h"

ThreadManager::ThreadManager()
{
	_inputListenerThread = new thread();
	_inputTimerThread = new thread();
	_autoSaveThread = new thread();
	_enemySpawnThread = new thread();
}

ThreadManager::~ThreadManager()
{
	delete _inputListenerThread;
	delete _inputTimerThread;
	delete _autoSaveThread;
	delete _enemySpawnThread;
}

void ThreadManager::StartInputListenerThread(Input* inputListener)
{
	_inputListenerThread = new thread(&Input::Listener, inputListener);
	_inputListenerThread->detach();
}

void ThreadManager::StartInputTimerThread(InputTimer* inputTimer)
{
	_inputListenerThread = new thread(&InputTimer::Run, inputTimer);
	_inputListenerThread->detach();
}

void ThreadManager::StartAutoSaveThread(AutosaveTimer* autosave) {
	_autoSaveThread = new thread(&AutosaveTimer::Run, autosave);
	_autoSaveThread->detach();
}

void ThreadManager::StartSpawnThread(EnemySpawn* enemySpawn)
{
	_enemySpawnThread = new thread(&EnemySpawn::Run, enemySpawn);
	_enemySpawnThread->detach();
}