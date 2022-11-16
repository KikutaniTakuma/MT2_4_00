#pragma once

class Vector2D;

class MyMath {
public:
	// ワールド座標を変換時の定数
	static const int COORDINATE_CHANGE_CONSTANT;

	/*
	ワールド座標をスクリーン座標に返還
	*/
	static void CoordinateChange(const Vector2D& worldPos, Vector2D& screenPos);

	/*
	ワールド座標をスクリーン座標に返還
	*/
	static void CoordinateChange(Vector2D& worldPos);
	/*
	ワールド座標をスクリーン座標に返還
	*/
	static void CoordinateChange(Vector2D& worldPos, const int coordinateChangeConstant);

	/*
	ワールド座標をスクリーン座標に返還
	*/
	static void CoordinateChange(int& worldPos);


	// 三平方の定理
	static float PythagoreanTheorem(float x, float y);

	// 正規化
	// 第一引数が正規化される
	static float Normalize(float x, float y);

	/*
	矩形の当たり判定
	
	第一引数：矩形の左上座標
	第二引数：矩形のサイズ
	第三引数：矩形の左上座標2
	第四引数：矩形のサイズ2

	戻り値：あたってる：１
	　　　  あたってない：０
	*/
	static bool CollisionRectangle(Vector2D LeftTop1, Vector2D size1, Vector2D LeftTop2, Vector2D size2);

	/*
	矩形の当たり判定

	第一引数：矩形の左上座標
	第二引数：矩形のサイズ
	第三引数：矩形の左上座標2
	第四引数：矩形のサイズ2

	戻り値：あたってる：１
	　　　  あたってない：０
	*/
	static bool CollisionRectangle(int LeftTopX1, int LeftTopY1, int sizeX1, int sizeY1, int LeftTopX2, int LeftTopY2, int sizeX2, int sizeY2);

	/*
	入れ替え

	第一引数と第二引数を入れ替える
	*/
	template <class T>
	static inline void Tmp(T& x, T& y) {
		T tmp;
		tmp = x;
		x = y;
		y = tmp;
	}


	/*
	バブルソート

	第一引数：データ
	第二引数：データの要素数
	第三引数：true小さい順、false大きい順
	*/
	static void BubbleSort(int* data, int arr, bool order);

	/*
	内積
	*/
	static float Dot(float x1, float y1, float x2, float y2);

	/*
	内積
	*/
	static float Dot(Vector2D vec1, Vector2D vec2);

	/*
	外積
	*/
};