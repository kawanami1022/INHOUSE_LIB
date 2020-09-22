#include <stdio.h>
#include <stdlib.h>
#include "DxLib.h"
#define SCREEN_SIZE_X 800
#define SCREEN_SIZE_Y 600

const unsigned int color[2] = { 0xffffff,0xff0000 };

void GameInit();
void GameInput();
void GameScene();
void GameDraw();
void GameEnd();
// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);


	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;				// エラーが起きたら直ちに終了
	}
	
	// 描画先画面を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);
	GameInit();
	// ループ
	while (ProcessMessage())
	{
		// 画面を初期化する

		GameScene();
		GameInput();
		GameDraw();

	}


	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;
}

// ｹﾞｰﾑｼｰﾝの初期化
void GameInit()
{
}

// ゲーム入力
void GameInput()
{

}

// ｹﾞｰﾑｼｰﾝ
void GameScene()
{

}

// ｹﾞｰﾑｼｰﾝの描画
void GameDraw()
{
	ClsDrawScreen();
	// 裏画面の内容を表画面に反映させる
	ScreenFlip();
}

void GameEnd()
{
}

