#include "player.h"

int main()
{
	sf::Vector2u resolution(1280, 720);

	sf::VideoMode videMode(resolution);

	sf::Texture playerTex;
	playerTex.loadFromFile("textures\\gufa.png");
	
	

	sts::player player(&playerTex, { 8,4 }, 0.1f,50.f);
	
	
	float deltaTime = 0.f;
	sf::Clock clock;

	sf::RenderWindow window(videMode, "animations",sf::Style::Close | sf::Style::Resize);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);


	std::optional<sf::Event> event;
	while (window.isOpen())
	{
		while (event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
				switch (keyPressed->scancode)
				{
				case sf::Keyboard::Scancode::Escape:
					window.close();
					break;
				}

			
		}

		deltaTime = clock.restart().asSeconds();
	   
		player.update(deltaTime);
		
	
		window.clear();

			window.draw(player);
		
		window.display();
	}
	
	return 0;
}
