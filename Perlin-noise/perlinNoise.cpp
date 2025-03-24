#include "perlinNoise.h"

namespace pn
{
	sf::Vector2f randomGradient(int ix, int iy)
	{
        const unsigned w = 8 * sizeof(unsigned);
        const unsigned s = w / 2;
        unsigned a = ix, b = iy;
        a *= 3284157443;

        b ^= a << s | a >> w - s;
        b *= 1911520717;

        a ^= b << s | b >> w - s;
        a *= 2048419325;
        float random = a * (3.14159265 / ~(~0u >> 1)); // in [0, 2*Pi]

        sf::Vector2f v;
        v.x = sin(random);
        v.y = cos(random);

        return v;
	}


   float dotGridGradient(int ix, int iy, float x, float y)
	{
        sf::Vector2f gradient = randomGradient(ix, iy);

        float dx = x - (float)ix;
        float dy = y - (float)iy;

        return (dx * gradient.x + dy * gradient.y);
	}


    constexpr float interpolate(float a0, float a1, float w)
    {
        return (a1 - a0) * (3.0 - w * 2.0) * w * w + a0;
    }


    float perlin(float x, float y) {

        int x0 = (int)x;
        int y0 = (int)y;
        int x1 = x0 + 1;
        int y1 = y0 + 1;

        float sx = x - (float)x0;
        float sy = y - (float)y0;

        float n0 = dotGridGradient(x0, y0, x, y);
        float n1 = dotGridGradient(x1, y0, x, y);
        float ix0 = interpolate(n0, n1, sx);

        n0 = dotGridGradient(x0, y1, x, y);
        n1 = dotGridGradient(x1, y1, x, y);
        float ix1 = interpolate(n0, n1, sx);

        float value = interpolate(ix0, ix1, sy);

        return value;
    }
}
