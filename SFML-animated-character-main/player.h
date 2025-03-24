#pragma once
#include "animation.h"

namespace sts
{
	class player:public sf::Drawable
	{
		sf::RectangleShape body;
		animation animation;
		unsigned int row;
		float speed;
		bool direction;
		bool idle;

	
	public:
		player(sf::Texture* texture, const sf::Vector2u& imageCount, float switchTime, float speed);

		void update( float deltaTime);

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		const sf::RectangleShape& getBody() const noexcept;

		sf::RectangleShape& getBody()  noexcept;

		bool isSteady() const noexcept;

		

		

		~player();
	};
}

