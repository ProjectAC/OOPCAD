#include "../stdafx.h"

#include "../include/Stroke.h"
#include <algorithm>
using namespace std;

namespace ACCAD
{

    void ACCAD::Stroke::exec(Image & image)
    {
        image.alterPixels(target);
    }

    void ACCAD::Stroke::undo(Image & image)
    {
        image.alterPixels(origin);
    }

ACCAD::Stroke::Stroke(const std::vector<std::pair<Vec2i, Color>>& origin, const std::vector<std::pair<Vec2i, Color>>& target)
{
    this->origin = origin;
    this->target = target;
}

ACCAD::Stroke::Stroke()
{
}

void ACCAD::Stroke::addPixel(const std::pair<Vec2i, Color>& origin, const std::pair<Vec2i, Color>& target)
{
    this->origin.push_back(origin);
    this->target.push_back(target);
}
