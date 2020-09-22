#include <DxLib.h>
#include <EffekseerForDXLib.h>
#define SCREEN_SIZE_X 800
#define SCREEN_SIZE_Y 600

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	
	ChangeWindowMode(true);
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);


	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;				// エラーが起きたら直ちに終了
	}

	// 描画先画面を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);
	while (ProcessMessage()==0)
	{
		ClsDrawScreen();


		ScreenFlip();
	}
	DxLib_End();
	return 0;
}	