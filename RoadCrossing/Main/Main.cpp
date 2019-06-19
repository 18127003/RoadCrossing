// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <conio.h>
#include <time.h>
#include "CGame.h"
#include "ConsoleControl.h"
using namespace std;



int main()
{
	ConsoleControl scr;
	scr.FixConsoleWindow();
	scr.LoadLevel();
	cout << "Game over!" << endl;
	char temp;
	temp = _getch();
	while (temp == 'r')
	{
		
		scr.Reset();
		cout << "Game over!" << endl;
		temp = _getch();
	}
	return 0;
}
