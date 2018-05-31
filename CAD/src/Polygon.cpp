#include "../stdafx.h"

#include "../include/Polygon.h"
#include "../include/Utility.h"
#include "../include/definitions.h"

using namespace std;

namespace ACCAD
{

    void Polygon::render(Renderer &renderer)
    {
        renderer.render(center, theta, borderColor, innerColor, vertices);
    }

    void Polygon::save(std::ostream &out)
    {
        out.write((const char *)&theta, sizeof(float));
        out << center << borderColor << innerColor;
        size_t tmp = vertices.size();
        out.write((const char *)&tmp, sizeof(float));
        for (auto &v : vertices)
            out << v;
    }

    void Polygon::load(std::istream &in)
    {
        in.read((char *)&theta, sizeof(float));
        in >> center >> borderColor >> innerColor;
        size_t tmp = vertices.size();
        in.read((char *)&tmp, sizeof(float));
        for (auto &v : vertices)
            in >> v;
    }

    vector<Vec2> Polygon::getAnchors()
    {
        return vertices;
    }

    vector<Vec2> Polygon::getBorder()
    {
        if (updated) reGen();
        vector<Vec2> points;
        for (auto d : delta)
        {
            float x = d[0] == 1 ? right : (d[0] == -1 ? left : 0);
            float y = d[1] == 1 ? top : (d[1] == -1 ? bottom : 0);
            points.push_back(Vec2(x, y).rotate(center, theta));
        }

        return points;
    }

    Vec2 Polygon::getBorder(int id)
    {
        if (updated) reGen();
        float x = delta[id][0] == 1 ? right : (delta[id][0] == -1 ? left : 0);
        float y = delta[id][1] == 1 ? top : (delta[id][1] == -1 ? bottom : 0);
        return Vec2(x, y).rotate(center, theta);
    }

    void Polygon::resize(int id, const Vec2 &to)
    {
        Vec2 from = getBorder(id);
        Vec2 oppo = getBorder((id + 4) % 8);
        center = (to + oppo) * 0.5;
        Vec2 newPos = (to - center).rotate(center, -theta);
        float rate = (to - oppo).length() / (from - oppo).length();

        for (auto &v : vertices)
            v = v * rate;

        updated = true;
    }

    void Polygon::alter(int id, const Vec2 &to)
    {
        vertices[id] = to;
        updated = true;
    }

    FigureType Polygon::getType()
    {
        return POLYGON;
    }

    void Polygon::reGen()
    {
        top = bottom = vertices[0].y;
        left = right = vertices[0].x;

        for (auto &v : vertices)
        {
            top = max(top, v.y);
            bottom = min(bottom, v.y);
            left = min(left, v.x);
            right = max(right, v.x);
        }

        updated = false;
    }

    Polygon::Polygon(const Vec2 &pos, float theta, const Color &cborder, const Color &cinner, const std::vector<Vec2> &verts) :
        IFigure(pos, theta, cborder, cinner),
        vertices(verts)
    {

    }
}