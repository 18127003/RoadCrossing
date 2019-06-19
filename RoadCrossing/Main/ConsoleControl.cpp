#include "pch.h"
#include "ConsoleControl.h"


ConsoleControl::ConsoleControl()
{
}


ConsoleControl::~ConsoleControl()
{
}
void ConsoleControl::FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void ConsoleControl::LoadLevel()
{
	cPlayer player;
	while (player.Is_Alive() == true)
	{
		cGame game(30+player.Level()*2, 5+player.Level()*1);
		player.setStartPos(game);
		while (game.Is_Exit() == false)
		{
			srand(unsigned int(time(NULL)));
			game.Run(player);
		}
	}
}
void ConsoleControl::Reset()
{
	system("cls");
	LoadLevel();
}