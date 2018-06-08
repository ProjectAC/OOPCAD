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
            vertices.push_back(center + Vec2(cos(i) * a, sin(i) * b));
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
            points.push_back(Vec2(center.x + a * d[0], center.y + b * d[1]).rotate(center, theta));
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

        updated = true;
    }

    bool Ellipse::isInsize(const Vec2 & point)
    {
        return pow((point.x - center.x) / a, 2) + pow((point.y - center.y) / b, 2) < 1;
    }

    FigureType Ellipse::getType()
    {
        return ELLIPSE;
    }

    Ellipse * Ellipse::Clone()
    {
        return new Ellipse(*this);
    }

    Ellipse::Ellipse(const Vec2 & pos, float theta, const Color &cborder, const Color &cinner, float a, float b) :
        IFigure(pos, theta, cborder, cinner),
        a(a),
        b(b)
    {
    }
}