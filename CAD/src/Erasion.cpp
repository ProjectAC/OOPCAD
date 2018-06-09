#include "..\include\Erasion.h"

void ACCAD::Erasion::redo(Image & image)
{
    image.eraseFigure(index);
}

void ACCAD::Erasion::undo(Image & image)
{
    image.insertFigure(index, origin);
}

ACCAD::Erasion::Erasion(IFigure * origin, int index)
{
    this->origin = origin->Clone();
    this->index = index;
}

ACCAD::Erasion::~Erasion()
{
    delete origin;
}
