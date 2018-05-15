#pragma once
#include "definitions.h"

namespace ACCAD
{
	/* Rotate a point around a center anti-clockwise.
	   The unit of theta is radians.
	 */
	Vec2 Vec2Rotate(const Vec2 & center, const Vec2 & point, float theta);
}

