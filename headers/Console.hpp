#pragma once
#include <iostream>
#include <Windows.h>

class Console
{
public:
	Console();
	~Console();
	void set_x_y(int x, int y);
	void print(std::string content);
};

