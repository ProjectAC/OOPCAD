#include "../include/Vec2.h"

Vec2::Vec2(float x, float y)
{
    this->x = x;
    this->y = y;
}

istream & ACCAD::operator>>(istream & in, Vec2 & vec2)
{
    //in >> vec2.x >> vec2.y;
    if (!in.good())
        throw IOException("Unexpected End-Of-File");
    in.read(&(vec2.x), sizeof(float) * 2);
    return in;
}

ostream & ACCAD::operator<<(ostream & out, const Vec2 & vec2)
{
    //out << vec2.x << vec2.y;
    out.write(&(vec2.x), sizeof(float) * 2);
    return out;
}

Vec2 Vec2::operator+(const Vec2 &b) const
{
    return {x + b.x, y + b.y};
}

Vec2 Vec2::operator-(const Vec2 &b)
{
    return {x - b.x, y - b.y};
}

Vec2 Vec2::operator*(float k)
{
    return {x * k, y * k};
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
    return {cos(theta) * tmp.x - sin(theta) tmp.y + center.x, sin(theta) * tmp.x + cos(theta) * tmp.y + center.y};
}

float ACCAD::eucDist(const Vec2 &a, const Vec2 &b)
{
    return (a - b).length();
}