#include "player.h"

namespace sts
{
	player::player(sf::Texture* texture, const sf::Vector2u& imageCount, float switchTime, float speed):animation(texture,imageCount,switchTime),idle(true)
	
	{
		this->speed = speed;
		row = 0;
		direction = true;

		body.setSize({ 100.f,200.f });
		body.setPosition({ 500.f,500.f });
		body.setFillColor(sf::Color::White);
		body.setTexture(texture);
		body.setOrigin(body.getSize() / 2.f);
	}

	void player::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(body,states);
	}

	void player::update(float deltaTime)
	{
		direction_state direction;
		sf::Vector2f movement;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			movement.x -= speed * deltaTime, direction.left = true;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			movement.x += speed * deltaTime, direction.right = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			movement.y -= speed * deltaTime, direction.up = true;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			movement.y += speed * deltaTime, direction.down = true;

		if ((movement.x == 0.f && movement.y == 0.f))
		
			row = 0, idle = true;
			
		

		else if (direction.down)
			row = 0, idle = false;
		else if (direction.left)
			row = 1, idle = false;
		else if (direction.right)
			row = 2, idle = false;
		else
			row = 3, idle = false;

		
		animation.update(row, deltaTime,direction );
		body.setTextureRect(animation.rect);
		body.move(movement);
	}

	const sf::RectangleShape& player::getBody() const noexcept
	{
		return body;
	}

	sf::RectangleShape& player::getBody() noexcept
	{
		return body;
	}


	bool player::isSteady() const noexcept
	{
		return idle;
	}




	player::~player()
	{
		
	}


}
