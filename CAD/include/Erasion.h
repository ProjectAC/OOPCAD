#pragma once

#include "definitions.h"
#include "Operation.h" 
#include "Figure.h"
#include "Image.h"
namespace ACCAD
{
    class Erasion : public IOperation
    {
    public:

        /* Erase this Figure
        */
        void exec(Image &image) override;

        /* Cancel this creation
        */
        void undo(Image &image) override;

        /* [Constructor]
        */
        Erasion(IFigure * origin, int index);

        ~Erasion();

    private:
        IFigure* origin;
        int index;
    };
}
