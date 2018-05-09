#pragma once

#include "Figure.h"
#include <vector>

namespace ACCAD
{
	class Ellipse : public IFigure
	{
	public:
	   	/* Render this figure on the Canvas
		 */
		void render() override;

		/* Save this figure to an output stream
		 */ 
		void save(std::ostream &out) override;

        /* [Constructor]
         * Construct an ellipse with a, b, and theta
         */
        Ellipse(float a, float b, float theta);
	};
}