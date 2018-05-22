#include "..\include\definitions.h"

ACCAD::Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void ACCAD::Color::save(std::ostream & out)
{
    out.write((char*)&r, 1);
    out.write((char*)&g, 1);
    out.write((char*)&b, 1);
    out.write((char*)&a, 1);
}

void ACCAD::Color::load(std::istream & in)
{
    in.read((char*)&r, 1);
    in.read((char*)&g, 1);
    in.read((char*)&b, 1);
    in.read((char*)&a, 1);
}

ACCAD::Vec2::Vec2(float x, float y)
{
    this->x = x;
    this->y = y;
}

void ACCAD::Vec2::save(std::ostream & out)
{
    out.write((char*)&x, 4);
    out.write((char*)&y, 4);
}

void ACCAD::Vec2::load(std::istream & in)
{
    in.read((char*)&x, 4);
    in.read((char*)&y, 4);
}

std::istream & ACCAD::operator>>(std::istream & in, Vec2 & vec2)
{
    in >> vec2.x >> vec2.y;
    return in;
}

std::ostream & ACCAD::operator<<(std::ostream & out, const Vec2 & vec2)
{
    out << vec2.x << vec2.y;
    return out;
}

std::istream & ACCAD::operator>>(std::istream & in, Color & color)
{
    in >> color.r >> color.b >> color.g >> color.a;
    return in;
}

std::ostream & ACCAD::operator<<(std::ostream & out, const Color & color)
{
    out << color.r << color.b << color.g << color.a;
    return out;
}
