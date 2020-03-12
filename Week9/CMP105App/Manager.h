#pragma once
#include <iostream>
#include <math.h>
#include <vector>
#include "Ball.h"
class Manager
{
public:
	Manager();
	~Manager();

	void spawn();
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);

	sf::RenderWindow* window;

	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; }

private:
	std::vector <Ball> balls;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
	int counter;
	bool flop;
};

