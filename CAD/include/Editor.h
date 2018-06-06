#pragma once

#include <vector>
#include <unordered_set>
#include "Vec2.h"
#include "definitions.h"
#include "Figure.h"
#include "Image.h"
#include "Loader.h"
#include "Operation.h"
#include "Brush.h"
#include "Alternation.h"
#include "Stroke.h"

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
        /* Draw from start-point to end-point and set the next start-point as current end-point.
         */
        void movePen(const Vec2i& from, const Vec2i& to);
        /* Current pen.
         */
        void setPen(const Pen& pen);
        Pen getPen();

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

        enum AlterMode
        {
            Vertex,
            Border,
        };
        /* Start altering a figure.
         */
        void startAlter(AlterMode alterMode);
        /* Finish altering a figure.
         */
        void finishAlter();
        /* Alter the selected figure
         */
        void AlterFigure(const Vec2i& from, const Vec2i& to);

        /* Erase the selected figure
         */
        void eraseSelectedFigure();

        /* Judge whether clicking the given pixel can select a figure.
         * If not, return -1, else return the index of the figure in image.
         */
        int SelectFigure(const Vec2i& point);
        /* Set the index which refer to the selected figure
         */
        void setSelectedIndex(int index);

    private:
        /* Resize an Anchor of a figure
         */
        void resizeFigure(int figure, int anchorId, const Vec2 &to);
        /* Alter an Anchor of a figure
         */
        void alterFigure(int figure, int anchorId, const Vec2 &to);
        /* Rotate an Anchor of a figure
         */
        void rotateFigure(int figure, int anchorId, const Vec2 &to);

        /* Erase a figure
         */
        void eraseFigure(int figure);

        Image image;
        Renderer renderer;
        Loader loader;
        
        int selectedIndex;
        Pen pen;
        std::vector<Vec2i> tempVertexes;
        std::vector<Vec2i> tempPixels;
        std::unordered_set<Vec2i> globalHashtable;

        Alternation* alter;
        Stroke* stroke;
        
        /* This is my self-designed Stack,
         * Not STL!!!
         */
        Stack<IOperation> stack; 
    };
}