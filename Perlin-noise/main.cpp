#include "perlinNoise.h"


int main()
{
	sf::Vector2u resolution(1280, 720);

	sf::VideoMode videMode(resolution);

	sf::RenderWindow window(videMode, "Perlin Noise", sf::Style::Close | sf::Style::Resize);

	std::uint8_t* pixels = new std::uint8_t[resolution.x * resolution.y * 4];

	const int GRID_SIZE = 400;


	for (int x=0;x<resolution.x;++x)
	{
		for (int y=0;y<resolution.y;++y)
		{
			int index = (y * resolution.x + x) * 4;

			float val = 0.f;
			float freq = 1.f;
			float amp = 1.f;

			for (int i=0;i<12;++i)
			{
				val += pn::perlin(x * freq / GRID_SIZE, y * freq / GRID_SIZE) * amp;
				freq *= 2.f;
				amp *= 0.5f;
			}
			val *= 1.2f;

			if (val > 1.f)
				val = 1.f;
			else if (val<-1.f)
				val = -1.f;

			int color = (int)(((val + 1.f) * 0.5f) * 255);

			pixels[index] = color;
			pixels[index + 1] = color;
			pixels[index + 2] = color;
			pixels[index + 3] = 255;
		}
	}

	sf::Texture texture(resolution);
	texture.update(pixels);

	sf::Sprite sprite(texture);


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


		window.clear();
		window.draw(sprite);
		window.display();
	}

	delete[] pixels;
	return 0;
}
