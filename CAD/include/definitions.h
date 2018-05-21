#pragma once

#include <iostream>

namespace ACCAD
{
    struct Vec2
    {
        float x, y;
		Vec2(float x = 0.0f, float y = 0.0f);
    };
	std::istream& operator>>(std::istream& in, Vec2& vec2);
	std::ostream& operator<<(std::ostream& out, const Vec2& vec2);

    struct Color
    {
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
		Color(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, unsigned char a = 0);
    };
	std::istream& operator>>(std::istream& in, Color& color);
	std::ostream& operator<<(std::ostream& out, const Color& color);
}
