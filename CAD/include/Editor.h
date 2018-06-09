#pragma once

#include <vector>
#include "Vec2.h"
#include "definitions.h"
#include "Figure.h"
#include "Image.h"
//#include "Loader.h"
#include "Operation.h"
#include "Brush.h"
#include "AlterManager.h"
#include "StrokeManager.h"
#include "Erasion.h"
#include "Insertion.h"

namespace ACCAD
{
    class Editor
    {
    public:
#pragma region PEN
        /* Pen Operation:
         *   Draw lines of any shapes with the given width by mouse.
         *   During drawing, the image will be changed realtimely by Editor instead of Stroke)
         *   and rerender each frame. After drawing, a Stroke instnce with origin and target 
         *   pixels info will be created. If it's valid, it will be pushed into stack.
         */

        /* Start drawing. 
         */
        void startDraw();

        /* Finish drawing. Construct a Stroke instance and push it into Operation stack if valid. 
         */
        void finishDraw();

        /* Draw from start-point to end-point with current pen.
         */
        void movePen(const Vec2i& from, const Vec2i& to);

        /* Current pen.
         */
        void setPen(const Pen& pen);
        Pen getPen();
#pragma endregion

#pragma region Insertion
        /* Insert Operation:
         *   Insert build-in figure or a polygon created by user.
         *   The same as Pen, the alternation is real-time and is done by Editor instead of Insertion.
         *   After inserting, a Insertion instance will be pushed into stack.
         */

        /* Insert a build-in Figure and set selectedIndex as index of this figure and enter alternation mode.
         * The following two functions in Alter region can be called during alternation mode
         *   + void alterFigure(const Vec2i& from, const Vec2i& to);
         *   + void setAlterMode(const Vec2i& point, MouseKeys mouse);
         * After altering, finishInsert function should be called to stop alternation mode.
         * Note: 
         *   The default AlterMode is Resize, which means calling alterFigure will resize the figure
         *   if setAlterMode isn't called.
         */
        void insertFigure(FigureType figureType, const Vec2i& center, float a = 80, float b = 60);

        /* Finish Insertion and stop alternation mode.
         * Construct a Insertion instance and push it into Operation stack.
         */
        void finishInsert();

        /* Start drawing a polygon by user.
         */
        void startPolygon();

        /* Finish drawing a polygon and enter alternation mode as insertFigure.
         * finishInsert function also should be called to stop alternation mode.
         */
        void finishPolygon();

        /* Add vertex to the drawing polygon.
         * If the vertex is close enough to the vertex[0], finishPolygon will be called automatically.
         */
        void addVertex(const Vec2i& vertex);
#pragma endregion

#pragma region Alter
        /* Alter Operation:
         *   Alter the selected figure.
         *   There are several build-in Alter Modes. In different Alter Mode, alterFigure will do 
         *   different operation. The alterFigure function will also change image.figures realtimely.
         *   Before calling finishAlter, you can calls alterFigure and setAlterMode in any time.
         *   However, after finishAlter called, all alternations will merge and an Altre instance 
         *   will be created.
         */

        enum MouseKeys
        {
            Left,
            Right
        };

        /* Start altering the selected figure.
         * With different mouse keys, the default Alter Mode is different.
         *   + MouseKeys:Left  - AlterMode:Move
         *   + MouseKeys:Right - AlterMode:Vertex
         * Note:
         *   Althought the default AlterMode of Right is Vertex, the anchorID is -1.
         *   setAlterMode also need to be called.
         */
        void startAlter(MouseKeys mouse);

        /* Finish altering the selected figure.
         * Construct a Alter instance and push it into Operation stack if valid.
         */
        void finishAlter();

        /* Alter the selected figure according AlterMode and AnchorID
         */
        void alterFigure(const Vec2i& from, const Vec2i& to);

        /* Set AlterMode and AnchorID according to mouse input.
         * The priority of AlterMode is in the order in which it appears as following.
         *   + Left: 
         *     ++ Resize: a circle whose center is an anchor on border
         *     ++ Rotate: a sector whose center is an anchor in the corner of border
         *     ++ Move: inside figure
         *   + Right:
         *     ++ Vertex: a circle whose center is the an anchor of polygon vertexes
         */
        void setAlterMode(const Vec2i& point, MouseKeys mouse);
#pragma endregion

#pragma region Erasion
        /* Erase the selected figure
         */
        void eraseFigure();
#pragma endregion

        /* Judge whether clicking the given pixel can select a figure.
         * If not, set selectedIndex as -1, else as the index of the figure in image.
         */
        int SelectFigure(const Vec2i& point);

        /* Set and Get the color of figure for insertion
         */
        Color getForegroundColor();
        Color getBackgroundColor();
        void setForegroundColor(const Color& color);
        void setBackgroundColor(const Color& color);

    private:
        Image image;
        /* TODO:
         *   1. render the whole image
         *   2. render the temporary vertexes during creating polygon. (insertBuffer) 
         */
        Renderer renderer;
        Loader loader;
        Pen pen;
        StrokeManager strokeManager;
        AlterManager alterManager;
        Color foreground;
        Color background;
        int selectedIndex;
        std::vector<Vec2> insertBuffer;

        const float AnchorThreshold = 5.0f;
        const float ResizeThreshold = 20.0f;

        /* This is my self-designed Stack,
         * Not STL!!!
         */
        Stack<IOperation> stack; //TODO
    };
}