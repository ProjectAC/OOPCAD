#pragma once

#include <vector>

namespace ACCAD
{
    class Renderer
    {
    public:

        /* Initialize the renderer
		 * Maybe it'll need a Handle of a window?
         */
        void init();

        /* Render a figure
         */
        void render(const Color &color, const std::vector<int> &vertices);
    };
}