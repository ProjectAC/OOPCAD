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

    struct Vec2i
    {
        int x, y;
        Vec2i(int x = 0, int y = 0);
        bool operator==(const Vec2i& p) const ;
    };

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


