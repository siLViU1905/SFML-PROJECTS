#include "character.h"

character::character() :texture(new sf::Texture) {}

bool character::setTexture(const char* file)
{
	if (!texture->loadFromFile(file))
		return false;
	player.setTexture(texture);
	return true;
}


const sf::RectangleShape& character::getPlayer() const
{
	return player;
}

sf::RectangleShape& character::getPlayer()
{
	return player;
}


character::~character()
{
	delete texture;
}
