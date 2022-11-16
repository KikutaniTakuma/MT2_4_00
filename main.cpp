#include <Novice.h>
#include "Vector2D/Vector2D.h"
#include "Matrix3x3/Matrix3x3.h"
#include "MyMath/MyMath.h"

const char kWindowTitle[] = "LC1A_08_キクタニタクマ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Vector2D size = { 200.0f, 100.0f };

	Vector2D leftTop = { size.x / -2.0f, size.y / 2.0f };
	Vector2D leftUnder = { size.x / -2.0f, size.y / -2.0f };
	Vector2D rightTop = { size.x / 2.0f, size.y / 2.0f };
	Vector2D rightUnder = { size.x / 2.0f, size.y / -2.0f };

	Vector2D worldLeftTop;
	Vector2D worldLeftUnder;
	Vector2D worldRightTop;
	Vector2D worldRightUnder;

	Vector2D screenLeftTop;
	Vector2D screenLeftUnder;
	Vector2D screenRightTop;
	Vector2D screenRightUnder;

	Vector2D pos = { 400.0f, 100.0f };

	float spd = 2.0f;

	Matrix3x3 world;

	Matrix3x3 scale;

	Matrix3x3 translate;

	float deg = 0.0f;
	float degSpd = 2.0f;

	Vector2D scaleValue = { 1.0f, 1.0f };
	float magnification = 1.0f;
	float scaleSpd = 0.02f;

	int texture = Novice::LoadTexture("./white1x1.png");

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		if (keys[DIK_W]) {
			pos.y += spd;
		}
		if (keys[DIK_S]) {
			pos.y -= spd;
		}
		if (keys[DIK_A]) {
			pos.x -= spd;
		}
		if (keys[DIK_D]) {
			pos.x += spd;
		}

		translate.MakeTranslate(pos);

		/*deg += degSpd;
		if (deg >= 360.0f) {
			deg = 0.0f;
		}*/

		magnification += scaleSpd;
		if (magnification >= 2.0f || magnification <= 0.5f) {
			scaleSpd *= -1.0f;
		}
		scaleValue = magnification;

		//scaleValue = MyMath::PythagoreanTheorem(pos.x - 400.0f, pos.y - 100.0f);

		scale.MakeScalar(scaleValue);

		world = translate * scale;

		worldLeftTop = leftTop * world;
		worldLeftUnder = leftUnder * world;
		worldRightTop = rightTop * world;
		worldRightUnder = rightUnder * world;

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		MyMath::CoordinateChange(worldLeftTop, screenLeftTop);
		MyMath::CoordinateChange(worldLeftUnder, screenLeftUnder);
		MyMath::CoordinateChange(worldRightTop, screenRightTop);
		MyMath::CoordinateChange(worldRightUnder, screenRightUnder);

		Novice::DrawQuad(
			static_cast<int>(screenLeftTop.x), static_cast<int>(screenLeftTop.y),
			static_cast<int>(screenRightTop.x), static_cast<int>(screenRightTop.y),
			static_cast<int>(screenLeftUnder.x), static_cast<int>(screenLeftUnder.y),
			static_cast<int>(screenRightUnder.x), static_cast<int>(screenRightUnder.y),
			0, 0, 1, 1, texture, WHITE
		);



		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
