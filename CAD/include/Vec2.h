#pragma once

#include <iostream>

namespace ACCAD
{
    struct Vec2i;

    struct Vec2
    {
        float x, y;

        Vec2(float x = 0.0f, float y = 0.0f);
        Vec2(Vec2i v2i);
        Vec2 operator+(const Vec2 &b) const;
        Vec2 operator-(const Vec2 &b) const;
        Vec2 operator*(float k) const;
        Vec2 operator/(float k) const;
        float operator*(const Vec2 &b) const;
        float sqrLength() const;
        float length() const;
        Vec2 abs();
        Vec2 rotate(const Vec2 &center, float theta);
        Vec2 normalize();
    };
    std::istream& operator>>(std::istream& in, Vec2& vec2);
    std::ostream& operator<<(std::ostream& out, const Vec2& vec2);
    float eucDist(const Vec2 &a, const Vec2 &b);

    struct Vec2i
    {
        int x, y;
        Vec2i(int x = 0, int y = 0);
        bool operator==(const Vec2i& p) const ;
        Vec2i operator+(const Vec2i& b) const;
        Vec2i operator-(const Vec2i& b) const;
        int sqrLength() const;
        float length() const;
    };
    int dot(const Vec2i &a, const Vec2i &b);
}

namespace std
{
    template<>
    struct hash<ACCAD::Vec2i>
    {
    public:
        typedef ACCAD::Vec2i argument_type;
        typedef size_t result_type;
        std::size_t operator()(const ACCAD::Vec2i &p) const
        {
            return std::hash<int>()(p.x) ^ std::hash<int>()(p.y);
        }
    };
}


