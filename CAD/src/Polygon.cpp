#include "../stdafx.h"

#include "../include/Polygon.h"
#include "../include/Utility.h"
#include "../include/definitions.h"

using namespace ACCAD;
using namespace std;

void Polygon::render(Renderer &renderer)
{
    renderer.render(center, theta, borderColor, innerColor, vertices);
}

void Polygon::save(std::ostream &out)
{
    out.write((const char *)&theta, sizeof(float));
    out << center << borderColor << innerColor;
    for ()
}

void Polygon::load(std::istream &in)
{

}

vector<Vec2> Polygon::getAnchors()
{

}

vector<Vec2> Polygon::getBorder()
{

}

void Polygon::resize(int id, const Vec2 &to)
{

}

FigureType Polygon::getType()
{
    return POLYGON;
}

Polygon::Polygon(const Vec2 &pos, float theta, const Color &cborder, const Color &cinner, const std::vector<Vec2> &verts) :
    IFigure(pos, theta, cborder, cinner),
    vertices(verts)
{

}