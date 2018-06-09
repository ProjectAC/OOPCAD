#include "../include/AlterManager.h"

using namespace std;
using namespace ACCAD;

ACCAD::AlterManager::AlterManager(Image & image)
{
    this->image = &image;
}

void ACCAD::AlterManager::startAlter(int index, AlterMode alterMode, int anchorID)
{
    isDirty = false;
    currentAlter = new Alternation(image->getFigure(index), index);
    this->alterMode = alterMode;
    this->anchorID = anchorID;
}

Alternation * ACCAD::AlterManager::finishAlter()
{
    if (!isDirty)
    {
        delete currentAlter;
        return nullptr;
    }
    else
    {
        return currentAlter;
    }
}

void ACCAD::AlterManager::setAlterMode(AlterMode alterMode, int anchorID)
{
    this->alterMode = alterMode;
    this->anchorID = anchorID;
}

void ACCAD::AlterManager::AlterFigure(const Vec2i & from, const Vec2i & to)
{
    IFigure *selectedFigure = image->getFigure(index);
    switch (alterMode)
    {
    case ACCAD::AlterManager::Vertex:
        if (anchorID != -1)
        {
            static_cast<Polygon*>(selectedFigure)->alter(anchorID, selectedFigure->getBorder(anchorID) + to - from);
            if ((to - from).sqrLength != 0) isDirty = true;
        }
        break;
    case ACCAD::AlterManager::Resize:
        if (anchorID != -1)
        {
            selectedFigure->resize(anchorID, selectedFigure->getBorder(anchorID) + to - from);
            if ((to - from).sqrLength != 0) isDirty = true;
            break;
        }
    case ACCAD::AlterManager::Rotate:
        if (anchorID != -1)
        {
            selectedFigure->rotate(anchorID, selectedFigure->getBorder(anchorID) + to - from);S
            if ((to - from).sqrLength != 0) isDirty = true;
            break;
        }
    case ACCAD::AlterManager::Move:
        selectedFigure->move(from, to);
        if ((to - from).sqrLength != 0) isDirty = true;
        break;
    default:
        break;
    }
}

std::vector<Vec2> ACCAD::AlterManager::getAnchors()
{
    IFigure *selectedFigure = image->getFigure(index);

    switch (alterMode)
    {
    case AlterMode::Vertex:
        switch (selectedFigure->getType())
        {
        case FigureType::POLYGON:
            return static_cast<Polygon*>(selectedFigure)->getAnchors();
        default:
            return {};
        }
    case AlterMode::Resize:
    case AlterMode::Move:
    case AlterMode::Rotate:
        return selectedFigure->getBorder;
    default:
        return {};
    }
}

AlterManager::AlterMode ACCAD::AlterManager::getAlterMode()
{
    return alterMode;
}
