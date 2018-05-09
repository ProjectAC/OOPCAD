#pragma once

#include <iostream>

namespace ACCAD
{
	class IFigure
	{
	public:
	   	/* Render this figure on the Canvas
		 */
		virtual void render() = 0;

		/* Save this figure to an output stream
		 */ 
		virtual void save(std::ostream &out) = 0;
	};
}