#include "Snake.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

Snake::Snake(sf::RenderWindow &window, sf::Event &evnt) {
	this->window = &window;
	this->evnt = &evnt;
	head.setSize(sf::Vector2f(50, 50));
	head.setPosition(50, 50);

	x = 50;
	y = 50;
	length = 1;
	

	lockX = false;
	lockY = false;

	gameSpeed = 2;
	snakeSpeed = 50;

	startingTick = 0;
	ticks = 5 * gameSpeed;

}

Snake::~Snake() {

}

void Snake::tick() {

	if (startingTick < ticks) {
		startingTick++;

		if (evnt->type == sf::Event::KeyPressed) {
			if (evnt->key.code == sf::Keyboard::Down && !keyLock) {
				down = true;
				up = false;
				left = false;
				right = false;
				keyLock = true;
			}
			if (evnt->key.code == sf::Keyboard::Up && !keyLock) {
				down = false;
				up = true;
				left = false;
				right = false;
				keyLock = true;
			}
			if (evnt->key.code == sf::Keyboard::Left && !keyLock) {
				down = false;
				up = false;
				left = true;
				right = false;
				keyLock = true;
			}
			if (evnt->key.code == sf::Keyboard::Right && !keyLock) {
				down = false;
				up = false;
				left = false;
				right = true;
				keyLock = true;
			}
		}

		keyLock = false;

		if (!lockY && !lockYY && down) {
			velY = snakeSpeed;
			velX = 0;
			lockX = false;
			lockY = true;
			lockXX = true;
		}
		if (!lockY && !lockYY && up) {
			velY = -snakeSpeed;
			velX = 0;
			lockX = false;
			lockY = true;
			lockXX = true;
		}
		if (!lockX && !lockXX && left) {
			velX = -snakeSpeed;
			velY = 0;
			lockY = false;
			lockX = true;
			lockYY = true;
		}
		if (!lockX && !lockXX && right) {
			velX = snakeSpeed;
			velY = 0;
			lockY = false;
			lockX = true;
			lockYY = true;
		}

	}

	else {

		startingTick = 0;

		lockXX = false;
		lockYY = false;

		y = y + velY;
		x = x + velX;

		positionsX.push_back(x);
		positionsY.push_back(y);

		itX = positionsX.begin();
		itY = positionsY.begin();

		if (positionsX.size() > length) {
			positionsX.erase(itX);
		}
		if (positionsY.size() > length) {
			positionsY.erase(itY);
		}

	}
}

void Snake::render() {
	for (int i = 0; i < positionsX.size(); i++) {
		head.setPosition(positionsX[i], positionsY[i]);
		this->window->draw(head);
	}
	
}

void Snake::grow() {
	length++;
}

int Snake::getX() {
	return x;
}

int Snake::getY() {
	return y;
}

int Snake::getLength() {
	return length;
}

std::vector<int> Snake::getPositionsX() {
	return positionsX;
}

std::vector<int> Snake::getPositionsY() {
	return positionsY;
}