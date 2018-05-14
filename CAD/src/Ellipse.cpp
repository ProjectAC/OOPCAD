#include "..\include\Ellipse.h"

using namespace ACCAD;
using namespace std;

std::vector<Vec2> ACCAD::Ellipse::getBorder()
{
	vector<Vec2> points;
	points.push_back(Vec2())
}

ACCAD::Ellipse::Ellipse(const Vec2 & pos, float a, float b, float theta)
{	
	this->center = pos;
	this->a = a;
	this->b = b;
	this->theta = theta;
}
