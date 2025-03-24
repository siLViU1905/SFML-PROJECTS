#pragma once
#include  <SFML/Graphics.hpp>

namespace sts
{
	class direction_state
	{
	public:
		bool up, left, right, down;
		direction_state();
	};


	class animation
	{
	public:
		sf::Vector2u imageCount, currentImage;
		float totalTime, switchTime;
		

		sf::IntRect rect;

		sf::Texture* texture;

		animation(sf::Texture* texture,const sf::Vector2u& imageCount, float switchTime);

		void update(int row,float deltaTime,direction_state direction);



		~animation();
	};
}

