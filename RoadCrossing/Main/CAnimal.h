#pragma once
#include <deque>
#include "LaneObj.h"
using namespace std;

class CAnimal: public LaneObj
{

public:
	CAnimal(int width);
	~CAnimal() {};
};
