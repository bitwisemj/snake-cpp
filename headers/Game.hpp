#pragma once
#include <conio.h>
#include <unistd.h>
#include "Apple.hpp"
#include "Board.hpp"
#include "Keyboard.hpp"
#include "Snake.hpp"
#include "Console.hpp"

class Game
{
	
private:
	Console console;
	Snake snake;
	Apple apple;
	bool game_over;
	int score;
	const static int BOUND_X = 60;
	const static int BOUND_Y = 20;
public:
	Game();
	~Game();
	void start();
	void draw_snake();
	void draw_apple();
	void draw_score();
	void clear();
	void detect_snake_apple_colision();
	void detect_colision();
};

