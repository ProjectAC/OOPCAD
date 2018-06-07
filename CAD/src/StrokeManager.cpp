#include "../include/StrokeManager.h"

using namespace std;
using namespace ACCAD;

inline char BlendChannel(char origin, char target, char alpha)
{
    return ((255 - alpha)*origin + alpha * target) >> 8;
}

inline Color Blend(const Color& origin, const Color& target)
{
    return Color(BlendChannel(origin.r, target.r, target.a), BlendChannel(origin.g, target.g, target.a), BlendChannel(origin.b, target.b, target.a), origin.a);
}

void ACCAD::StrokeManager::startDraw()
{
    Hashtable.clear();
    currentStroke = new Stroke();
}

Stroke* ACCAD::StrokeManager::finishDraw()
{
    if (Hashtable.size() == 0)
    {
        delete currentStroke;
        return nullptr;
    } 
    else
    {
        return currentStroke; 
    }
}

void ACCAD::StrokeManager::addPixels(const std::vector<Vec2i> &pixels, const Color & originColor, const Color & targetColor, Image& image)
{
    for (auto pixel : pixels)
    {
        addPixel(pixel, originColor, targetColor, image);
    }
}

void ACCAD::StrokeManager::addPixel(const Vec2i & pixel, const Color & originColor, const Color & targetColor, Image & image)
{
    if (Hashtable.find(pixel) == Hashtable.end())
    {
        currentStroke->addPixel({ pixel,originColor }, { pixel,Blend(originColor,targetColor) });
        image.alterPixel(pixel, Blend(originColor, targetColor));
        Hashtable.insert(pixel);
    }
}

