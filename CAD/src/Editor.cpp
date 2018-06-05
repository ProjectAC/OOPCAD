#include "../include/Editor.h"

using namespace std;
using namespace ACCAD;

void ACCAD::Editor::startDraw()
{

}

void ACCAD::Editor::movePen(const Vec2i & from, const Vec2i & to)
{
    if (from.x == to.x)
    {
        for (int i = max(from.x - pen.width - 1, 0); i < min(to.x + pen.width + 1, image.getWidth); i++)
        {
            for (int j = max(from.y - pen.width - 1, 0); j < min(to.y + pen.width + 1, image.getWidth); j++)
            {
                
            }
        }
    }
    else
    {

    }
}
