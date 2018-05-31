#pragma once

#include <vector>
#include "definitions.h"
#include "Vec2.h"
#include <Windows.h>

namespace ACCAD
{
    class Renderer
    {
    public:

        /* Initialize the renderer
         * Maybe it'll need a Handle of a window?
         */
        void init(HWND hWnd);

        /* Flush the buffer
         * Then swap buffers
         */
        void flush();

        /* Render a figure
         */
        void render(const Vec2 &center, float theta, const Color &cborder, const Color &cinner, const std::vector<Vec2> &vertices, bool show = false);

        /* Render the background
         */

    //private:

        HWND hWnd;
        HDC hDC;
        HGLRC hRC;
    };
}