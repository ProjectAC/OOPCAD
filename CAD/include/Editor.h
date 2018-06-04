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
        void setPen(const Pen*& pen);

        /* Insert an ellipse. Set selectedFigure as this figure and enter alternation mode.
         * finishAlter should be called after calling this function.
         */
        void insertEllipse(const Vec2i& center);
        /* Insert an rectangle and set selectedFigure as this figure and enter alternation mode.
         * finishAlter should be called after calling this function.
         */
        void insertRectangle(const Vec2i& center);

        /* Start drawing a polygon.
         */
        void startPolygon();
        /* Finish drawing a polygon.
        */
        void finishPolygon();
        /* Add vertex to the drawing polygon.
        */
        void addVertex(const Vec2i& vertex);

        /* Start altering a figure. In the alternation mode, you can do resize, alter vertex (only for polygon) and rotate for figure.
         */
        void startAlter();
        /* Finish resizing a figure.
        */
        void finishAlter();
        /* Resize an Anchor of a figure
         */
        void resizeFigure(IFigure *figure, int anchorId, const Vec2 &to);
        /* Alter an Anchor of a figure
        */
        void alterFigure(Polygon *figure, int anchorId, const Vec2 &to);
        /* Rotate an Anchor of a figure
        */
        void rotateFigure(IFigure *figure, int anchorId, const Vec2 &to);

        /* Erase a figure
         */
        void eraseFigure(IFigure *figure);

        /* Erase the selected figure
         */
        void eraseSelectedFigure();

    private:
        
        Image image;
        Renderer renderer;
        Loader loader;

        Pen pen;
        Vec2i startPoint;
        IFigure* selectedFigure;

        /* This is my self-designed Stack,
         * Not STL!!!
         */
        Stack<IOperation> stack; 
    };
}