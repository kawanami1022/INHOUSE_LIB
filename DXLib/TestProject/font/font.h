#pragma once
namespace font
{

// Draw Font from Font Image  ( x座標,y座標,拡大縮小,string)
void DrawStringFromImage(int x, int y, int fontsizeX, int fontsizeY, int extend, const char* str, int* GrHandle);		


}