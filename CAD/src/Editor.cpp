#include "../include/Editor.h"
#include <queue>
using namespace std;
using namespace ACCAD;

inline bool IsInside(const Vec2i& pixel, const Image& image)
{
    return (0 <= pixel.x && pixel.x < image.getWidth()) && (0 <= pixel.y && pixel.y < image.getHeight());
}

float DistanceToLine(const Vec2i& point, const Vec2i& lineA, const Vec2i& lineB)
{
    if (lineA == lineB)
    {
        return sqrt(pow(point.x - lineA.x, 2) + pow(point.y - lineA.y, 2));
    }
    else
    {
        //Ax+By+C=0
        float A = lineB.y - lineA.y;
        float B = lineA.x - lineB.x;
        float C = -lineA.y*B - lineA.x*A;
        return abs(A*point.x + B * point.y + C) / sqrt(A*A + B * B);
    }    
}

void ACCAD::Editor::startDraw()
{
    tempPixels.clear();
}

void ACCAD::Editor::finishDraw()
{
    image.alterPixels(vector<Vec2i>(tempPixels.begin(), tempPixels.end()), pen.color);
    //创建stroke，明早写
}

void ACCAD::Editor::movePen(const Vec2i & from, const Vec2i & to)
{
    static
    unordered_set<Vec2i> hashtable;
    queue<Vec2i> queue;
    queue.push(from);
    hashtable.insert(from);
    while (!queue.empty())
    {
        auto center = queue.front();
        queue.pop();
        for (auto d : delta)
        {
            Vec2i point(center.x + d[0], center.y + d[1]);
            //在边界内，未搜索过，距离小于画笔宽度
            if (IsInside(point, image) && hashtable.find(point) == hashtable.end() && pen.width / 2 < DistanceToLine(point, from, to) )
            {
                queue.push(point);
                hashtable.insert(point);
                tempPixels.insert(point);
            }
        }
    }
}

void ACCAD::Editor::insertEllipse(const Vec2i & center)
{
    
}

void ACCAD::Editor::startAlter(AlterMode alterMode)
{
    alter = new Alternation(image.getFigure(selectedIndex), selectedIndex);
}

void ACCAD::Editor::finishAlter()
{
    alter->AddTarget(image.getFigure(selectedIndex));
}

void ACCAD::Editor::AlterFigure(const Vec2i & from, const Vec2i & to)
{
    //根据像素坐标判断作何种修改，然后调用image的接口修改figure
}

int ACCAD::Editor::SelectFigure(const Vec2i & point)
{
    //根据像素坐标选择图形
    return 0;
}
