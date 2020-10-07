#pragma once
#include <cstring>
#include "../math.h"


template<class T>
Matrix3x3Tmp<T> operator* (Matrix3x3Tmp<T> mat1, Matrix3x3Tmp<T> mat2)
{
	Matrix3x3Tmp<T> tmp;
	// Zero clear.
	std::memset(&tmp, 0, sizeof(tmp));

	for (int row = 0; row < 3; row++)
		for (int column = 0; column < 3; column++)
			for (int idx = 0; idx < 3; idx++)
				tmp.index[row][column] += mat1.index[row][idx] * mat2.index[idx][column];

	return tmp;
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
