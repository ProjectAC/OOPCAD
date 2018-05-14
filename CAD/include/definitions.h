#pragma once

namespace ACCAD
{
    struct Vec2
    {
        float x, y;
		Vec2(float x = 0, float y = 0);
    };

    struct Color
    {
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
		Color(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, unsigned char a = 0);
    };
}
