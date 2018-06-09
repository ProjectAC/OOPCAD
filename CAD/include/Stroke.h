#pragma once

#include "Operation.h"
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
        Stroke(const std::vector<std::pair<Vec2i, Color> > &origin, const std::vector<std::pair<Vec2i, Color> > &target);
        Stroke();

        void addPixel(const std::pair<Vec2i, Color>& origin, const std::pair<Vec2i, Color>& target);

    private:
        std::vector<std::pair<Vec2i, Color> > origin;
        std::vector<std::pair<Vec2i, Color> > target;
    };
}