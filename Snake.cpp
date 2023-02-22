#include "headers/Snake.hpp"

Snake::Snake() :
direction(KEY_LEFT),
length(1)
{
	snake_x[0] = 5;
	snake_y[0] = 5;
	
	last_x = -1;
	last_y = -1;
}

Snake::~Snake()
{
}


void Snake::move_left() {
	reallocate_position();
	snake_x[0] -= 1;
}

void Snake::move_right() {
	reallocate_position();
	snake_x[0] += 1;
}

void Snake::move_up() {
	reallocate_position();
	snake_y[0] -= 1;
}

void Snake::move_down() {
	reallocate_position();
	snake_y[0] += 1;
}

void Snake::run(int key) {
	
	last_x = snake_x[length - 1];
	last_y = snake_y[length - 1];
	
	using move = void (Snake::*)();
    std::map<int, move> moves;
	
	moves[KEY_DOWN] = &Snake::move_down;
	moves[KEY_UP] = &Snake::move_up;
	moves[KEY_LEFT] = &Snake::move_left;
	moves[KEY_RIGHT] = &Snake::move_right;
	
	if (moves.find(key) != moves.end()) {
		move movement = moves[key];
		(this->*movement)();
	}
}

void Snake::increase() {
	
	length += 1;
	snake_x[length - 1] = last_x;
	snake_y[length - 1] = last_y;
}


void Snake::reallocate_position() {
	
	for (int index = length - 1; index > 0; index--) {
		snake_x[index] = snake_x[index - 1];
		snake_y[index] = snake_y[index - 1];
	}
}

int* Snake::get_x_axis() {
	return snake_x;
}

int* Snake::get_y_axis() {
	return snake_y;
}

int Snake::get_length() {
	return length;
}

int Snake::get_last_x() {
	return last_x;
}

int Snake::get_last_y() {
	return last_y;
}

int Snake::get_head_x() {
	return snake_x[0];
}

int Snake::get_head_y() {
	return snake_y[0];
}