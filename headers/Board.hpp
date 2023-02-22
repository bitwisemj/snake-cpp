#pragma once
#include "Console.hpp"

class Board
{
private:
	int width;
	int height;
public:
	Board(int width, int height);
	~Board();
	void draw(Console& console);

};

