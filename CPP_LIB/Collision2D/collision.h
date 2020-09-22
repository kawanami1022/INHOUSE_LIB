//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
#include <iostream>
#include <math.h>
#include <utility>
#include "collision.h"

using namespace std;

struct LINE
{
	float x_f;
	float y_f;
	float sloap;	// �X��
};

enum COLL_ID
{
	COLL_ID_X,
	COLL_ID_Y,
	COLL_ID_MAX,
};

#ifndef _COLLISION_H_
#define _COLLISION_H_

//�ړI  :2�̋�`�̏Փ˔���
template <class T>
bool collisionRect(T* Rect1UL, T* Rect1DR, T* Rect2UL, T* Rect2DR);

//�ړI�@:2�̉~�̏Փ˔���
template <class T>
bool collisionCircle(T* C1Point, T C1Radious, T* C2Point, T C2Radious);

//�ړI:�����̌X�������߂�
template <class T>
float getlineSloap(T* LPoint1, T* LPoint2);

//�ړI:2�̌�_�����߂�
template <class T>
float *lineIntersect(T* L1Point, T L1Sloap, T* L2Point, T L2Sloap);

//�ړI	:�_�����̒��ɂ��邩����
template <class T>
bool checkPToLIntersect(T* LPoint1, T* LPoint2, T* CPoint);

//�ړI	;�_����`�̒����݂��Ă邩����
template <class T>
bool checkPInRect(T* Point, T* RectUL, T* RectDR);

//�ړI:�����̓����蔻��
template <class T>
bool collisionLine(T* Point1A, T* Point2A, T* Point1B, T* Point2B);



//�ړI  :2�̋�`�̏Փ˔���
//����	:Rect1UL	��1��`�̍���	
//		:Rect1DR	��1��`�̉E��
//		:Rect2UL	��2��`�̍���
//		:Rect2DR	��2��`�̉E��
template <class T>
bool collisionRect(T* Rect1UL, T* Rect1DR, T* Rect2UL, T* Rect2DR)
{
	if (Rect1UL[0] < Rect2DR[0] && Rect2UL[0] < Rect1DR[0]
		&& Rect1UL[1] < Rect2DR[1] && Rect2UL[1] < Rect1DR[1])
	{
		return true;
	}
	return false;
}


//�ړI�@:2�̉~�̏Փ˔���
//����  :C1Point	��1�~�̍��W
//      :C1Radious  ��1�~�̔��a
//      :C2Point	��2�~�̍��W
//      :C2Radious	��2�~�̔��a
template <class T>
bool collisionCircle(T* C1Point, T C1Radious, T* C2Point, T C2Radious)
{
	T temp[2] = { 0,0 };
	// 2�_�Ԃ�x������
	temp[0] = (fabsf)((C1Point[0] - C2Point[0]) * (C1Point[0] - C2Point[0]));
	// 2�_�Ԃ�y������
	temp[1] = (fabsf)((C1Point[1] - C2Point[1]) * (C1Point[1] - C2Point[1]));

	if ((C1Radious + C2Radious) * (C1Radious + C2Radious) < (temp[0] + temp[1]))
	{
		return true;
	}
	return false;
}

//�ړI�@:�X�������߂�
//���́@:LPoint1 �_1
//		:LPoint2 �_2
template <class T>
float getlineSloap(T* LPoint1, T* LPoint2)
{

	return (LPoint2[1] - LPoint1[1]) / (LPoint2[0] - LPoint1[0]);
}

//�ړI	:2�̌�_�����߂�
//����	:L1Point ��1�̒������2D�̓_
//		:L1Sloap ��1�̒����̌X��
//		:L2Point ��2�̒������2D�̓_
//		:L2Sloap ��2�̒����̌X��
template <class T>
float* lineIntersect(T* L1Point, T L1Sloap, T* L2Point, T L2Sloap)
{
	float temp[2] = { 0,0 };

	// ��_��x�������߂�
	temp[0] = (L1Sloap * L1Point[0] - L2Sloap * L2Point[0] + L2Point[1] - L1Point[1]) / (L1Sloap - L2Sloap);
	// ��_��y�������߂�
	temp[1] = L2Sloap * (temp[0] - L2Point[0]) + L2Point[1];
	return temp;
}

//�ړI	:�_�����̒��ɂ��邩����
//����	:LPoint1 �����̍��W(�ړ���)
//		:LPoint2 �����̍��W(�ړ���)
//		:CPoint  ��_
template <class T>
bool checkPToLIntersect(T* LPoint1, T* LPoint2, float* CPoint)
{
	// �ړ���̂ق����傫���ꍇ���g�������ւ���
	if (LPoint2[COLL_ID_X] < LPoint1[COLL_ID_X]) { swap(LPoint1[COLL_ID_X], LPoint2[COLL_ID_X]); }
	if (LPoint2[COLL_ID_Y] < LPoint1[COLL_ID_Y]) { swap(LPoint1[COLL_ID_Y], LPoint2[COLL_ID_Y]); }

	if (LPoint1[COLL_ID_X] < CPoint[COLL_ID_X] && CPoint[COLL_ID_X] < LPoint2[COLL_ID_X]
		&& LPoint1[COLL_ID_Y] < CPoint[COLL_ID_Y] && CPoint[COLL_ID_Y] < LPoint2[COLL_ID_Y])
	{
		return true;
	}
	return false;
}

//�ړI	;�_����`�̒����݂��Ă邩����
//����	:Point	�_�̍��W
//		:RectUL	��`����̍��W
//		:RectDR ��`�E��
template <class T>
bool checkPInRect(T* Point, T* RectUL, T* RectDR)
{
	if (RectUL[COLL_ID_X] < Point[COLL_ID_X] &&
		Point[COLL_ID_X] < RectDR[COLL_ID_X] &&
		RectUL[COLL_ID_Y] < Point[COLL_ID_Y] &&
		Point[COLL_ID_Y] < RectDR[COLL_ID_Y])
	{
		return true;
	}
	return false;
}

//�ړI	:�����̓����蔻��
//����	:Point1A ��1�̓_(�ړ���)
//		:Point2A ��1�̓_(�ړ���)
//		:Point1B ��2�̓_(�ړ���)
//		:Point2B ��2�̓_(�ړ���)
template <class T>
bool collisionLine(T* Point1A, T* Point2A, T* Point1B, T* Point2B)
{
	LINE line[2] = { 0,0 };
	T crossPoint[2] = { 0,0 };

	// ��A�̌X��
	line[0].sloap = getlineSloap(Point1A, Point2A);
	// ��B�̌X��
	line[1].sloap = getlineSloap(Point1B, Point2B);

	*crossPoint = *lineIntersect(Point1A, line[0].sloap, Point1B, line[1].sloap);
	//crossPoint[1] = lineIntersect(Point1A, line[0].sloap, Point1B, line[1].sloap)[1];


	//----���肷��
	if (checkPToLIntersect(Point1A, Point2A, crossPoint)
		&& checkPToLIntersect(Point1B, Point2B, crossPoint))
	{
		return true;
	}

	return false;
}

#endif