#include <math.h>
#include "..\include\Utility.h"

using namespace ACCAD;
Vec2 ACCAD::Vec2Rotate(const Vec2 & center, const Vec2 & point, float theta)
{
	float tempX = point.x - center.x;
	float tempY = point.y - center.y;
	return Vec2(cos(theta)*tempX - sin(theta)*tempY + center.x, sin(theta)*tempX + cos(theta)*tempY + center.y);
}
