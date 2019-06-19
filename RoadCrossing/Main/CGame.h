#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <string>
#include "CPlayer.h"
#include "CVehicle.h"
#include "ConsoleControl.h"
using namespace std;
class cGame
{
private:
	int level;
	bool quit;
	int numberOfLanes;
	int width;
	//cPlayer * player;
	vector<cLane*> map;
	friend class cPlayer;
public:
	cGame(int w, int h );
	~cGame();
	void Draw(cPlayer player);
	void Input(cPlayer &player);
	void Logic(cPlayer &player);
	void Reload(cPlayer &player);
	void Run(cPlayer &player);
	bool Is_Exit()
	{
		return quit;
	}
	void EndThread(thread *t);
	bool SaveLocal(string path);
	void Preset();
};

