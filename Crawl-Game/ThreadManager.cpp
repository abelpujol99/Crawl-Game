#include "ThreadManager.h"

ThreadManager::ThreadManager()
{
	_inputListenerThread = new thread();
}

ThreadManager::~ThreadManager()
{
	delete _inputListenerThread;
	for (auto timer : _timerThreads) {
		delete timer;
	}
	_timerThreads.clear();
}

void ThreadManager::StartInputListenerThread(Input* inputListener)
{
	_inputListenerThread = new thread(&Input::Listener, inputListener);
	_inputListenerThread->detach();
}

void ThreadManager::StartTimer(Timer* timer)
{
	_timerThreads.push_back(new thread(&Timer::Run, timer));
	_timerThreads.back()->detach();
}