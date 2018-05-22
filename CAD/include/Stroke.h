#pragma once

#include "Operation.h"
#include "Figure.h"
#include <vector>

namespace ACCAD
{
    class Stroke : public Operation
    {
    public:

        /* Draw this stroke
         */
        void exec(Image &image) override;

        /* Cancel this stroke
         */
        void undo(Image &image) override;

        /* [Constructor]
         */
        Stroke(const std::vector<pair<Vec2, Color> > &origin, const Color &target);
    };
}