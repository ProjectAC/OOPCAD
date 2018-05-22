#pragma once

#include <iostream>

namespace ACCAD
{
    struct Vec2
    {
        float x, y;
        /* [Constructor]
         * Construct a 2-dim Vector with x and y
         */
		Vec2(float x = 0.0f, float y = 0.0f);

        /* Save this vector to an output stream
         */
        void save(std::ostream &out);

        /* Load from an input stream to this vector
         */
        void load(std::istream &in);
    };
	std::istream& operator>>(std::istream& in, Vec2& vec2);
	std::ostream& operator<<(std::ostream& out, const Vec2& vec2);

    struct Color
    {
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
        /* [Constructor]
         * Construct a color with red, green, blue and alpha
         */
		Color(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, unsigned char a = 0);

        /* Save this color to an output stream
        */
        void save(std::ostream &out);

        /* Load from an input stream to this color
        */
        void load(std::istream &in);
    };
	std::istream& operator>>(std::istream& in, Color& color);
	std::ostream& operator<<(std::ostream& out, const Color& color);
}
