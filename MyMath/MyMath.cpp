#include "MyMath/MyMath.h"
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Vector2D/Vector2D.h"

const int MyMath::COORDINATE_CHANGE_CONSTANT = 500;

void MyMath::CoordinateChange(const Vector2D& worldPos, Vector2D& screenPos) {
	screenPos.x = worldPos.x;
	screenPos.y = (worldPos.y * -1) + COORDINATE_CHANGE_CONSTANT;
}

void MyMath::CoordinateChange(Vector2D& worldPos) {
	worldPos.y = (worldPos.y * -1) + COORDINATE_CHANGE_CONSTANT;
}

void MyMath::CoordinateChange(Vector2D& worldPos, const int coordinateChangeConstant) {
	worldPos.y = (worldPos.y * -1) + coordinateChangeConstant;
}

void MyMath::CoordinateChange(int& worldPos) {
	worldPos = (worldPos * -1) + COORDINATE_CHANGE_CONSTANT;
}

bool MyMath::CollisionRectangle(Vector2D LeftTop1, Vector2D size1, Vector2D LeftTop2, Vector2D size2) {
	if (LeftTop1.x < LeftTop2.x + size2.x && LeftTop2.x < LeftTop1.x + size1.x) {
		if (LeftTop1.y < LeftTop2.y - size2.y && LeftTop2.y < LeftTop1.y - size1.y) {
			return true;
		}
	}
	return false;
}

bool MyMath::CollisionRectangle(int LeftTopX1, int LeftTopY1, int sizeX1, int sizeY1, int LeftTopX2, int LeftTopY2, int sizeX2, int sizeY2) {
	if (LeftTopX1 < LeftTopX2 + sizeX2 && LeftTopX2 < LeftTopX1 + sizeX1) {
		if (LeftTopY1 < LeftTopY2 + sizeY2 && LeftTopY2 < LeftTopY1 + sizeY1) {
			return true;
		}
	}
	return false;
}

float MyMath::PythagoreanTheorem(float x, float y) {
	return sqrtf(powf(x, 2.0f) + powf(y, 2.0f));
}

float MyMath::Normalize(float x, float y) {
	return x / MyMath::PythagoreanTheorem(x, y);
}

void MyMath::BubbleSort(int* data, int arr, bool order) {
	for (int i = 0; i < arr - 1; i++) {
		for (int j = arr - 1; j > i; j--) {
			if (order == true) {
				if (data[j - 1] > data[j]) {
					MyMath::Tmp(data[j], data[j - 1]);
				}
			}
			else if (order == false) {
				if (data[j - 1] < data[j]) {
					MyMath::Tmp(data[j], data[j - 1]);
				}
			}
		}
	}
}

float MyMath::Dot(float x1, float y1, float x2, float y2) {
	return (x1 * x2) + (y1 * y2);
}

float MyMath::Dot(Vector2D vec1, Vector2D vec2) {
	return (vec1.x * vec2.x) + (vec1.y * vec2.y);
}