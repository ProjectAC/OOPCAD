#pragma once

#include <vector>
#include "Vec2.h"
#include "definitions.h"
#include "Figure.h"
#include "Image.h"
#include "Loader.h"
#include "Operation.h"
#include "Brush.h"
#include "AlterManager.h"
#include "StrokeManager.h"

namespace ACCAD
{
    class Editor
    {
    public:
#pragma region PEN
        /* Start drawing. Save all drawing infomation. 
         */
        void startDraw();
        /* Finish drawing. Construct a Stroke instance and push it into Operation stack. 
         */
        void finishDraw();
        /* Draw from start-point to end-point and set the next start-point as current end-point.
         */
        void movePen(const Vec2i& from, const Vec2i& to);
        /* Current pen.
         */
        void setPen(const Pen& pen);
        Pen getPen();
#pragma endregion

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

#pragma region Alter
        enum MouseButton
        {
            Left,
            Right
        };
        /* Start altering the selected figure.
         */
        void startAlter(MouseButton mouse);
        /* Finish altering the selected figure.
         */
        void finishAlter();
        /* Alter the selected figure
         */
        void AlterFigure(const Vec2i& from, const Vec2i& to);

        /* Set AlterMode according to mouse input.
        */
        void setAlterMode(const Vec2i& point, MouseButton mouse);
#pragma endregion

        /* Erase the selected figure
         */
        void eraseSelectedFigure();

        /* Judge whether clicking the given pixel can select a figure.
         * If not, return -1, else return the index of the figure in image.
         */
        int SelectFigure(const Vec2i& point);

    private:
        /* Erase a figure
        */
        void eraseFigure(IFigure* figure);

        Image image;
        Renderer renderer;
        Loader loader;
        
        int selectedIndex;
        Pen pen;
        StrokeManager strokeManager;
        AlterManager alterManager;
        
        /* This is my self-designed Stack,
         * Not STL!!!
         */
        Stack<IOperation> stack; //TODO
    };
}