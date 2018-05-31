#pragma once

#include "Operation.h"
#include "Figure.h"
#include <vector>

namespace ACCAD
{
    class Stroke : public IOperation
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
        Stroke(const std::vector<std::pair<Vec2, Color> > &origin, const Color &target);

    private:
        std::vector<std::pair<Vec2, Color> > origin;
        std::vector<std::pair<Vec2, Color> > target;
    };
}