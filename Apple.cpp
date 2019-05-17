#include "Apple.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iostream>

Apple::Apple(sf::RenderWindow &window) {
	this->window = &window;
	srand(time(0));
	x = floor((floor((rand() % 600) + 1)) / 50) * 50;
	y = floor((floor((rand() % 600) + 1)) / 50) * 50;

	apple.setSize(sf::Vector2f(50, 50));
	apple.setFillColor(sf::Color::Red);

}


Apple::~Apple() {

}

void Apple::render() {
	apple.setPosition(x, y);
	window->draw(apple);
}

void Apple::eat() {
	x = floor((floor((rand() % 600) + 1)) / 50) * 50;
	y = floor((floor((rand() % 600) + 1)) / 50) * 50;
}

int Apple::getX() {
	return x;
}

int Apple::getY() {
	return y;
}
