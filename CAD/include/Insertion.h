#pragma once

#include "definitions.h"
#include "Operation.h" 
#include "Figure.h"
#include "Image.h"
namespace ACCAD
{
    class Insertion : public IOperation
    {
    public:

        /* Create this Figure
        */
        void redo(Image &image) override;

        /* Cancel this creation
        */
        void undo(Image &image) override;

        /* [Constructor]
        */
        Insertion(IFigure * target);

        ~Insertion();

    private:
        IFigure * target;
        int index;
    };
}
