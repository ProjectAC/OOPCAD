#include "stdafx.h"

#include "../include/Figure.h"

using namespace std;

namespace ACCAD
{

    FigureType IFigure::getType()
    {
        return UNKNOWN;
    }

    void IFigure::rotate(int id, const Vec2 &to)
    {
        Vec2 tmp = to - center;
        theta = atan2(tmp.y, tmp.x);
    }

    void IFigure::move(const Vec2 & from, const Vec2 & to)
    {
        center = center + (to - from);
    }

    IFigure::IFigure(const Vec2 & center, float theta, const Color &cborder, const Color &cinner) :
        center(center),
        theta(theta),
        borderColor(cborder),
        innerColor(cinner),
        updated(true)
    {

    }

    IFigure::IFigure()
    {
    }
}