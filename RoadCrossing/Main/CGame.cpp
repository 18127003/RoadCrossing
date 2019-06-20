
#include "pch.h"
#include "CGame.h"


cGame::cGame(int w = 20, int h = 10)
{
	numberOfLanes = h;
	width = w;
	quit = false;
	for (int i = 0; i < numberOfLanes; i++)
	{
		if (rand() % 2 == 1)
		{
			map.push_back(new cLane(width));
			map[i]->IsCar(true);
		}
		else
		{
			map.push_back(new CAnimal(width));
			map[i]->IsCar(false);
		}
	}
		
	//player = new cPlayer(width);
}
void cGame::Preset()
{
	for (int i = 0; i < numberOfLanes; i++)
	{
		for (int j = 0; j < width; j++)
		{
			map[i]->Preset(j);
		}
	}
}
void cGame::Draw(cPlayer player)
{
	system("cls");
	for (int i = 0; i < numberOfLanes; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == 0 && (j == 0 || j == width - 1)) cout << "S";
			if (i == numberOfLanes - 1 && (j == 0 || j == width - 1)) cout << "F";
			if (map[i]->CheckPos(j) && i != 0 && i != numberOfLanes - 1)
				map[i]->Draw();
			else if (player.Pos(j, i) == true)
				cout << "V";
			else
				cout << " ";
		}
		cout << endl;
	}
	cout << "Score: " << player.Score() << endl;
}
void cGame::Input(cPlayer &player)
{
	if (_kbhit())
	{
		char current = _getch();
		if (current == 'a')
			player.x--;
		if (current == 'd')
			player.x++;
		if (current == 'w')
			player.y--;
		if (current == 's')
			player.y++;
		if (current == 'q')
		{
			quit = true;
			player.SetAlive(false);
		}

	}
}
void cGame::Logic(cPlayer &player)
{
	for (int i = 1; i < numberOfLanes - 1; i++)
	{
		if (rand() % 50 > 23 - player.Level() && rand() % 50 < 26 + player.Level())    //speed
			map[i]->Move();
		if (map[i]->CheckPos(player.x) && player.y == i)
		{
			quit = true;
			player.SetAlive(false);
		}
	}
	if (player.y == numberOfLanes - 1)
	{
		player.IncreaseScore();
		player.LevelUp();
		quit = true;
		//cout << "\x07";
		//map[rand() % numberOfLanes]->ChangeDirection();
	}
}
void cGame::Reload(cPlayer &player)
{
	cPlayer &temp = const_cast<cPlayer &>(player);
	while (!quit)
	{
		Logic(temp);
		Draw(temp);
	}
}
void cGame::Run(cPlayer &player)
{
	Preset();
	thread t(&cGame::Reload, this, ref(player));
	while (!quit)
	{
		Input(player);
	}
	EndThread(&t);
}
void cGame::EndThread(thread *t)
{
	t->join();
}
cGame::~cGame()
{
	//delete player;
	for (size_t i = 0; i < map.size(); i++)
	{
		LaneObj * current = map.back();
		map.pop_back();
		delete current;
	}
}