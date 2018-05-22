#pragma once

#include <iostream>

namespace ACCAD
{
    struct Vec2
    {
        float x, y;

        Vec2(float x = 0.0f, float y = 0.0f);
        inline Vec2 operator+(const Vec2 &b) const;
        inline Vec2 operator-(const Vec2 &b) const;
        inline Vec2 operator*(float k) const;
        inline float sqrLength() const;
        inline float length() const;
        inline Vec2 rotate(const Vec2 &center, float theta);
    };
    inline std::istream& operator>>(std::istream& in, Vec2& vec2);
    inline std::ostream& operator<<(std::ostream& out, const Vec2& vec2);
    inline float eucDist(const Vec2 &a, const Vec2 &b);
}