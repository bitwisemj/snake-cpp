#include "headers/Apple.hpp"

Apple::Apple()
{
	srand(time(NULL));
}

Apple::~Apple()
{
}

void Apple::update_position() {
	pos_x = std::max(1, rand() % bound_x);
	pos_y = std::max(1, rand() % bound_y);
}

void Apple::set_bounds(int bound_x, int bound_y) {
	this->bound_x = bound_x;
	this->bound_y = bound_y;
}

int Apple::get_pos_x() {
	return pos_x;
}

int Apple::get_pos_y() {
	return pos_y;
}
