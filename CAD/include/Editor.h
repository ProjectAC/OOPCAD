#pragma once

#include <vector>
#include "Vec2.h"
#include "definitions.h"
#include "Figure.h"
#include "Image.h"
#include "Loader.h"
#include "Operation.h"

namespace ACCAD
{
    class Editor
    {
    public:
        /* Alter each pixel to given color
         */
        //void alterPixels(const std::vector<std::pair<Vec2, Color> > &pixels);

        /* Alter all pixels to the same color
         */
        //void alterPixels(const std::vector<Vec2> &pixels, const Color &color);

        /* Start drawing. Save all drawing infomation. 
         */
        void startDraw();

        /* Finish drawing. Construct a Stroke instance and push it into Operation stack. 
         */
        void finishDraw();

        /* Set a start-point.
         */
        void setStartPoint(const Vec2i& from);

        /* Draw from start-point to end-point and set the next start-point as current end-point.
         */
        void movePen(const Vec2i& to);
        
        /* Set current pen.
         */
        void setPen(const Pen& pen);

        /* Insert a figure
         */
        void insertFigure(IFigure *figure);

        /* Alter an Anchor of a figure
         */
        void alterFigure(IFigure *figure, int anchorId, const Vec2 &from, const Vec2 &to);

        /* Erase a figure
         */
        void eraseFigure(IFigure *figure);

    private:
        
        Image image;
        Renderer renderer;
        Loader loader;

        Pen pen;
        Vec2i startPoint;


        /* This is my self-designed Stack,
         * Not STL!!!
         */
        Stack<IOperation> stack; 
    };
}