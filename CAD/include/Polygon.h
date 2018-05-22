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

        /* Load from an input stream to this figure
         */ 
        void load(std::istream &in) override;

        /* Returns the vertices of the polygon
         */
        std::vector<Vec2> getAnchors() override;

        /* Returns the 8 Points of its border
         * e.g, Right, TopRight, Top, TopLeft, Left, BottomLeft, Bottom, BottomRight 
         */
        std::vector<Vec2> getBorder() override;

        /* [Constructor]
         * Construct a polygon with a list of Vertices
         */
        Polygon(const Vec2 &pos, const std::vector<Vec2> &verts, float theta);
    };
}