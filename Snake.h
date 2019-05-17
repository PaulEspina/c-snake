#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <vector>

class Snake
{
public:
	Snake(sf::RenderWindow &window, sf::Event &evnt);
	~Snake();

	void tick();
	void render();
	void grow();

	int getX();
	int getY();
	int getLength();
	std::vector<int> getPositionsX();
	std::vector<int> getPositionsY();

private:
	sf::RenderWindow *window = &sf::RenderWindow();
	sf::Event *evnt = &sf::Event();
	sf::RectangleShape head;

	std::vector<int> positionsX, positionsY;
	std::vector<int>::iterator itX, itY;

	int x, y, velX ,velY, snakeSpeed, gameSpeed, startingTick, ticks, length;
	bool lockX, lockY, lockXX, lockYY;
	bool up, down, left, right, keyLock;

};

