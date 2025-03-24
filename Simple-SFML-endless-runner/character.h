#pragma once
#include <SFML/Graphics.hpp>

class character
{
	sf::RectangleShape player;
	sf::Texture* texture;
public:
	character();

	bool setTexture(const char* file);

	const sf::RectangleShape& getPlayer() const;

	sf::RectangleShape& getPlayer();

	~character();
	
};

