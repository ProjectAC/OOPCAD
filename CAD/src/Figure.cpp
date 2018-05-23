#include "stdafx.h"

#include "..\include\Figure.h"

using namespace ACCAD;
using namespace std;

vector<Vec2> IFigure::getAnchors()
{
    return vector<Vec2>();
}

IFigure::IFigure(const Vec2 & pos, const Color &cborder, const Color &cinner) : 
    center(pos), 
    borderColor(cborder),
    innerColor(cinner),
    updated(false)
{
    
}