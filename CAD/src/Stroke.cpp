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

inline char BlendChannel(char origin, char target, char alpha)
{
    return ((255 - alpha)*origin + alpha * target) >> 8;
}

inline Color Blend(const Color& origin, const Color& target)
{
    return Color(BlendChannel(origin.r, target.r, target.a), BlendChannel(origin.g, target.g, target.a), BlendChannel(origin.b, target.b, target.a), origin.a);
}

ACCAD::Stroke::Stroke(const std::vector<std::pair<Vec2i, Color>>& origin, const Color & target)
{
    this->origin = origin;
    this->target.resize(origin.size());
    transform(this->origin.begin(), this->origin.end(), this->target.begin(),
        [target](pair<Vec2i, Color> org)->pair<Vec2i, Color>
        {
            return pair<Vec2i, Color>(org.first, Blend(org.second, target));
        });
}
