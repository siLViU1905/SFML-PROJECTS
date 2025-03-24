#pragma once
#include "structures.h"

namespace sts
{
	class chunck: public sf::Drawable
	{
		unsigned int size;
		float componentSize;
		sf::Vector2f position;

		std::vector<std::vector<structure*>> components;
	public:
		chunck();

		chunck(const chunck& other);

		chunck(unsigned int chunckSize,float componentSize);

		bool contains(const sf::FloatRect& frect) const;

		bool intersects(const sf::FloatRect& frect) const;

		void loadChunck();

		void setPosition(const sf::Vector2f& position);

		sf::Vector2f getPosition() const;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		unsigned int getSize() const;

		float getComponentSize() const;

		std::vector<std::vector<structure*>>& getComponents();

		const std::vector<std::vector<structure*>>& getComponents() const;

		~chunck();
	};

}

