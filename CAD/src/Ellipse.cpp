#include "stdafx.h"

#include "../include/Ellipse.h"
#include "../include/Utility.h"
#include "../include/definitions.h"

using namespace std;

namespace ACCAD
{

    const float Ellipse::RENDER_DELTA = PI / 200;

    void Ellipse::render(Renderer &renderer)
    {
        vector<Vec2> vertices;
        for (register float i = 0, pi2 = 2 * PI; i < pi2; i += RENDER_DELTA)
            vertices.push_back(Vec2(cos(i) * a, sin(i) * b));
        renderer.render(center, theta, borderColor, innerColor, vertices);
    }

    void Ellipse::save(std::ostream & out)
    {
        out.write((const char *)&theta, sizeof(float));
        out << center << borderColor << innerColor;
        out.write((const char *)&a, sizeof(float));
        out.write((const char *)&b, sizeof(float));
    }

    void Ellipse::load(std::istream & in)
    {
        in.read((char *)&theta, sizeof(float));
        in >> center >> borderColor >> innerColor;
        in.read((char *)&a, sizeof(float));
        in.read((char *)&b, sizeof(float));
    }

    vector<Vec2> Ellipse::getBorder()
    {
        vector<Vec2> points;
        for (auto d : delta)
            points.push_back(center + Vec2(a * d[0], b * d[1]).rotate({0, 0}, theta));
        return points;
    }

    Vec2 Ellipse::getBorder(int id)
    {
        return center + Vec2(a * delta[id][0], b * delta[id][1]).rotate({0, 0}, theta);
    }

    void Ellipse::resize(int id, const Vec2 &to)
    {
        Vec2 oppo = getBorder((id + 4) % 8);
        Vec2 res = ((to - oppo) / 2).rotate({ 0, 0 }, -theta);
        Vec2 delta = { 0, 0 };

        if (id != 2 && id != 6)
        {
            a = abs(res.x);
            delta.x = res.x;
        }
        if (id != 0 && id != 4)
        {
            b = abs(res.y);
            delta.y = res.y;
        }
        center = oppo + delta.rotate({ 0, 0 }, theta);

        updated = true;
    }

    FigureType Ellipse::getType()
    {
        return ELLIPSE;
    }

    Ellipse::Ellipse(const Vec2 & pos, float theta, const Color &cborder, const Color &cinner, float a, float b) :
        IFigure(pos, theta, cborder, cinner),
        a(a),
        b(b)
    {
    }

    Ellipse::Ellipse()
    {

    }
}