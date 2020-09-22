#pragma once
namespace Physics2D
{
	// �ړI: �d�͂�������
	// velocity_y		: y�̈ړ����x
	// acceleration	: �d�͉����x
	template<typename T>
	T Gravity( T* velocity_y, T acceleration)
	{
		(*velocity_y) += acceleration;
		return (*velocity_y);
	}
	// �ړI: �d�͂�������
	// pos_y			: y���W
	// velocity_y		: y�̈ړ����x
	// acceleration	: �d�͉����x
	template<typename U,typename T>
	U Gravity(U* pos_y,T* velocity_y, T acceleration)
	{
		(*velocity_y) += acceleration;
		(*pos_y) += static_cast<U>(*velocity_y);
		return (*pos_y);
	}

	// �ړI: �d�͂�������
	// pos_y			: y���W
	// stopPoint_y	: �n��
	// velocity_y		: y�̈ړ����x
	// acceleration	: �d�͉����x
	template<typename U, typename T>
	U Gravity(U* pos_y,U stopPoint_y, T* velocity_y, T acceleration)
	{
		U pos_y_copy = (*pos_y);
		(*velocity_y) += acceleration;
		pos_y_copy += static_cast<U>(*velocity_y);
		if ( pos_y_copy>= stopPoint_y)
		{
			(*pos_y)= stopPoint_y;
			(*velocity_y) = 0;
		}
		else {
			(*velocity_y) += acceleration;
			(*pos_y) = pos_y_copy;
		}
		return (*pos_y);
	}

}

using namespace Physics2D;