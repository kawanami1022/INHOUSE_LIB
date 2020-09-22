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
// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);


	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;				// �G���[���N�����璼���ɏI��
	}
	
	// �`����ʂ𗠉�ʂɃZ�b�g
	SetDrawScreen(DX_SCREEN_BACK);
	GameInit();
	// ���[�v
	while (ProcessMessage())
	{
		// ��ʂ�����������

		GameScene();
		GameInput();
		GameDraw();

	}


	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;
}

// �ްѼ�݂̏�����
void GameInit()
{
}

// �Q�[������
void GameInput()
{

}

// �ްѼ��
void GameScene()
{

}

// �ްѼ�݂̕`��
void GameDraw()
{
	ClsDrawScreen();
	// ����ʂ̓��e��\��ʂɔ��f������
	ScreenFlip();
}

void GameEnd()
{
}

