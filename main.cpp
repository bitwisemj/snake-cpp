#include <iostream>
#include "headers/Game.hpp"

int main() {

	std::cout << "Press enter to start";
	std::cin.get();
	Game game;
	game.start();
	return 0;
}