#include "..\include\Ellipse.h"
#include "..\include\Utility.h"
using namespace ACCAD;
using namespace std;

void ACCAD::Ellipse::save(std::ostream & out)
{
	out << a << b << theta;
	out << center << borderColor << innerColor;
}

void ACCAD::Ellipse::load(std::istream & in)
{
	in >> a >> b >> theta;
	in >> center >> borderColor >> innerColor;
}

std::vector<Vec2> ACCAD::Ellipse::getBorder()
{
	vector<Vec2> points;
	points.push_back(Vec2Rotate(center, Vec2(center.x + a, center.y), theta));
	points.push_back(Vec2Rotate(center, Vec2(center.x + a, center.y + b), theta));
	points.push_back(Vec2Rotate(center, Vec2(center.x, center.y + b), theta));
	points.push_back(Vec2Rotate(center, Vec2(center.x - a, center.y + b), theta));
	points.push_back(Vec2Rotate(center, Vec2(center.x - a, center.y), theta));
	points.push_back(Vec2Rotate(center, Vec2(center.x - a, center.y - b), theta));
	points.push_back(Vec2Rotate(center, Vec2(center.x, center.y - b), theta));
	points.push_back(Vec2Rotate(center, Vec2(center.x + a, center.y - b), theta));
	return points;
}

ACCAD::Ellipse::Ellipse(const Vec2 & pos, float a, float b, float theta)
{	
	this->center = pos;
	this->a = a;
	this->b = b;
	this->theta = theta;
}
