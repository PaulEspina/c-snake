#pragma once
#include <SFML/Graphics.hpp>

class Apple
{
public:
	Apple(sf::RenderWindow &window);
	~Apple();

	void render();
	void eat();

	int getX();
	int getY();
private:
	sf::RenderWindow *window = &sf::RenderWindow();

	sf::RectangleShape apple;

	int x, y;

};

