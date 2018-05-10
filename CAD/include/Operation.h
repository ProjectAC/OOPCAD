#pragma once

namespace ACCAD
{
    class IOperation
    {
    public:
        /* Execute this operation
         */
        virtual void exec(Image &image) = 0;

        /* Undo this operation
         */ 
        virtual void undo(Image &image) = 0;
        
    };
}