#include "pch.h"
#include "LaneObj.h"


/*LaneObj::LaneObj(int width)
{
	for (int i = 0; i < width; i++)
		obj.push_front(true);
	right = rand() % 2;
}*/
void LaneObj::Move()
{
	if (right)
	{
		if (rand() % 10 == 1)
			obj.push_front(true);
		else
			obj.push_front(false);
		obj.pop_back();
	}
	else
	{
		if (rand() % 10 == 1)
			obj.push_back(true);
		else
			obj.push_back(false);
		obj.pop_front();
	}
}
void LaneObj::Draw()
{
	if (Is_car == true) cout << "#";
	else cout << "o";
}

LaneObj::~LaneObj()
{
}
