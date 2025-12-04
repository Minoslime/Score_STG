#include "DxLib.h"
#include"main.h"

// 各キャラの中心を基準に描画するための補正関数。
void DrawGra_Bullet(int x, int y, int GrHandle, int TransFlag)
{
	int w, h;
	GetGraphSize(GrHandle, &w, &h);
	DrawGraph(x-w/2, y-h/2, GrHandle, TransFlag);
}

void DrawGra_Item(int x, int y, int GrHandle, int TransFlag)
{
	int w, h;
	GetGraphSize(GrHandle, &w, &h);
	DrawExtendGraph(x - w / 2, y - h / 2,x-(w/2)+it.size,y-(h/2)+it.size, GrHandle, TransFlag);
}

void DrawGra_Mob(int x, int y, int GrHandle, int TransFlag)
{
	int w, h;
	GetGraphSize(GrHandle, &w, &h);
	DrawExtendGraph(x - w / 2, y - h / 2,x-(w/2)+m.size,y-(h/2)+m.size, GrHandle, TransFlag);
}

void DrawGra_Mob_Bullet(int x, int y, int GrHandle, int TransFlag)
{
	int w, h;
	GetGraphSize(GrHandle, &w, &h);
	DrawExtendGraph(x - w / 2, y - h / 2, x - (w / 2) + mb.r, y - (h / 2) + mb.r, GrHandle, TransFlag);
}