#include<stdio.h>
#include"DxLib.h"
#include"main.h"
#include<math.h>


void Score(int a) {//aは加減算の状況
	switch (a) {
	case 0://ヒット
		p.score += 10;
		break;
	case 1://撃破
		p.score += 50 * HP;
		break;
	case 2://被撃破
		break;
	case 3://アイテム取得
		break;
	case 4://ボス撃破
		break;
	case 5://グレイズ
		break;
		

	}

}