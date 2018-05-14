#pragma once

#include <iostream>
#include <vector>
#include "definitions.h"

namespace ACCAD
{
    class IFigure
    {
    public:

        /* Render this figure on the Renderer
         */
        virtual void render(Renderer &renderer) = 0;

        /* Save this figure to an output stream
         */ 
        virtual void save(std::ostream &out) = 0;

        /* Load from an input stream to this figure
         */ 
        virtual void load(std::istream &in) = 0;

        /* Get all anchor points
         */
        virtual std::vector<Vec2> getAnchors() = 0;

        /* Returns the 8 Points of its border
         * e.g, Right, TopRight, Top, TopLeft, Left, BottomLeft, Bottom, BottomRight 
         */
        virtual std::vector<Vec2> getBorder() = 0;

    private:
        
        Color borderColor, innerColor;
        Vec2 center;
    };
}
