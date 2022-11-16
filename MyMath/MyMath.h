#pragma once

class Vector2D;

class MyMath {
public:
	// ���[���h���W��ϊ����̒萔
	static const int COORDINATE_CHANGE_CONSTANT;

	/*
	���[���h���W���X�N���[�����W�ɕԊ�
	*/
	static void CoordinateChange(const Vector2D& worldPos, Vector2D& screenPos);

	/*
	���[���h���W���X�N���[�����W�ɕԊ�
	*/
	static void CoordinateChange(Vector2D& worldPos);
	/*
	���[���h���W���X�N���[�����W�ɕԊ�
	*/
	static void CoordinateChange(Vector2D& worldPos, const int coordinateChangeConstant);

	/*
	���[���h���W���X�N���[�����W�ɕԊ�
	*/
	static void CoordinateChange(int& worldPos);


	// �O�����̒藝
	static float PythagoreanTheorem(float x, float y);

	// ���K��
	// �����������K�������
	static float Normalize(float x, float y);

	/*
	��`�̓����蔻��
	
	�������F��`�̍�����W
	�������F��`�̃T�C�Y
	��O�����F��`�̍�����W2
	��l�����F��`�̃T�C�Y2

	�߂�l�F�������Ă�F�P
	�@�@�@  �������ĂȂ��F�O
	*/
	static bool CollisionRectangle(Vector2D LeftTop1, Vector2D size1, Vector2D LeftTop2, Vector2D size2);

	/*
	��`�̓����蔻��

	�������F��`�̍�����W
	�������F��`�̃T�C�Y
	��O�����F��`�̍�����W2
	��l�����F��`�̃T�C�Y2

	�߂�l�F�������Ă�F�P
	�@�@�@  �������ĂȂ��F�O
	*/
	static bool CollisionRectangle(int LeftTopX1, int LeftTopY1, int sizeX1, int sizeY1, int LeftTopX2, int LeftTopY2, int sizeX2, int sizeY2);

	/*
	����ւ�

	�������Ƒ����������ւ���
	*/
	template <class T>
	static inline void Tmp(T& x, T& y) {
		T tmp;
		tmp = x;
		x = y;
		y = tmp;
	}


	/*
	�o�u���\�[�g

	�������F�f�[�^
	�������F�f�[�^�̗v�f��
	��O�����Ftrue���������Afalse�傫����
	*/
	static void BubbleSort(int* data, int arr, bool order);

	/*
	����
	*/
	static float Dot(float x1, float y1, float x2, float y2);

	/*
	����
	*/
	static float Dot(Vector2D vec1, Vector2D vec2);

	/*
	�O��
	*/
};