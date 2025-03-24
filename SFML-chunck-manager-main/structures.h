#pragma once
#include <SFML/Graphics.hpp>



namespace sts
{


	class structure: public sf::Drawable
	{
	protected:
		sf::RectangleShape component;
	public:
		structure();

		const sf::RectangleShape& getComponent() const;

		 sf::RectangleShape& getComponent();

		 virtual void textureFile(const char* filename) = 0;
		
		 virtual void generate(const sf::Vector2f& pos, const sf::Vector2f& size) = 0;

		 virtual void _generate() = 0;

		 void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		virtual ~structure();
	};


	class lake :public structure
	{
		const char* texturePath;
	public:
		lake();

		void textureFile(const char* filename) override;

		void generate(const sf::Vector2f& pos, const sf::Vector2f& size) override;

		void _generate() override;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		~lake();
	};


	class grass :public structure
	{
		const char* texturePath;
	public:
		grass();


		void textureFile(const char* filename) override;

		void generate(const sf::Vector2f& pos, const sf::Vector2f& size) override;

		void _generate() override;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		~grass();
	};


	bool initTextures();

	structure* generateStructure(float lakeProp);

}
