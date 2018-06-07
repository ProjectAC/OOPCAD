#include "../stdafx.h"

#include "../include/Image.h"
#include <algorithm>
#include <exception>

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

    void Image::alterPixel(const Vec2i & pixel, const Color & color)
    {
        this->at(pixel) = color;
    }

    void Image::alterPixels(const std::vector<std::pair<Vec2i, Color> > &pixels)
    {
        for (auto &p : pixels)
            this->at(p.first) = p.second;
    }

    void Image::alterPixels(const std::vector<Vec2i> &pixels, const Color &color)
    {
        for (auto &p : pixels)
            this->at(p) = color;
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

    void Image::overwriteFigure(int index, IFigure * target)
    {
        delete figures[index];
        figures[index] = target->Clone();
    }

    IFigure* Image::getFigure(int index)
    {
        return figures[index];
    }

    Color& Image::at(unsigned int x, unsigned int y)
    {
        if (isInside(x, y))
            return canvas[y*width + x];
        else
            throw out_of_range("Out of range for image");
    }
    Color & Image::at(const Vec2i & v2i)
    {
        return at(v2i.x, v2i.y);
    }
    bool Image::isInside(unsigned int x, unsigned int y) const
    {
        return (0 <= x && x < width) && (0 <= y && y < height);
    }
    bool Image::isInside(const Vec2i & v2i) const
    {
        return isInside(v2i.x,v2i.y);
    }
}