#pragma once

#include <vector>
#include <set>

namespace ACCAD
{
    class Image
    {
    public:

        /* Alter each pixel to given color
         */
        void alterPixels(std::vector<pair<Vec2, Color> > pixels);

        /* Alter all pixels to the same color
         */
        void alterPixels(std::vector<Vec2> pixels, Color color);

        /* Insert a figure
         */
        void insertFigure(IFigure *figure);

        /* Erase a figure
         */
        void eraseFigure(IFigure *figure);

    private:

        Color **canvas;
        std::set<IFigure*> IFigure;
        unsigned int width, height;
    };
}