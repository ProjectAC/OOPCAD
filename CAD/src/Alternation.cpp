#include "..\include\Alternation.h"

void ACCAD::Alternation::exec(Image & image)
{
    image.overwriteFigure(index, target);
}

void ACCAD::Alternation::undo(Image & image)
{
    image.overwriteFigure(index, origin);
}

ACCAD::Alternation::Alternation(IFigure * origin, int index)
{
    this->isTargetNull = true;
    this->target = nullptr;
    this->origin = origin->Clone();//TODO:多态的深拷贝
    this->index = index;
}

void ACCAD::Alternation::AddTarget(IFigure * target)
{
    this->target = target->Clone();//TODO:同上
    this->isTargetNull = false;
}

ACCAD::Alternation::~Alternation()
{
    delete target;
    delete origin;
}
