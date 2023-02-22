#include "headers/Console.hpp"

Console::Console() {
	
}

Console::~Console() {
	
}

void Console::set_x_y(int x, int y) {
	
	static const HANDLE handle_output = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = {(SHORT) x, (SHORT) y};
	SetConsoleCursorPosition(handle_output, coord);
}

void Console::print(std::string content) {
	
	std::cout << content;
}

