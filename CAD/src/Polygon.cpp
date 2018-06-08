#include "stdafx.h"

#include "../include/Polygon.h"
#include "../include/Utility.h"
#include "../include/definitions.h"

using namespace std;

namespace ACCAD
{

    void Polygon::render(Renderer &renderer)
    {
        renderer.render(center, theta, borderColor, innerColor, vertices, true);
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
        vector<Vec2> res;
        for (auto &v : vertices)
            res.push_back(center + v.rotate(0, theta));
        return res;
    }

    vector<Vec2> Polygon::getBorder()
    {
        vector<Vec2> points;
        for (auto d : delta)
        {
            float x = d[0] == 1 ? right : (d[0] == -1 ? left : 0);
            float y = d[1] == 1 ? top : (d[1] == -1 ? bottom : 0);
            points.push_back(center + Vec2(x, y).rotate(0, theta));
        }

        return points;
    }

    Vec2 Polygon::getBorder(int id)
    {
        float x = delta[id][0] == 1 ? right : (delta[id][0] == -1 ? left : 0);
        float y = delta[id][1] == 1 ? top : (delta[id][1] == -1 ? bottom : 0);
        return center + Vec2(x, y).rotate(0, theta);
    }

    void Polygon::resize(int id, const Vec2 &to)
    {
        Vec2 oppo = getBorder((id + 4) % 8);
        Vec2 res = ((to - oppo) / 2).rotate({ 0, 0 }, -theta);
        Vec2 delta = { 0, 0 }, rate = { 1, 1 };
        if (id != 2 && id != 6)
        {
            delta.x = res.x;
            rate.x = res.x * 2 / (right - left);
        }
        if (id != 0 && id != 4)
        {
            delta.y = res.y;
            rate.y = res.y * 2 / (top - bottom);
        }

        center = oppo + delta.rotate({ 0, 0 }, theta);

        for (auto &v : vertices)
        {
            v.x = v.x * rate.x;
            v.y = v.y * rate.y;
        }

        reGen();
        updated = true;
    }

    void Polygon::alter(int id, const Vec2 &to)
    {
        vertices[id] = to - center;
        Vec2 delta = getPos(vertices);
        for (auto &v : vertices)
            v = v - delta;
        center = center + delta;

        reGen();
        updated = true;
    }

    bool Polygon::isInside(const Vec2 & point)
    {
        int   i, j = vertices.size() - 1;
        bool  oddNodes = false;
        float x = point.x, y = point.y;
        for (i = 0; i<vertices.size(); i++) 
        {
            if ((vertices[i].y< y && vertices[j].y >= y
                || vertices[j].y<y && vertices[i].y >= y)
                && (vertices[i].x <= x || vertices[j].x <= x)) 
            {
                oddNodes ^= (vertices[i].x + (y - vertices[i].y) / (vertices[j].y - vertices[i].y)*(vertices[j].x - vertices[i].x) < x);
            }
            j = i;
        }
        return oddNodes;
    }

    FigureType Polygon::getType()
    {
        return POLYGON;
    }

    Polygon * Polygon::Clone()
    {
        return new Polygon(*this);
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

    Vec2 Polygon::getPos(const std::vector<Vec2> &vertices)
    {
        float top, bottom, left, right;
        top = bottom = vertices[0].y;
        left = right = vertices[0].x;

        for (auto &v : vertices)
        {
            top = max(top, v.y);
            bottom = min(bottom, v.y);
            left = min(left, v.x);
            right = max(right, v.x);
        }

        return { (left + right) / 2, (top + bottom) / 2 };
    }

    Polygon::Polygon(const Color &cborder, const Color &cinner, const std::vector<Vec2> &verts) :
        IFigure(getPos(verts), 0, cborder, cinner),
        vertices(verts)
    {
        for (auto &v : vertices)
            v = v - center;

        reGen();
    }

    Polygon::Polygon()
    {
        
    }
}