#include "../stdafx.h"

#include "../include/Vec2.h"

using namespace std;

namespace ACCAD
{

    Vec2::Vec2(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    Vec2::Vec2(Vec2i v2i)
    {
        x = (float)v2i.x;
        y = (float)v2i.y;
    }

    istream & ACCAD::operator>>(istream & in, Vec2 & vec2)
    {
        in.read((char *)&(vec2.x), sizeof(float));
        in.read((char *)&(vec2.y), sizeof(float));
        return in;
    }

    ostream & ACCAD::operator<<(ostream & out, const Vec2 & vec2)
    {
        out.write((const char *)&(vec2.x), sizeof(float));
        out.write((const char *)&(vec2.y), sizeof(float));
        return out;
    }

    Vec2 Vec2::operator+(const Vec2 &b) const
    {
        return { x + b.x, y + b.y };
    }

    Vec2 Vec2::operator-(const Vec2 &b) const
    {
        return { x - b.x, y - b.y };
    }

    Vec2 Vec2::operator*(float k) const
    {
        return { x * k, y * k };
    }

    float Vec2::sqrLength() const
    {
        return x * x + y * y;
    }

    float Vec2::length() const
    {
        return sqrt(sqrLength());
    }

    Vec2 Vec2::rotate(const Vec2 & center, float theta)
    {
        const Vec2 tmp = *this - center;
        return { cos(theta) * tmp.x - sin(theta) * tmp.y + center.x, sin(theta) * tmp.x + cos(theta) * tmp.y + center.y };
    }

    float ACCAD::eucDist(const Vec2 &a, const Vec2 &b)
    {
        return (a - b).length();
    }

    int dot(const Vec2i & a, const Vec2i & b)
    {
        return a.x*b.x + a.y*b.y;
    }

    Vec2i::Vec2i(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    bool Vec2i::operator==(const Vec2i & p) const
    {
        return x == p.x&&y == p.y;
    }
    Vec2i Vec2i::operator+(const Vec2i & b) const
    {
        return { x + b.x, y + b.y };
    }
    Vec2i Vec2i::operator-(const Vec2i & b) const
    {
        return { x - b.x, y - b.y };
    }
    int Vec2i::sqrLength() const
    {
        return x * x + y * y;
    }
    float Vec2i::length() const
    {
        return sqrt(sqrLength());
    }
}

