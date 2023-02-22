#pragma once
#include <iostream>
#include <map>
#include <functional>
#include "Keyboard.hpp"
#include "IMovement.hpp"

class Snake : public IMovement
{
private:
	int snake_x[100];
	int snake_y[100];
	int direction;
	int last_x;
	int last_y;
	int length;
public:
	Snake();
	~Snake();
	void move_left() override;
	void move_right() override;
	void move_up() override;
	void move_down() override;
	void run(int key) override;
	void increase();
	int* get_x_axis();
	int* get_y_axis();
	int get_head_x();
	int get_head_y();
	int get_length();
	int get_last_x();
	int get_last_y();
	void reallocate_position();
	
	
};

