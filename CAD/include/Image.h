#pragma once

#include <vector>
#include <set>
#include "Vec2.h"
#include "definitions.h"
#include "Figure.h"

namespace ACCAD
{
    class Image
    {
    public:

        /* Alter each pixel to given color
         */
        void alterPixels(const std::vector<std::pair<Vec2, Color> > &pixels);

        /* Alter all pixels to the same color
         */
        void alterPixels(const std::vector<Vec2> &pixels, const Color &color);

        /* Insert a figure
         */
        void insertFigure(IFigure *figure);

        /* Alter an Anchor of a figure
         */
        void alterFigure(IFigure *figure, int anchorId, const Vec2 &from, const Vec2 &to);

        /* Erase a figure
         */
        void eraseFigure(IFigure *figure);

    private:

        Color **canvas;
        std::set<IFigure*> IFigure;
        unsigned int width, height;
    };
}