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
#include "Erasion.h"

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

#pragma region Insertion
        /* Insert a Figure. Set selectedFigure as this figure and enter alternation mode.
         */
        void insertFigure(FigureType figureType, const Vec2i& center);

        /* Start drawing a polygon.
         */
        void startPolygon();
        /* Finish drawing a polygon.
         */
        void finishPolygon();
        /* Add vertex to the drawing polygon.
         */
        void addVertex(const Vec2i& vertex);
#pragma endregion

#pragma region Alter
        enum MouseKeys
        {
            Left,
            Right
        };
        /* Start altering the selected figure.
         */
        void startAlter(MouseKeys mouse);
        /* Finish altering the selected figure.
         */
        void finishAlter();
        /* Alter the selected figure
         */
        void alterFigure(const Vec2i& from, const Vec2i& to);

        /* Set AlterMode according to mouse input.
        */
        void setAlterMode(const Vec2i& point, MouseKeys mouse);
#pragma endregion

#pragma region Erasion
        /* Erase the selected figure
         */
        void eraseSelectedFigure();
#pragma endregion

        /* Judge whether clicking the given pixel can select a figure.
         * If not, return -1, else return the index of the figure in image.
         */
        int SelectFigure(const Vec2i& point);

    private:
        Image image;
        Renderer renderer;
        Loader loader;
        
        int selectedIndex;
        Pen pen;
        StrokeManager strokeManager;
        AlterManager alterManager;

        const float anchorThreshold = 5.0f;
        const float resizeThreshold = 20.0f;
        /* This is my self-designed Stack,
         * Not STL!!!
         */
        Stack<IOperation> stack; //TODO
    };
}