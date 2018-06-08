#include "..\include\Insertion.h"

void ACCAD::Insertion::exec(Image & image)
{
    index = image.insertFigure(target);
}

void ACCAD::Insertion::undo(Image & image)
{
    image.eraseFigure(index);
}

ACCAD::Insertion::Insertion(IFigure * target)
{
    this->target = target->Clone();
    this->index = index;
}

ACCAD::Insertion::~Insertion()
{
    delete target;
}
