#pragma once
#include "../Vector2.h"
template<class T> Vector2Tmp<T>::Vector2Tmp()
{
	x = 0;
	y = 0;
}

template<class T> Vector2Tmp<T>::Vector2Tmp(T x, T y)
{
	this->x = x;
	this->y = y;
}

// 目的:デカルト座標系での角度を求める
//入力	:x	x座標
//		:y	y座標
template<class T>T Vector2Tmp<T>::calcAngle(T x, T y)
{
	// 0°～90°の時
	if (0 < x && 0 < y)
		return atan(y / x) * 180 / PI;

	// 90°～180°の時  180°～270°の時
	if (x < 0 && 0 < y || x < 0 && y < 0)
		return 180 + atan(y / x) * 180 / PI;
	// 270°～360°の時
	else { return 360 + atan(y / x) * 180 / PI; }
}

//目的	:
//入力	:angle
template<class T>T Vector2Tmp<T>::calcSin(T angle)
{
	return sin(angle * (PI / 180));
}

//目的	:
//入力	:angle
template<class T>T Vector2Tmp<T>::calcCos(T angle)
{
	return cos(angle * (PI / 180));
}

// 目的	:2点間の距離の合成した距離を求める
//入力	:pointA	
//		:pointB
template<class T>T Vector2Tmp<T>::calcTwoPtDisComp(T* pointA, T* pointB)
{
	// 0:x 1:y
	int dissX = pointA[0] + pointB[0];
	int dissY = pointA[1] + pointB[1];
	return sqrtf(dissX * dissX + dissY * dissY);
}

//目的	:x軸の移動量を求める
//入力	:dis		
//		 angle		
template<class T>T Vector2Tmp<T>::calcVecX(T dis, T angle)
{
	double vec = dis * calcCos(angle);
	return vec;
}

//目的	:y軸の移動量を求める
//入力	:dis		
//		 angle		
template<class T>T Vector2Tmp<T>::calcVecY(T dis, T angle)
{
	double vec = dis * calcSin(angle);
	return vec;
}

template<class T>
Vector2Tmp<T>& Vector2Tmp<T>::operator=(const Vector2Tmp& vec2)
{
	// TODO: return ステートメントをここに挿入します
	x = vec2.x;
	y = vec2.y;
	return (*this);
}

template<class T>
Vector2Tmp<T>& Vector2Tmp<T>::operator+=(Vector2Tmp& vec2)
{
	// TODO: return ステートメントをここに挿入します
	this->x += vec2.x;
	this->y += vec2.y;
	return (*this);
}

template<class T>
Vector2Tmp<T>& Vector2Tmp<T>::operator-=(Vector2Tmp& vec2)
{
	// TODO: return ステートメントをここに挿入します
	this->x -= vec2.x;
	this->y -= vec2.y;
	return (*this);
}

template<class T>
Vector2Tmp<T>& Vector2Tmp<T>::operator*=(Vector2Tmp& vec2)
{
	// TODO: return ステートメントをここに挿入します
	this->x *= vec2.x;
	this->y *= vec2.y;
	return (*this);
}

template<class T>
Vector2Tmp<T>& Vector2Tmp<T>::operator/=(Vector2Tmp& vec2)
{
	// TODO: return ステートメントをここに挿入します
	this->x /= vec2.x;
	this->y /= vec2.y;
	return (*this);
}

template<class T>
Vector2Tmp<T>& Vector2Tmp<T>::operator%=(Vector2Tmp& vec2)
{
	// TODO: return ステートメントをここに挿入します
	this->x %= vec2.x;
	this->y %= vec2.y;
	return (*this);
}

template<class T>
inline bool Vector2Tmp<T>::operator==(Vector2Tmp& vec2)
{
	return ((this->x == vec2.x) && (this->y == vec2.y));
}
template<class T>
inline bool Vector2Tmp<T>::operator!=(Vector2Tmp& vec2)
{
	return((this->x != vec2.x) || (this->y != vec2.y));;
}
template<class T>
inline bool Vector2Tmp<T>::operator<(Vector2Tmp& vec2)
{
	return false;
}

template<class T>
inline bool Vector2Tmp<T>::operator<=(Vector2Tmp& vec2)
{
	return((this->x <= vec2.x) || (this->y <= vec2.y));;
}

template<class T>
Vector2Tmp<T> operator+(const Vector2Tmp<T>& vec2, Vector2Tmp<T> vec2_)
{
	// TODO: return ステートメントをここに挿入します
	return { vec2.x + vec2_.x, vec2.y + vec2_.y };
}

template<class T>
Vector2Tmp<T> operator-(const Vector2Tmp<T>& vec2, Vector2Tmp<T> vec2_)
{
	return { vec2.x - vec2_.x, vec2.y - vec2_.y };
}

template<class T>
inline Vector2Tmp<T> operator*(const Vector2Tmp<T>& vec2, Vector2Tmp<T> vec2_)
{
	return { vec2.x * vec2_.x, vec2.y * vec2_.y };
}

template<class T>
inline Vector2Tmp<T> operator/(const Vector2Tmp<T>& vec2, Vector2Tmp<T> vec2_)
{
	return { vec2.x / vec2_.x, vec2.y / vec2_.y };
}

template<class T>
inline Vector2Tmp<T> operator%(const Vector2Tmp<T>& vec2, Vector2Tmp<T> vec2_)
{
	return { vec2.x % vec2_.x, vec2.y % vec2_.y };
}

template<class T>
inline Vector2Tmp<T> operator+(const Vector2Tmp<T>& vec2, T K)
{
	return { vec2.x + K, vec2.y + K };
}

template<class T>
inline Vector2Tmp<T> operator-(const Vector2Tmp<T>& vec2, T K)
{
	return { vec2.x - K, vec2.y - K };
}

template<class T>
inline Vector2Tmp<T> operator*(const Vector2Tmp<T>& vec2, T K)
{
	return { vec2.x * K, vec2.y * K };
}

template<class T>
inline Vector2Tmp<T> operator/(const Vector2Tmp<T>& vec2, T K)
{
	return { vec2.x / K, vec2.y / K };
}

template<class T>
inline Vector2Tmp<T> operator%(const Vector2Tmp<T>& vec2, T K)
{
	return { vec2.x % K, vec2.y % K };
}

template<class T>
inline bool operator==(Vector2Tmp<T>& vec2, T k)
{
	return (vec2.x == k && vec2.y == k);
}

template<class T>
inline bool operator!=(Vector2Tmp<T>& vec2, T k)
{
	return false;
}

template<class T>
inline bool operator<(Vector2Tmp<T>& vec2, T k)
{
	return (vec2.x < k || vec2.y < k);
}

template<class T>
inline bool operator<=(Vector2Tmp<T>& vec2, T k)
{
	return (vec2.x <= k && vec2.y <= k);
}