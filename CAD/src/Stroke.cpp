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

ACCAD::Stroke::Stroke(const std::vector<std::pair<Vec2, Color>>& origin, const Color & target)
{
    this->origin = origin;
    this->target.resize(origin.size());
    transform(this->target.begin(), this->target.end(), this->target.begin(), 
        [target](pair<Vec2, Color> org)->pair<Vec2, Color>
        {
            return pair<Vec2, Color>(org.first,target);
        });
}
