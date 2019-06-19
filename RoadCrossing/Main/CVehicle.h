#pragma once
#include <deque>
using namespace std;
class cLane
{
private:
	deque<bool> cars;
	bool right;
public:
	cLane(int width);
	void Move();
	bool CheckPos(int pos) { return cars[pos]; }
	void Preset(int pos) { cars[pos] = false; }
	void ChangeDirection() { right = !right; }
};

