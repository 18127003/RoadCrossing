#pragma once
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

class LaneObj
{
public:

	LaneObj() {};
	void Move();
	bool CheckPos(int pos) { return obj[pos]; }
	void Preset(int pos) { obj[pos] = false; }
	void ChangeDirection() { right = !right; }
	virtual ~LaneObj();
	void IsCar(bool is_car) { Is_car = is_car; }
	void Draw();
protected:
	deque<bool> obj;
	bool right;
private:
	bool Is_car=true;
};

