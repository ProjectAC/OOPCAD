#pragma once

#include <vector>
#include <set>
#include "Vec2.h"
#include "definitions.h"
#include "Figure.h"
#include "Polygon.h"
#include "Ellipse.h"

namespace ACCAD
{
    class Image
    {
    public:
        Image(unsigned int width, unsigned int height, Color color = { 255,255,255,255 });
        ~Image();

        /* Alter each pixel to given color
         */
        void alterPixels(const std::vector<std::pair<Vec2i, Color> > &pixels);

        /* Alter all pixels to the same color
         */
        void alterPixels(const std::vector<Vec2i> &pixels, const Color &color);

        /* Insert a figure
         */
        void insertFigure(IFigure *figure);

        /* Alter an Anchor of a Polygon
         */
        void alterFigure(Polygon *figure, int anchorId, const Vec2 &to);

        /* Resize a figure
         */
        void resizeFigure(IFigure *figure, int anchorId, const Vec2 &to);

        /* Erase a figure
         */
        void eraseFigure(IFigure *figure);

        unsigned int getWidth() const;
        unsigned int getHeight() const;

    private:
        /* Right-up is 0, left-bottom is (width-1)*(height-1) and row first.
           e.g. canvas[x, y] = canvas[y * width + x].
        */
        Color *canvas;
        std::vector<IFigure*> figures;
        unsigned int width, height;

        Color& at(unsigned int width, unsigned int height);
    };
}