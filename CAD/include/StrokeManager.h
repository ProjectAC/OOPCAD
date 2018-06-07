#pragma once

#include "Stroke.h"
#include "Brush.h"
#include <vector>
#include <unordered_set>

namespace ACCAD
{
    class StrokeManager
    {
    public:
        /* Start drawing. Create a Stroke instance and maintain it.
         */
        void startDraw();
        /* Finish drawing. Return a pointer to the stroke if it's vaild, or nullptr if it's invalid.
         */
        Stroke* finishDraw();
        /* Add pixels to current stroke, eliminate duplicate pixels and maintain the image.
         */
        void addPixels(const std::vector<Vec2i> &pixels, const Color & originColor, const Color & targetColor, Image& image);
        void addPixel(const Vec2i &pixel, const Color & originColor, const Color & targetColor, Image& image);
    private:
        Stroke * currentStroke;
        std::unordered_set<Vec2i> Hashtable;
    };
}