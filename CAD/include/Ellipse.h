#pragma once

#include "Figure.h"
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

        /* Returns the top and right tangency points
         * of this ellipse and the circumscribing rectangle 
         */
        std::vector<Vec2> getAnchors() override;

        /* [Constructor]
         * Construct an ellipse with a, b, and theta
         */
        Ellipse(float a, float b, float theta);
    };
}