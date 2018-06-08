#include "..\include\Alternation.h"

void ACCAD::Alternation::exec(Image & image)
{
    image.assignFigure(index, target);
}

void ACCAD::Alternation::undo(Image & image)
{
    image.assignFigure(index, origin);
}

ACCAD::Alternation::Alternation(IFigure * origin, int index)
{
    this->target = nullptr;
    this->origin = origin->Clone();//TODO:多态，深拷贝
    this->index = index;
}

void ACCAD::Alternation::AddTarget(IFigure * target)
{
    this->target = target->Clone();//TODO:同上
}

ACCAD::Alternation::~Alternation()
{
    delete target;
    delete origin;
}
