#include "Manager.h"
Manager::Manager()
{
	spawnPoint = sf::Vector2f(350, 250);
	texture.loadFromFile("gfx/Beach_Ball.png");

	for (int i = 0; i < 20; i++)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&texture);
		balls[i].setSize(sf::Vector2f(100, 100));
	}

	counter = 0;
}

Manager::~Manager()
{
}

void Manager::update(float dt)
{
	//call update on all alive balls
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			balls[i].update(dt);
		}
	}
	deathCheck();
}

//spawn new ball
//find a dead ball, make it alive, move to spawnpoint, give random velocity
void Manager::spawn()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (!balls[i].isAlive())
		{
			flop = false;

			balls[i].setAlive(true);
			balls[i].setVelocity(rand() % 200 - 100, rand() % 200 - 100);
			balls[i].setPosition(spawnPoint);

			//adds to counter and outputs it
			counter++;
			std::cout << counter << "\n";
			return;
		}
	}

	balls.push_back(Ball());
	balls[balls.size() - 1].setAlive(true);
	balls[balls.size() - 1].setTexture(&texture);
	balls[balls.size() - 1].setSize(sf::Vector2f(100, 100));
	balls[balls.size() - 1].setVelocity(rand() % 200 - 100, rand() % 200 - 100);
	balls[balls.size() - 1].setPosition(spawnPoint);

	//adds to counter and outputs it
	counter++;
	std::cout << counter << "\n";
}

void Manager::deathCheck()
{
	sf::Vector2u pos = window->getSize();
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			if (balls[i].getPosition().x < 0)
			{
				balls[i].setAlive(false);
				counter--;
			}
			if (balls[i].getPosition().x > pos.x)
			{
				balls[i].setAlive(false);
				counter--;
			}
			if (balls[i].getPosition().y < 0)
			{
				balls[i].setAlive(false);
				counter--;
			}
			if (balls[i].getPosition().y > pos.y)
			{
				balls[i].setAlive(false);
				counter--;
			}
		}
	}
}

void Manager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			window->draw(balls[i]);
		}
	}
}