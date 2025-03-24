#include "world.h"

world::world(unsigned int windowWidth, unsigned int windowHeight, float playerSpeed) :playerSpeed(playerSpeed),screenWidth(windowWidth),screenHeight(windowHeight)
{
	float t = (float)windowWidth / 20.f + 1.f;
	ground.assign((int)t, sf::RectangleShape(sf::Vector2f((float)windowWidth / t, 20.f)));
	srand(time(0));
	tileStep = (float)windowWidth / t;
	float x = 0.f, y = (float)windowHeight - 20.f;
	for (auto& tile : ground)
	{
		tile.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
		tile.setPosition(x, y);
		x += tileStep;
	}
	player.getPlayer().setPosition(windowWidth / 2, y - 40.f);
	player.getPlayer().setSize(sf::Vector2f(20.f, 40.f));
	player.getPlayer().setFillColor(sf::Color::White);
}


void world::updateWorld()
{
	if (playerSpeed > 0.f)
	{
		if (player.getPlayer().getPosition().x + player.getPlayer().getSize().x >= screenWidth)
		{
			float t = (float)screenWidth / 20.f + 1.f;

			sf::RectangleShape rect(sf::Vector2f((float)screenWidth / t, 20.f));
			rect.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
			rect.setPosition(player.getPlayer().getPosition().x + player.getPlayer().getSize().x, (float)screenHeight - 20.f);

			ground.push_back(rect);
			player.getPlayer().move(-playerSpeed, 0.f);

			for (auto& tile : ground)
				tile.move(-playerSpeed, 0.f);
		}
    } 
	else
	{
		if (player.getPlayer().getPosition().x <= 5.f)
		{
			float t = (float)screenWidth / 20.f + 1.f;

			sf::RectangleShape rect(sf::Vector2f((float)screenWidth / t, 20.f));
			rect.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
			rect.setPosition(0.f, (float)screenHeight - 20.f);

			ground.push_front(rect);
			player.getPlayer().move(-playerSpeed, 0.f);

			for (auto& tile : ground)
				tile.move(-playerSpeed, 0.f);
		}
	}
}


void world::move(bool direction)
{
	if (direction)
	{
		playerSpeed = abs(playerSpeed);
		player.getPlayer().move(playerSpeed, 0.f);
	}

	else
	{
		playerSpeed = -abs(playerSpeed);
		player.getPlayer().move(playerSpeed, 0.f);
	}
	
	updateWorld();
}


void world::draw(sf::RenderWindow& window)
{
	window.draw(player.getPlayer());
	for (const auto& tile : ground)
		window.draw(tile);
}


character& world::getCharacter()
{
	return player;
}

const character& world::getCharacter() const
{
	return player;
}


world::~world() {}
