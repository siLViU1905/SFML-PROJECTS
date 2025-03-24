#include "chunck_handler.h"

bool edgeColision(const sf::RectangleShape& edge, const sf::RectangleShape& rect, float sensivity = 0.f)
{
	sf::Vector2f futurePos = rect.getPosition();

	if (futurePos.x <= edge.getPosition().x + sensivity)
		return true;

	if (futurePos.y <= edge.getPosition().y + sensivity)
		return true;

	if (futurePos.x + rect.getSize().x >= edge.getPosition().x + edge.getSize().x - sensivity)
		return true;

	if (futurePos.y + rect.getSize().y >= edge.getPosition().y + edge.getSize().y - sensivity)
		return true;

	return false;
}


int main()
{
	sts::initTextures();

	sf::Vector2u resolution(1280, 720);

	sf::RectangleShape edge(static_cast<sf::Vector2f>(resolution));
	edge.setPosition({ 0.f,0.f });
	sf::RectangleShape initEdge = edge;

	sf::VideoMode videMode(resolution);

	srand(time(0));

	sts::chunck_handler chunckH(sts::chunck(4, 50.f));
	chunckH.preloadChuncks({ 100.f,100.f }, 5);

	const std::vector<std::vector<sts::chunck*>>& chuncks = chunckH.getChuncks();

	sf::Texture playerTex;
	playerTex.loadFromFile("textures\\caracter.png");

	sf::RectangleShape player({ 40.f, 40.f });
	player.setFillColor(sf::Color::White);
	player.setPosition({ resolution.x / 2.f,resolution.y / 2.f });
	player.setTexture(&playerTex);

	sf::RenderWindow window(videMode, "texs");
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	bool renderall = false;
	bool addChunck = false;


	std::optional<sf::Event> event;
	while (window.isOpen())
	{
		while (event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
			{
				switch (keyPressed->scancode)
				{
				case sf::Keyboard::Scancode::Escape:
					window.close();
					break;
				case sf::Keyboard::Scancode::W:
					if (!edgeColision(edge, player))
					{
						player.move({ 0.f,-10.f });
						if (addChunck)
							chunckH.addChunck(player.getPosition());
					}
					else
						player.move({ 0.f,10.f });
					break;
				case sf::Keyboard::Scancode::S:
					if (!edgeColision(edge, player))
					{
						player.move({ 0.f,10.f });
						if (addChunck)
							chunckH.addChunck(player.getPosition());
					}
					else
						player.move({ 0.f,-10.f });
					break;
				case sf::Keyboard::Scancode::A:
					
					if (!edgeColision(edge, player))
					{
						player.move({ -10.f,0.f });
						if (addChunck)
							chunckH.addChunck({ player.getPosition().x - chuncks[0][0]->getComponentSize() * (float)chuncks[0][0]->getComponents().size(),player.getPosition().y});
					}
					else
						player.move({ 10.f,0.f });		
					break;
				case sf::Keyboard::Scancode::D:
					if (!edgeColision(edge, player))
					{
						player.move({ 10.f,0.f });
						if (addChunck)
							chunckH.addChunck(player.getPosition());
					}
					else
						player.move({ -10.f,0.f });
					break;
				case sf::Keyboard::Scancode::Enter:
					renderall = !renderall;
					break;
				}
			}
		}

		addChunck = true;

		window.clear();

		if (!renderall)
		{
			for (int i = 0; i < chuncks.size(); ++i)
			{
				for (int j = 0; j < chuncks.size(); ++j)
					if (chuncks[i][j]->intersects(player.getGlobalBounds()))
					{
						window.draw(*chuncks[i][j]);
						addChunck = false;
						break;
					}
				if (!addChunck)
					break;
			}
		}
		else
		{
			for (int i = 0; i < chuncks.size(); ++i)
				for (int j = 0; j < chuncks.size(); ++j)
				{
					if (chuncks[i][j]->intersects(player.getGlobalBounds()))
						addChunck = false;
					window.draw(*chuncks[i][j]);
				}
		}

		window.draw(player);

		window.display();
	}
	
	return 0;
}