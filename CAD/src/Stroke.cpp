#include "..\stdafx.h"

#include "..\include\Stroke.h"
#include <algorithm>
using namespace std;
using namespace ACCAD;

void ACCAD::Stroke::exec(Image & image)
{
    image.alterPixels(target);
}

void ACCAD::Stroke::undo(Image & image)
{
    image.alterPixels(origin);
}

ACCAD::Stroke::Stroke(const std::vector<std::pair<Vec2i, Color>>& origin, const Color & target)
{
    this->origin = origin;
    for (auto item : origin)
    {
        this->target.push_back({ item.first, target });
    }
}
