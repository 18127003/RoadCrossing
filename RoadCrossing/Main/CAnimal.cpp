#include "pch.h"
#include "CAnimal.h"


CAnimal::CAnimal(int width)
{
	for (int i = 0; i < width; i++)
		obj.push_front(true);
	right = rand() % 2;
}

