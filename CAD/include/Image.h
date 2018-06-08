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

        /* Alter a pixels to given color
        */
        void alterPixel(const Vec2i &pixel, const Color &color);

        /* Alter each pixel to given color
         */
        void alterPixels(const std::vector<std::pair<Vec2i, Color> > &pixels);

        /* Alter all pixels to the same color
         */
        void alterPixels(const std::vector<Vec2i> &pixels, const Color &color);

        /* Insert a figure. Return the index of the figure in vector.
         */
        int insertFigure(IFigure *figure);

        /* Alter an Anchor of a Polygon
         */
        void alterFigure(int index, int anchorId, const Vec2 &to);

        /* Resize a figure
         */
        void resizeFigure(int index, int anchorId, const Vec2 &to);

        /* Rotate a figure
        */
        void rotateFigure(int index, int anchorId, const Vec2 &to);

        /* Move a figure
        */
        void moveFigure(int index, const Vec2 &from, const Vec2 &to);

        /* Replace a figure.
         */
        void assignFigure(int index, IFigure* target);

        /* Erase a figure
         */
        void eraseFigure(int index);

        Color& at(unsigned int x, unsigned int y);
        Color& at(const Vec2i& v2i);
        bool isInside(unsigned int x, unsigned int y) const;
        bool isInside(const Vec2i& v2i) const;

        unsigned int getWidth() const;
        unsigned int getHeight() const;

        IFigure* getFigure(int index);

    private:
        /* Right-up is 0, left-bottom is (width-1)*(height-1) and row first.
           e.g. canvas[x, y] = canvas[y * width + x].
        */
        Color *canvas;
        std::vector<IFigure*> figures;
        unsigned int width, height;

    };
}