#pragma once

#include "definitions.h"
#include "Operation.h" 
#include "Figure.h"
#include "Image.h"
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
        Alternation(IFigure * origin, int index);
        //Alternation(IFigure *figure, int vertexId, const Vec2 &from, const Vec2 &to);

        void AddTarget(IFigure * Target);

        ~Alternation();

    private:
        IFigure* target;
        IFigure* origin;
        int index;
        bool isTargetNull;
    };
}
