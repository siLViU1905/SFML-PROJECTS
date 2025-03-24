#pragma once
#include "character.h"
#include <list>

class world
{
	std::list<sf::RectangleShape> ground;

	character player;

	float playerSpeed;

	float tileStep;

	unsigned int screenWidth, screenHeight;

	void updateWorld();
public:
	world(unsigned int windowWidth,unsigned int windowHeight, float playerSpeed);

	//if true goes right else goes left
	void move(bool direction);

	void draw(sf::RenderWindow& window);

	character& getCharacter();

	const character& getCharacter() const;

	~world();
};

