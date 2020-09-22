#pragma once
#include <SDL.h>


struct RGB;
struct RGBA;

template<class T>
class Vector2Tmp;

template <class T >
struct RectTmp
{
	Vector2Tmp<T> pos_;
	T width_;
	T hight_;
	RGBA color_;
	bool fillFlag_;		//bool FillFlag :true fill false outline

	RectTmp();
	RectTmp(Vector2Tmp<T>,T,T);
	RectTmp(Vector2Tmp<T>,T,T,RGBA);
	RectTmp(Vector2Tmp<T>, T, T, RGBA,bool);

	// Getter
	Vector2Tmp<T> Position2()const
	{
		return pos_;
	}

	T Right()const
	{
		return pos_.x + width_;
	}

	T Buttom()const
	{
		return pos_.y + hight_;
	}

	// draw Function
	void Draw(SDL_Renderer*);
	void Draw(SDL_Renderer*, bool FillFlag);
	void FillDraw(SDL_Renderer*);
	void OutlineDraw(SDL_Renderer*);

};


template <class T >
struct CircleTmp
{
	Vector2Tmp<T> vec2;
	T radious;
};

#include "detail/Geometry2D.h"


using Rect = RectTmp<int>;
using RectS = RectTmp<short>;
using RectL = RectTmp<long>;
using RectF = RectTmp<float>;
using RectD = RectTmp<double>;

using Circle = CircleTmp<int>;
using CircleS = CircleTmp<short>;
using CircleL = CircleTmp<long>;
using CircleF = CircleTmp<float>;
using CircleD = CircleTmp<double>;


