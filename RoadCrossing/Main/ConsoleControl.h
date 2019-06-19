#pragma once
#include <windows.h>
#include <thread>
#include "CGame.h"
#include <time.h>
using namespace std;
class ConsoleControl
{
public:
	ConsoleControl();
	~ConsoleControl();
	void FixConsoleWindow();
	void LoadLevel();
	void Reset();
private:

};

