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
                strokeManager.addPixel(point, image.at(point), pen.color);
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

void ACCAD::Editor::startAlter(MouseButton mouse)
{
    AlterManager::AlterMode alterMode;
    switch (mouse)
    {
    case ACCAD::Editor::Left:
        alterMode = AlterManager::Move;
        break;
    case ACCAD::Editor::Right:
        alterMode = AlterManager::Vertex;
        break;
    default:
        alterMode = AlterManager::Move;
        break;
    }
    alterManager.startAlter(selectedIndex, alterMode);
}

void ACCAD::Editor::finishAlter()
{
    Alternation* alter = alterManager.finishAlter();
    if (alter != nullptr)
    {
        stack.pushback(alter);
    }
}

void ACCAD::Editor::AlterFigure(const Vec2i & from, const Vec2i & to)
{
    alterManager.AlterFigure(from, to);
}

void ACCAD::Editor::setAlterMode(const Vec2i & point, MouseButton mouse)
{
    //操作方式：
    //左键：
    //  8个锚点为圆心的8个圆：缩放
    //  4个角外部的扇形区域：旋转
    //  图形内部：移动
    //右键：
    //  多边形指定顶点移动
    switch (mouse)
    {
    case MouseButton::Left:
        break;
    case MouseButton::Right:
        break;
    default:
        break;
    }
}

int ACCAD::Editor::SelectFigure(const Vec2i & point)
{
    //根据像素坐标选择图形
    return 0;
}
