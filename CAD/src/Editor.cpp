#include "../include/Editor.h"
#include <queue>
#include <algorithm>
using namespace std;
using namespace ACCAD;

inline bool IsInside(const Vec2i& pixel, const Image& image)
{
    return (0 <= pixel.x && pixel.x < image.getWidth()) && (0 <= pixel.y && pixel.y < image.getHeight());
}

float DistanceToLine(const Vec2i& P, const Vec2i& A, const Vec2i& B)
{
    auto BA = A - B;
    int sqr_len = BA.sqrLength();
    if (sqr_len == 0.0)
        return (P - A).length();
    float t = max(0, min(1, dot(P - A, B - A) / sqr_len));
    Vec2 projection = Vec2(A) + Vec2(B - A)*t;
    return (Vec2(P) - projection).length();
}

void ACCAD::Editor::startDraw()
{
    strokeManager.startDraw();
}

void ACCAD::Editor::finishDraw()
{
    Stroke* stroke = strokeManager.finishDraw();
    if (stroke != nullptr)
    {
        //TODO:
        stack.pushback(stroke);
    }
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
            //在边界内&&像素未搜索过&&距离小于画笔宽度
            if (image.isInside(point) && hashtable.find(point) == hashtable.end() && DistanceToLine(point, from, to) <= pen.width / 2)
            {
                queue.push(point);
                hashtable.insert(point);
                strokeManager.addPixel(point, image.at(point), pen.color, image);
            }
        }
    }
    //TODO：画面刷新一次？
}

void ACCAD::Editor::setPen(const Pen & pen)
{
    this->pen = pen;
}

Pen ACCAD::Editor::getPen()
{
    return this->pen;
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
    //渲染？
}

int ACCAD::Editor::SelectFigure(const Vec2i & point)
{
    //根据像素坐标选择图形
    return 0;
}
