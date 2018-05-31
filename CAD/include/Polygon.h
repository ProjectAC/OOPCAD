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
        std::vector<Vec2> getAnchors();

        /* Returns the 8 Points of its border
         * e.g, Right, TopRight, Top, TopLeft, Left, BottomLeft, Bottom, BottomRight 
         */
        std::vector<Vec2> getBorder() override;
        
        /* Returns the <id>-th Point of its border
         */
        Vec2 getBorder(int id) override;

        /* Rescale by dragging the <id>-th border point to <to>
         * Its opposite point should stay still
         */
        void resize(int id, const Vec2 &to) override;

        /* Move an anchor point
         */
        void alter(int id, const Vec2 &to);

        /* Returns the TYPE (enum FigureType) of this Figure
         */
        FigureType getType() override;

        /* [Constructor]
         * Construct a polygon with a list of Vertices
         */
        Polygon(const Vec2 &pos, float theta, const Color &cborder, const Color &cinner, const std::vector<Vec2> &verts);

    private:

        void reGen();
        
        std::vector<Vec2> vertices;
        float top, bottom, left, right;
    };
}