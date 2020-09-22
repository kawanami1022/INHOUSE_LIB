#include "DxLib.h"
#include "font.h"

void font::DrawStringFromImage(int x, int y,int fontsizeX,int fontsizeY, int extend, const char* str,int *GrHandle)
{
	int dstX = x;					// strのx座標
	int dstY = y;					// strのｙ座標
	int checkCode;					// ASCIIｺｰﾄﾞの確認
	int imageOrder;					// Order of font image
	int sizeStr = static_cast<int>(strlen(str));		// length of a string
	int fontSizeX = fontsizeX * extend;	// ﾌｫﾝﾄ画像のサイズ
	int fontSizeY = fontsizeY * extend;	// ﾌｫﾝﾄ画像のサイズ


	for (int i = 0; i < sizeStr; i++)
	{
		checkCode = static_cast<int>(str[i]);		// check ASCII code of each character of a string 
		imageOrder = checkCode - 32;					// then conver to Font Image order　(-32)

		DrawRotaGraph(dstX + i * fontSizeX, dstY, extend, 0, GrHandle[imageOrder], true);
	}

}