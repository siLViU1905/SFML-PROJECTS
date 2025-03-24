#pragma once
#include <SFML/Graphics.hpp>

namespace pn
{
	sf::Vector2f randomGradient(int ix, int iy);

	float dotGridGradient(int ix, int iy, float x, float y);

	constexpr float interpolate(float a0, float a1, float w);

	float perlin(float x, float y);
}
