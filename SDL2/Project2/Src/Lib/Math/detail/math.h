#pragma once
#include "../math.h"


template<class T>
Matrix3x3Tmp<T> operator* (Matrix3x3Tmp<T> mat1, Matrix3x3Tmp<T> mat2)
{
	auto tmpMatrix;
	tmpMatrix.index[0][0] = mat1.index[0][0] * mat2.index[0][0];
	tmpMatrix.index[0][0] = mat1.index[1][0] * mat2.index[0][1];
	tmpMatrix.index[0][0] = mat1.index[2][0] * mat2.index[0][2];

	tmpMatrix.index[0][0] = mat1.index[0][1] * mat2.index[1][0];
	tmpMatrix.index[0][0] = mat1.index[1][1] * mat2.index[1][1];
	tmpMatrix.index[0][0] = mat1.index[2][1] * mat2.index[1][2];

	tmpMatrix.index[0][0] = mat1.index[0][2] * mat2.index[0][0];
	tmpMatrix.index[0][0] = mat1.index[1][2] * mat2.index[0][0];
	tmpMatrix.index[0][0] = mat1.index[2][2] * mat2.index[0][0];

	return tmpMatrix;
}

template<class T>
inline Matrix3x3Tmp<T> IdentityMat()
{
	return { { 1,0,0 },
			{ 0,1,0 },
			{ 0,0,1 } };
}

template<class T>
inline Matrix3x3Tmp<T> TranslateMatrix(T x, T y)
{
	return Matrix3x3Tmp<T>();
}

template<class T>
inline Matrix3x3Tmp<T> RotateMatrix(T angle)
{
	return Matrix3x3Tmp<T>();
}
