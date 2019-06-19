#pragma once
#include "cGame.h"
class cPlayer
{
private:
	int score = 0;
	int level = 0;
	friend class cGame;
	int x, y;
	bool live = true;
public:
	void IncreaseScore(){ score++;}
	int Score() { return score; }
	void LevelUp() { level++; }
	int Level() { return level; }
	cPlayer() {};
	//cPlayer(int width) { x = width / 2; y = 0; }
	bool Pos(int x, int y);
	void setStartPos(cGame &game);
	void SetAlive(bool is_live) { live = is_live; }
	bool Is_Alive() { return live; }
};

