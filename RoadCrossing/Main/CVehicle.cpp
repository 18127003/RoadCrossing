#include "pch.h"
#include "CVehicle.h"

cLane::cLane(int width)
{
	for (int i = 0; i < width; i++)
		obj.push_front(true);
	right = rand() % 2;
}
