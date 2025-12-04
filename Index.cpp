#include<stdio.h>
#include<math.h>
#include"DxLib.h"
#include"main.h"
#include<stdlib.h>


FILE* Config_Handle;

void Config_load() {//設定を読み込む機能

	Config_Handle = fopen("config.txt", "r");

	if (Config_Handle == 0)exit(1);
	else {
		char line[256];
		char key[128];
		char value[128];

		while (fgets(line, sizeof(line), Config_Handle)) {
			if (sscanf_s(line, "%127[^:]:%127s", key, (unsigned)_countof(key), value, (unsigned)_countof(value)) == 2) {
				// 5. 項目名(key)に応じて、対応する変数に値を代入
				if (strcmp(key, "WindowSize") == 0) {
					strcpy_s(i.Config_Window_Size, sizeof(i.Config_Window_Size), value);
				}
				else if (strcmp(key, "Life") == 0) {
					strcpy_s(i.Config_Life, sizeof(i.Config_Life), value);
				}
				else if (strcmp(key, "WindowMode") == 0) {
					strcpy_s(i.Config_Window_Mode, sizeof(i.Config_Window_Mode), value);
				}

			}

		}

		fclose(Config_Handle);
		
	}
	p.first_life = atoi(i.Config_Life);//文字として読み取ったものを数値に変換
	i.Full_Screen_Flag = atoi(i.Config_Window_Mode);
	i.Window_Setting = atoi(i.Config_Window_Size);
	Size_Change(i.Window_Setting);
	
	
	
	

	SetGraphMode(i.Window_x, i.Window_y, 32);
	ChangeWindowMode(i.Full_Screen_Flag);
	

}

void FpsTimeFanction() {
	if (FpsTime_i == 0)
		FpsTime[0] = GetNowCount();               //1周目の時間取得
	if (FpsTime_i == 49) {
		FpsTime[1] = GetNowCount();               //50周目の時間取得
		Fps = 50 * 1000.0f / ((FpsTime[1] - FpsTime[0]));//測定した値からfpsを計算
		FpsTime_i = 0;//カウントを初期化
	}
	else
		FpsTime_i++;//現在何周目かカウント
	if (Fps != 0)
		DrawFormatString(i.Play_x, i.Window_y - i.Font_Size, c.Gold, "FPS %.1f", Fps); //fpsを表示
	return;
}


void Clear_Date() {
	//フラグ関連
	printfDx("Loading...");
	memset(pb.flag, 0, sizeof(pb.flag));
	 memset(m.flag, 0, sizeof(m.flag));
	 memset(mb.flag, 0, sizeof(mb.flag));
	 memset(b.flag, 0, sizeof(b.flag));
	 memset(bb.flag, 0, sizeof(bb.flag));
	//プレイヤー関連
	p.x = i.Window_x / 2;
	p.y = i.Window_y / 2;
	p.score = 0;
	p.Power = 1;
	m.Death = 0;





	clsDx();
	i.Mode = 1;//ゲームモードを戻す
}