#pragma once

#include "Alternation.h"

namespace ACCAD
{
    class AlterManager 
    {
    public:
        enum AlterMode
        {
            None,
            Vertex,
            Resize,
            Rotate,
            Move,
        };

        AlterManager(Image& image);

        /* Start altering a figure.
        */
        void startAlter(int index, AlterMode alterMode);
        /* Finish altering a figure.
        */
        Alternation * finishAlter();

        /* Set AlterMode and the selected anchor.
        */
        void setAlterMode(AlterMode alterMode, int anchorID);

        /* Alter the figure according to alter mode and anchor selected.
        * If alterMode is None, then no alternation will be done.
        */
        void AlterFigure(const Vec2i& from, const Vec2i& to);

        /* Get active anchors according to alter mode and figure selected
        */
        std::vector<Vec2> getAnchors();

    private:
        Alternation * currentAlter;
        Image * image;
        bool isDirty;
        int index;
        AlterMode alterMode;
        int anchorID;
    };
}
