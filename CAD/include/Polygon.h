#pragma once

#include "Figure.h"
#include <vector>

namespace ACCAD
{
    class Polygon : public IFigure
    {
    public:

        /* Render this figure on the Renderer
         */
        void render(Renderer &renderer) override;

        /* Save this figure to an output stream
         */ 
        void save(std::ostream &out) override;

        /* Returns the vertices of the polygon
         */
        std::vector<Vec2> getAnchors() override;

        /* [Constructor]
         * Construct a polygon with a list of Vertices
         */
        Polygon(std::vector<Vec2> verts);
    };
}