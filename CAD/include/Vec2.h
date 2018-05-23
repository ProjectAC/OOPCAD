#pragma once

#include <iostream>

namespace ACCAD
{
    struct Vec2
    {
        float x, y;

        Vec2(float x = 0.0f, float y = 0.0f);
        Vec2 operator+(const Vec2 &b) const;
        Vec2 operator-(const Vec2 &b) const;
        Vec2 operator*(float k) const;
        float sqrLength() const;
        float length() const;
        Vec2 rotate(const Vec2 &center, float theta);
    };
    std::istream& operator>>(std::istream& in, Vec2& vec2);
    std::ostream& operator<<(std::ostream& out, const Vec2& vec2);
    float eucDist(const Vec2 &a, const Vec2 &b);
}