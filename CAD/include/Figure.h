#pragma once

#include <iostream>

namespace ACCAD
{
    struct Vec2
    {
        float x, y;
    };

    class IFigure
    {
    public:

        /* Render this figure on the Renderer
         */
        virtual void render(Renderer &renderer) = 0;

        /* Save this figure to an output stream
         */ 
        virtual void save(std::ostream &out) = 0;

        /* Get all anchor points
         */
        virtual std::vector<Vec2> getAnchors();
    };
}