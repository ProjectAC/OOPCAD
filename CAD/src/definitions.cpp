#include "..\include\definitions.h"

ACCAD::Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

ACCAD::Vec2::Vec2(float x, float y)
{
	this->x = x;
	this->y = y;
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
