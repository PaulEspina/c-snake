#include <string>
#include "Snake.h"
#include "Apple.h"
#include <iostream>

const int WIDTH = 600;
const int HEIGHT = 600;
const std::string TITLE = "Snake";

const int FPS = 60;

int main() {
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), TITLE);
	
	window.setFramerateLimit(FPS);

	sf::Event evnt;
	Snake snake = Snake(window, evnt);
	Apple apple = Apple(window);

	std::vector<int> positionsX;
	std::vector<int> positionsY;

	int as = 0;

	bool gameOver = false;

	while (window.isOpen()) {

		if (gameOver) {
			window.close();
		}

		while (window.pollEvent(evnt)) {

			if (evnt.type == sf::Event::Closed) window.close();
		}

		window.clear();

		snake.tick();

		if (snake.getX() == apple.getX() && snake.getY() == apple.getY()) {
			apple.eat();
			snake.grow();
		}

		positionsX = snake.getPositionsX();
		positionsY = snake.getPositionsY();

		int sizePos = positionsX.size() - 1;

		for (int i = 0; i < sizePos; i++) {
			if (snake.getX() == positionsX[i] && snake.getY() == positionsY[i]) {
				gameOver = true;
				as++;
			}

			if (apple.getX() == positionsX[i] && apple.getY() == positionsY[i]) {
				apple.eat();
			}
		}

		if (snake.getX() >= WIDTH || snake.getX() < 0) {
			gameOver = true;
		}
		if (snake.getY() >= HEIGHT || snake.getY() < 0) {
			gameOver = true;
		}

		apple.render();
		snake.render();

		window.display();
	}
}

