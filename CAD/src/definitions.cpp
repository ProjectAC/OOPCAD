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
