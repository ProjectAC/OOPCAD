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

IFigure* GenerateFigure(FigureType figureType, const Vec2i & center, const Color & cborder, const Color & cinner, float a, float b)
{
    switch (figureType)
    {
    case ACCAD::ELLIPSE:
        return new ACCAD::Ellipse(center, 0.0f, cborder, cinner, a, b);
    case ACCAD::POLYGON:
        return new ACCAD::Polygon(cborder, cinner, { Vec2(center) + Vec2(a,b), Vec2(center) + Vec2(-a,b), Vec2(center) + Vec2(-a,-b), Vec2(center) + Vec2(a,-b) });
    default:
        return nullptr;
    }
}

void ACCAD::Editor::insertFigure(FigureType figureType, const Vec2i & center, float a, float b)
{
    IFigure * figure = GenerateFigure(figureType, center, foreground, background, a, b);
    selectedIndex = image.insertFigure(figure);
    alterManager.startAlter(selectedIndex, AlterManager::Resize, 7);
}

void ACCAD::Editor::finishInsert()
{
    Alternation* tmpAlter = alterManager.finishAlter();
    delete tmpAlter;
    Insertion* insert = new Insertion(image.getFigure(selectedIndex));
    stack.pushback(insert);
}

void ACCAD::Editor::startPolygon()
{
    insertBuffer.clear();
}

void ACCAD::Editor::finishPolygon()
{
    Polygon figure(foreground, background, insertBuffer);
    selectedIndex = image.insertFigure(&figure);
    alterManager.startAlter(selectedIndex, AlterManager::Vertex, 0);
}

void ACCAD::Editor::addVertex(const Vec2i & vertex)
{
    if (!insertBuffer.empty() && (Vec2(vertex) - insertBuffer[0]).length() < AnchorThreshold)
    {
        finishPolygon();
    }
    else
    {
        insertBuffer.push_back(vertex);
    }
}

void ACCAD::Editor::startAlter(MouseKeys mouse)
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
    alterManager.startAlter(selectedIndex, alterMode, -1);
}

void ACCAD::Editor::finishAlter()
{
    Alternation* alter = alterManager.finishAlter();
    if (alter != nullptr)
    {
        stack.pushback(alter);
    }
}

void ACCAD::Editor::alterFigure(const Vec2i & from, const Vec2i & to)
{
    alterManager.AlterFigure(from, to);
    //TODO：画面刷新
}

void ACCAD::Editor::setAlterMode(const Vec2i & point, MouseKeys mouse)
{
    //操作方式：
    //左键：
    //  8个锚点为圆心的8个圆：缩放
    //  4个角外部的扇形区域：旋转
    //  图形中心为圆心的圆：移动
    //右键：
    //  多边形指定顶点移动
    IFigure * figure = image.getFigure(selectedIndex);
    AlterManager::AlterMode alterMode = AlterManager::None;
    int anchorID = -1;
    switch (mouse)
    {
        case MouseKeys::Left:
        {
            auto anchors = figure->getBorder();
            for (int i = 0; i < anchors.size(); i++)
            {
                if ((anchors[i] - point).length() < AnchorThreshold)
                {
                    alterMode = AlterManager::Resize;
                    anchorID = i;
                    goto OutsideSwitch;
                }
            }

            auto center = (anchors[0] + anchors[4])*0.5f;
            float a = abs((anchors[0] - center).x);
            float b = abs((anchors[2] - center).y);
            auto r = Vec2(point) - center;
            for (int i = 1; i < anchors.size(); i+=2)
            {
                if ((anchors[i] - point).length() < ResizeThreshold && 
                    abs(r.x)>a &&
                    abs(r.y)>b)
                {
                    alterMode = AlterManager::Rotate;
                    anchorID = i;
                    goto OutsideSwitch;
                }
            }

            if (figure->isInside(point))
            {
                alterMode = AlterManager::Move;
                goto OutsideSwitch;
            }
            alterManager.setAlterMode(AlterManager::None, -1);
            break;
        }
        case MouseKeys::Right:
        {
            if (figure->getType() == FigureType::POLYGON)
            {
                auto anchors = static_cast<Polygon*>(figure)->getAnchors();
                for (int i = 0; i < anchors.size(); i++)
                {
                    if ((anchors[i] - point).length() < AnchorThreshold)
                    {
                        alterMode = AlterManager::Vertex;
                        anchorID = i;
                        goto OutsideSwitch;
                    }
                }
            }
            break;
        }
        default:
            break;
    }
OutsideSwitch:
    alterManager.setAlterMode(alterMode,anchorID);
}

void ACCAD::Editor::eraseFigure()
{
    if (selectedIndex != -1)
    {
        Erasion * erasion = new Erasion(image.getFigure(selectedIndex), selectedIndex);
        image.eraseFigure(selectedIndex);
        stack.pushback(erasion);
    }
}

int ACCAD::Editor::SelectFigure(const Vec2i & point)
{
    for (int i = image.getFigureCount() - 1; i >= 0; i--)
    {
        if (image.getFigure(i)->isInside(point))
        {
            selectedIndex = i;
            return i;
        }
    }
}

Color ACCAD::Editor::getForegroundColor()
{
    return foreground;
}

Color ACCAD::Editor::getBackgroundColor()
{
    return background;
}

void ACCAD::Editor::setForegroundColor(const Color & color)
{
    foreground = color;
}

void ACCAD::Editor::setBackgroundColor(const Color & color)
{
    background = color;
}
