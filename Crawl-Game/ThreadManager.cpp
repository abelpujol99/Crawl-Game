#include "ThreadManager.h"

ThreadManager::ThreadManager()
{
	_inputListenerThread = new thread();
	_autoSaveThread = new thread();
	_createEntityThread = new thread();
}

ThreadManager::~ThreadManager()
{
	delete _inputListenerThread;
	delete _autoSaveThread;
	delete _createEntityThread;
}

void ThreadManager::StartInputThread(Input* input)
{
	_inputListenerThread = new thread(&Input::Listener, input);
	_inputListenerThread->detach();
}
