#pragma once

#include "Figure.h"
#include "definitions.h"
#include <vector>

namespace ACCAD
{
    class Ellipse : public IFigure
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

        /* Returns the 8 Points of its border
         * e.g, Right, TopRight, Top, TopLeft, Left, BottomLeft, Bottom, BottomRight 
         */
        std::vector<Vec2> getBorder() override;

        /* Returns the <id>-th Point of its border
         */
        Vec2 getBorder(int id) override;

        /* Rescale by dragging a border point
         * Its opposite point should stay
         */
        void resize(int id, const Vec2 &to) override;

        /* Return if a point is inside the ellipse
         */
        bool isInsize(const Vec2& point) override;

        /* Returns the TYPE (enum FigureType) of this Figure
        */
        FigureType getType() override;

        /* Deep copy a ellipse;
        */
        Ellipse* Clone() override;

        /* [Constructor]
         * Construct an ellipse with a, b, and theta
         */
        Ellipse::Ellipse(const Vec2 & pos, float theta, const Color &cborder, const Color &cinner, float a, float b);

    private:

        float a;
        float b;
        static const float RENDER_DELTA;
    };
}