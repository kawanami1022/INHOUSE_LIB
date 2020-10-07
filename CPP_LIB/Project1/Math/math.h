#pragma once
#include <cmath>

template<class T>
struct Matrix3x3Tmp
{
	T index[3][3];		// [column][row]
};

//
template<class T>
Matrix3x3Tmp<T> operator*(Matrix3x3Tmp<T> mat1, Matrix3x3Tmp<T> mat2);


// return IdentityMatrix
template<class T>
Matrix3x3Tmp<T> IdentityMat();

// return parallel transfer matrix
//@param x axis moving amount
//@param y axis moving amount
template<class T>
Matrix3x3Tmp<T> TranslateMatrix(T x,T y);

// return rotate matrix
//@param angle: rotation degree
template<class T>
Matrix3x3Tmp<T> RotateMatrix(T angle);



#include "detail/math.h"

