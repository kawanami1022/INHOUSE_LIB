#pragma once
#include "../Geometry2D.h"

template<class T>
RectTmp<T>::RectTmp()
{
	pos_ = Vector2(0, 0);
	width_ = 0;
	hight_ = 0;
}

template<class T>
RectTmp<T>::RectTmp(Vector2Tmp<T> vec, T hight, T width)
{
	pos_=Vector2Tmp<T>(vec.x,vec.y);
	width_ = hight;
	hight_ = width;
}