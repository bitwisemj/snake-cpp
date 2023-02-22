#include "headers/Board.hpp"

Board::Board(int width, int height) :
width(width),
height(height)
{
}

Board::~Board()
{
}


void Board::draw(Console& console) {
	
	for (int x = 0; x < width; x++) {
		console.set_x_y(x, 0);
		console.print("#");
	}
	
	for (int y = 0; y < height; y++) {
		console.set_x_y(width, y);
		console.print("#");
	}
	
	for (int x = width; x >= 0; x--) {
		console.set_x_y(x, height);
		console.print("#");
	}
	
	for (int y = height; y >= 0; y--) {
		console.set_x_y(0, y);
		console.print("#");
	}
}

