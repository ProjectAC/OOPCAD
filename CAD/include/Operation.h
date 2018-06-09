#pragma once

#include "Image.h"

namespace ACCAD
{
    class IOperation
    {
    public:
        /* Redo this operation
         */
        virtual void redo(Image &image) = 0;

        /* Undo this operation
         */ 
        virtual void undo(Image &image) = 0;
        
    };
}