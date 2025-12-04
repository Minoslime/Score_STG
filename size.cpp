#include"main.h"
#include<math.h>
#include"DxLib.h"



void Size_Change(int mode) {//ウィンドウサイズに合わせて様々な数値を変化

	switch (mode) {
	case 2:
		//プレイヤー関連
		p.r *= 2;
		p.normal_speed *= 2;
		p.low_speed *= 2;
		pb.r *= 2;
		pb.speed *= 2;
		//雑魚敵関連
		m.size *= 2;
		Fate_Speed *= 2;
		mb.r *= 2;
		mb.speed *= 2;
		//ボス関連
		b.size *= 2;
		b.speed *= 2;
		bb.Exe_MAX *= 2;
		bb.Exe_Plus *= 2;
		bb.First_r *= 2;
		bb.First_Speed *= 2;
		//オプション関連
		i.Window_x = 1280;
		i.Window_y = 720;
		i.Font_Size *= 2;
		it.size *= 2;
		break;
	case 3:
		//プレイヤー関連
		p.r *= 3;
		p.normal_speed *= 3;
		p.low_speed *= 3;
		pb.r *= 3;
		pb.speed *= 3;
		//雑魚敵関連
		m.size *= 3;
		Fate_Speed *= 3;
		mb.r *= 3;
		mb.speed *= 3;
		//ボス関連
		b.size *= 3;
		b.speed *= 3;
		bb.Exe_MAX *= 3;
		bb.Exe_Plus *= 3;
		bb.First_r *= 3;
		bb.First_Speed *= 3;
		//オプション関連
		i.Window_x = 1920;
		i.Window_y = 1080;
		i.Font_Size *= 3;
		it.size *= 3;
		break;
		
	}
	i.Play_x = i.Window_x * 0.8;
	i.Play_XX = i.Window_x * 0.2;
	SetFontSize(i.Font_Size);
}