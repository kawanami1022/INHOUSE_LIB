#pragma once
#include "../Geometry2D/Geometry2D.h"

namespace Collision2D
{

template<typename T>
bool IsHitAABB(RectTmp<T>&,RectTmp<T>&);		// check hit rectangle

}

#include "detail/Collision2D.h"


