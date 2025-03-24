#include "structures.h"
#include <iostream>


sf::Texture lakeTexture;
sf::Texture grassTexture;

namespace sts
{

	structure::structure() 
	{}

	const sf::RectangleShape& structure::getComponent() const
	{
		return component;
	}

	sf::RectangleShape& structure::getComponent()
	{
		return component;
	}


	void structure::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(component, states);
	}

	structure::~structure() 
	{
		
	}

	lake::lake() :structure() {}

	void lake::textureFile(const char* filename)
	{
		if (!filename)
			filename = "textures\\lakeTex.png";
		std::cout << "Lake texture loaded\n";
	}


	void lake::generate(const sf::Vector2f& pos, const sf::Vector2f& size)
	{
		
		component.setTexture(&lakeTexture);
		component.setFillColor(sf::Color::White);
		component.setPosition(pos);
		component.setSize(size);
	}

	void lake::_generate()
	{
		
		component.setTexture(&lakeTexture);
		component.setFillColor(sf::Color::White);
	}

	void lake::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(component, states);
	}


	lake::~lake() {}



	grass::grass() :structure() {}


	void grass::textureFile(const char* filename)
	{
		if (!filename)
			filename = "textures\\grassTex.png";
		
		std::cout << "Grass texture loaded\n";
	}

	void grass::generate(const sf::Vector2f& pos, const sf::Vector2f& size)
	{
		
		component.setTexture(&grassTexture);
		component.setFillColor(sf::Color::White);
		component.setPosition(pos);
		component.setSize(size);
	}

	void grass::_generate()
	{
		
		component.setTexture(&grassTexture);
		component.setFillColor(sf::Color::White);
	}

	void grass::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(component, states);
	}

	grass::~grass() {}


	bool initTextures()
	{
		return lakeTexture.loadFromFile("textures\\lakeTex.png") && grassTexture.loadFromFile("textures\\grassTex.png");
	}

	structure* generateStructure(float lakeProp)
	{
		float prop = static_cast<float>(rand()) / RAND_MAX;
		if (prop <= lakeProp)
			return new lake();
		return new grass();
	}
}
