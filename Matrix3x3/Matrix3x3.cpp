#include "Matrix3x3.h"
#include "Vector2D/Vector2D.h"
#define _USE_MATH_DEFINES
#include <math.h>

Matrix3x3::Matrix3x3()
{
	for (int&& y = 0; y < Matrix3x3::HEIGHT; y++) {
		for (int&& x = 0; x < Matrix3x3::WIDTH; x++) {
			this->m[y][x] = 0.0f;
		}
	}
}

Matrix3x3::Matrix3x3(const Matrix3x3& matrix) {
	*this = matrix;
}

Matrix3x3 Matrix3x3::operator+(const Matrix3x3& Matrix1) {
	Matrix3x3 tmp;

	for (int&& y = 0; y < Matrix3x3::HEIGHT; y++) {
		for (int&& x = 0; x < Matrix3x3::WIDTH; x++) {
			tmp.m[y][x] = this->m[y][x] + Matrix1.m[y][x];
		}
	}

	return tmp;
}

Matrix3x3 Matrix3x3::operator-(const Matrix3x3& Matrix1) {
	Matrix3x3 tmp;

	for (int&& y = 0; y < Matrix3x3::HEIGHT; y++) {
		for (int&& x = 0; x < Matrix3x3::WIDTH; x++) {
			tmp.m[y][x] = this->m[y][x] - Matrix1.m[y][x];
		}
	}

	return tmp;
}

Matrix3x3 Matrix3x3::operator*(const Matrix3x3& Matrix1) {
	Matrix3x3 tmp;
	
	for (int&& y = 0; y < Matrix3x3::HEIGHT; y++) {
		for (int&& x = 0; x < Matrix3x3::WIDTH; x++){
			for (int&& i = 0; i < Matrix3x3::WIDTH; i++) {
				tmp.m[y][x] += this->m[y][i] * Matrix1.m[i][x];
			}
		}
	}

	return tmp;
}

const Matrix3x3& Matrix3x3::operator=(const Matrix3x3& Matrix1) {
	for (int&& y = 0; y < Matrix3x3::HEIGHT; y++) {
		for (int&& x = 0; x < Matrix3x3::WIDTH; x++) {
			this->m[y][x] = Matrix1.m[y][x];
		}
	}

	return *this;
}

const Matrix3x3& Matrix3x3::operator*=(const Matrix3x3& Matrix1) {
	*this = *this * Matrix1;

	return *this;
}

Matrix3x3 Matrix3x3::MakeRotate(float degree) {
	degree *= static_cast<float>(M_PI) / 180.0f;

	this->m[0][0] = cosf(degree);
	this->m[0][1] = sinf(degree);
	this->m[1][0] = -1.0f * sinf(degree);
	this->m[1][1] = cosf(degree);

	this->m[2][2] = 1.0f;

	return *this;
}

Matrix3x3 Matrix3x3::MakeTranslate(const Vector2D& vec) {
	this->m[0][0] = 1.0f;
	this->m[1][1] = 1.0f;
	this->m[2][2] = 1.0f;

	this->m[2][0] = vec.x;
	this->m[2][1] = vec.y;

	return *this;
}
Matrix3x3 Matrix3x3::MakeTranslate(const float& vecX, const float& vecY) {
	this->m[0][0] = 1.0f;
	this->m[1][1] = 1.0f;
	this->m[2][2] = 1.0f;

	this->m[2][0] = vecX;
	this->m[2][1] = vecY;

	return *this;
}

Matrix3x3 Matrix3x3::MakeScalar(const Vector2D& vec) {
	this->m[0][0] = vec.x;
	this->m[1][1] = vec.y;
	this->m[2][2] = 1.0f;

	return *this;
}
Matrix3x3 Matrix3x3::MakeScalar(const float& vecX, const float& vecY) {
	this->m[0][0] = vecX;
	this->m[1][1] = vecY;
	this->m[2][2] = 1.0f;

	return *this;
}

Matrix3x3 Matrix3x3::Affin(const Vector2D& size, float degree, const Vector2D& trancelate) {
	degree *= static_cast<float>(M_PI) / 180.0f;
	
	this->m[0][0] = size.x * cosf(degree);
	this->m[0][1] = size.x * sinf(degree);
	this->m[1][0] = size.y * -1.0f * sinf(degree);
	this->m[1][1] = size.y * cosf(degree);

	this->m[2][0] = trancelate.x;
	this->m[2][1] = trancelate.y;

	this->m[2][2] = 1.0f;
	
	return *this;
}