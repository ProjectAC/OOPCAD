#include "../stdafx.h"

#include "../include/Image.h"
#include <algorithm>
using namespace std;

namespace ACCAD
{
    Image::Image(unsigned int width, unsigned int height, Color color)
    {
        canvas = new Color[width*height];
        for (unsigned int i = 0; i < width*height; i++)
        {
            canvas[i] = color;
        }
        this->width = width;
        this->height = height;
    }

    Image::~Image()
    {
        delete[]canvas;
    }

    void Image::alterPixels(const std::vector<std::pair<Vec2i, Color> > &pixels)
    {
        for (auto &p : pixels)
            this->at(p.first.x, p.first.y) = p.second;
    }

    void Image::alterPixels(const std::vector<Vec2i> &pixels, const Color &color)
    {
        for (auto &p : pixels)
            this->at(p.x, p.y) = color;
    }

    void Image::insertFigure(IFigure *figure)
    {
        figures.push_back(figure);
    }

    void Image::alterFigure(Polygon *figure, int anchorId, const Vec2 &to)
    {
        figure->alter(anchorId, to);
    }

    void Image::resizeFigure(IFigure * figure, int anchorId, const Vec2 & to)
    {
        figure->resize(anchorId, to);
    }

    void Image::eraseFigure(IFigure *figure)
    {
        auto iter = find(figures.begin(), figures.end(), figure);
        figures.erase(iter);
    }

    unsigned int Image::getWidth() const
    {
        return this->width;
    }

    unsigned int Image::getHeight() const
    {
        return this->height;
    }

    Color& Image::at(unsigned int x, unsigned int y)
    {
        return canvas[y*width + x];
    }
}