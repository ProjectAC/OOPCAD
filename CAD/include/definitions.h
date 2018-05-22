#pragma once

#include <iostream>

namespace ACCAD
{
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

    const int delta[8][2] = {
        { 1,  0},
        { 1,  1},
        { 0,  1},
        {-1,  1},
        {-1,  0},
        {-1, -1},
        { 0, -1},
        { 1, -1}
    };
}
