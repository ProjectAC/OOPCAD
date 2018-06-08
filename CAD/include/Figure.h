#pragma once

#include <iostream>
#include <vector>
#include "definitions.h"
#include "Renderer.h"
#include "Vec2.h"

namespace ACCAD
{
    enum FigureType
    {
        UNKNOWN,
        ELLIPSE,
        POLYGON
    };

    class IFigure
    {
    public:

        /* Render this figure on the Renderer
         */
        virtual void render(Renderer &renderer) = 0;

        /* Save this figure to an output stream
         */ 
        virtual void save(std::ostream &out) = 0;

        /* Load from an input stream to this figure
         */ 
        virtual void load(std::istream &in) = 0;

        /* Returns the TYPE (enum FigureType) of this Figure
         */
        virtual FigureType getType();

        /* Returns the 8 Points of its border
         * e.g, in polar order:
         * 0 - Right,
         * 1 - TopRight, 
         * 2 - Top,
         * 3 - TopLeft,
         * 4 - Left,
         * 5 - BottomLeft
         * 6 - Bottom
         * 7 - BottomRight 
         */
        virtual std::vector<Vec2> getBorder() = 0;

        /* Returns the <id>-th Point of its border
         */
        virtual Vec2 getBorder(int id) = 0;

        /* Rescale by dragging the <id>-th border point to <to>
         * Its opposite point should stay still
         */
        virtual void resize(int id, const Vec2 &to) = 0;

        void rotate(int id, const Vec2 &to);

        void move(const Vec2& from, const Vec2& to);

        virtual bool isInside(const Vec2& point) = 0;

        IFigure(const Vec2 & pos, float theta, const Color &cborder, const Color &cinner);

        virtual IFigure* Clone() = 0;

    protected:

        float theta;
        Vec2 center;
        Color borderColor, innerColor;
        bool updated;
    };
}
