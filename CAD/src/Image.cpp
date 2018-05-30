#include "../include/Image.h"
#include <algorithm>
using namespace std;
using namespace ACCAD;

void Image::alterPixels(const std::vector<std::pair<Vec2i, Color> > &pixels)
{
    for (auto &p : pixels)
        canvas[p.first.x][p.first.y] = p.second;
}

void Image::alterPixels(const std::vector<Vec2i> &pixels, const Color &color)
{
    for (auto &p : pixels)
        canvas[p.x][p.y] = color;
}

void Image::insertFigure(IFigure *figure)
{
    figures.push_back(figure);
}

void Image::alterFigure(Polygon *figure, int anchorId, const Vec2 &to)
{
    figure->
}

void Image::alterFigure(Ellipse * figure, int anchorId, const Vec2 & to)
{

}

void Image::eraseFigure(IFigure *figure)
{
    auto iter = find(figures.begin(), figures.end(), figure);
    figures.erase(iter);
}
