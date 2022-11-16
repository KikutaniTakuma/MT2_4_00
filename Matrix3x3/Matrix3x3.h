#pragma once

class Vector2D;

class Matrix3x3 {
public:
	Matrix3x3();
	Matrix3x3(const Matrix3x3& matrix);
	inline ~Matrix3x3(){}

private:
	static const int HEIGHT = 3;
	static const int WIDTH = 3;

public:
	float m[HEIGHT][WIDTH];

	Matrix3x3 operator+(const Matrix3x3& Matrix1);
	Matrix3x3 operator-(const Matrix3x3& Matrix1);
	Matrix3x3 operator*(const Matrix3x3& Matrix1);
	const Matrix3x3& operator=(const Matrix3x3& Matrix1);
	const Matrix3x3& operator*=(const Matrix3x3& Matrix1);

	// ��]�s��
	Matrix3x3 MakeRotate(float degree);

	// ���s�ړ��s��
	Matrix3x3 MakeTranslate(const Vector2D& vec);
	Matrix3x3 MakeTranslate(const float& vecX, const float& vecY);

	// �X�J���[�{�s��
	Matrix3x3 MakeScalar(const Vector2D& vec);
	Matrix3x3 MakeScalar(const float& vecX, const float& vecY);

	// �A�t�B���ϊ�
	Matrix3x3 Affin(const Vector2D& size, float degree, const Vector2D& trancelate);
};