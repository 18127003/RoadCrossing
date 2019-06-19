#include "pch.h"
#include "CPlayer.h"

bool cPlayer::Pos(int x, int y)
{
	if (this->x == x && this->y == y) return true;
	return false;
}
void cPlayer::setStartPos(cGame &game)
{
	x = game.width/2;
	y = 0;
}

