#pragma once
#include <iostream>
#include <typeinfo>
#include "../../Vector2/Vector2.h"
#include "../Geometry2D.h"
#include "../../Constraint/cast.h"
#include "../../Color/Color.h"

template<class T>
RectTmp<T>::RectTmp()
{
	pos_ = Vector2(0, 0);
	width_ = 0;
	hight_ = 0;
	color_ = {0xff,0xff,0xff,0xff};
	fillFlag_ = false;
}

template<class T>
RectTmp<T>::RectTmp(Vector2Tmp<T> vec, T hight, T width)
{
	pos_=Vector2Tmp<T>(vec.x,vec.y);
	width_ = hight;
	hight_ = width;
	color_ = { 0xff,0xff,0xff,0xff };
	fillFlag_ = false;
}



template<class T>
inline RectTmp<T>::RectTmp(Vector2Tmp<T> vec, T hight, T width, RGBA color)
{
	pos_ = Vector2Tmp<T>(vec.x, vec.y);
	width_ = hight;
	hight_ = width;
	color_ = color;
	fillFlag_ = false;
}

template<class T>
RectTmp<T>::RectTmp(Vector2Tmp<T> vec, T hight, T width, RGBA color,bool FillFlag)
{
	pos_ = Vector2Tmp<T>(vec.x, vec.y);
	width_ = hight;
	hight_ = width;
	color_ = color;
	fillFlag_ = FillFlag;
}

// this function can Draw a rectangle
template<class T>
void RectTmp<T>::Draw(SDL_Renderer* renderer)
{
	fillFlag_ == true ? FillDraw(renderer) : OutlineDraw(renderer);
}

// this function can Draw a rectangle
//bool FillFlag :true fill false outline
template<class T>
void RectTmp<T>::Draw(SDL_Renderer* renderer, bool FillFlag)
{
	FillFlag == true ? FillDraw(renderer) : OutlineDraw(renderer);
}

//  a rectangle Draw FillBox
// SDL_Renderer: 
template<class T>
void RectTmp<T>::FillDraw(SDL_Renderer* renderer)
{
	if (typeid(T) == typeid(int))
	{
		SDL_Rect fillRect = { pos_.x,pos_.y,hight_,width_ };
		SDL_SetRenderDrawColor(renderer, color_.r, color_.g, color_.b, color_.a);
		SDL_RenderFillRect(renderer, &fillRect);
	}

	if (typeid(T) == typeid(float))
	{
		SDL_FRect fillRect = { STCF(pos_.x),STCF(pos_.y),STCF(hight_),STCF(width_) };
		SDL_SetRenderDrawColor(renderer, color_.r, color_.g, color_.b, color_.a);
		SDL_RenderFillRectF(renderer, &fillRect);
	}
}

// a rectangle Draw outline
template<class T>
void RectTmp<T>::OutlineDraw(SDL_Renderer* renderer)
{
	if (typeid(T) == typeid(int))
	{
		SDL_Rect fillRect = { pos_.x,pos_.y,hight_,width_ };
		SDL_SetRenderDrawColor(renderer, color_.r, color_.g, color_.b, color_.a);
		SDL_RenderDrawRect(renderer, &fillRect);
	}

	if (typeid(T) == typeid(float))
	{
		SDL_FRect fillRect = { STCF(pos_.x), STCF(pos_.y), STCF(hight_), STCF(width_) };
		SDL_SetRenderDrawColor(renderer, color_.r, color_.g, color_.b, color_.a);
		SDL_RenderDrawRectF(renderer, &fillRect);
	}
}


