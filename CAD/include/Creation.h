#pragma once

#include "Operation.h"
#include "Figure.h"

namespace ACCAD
{
    class Creation : public Operation
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
        Creation(IFigure *figure);
    };
}