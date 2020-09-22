#pragma once
#include <algorithm>
#include "../Collision2D.h"

template<typename T>
bool Collision2D::IsHitAABB(RectTmp<T>& rect1, RectTmp<T>& rect2)
{
	return ((std::max(rect1.Position2().x, rect2.Position2().x) < std::min(rect1.Right(), rect2.Right()))
			&& std::max(rect1.Position2().y, rect2.Position2().y) < std::min(rect1.Buttom(), rect2.Buttom()));
}