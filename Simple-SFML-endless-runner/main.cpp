#include <SFML/Audio.hpp>
#pragma comment(lib, "sfml-audio-d.lib")
#include "world.h"


int main() 
{
	sf::RenderWindow window(sf::VideoMode(600, 400), "Simple SFML");
	window.setFramerateLimit(60);

	sf::Music music;
	if (!music.openFromFile("song.ogg"))
		return -1;
	music.play();
	music.setVolume(50);
	music.setLoop(true);

	world w(600, 400,10.f);

	w.getCharacter().setTexture("caracter.png");

	sf::Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
				window.close();
			else if (event.key.code == sf::Keyboard::D)
				w.move(true);
			else if (event.key.code == sf::Keyboard::A)
				w.move(false);
		}

		window.clear();

		w.draw(window);

		window.display();

	}

    return 0;
}
