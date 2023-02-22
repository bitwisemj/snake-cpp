#pragma once
#include <algorithm>
#include <stdlib.h>
#include <time.h>

class Apple
{
private:
	int pos_x;
	int pos_y;
	int bound_x;
	int bound_y;
public:
	Apple();
	~Apple();
	void update_position();
	void set_bounds(int bound_x, int bound_y);
	int get_pos_x();
	int get_pos_y();

};

