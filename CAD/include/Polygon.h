#pragma once

#include "Figure.h"
#include <vector>

namespace ACCAD
{
	class Polygon : public IFigure
	{
	public:
        struct Vertices
        {
            float x, y;
        };

	   	/* Render this figure on the Canvas
		 */
		void render() override;

		/* Save this figure to an output stream
		 */ 
		void save(std::ostream &out) override;

        /* Find the nearest
         * 
         */

        /* [Constructor]
         * Construct a polygon with a list of Vertices
         */
        Polygon(std::vector<Vertices> verts);
	};
}