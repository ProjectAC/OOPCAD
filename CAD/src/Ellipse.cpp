#include "..\include\Ellipse.h"
#include "..\include\Utility.h"
#include "..\include\definitions.h"

using namespace ACCAD;
using namespace std;

void Ellipse::save(std::ostream & out)
{
    //out << a << b << theta;
    out.write((const char *)&a, sizeof(float) * 3);
    out << center << borderColor << innerColor;
}

void Ellipse::load(std::istream & in)
{
    //in >> a >> b >> theta;
    in.read((char *)&a, sizeof(float) * 3);
    in >> center >> borderColor >> innerColor;
}

vector<Vec2> Ellipse::getBorder()
{
    vector<Vec2> points;
	for (auto d : delta)
		points.push_back(Vec2(center.x + a * d[0], center.y + b * d[1]).rotate(center, theta));
	/*
   	points.push_back(Vec2(center.x + a, center.y    ).rotate(center, theta));
    points.push_back(Vec2(center.x + a, center.y + b).rotate(center, theta));
    points.push_back(Vec2(center.x    , center.y + b).rotate(center, theta));
    points.push_back(Vec2(center.x - a, center.y + b).rotate(center, theta));
    points.push_back(Vec2(center.x - a, center.y    ).rotate(center, theta));
    points.push_back(Vec2(center.x - a, center.y - b).rotate(center, theta));
    points.push_back(Vec2(center.x    , center.y - b).rotate(center, theta));
    points.push_back(Vec2(center.x + a, center.y - b).rotate(center, theta));
	*/
    return points;
}

Vec2 Ellipse::getBorder(int id)
{
	return Vec2(center.x + a * delta[id][0], center.y + b * delta[id][1]).rotate(center, theta);
}

void Ellipse::resize(int id, const Vec2 &to)
{
    Vec2 oppo = getBorder((id + 4) % 8);
	center = (to + oppo) * 0.5;
	Vec2 newPos = (to - center).rotate(center, -theta);

	if (id != 2 && id != 6)
		a = abs(newPos.x);
	if (id != 0 && id != 4)
		b = abs(newPos.y);
}

Ellipse::Ellipse(const Vec2 & pos, float a, float b, float theta)
{    
    this->center = pos;
    this->a = a;
    this->b = b;
    this->theta = theta;
}
