#include "headers/Game.hpp"

Game::Game() :
game_over(false),
score(0)
{
	Board board(BOUND_X, BOUND_Y);
	board.draw(console);
	apple.set_bounds(BOUND_X - 2, BOUND_Y - 2);
	apple.update_position();
}

Game::~Game()
{
}

void Game::start() {
	
	int key = KEY_RIGHT;
	
	while(!game_over) {
		
		if (kbhit()) {
			key = getch();
		}
		
		snake.run(key);
		clear();
		draw_score();
		draw_apple();
		draw_snake();
		detect_snake_apple_colision();
		detect_colision();
		usleep(90000);
	}
}

void Game::clear() {
	console.set_x_y(snake.get_last_x(), snake.get_last_y());
	console.print(" ");
}

void Game::draw_snake() {
	
	for (int index = 0; index < snake.get_length(); index++) {
		console.set_x_y(snake.get_x_axis()[index], snake.get_y_axis()[index]);
		std::string snake_part = index == 0 ? "O" : "o";
		console.print(snake_part);
	}
}

void Game::draw_score() {
	
	console.set_x_y(BOUND_X + 5, 2);
	std::string content = "Score: "+ std::to_string(score);
	console.print(content);
}

void Game::draw_apple() {	
	console.set_x_y(apple.get_pos_x(), apple.get_pos_y());
	console.print("@");
}

void Game::detect_snake_apple_colision() {
	
	if (snake.get_head_x() == apple.get_pos_x() &&
			snake.get_head_y() == apple.get_pos_y()) {
		apple.update_position();
		snake.increase();
		score++;
	}
}

void Game::detect_colision() {
	
	if (snake.get_head_x() <= 0 || 
		snake.get_head_y() <= 0 ||
		snake.get_head_x() >= BOUND_X ||
		snake.get_head_y() >= BOUND_Y) {
			game_over = true;
	}
	
	for (int index = 1; index < snake.get_length(); index++) {
		if (snake.get_head_x() == snake.get_x_axis()[index] && 
			snake.get_head_y() == snake.get_y_axis()[index]) {
				game_over = true;
		}
	} 
}

