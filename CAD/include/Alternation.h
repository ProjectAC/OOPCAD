#pragma once

#include "definitions.h"
#include "Operation.h" 

namespace ACCAD
{
    class Alternation : public IOperation
    {
    public:

        /* Create this Figure
         */
        void exec(Image &image) override;

        /* Cancel this creation
         */
        void undo(Image &image) override;

        /* [Constructor]
         */
        Alternation(IFigure *figure, int vertexId, const Vec2 &from, const Vec2 &to);

    };
}
