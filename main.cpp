#include<stdio.h>
#include"DxLib.h"
#include"main.h"
#include<string.h>
#include<stdlib.h>



//宣言集
Player p;
Mob m;
Player_Bullet pb;
Mob_Bullet mb;
Color c;
Index i;
BOSS b;
BOSS_Bullet bb;
Sound s;
BOM bo;
BGM bg;
Graph g;
Item it;
int counter = 0;
int FpsTime[2] = { 0, };
int FpsTime_i = 0;
double Fps = 0.0;
int gg = 0;//ゲームスタート選択時のズレ
int o = 0;//オプション選択時のズレ
int d = 0;//プレイデータ選択時の文字ずれ
int e = 0;//終了選択時の文字ずれ
int a = 0;//選択項目の横に赤い丸(y)
int q =0;//循環
int k_1, k_2, k_3, k_4,k_5,title;//曲再生時の文字ずれ
int StartTime; // ループ開始時間
const int FPS = 60; // 目標FPS
const int FRAME_TIME = 1000 / FPS; // 1フレームあたりの時間(ミリ秒)
int Fate_Speed = 5;
int HP = 0;
bool Reset;
bool Pause = false;//一時停止フラグ、trueが一時停止中


void Option() {
	
	DrawFormatString(0, i.Window_y - i.Font_Size, c.Silver, "Zキーで決定、↑↓キーで選択");
	a = q * (i.Window_y / 10) + i.Window_y / 2 + p.r;
	printfDx("%d\n", q);
	DrawFormatString(0, i.Window_y*0.3, c.Purple, "オプションだよ");
	if (CheckHitKey(KEY_INPUT_ESCAPE) == 1 || CheckHitKey(KEY_INPUT_X) == 1) {
		i.Mode = 0;
		q = 0;
	}
	if (i.nowkey[KEY_INPUT_UP] == 1 && i.lastkey[KEY_INPUT_UP] == 0) {
		q = (q - 1) % 4;
	}

	if (i.nowkey[KEY_INPUT_DOWN] == 1 && i.lastkey[KEY_INPUT_DOWN] == 0) {
		q = (q + 1) % 4;
	}
	if (q < 0)q = 3;
	DrawFormatString(i.Window_x * 0.1 + gg, i.Window_y * 0.5, c.White, "BGM:%d",i.Volume_BGM);
	DrawFormatString(i.Window_x * 0.1 + o, i.Window_y * 0.6, c.White, "SE:%d",i.Volume_SE);
	DrawFormatString(i.Window_x * 0.1 + d, i.Window_y * 0.7, c.White, "画面設定をします:%d",i.Full_Screen_Flag);
	DrawFormatString(i.Window_x * 0.1 + e, i.Window_y * 0.8, c.White, "戻る");
	DrawCircle(i.Window_x * 0.2 - i.Font_Size, a, p.r, c.Green, true);
	gg = 0;
	o = 0;
	d = 0;
	e = 0;
	switch (q) {
	case 0:
		gg = i.Window_x * 0.1;
		DrawFormatString(i.Window_x * 0.4, i.Window_y * 0.6, c.Blue, "BGMの音量を調整できます");
		break;
	case 1:
		o = i.Window_x * 0.1;
		DrawFormatString(i.Window_x * 0.4, i.Window_y * 0.6, c.Blue, "効果音の音量を調整できます");
		break;
	case 2:
		d = i.Window_x * 0.1;
		DrawFormatString(i.Window_x * 0.4, i.Window_y * 0.6, c.Blue, "画面モードの変更ができます\n0がフルスクリーン、1がウィンドウモード\n※フルスクリーンでの動作を推奨しています");
		break;
	case 3:
		e = i.Window_x * 0.1;
		DrawFormatString(i.Window_x * 0.4, i.Window_y * 0.6, c.Blue, "タイトルに戻ります");
		break;
	}
	
		switch (q) {
		case 0:
			if (CheckHitKey(KEY_INPUT_RIGHT) == 1)i.Volume_BGM++;
			if (CheckHitKey(KEY_INPUT_LEFT) == 1)i.Volume_BGM--;

			break;
		case 1:
			if (CheckHitKey(KEY_INPUT_RIGHT) == 1)i.Volume_SE++;
			if (CheckHitKey(KEY_INPUT_LEFT) == 1)i.Volume_SE--;
			break;
		case 2:
			if (i.nowkey[KEY_INPUT_RIGHT] == 1 && i.lastkey[KEY_INPUT_RIGHT] == 0)i.Full_Screen_Flag ++;
			if (i.nowkey[KEY_INPUT_LEFT] == 1 && i.lastkey[KEY_INPUT_LEFT] == 0)i.Full_Screen_Flag --;
			if (i.Full_Screen_Flag < 0)i.Full_Screen_Flag = 1;
			if (i.Full_Screen_Flag > 1)i.Full_Screen_Flag = 0;
			if (i.nowkey[KEY_INPUT_Z] == 1 && i.lastkey[KEY_INPUT_Z] == 0) {
				Size_Change(i.Full_Screen_Flag);
				ChangeWindowMode(i.Full_Screen_Flag);
			}
			break;
		case 3:
			if (i.nowkey[KEY_INPUT_Z] == 1 && i.lastkey[KEY_INPUT_Z] == 0) {
				i.Mode = 0;
				q = 0;
			}
			break;
		}
	}


/*
void Play_Date() {
	Load_Play_Date();
	DrawFormatString(0, i.Window_y / 2, c.Purple, "プレイデータを見れるよ");
	if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)i.Mode = 0;
	for (int j = 0; j < 10; j++) {
		DrawFormatString(i.Window_x * 0.3, i.Window_y * 0.1, c.Silver, "プレイ回数:%d", N_Play_Count);
	}
}*/


void Music() {

	DrawFormatString(0, i.Window_y - i.Font_Size, c.Silver, "Zキーで決定、↑↓キーで選択");
	a = q * (i.Window_y / 10) + i.Window_y *0.3 + p.r;
	printfDx("%d\n", q);
	DrawFormatString(i.Window_x/2, 0, c.Purple, "Music Roomだよ");
	if (CheckHitKey(KEY_INPUT_ESCAPE) == 1 || CheckHitKey(KEY_INPUT_X) == 1) {
		i.Mode = 0;
		q = 0;
	}
	if (i.nowkey[KEY_INPUT_UP] == 1 && i.lastkey[KEY_INPUT_UP] == 0) {
		q = (q - 1) % 7;
	}

	if (i.nowkey[KEY_INPUT_DOWN] == 1 && i.lastkey[KEY_INPUT_DOWN] == 0) {
		q = (q + 1) % 7;
	}
	if (q < 0)q = 6;
	DrawFormatString(i.Window_x * 0.1 + k_1, i.Window_y * 0.3, c.White, "曲1:プレステ・ジョアンの黄金境");
	DrawFormatString(i.Window_x * 0.1 + k_2, i.Window_y * 0.4, c.White, "曲2:フォーカラーラビリンス");
	DrawFormatString(i.Window_x * 0.1 + k_3, i.Window_y * 0.5, c.White, "曲3:記憶の深海に沈む少女");
	DrawFormatString(i.Window_x * 0.1 + k_4, i.Window_y * 0.6, c.White, "曲4:ピラミッドの神域");
	DrawFormatString(i.Window_x * 0.1 + k_5, i.Window_y * 0.7, c.White, "曲5:ファンタスティックドリフト");
	DrawFormatString(i.Window_x * 0.1 + title, i.Window_y * 0.8, c.White, "タイトル曲:錦の上の巫女");
	DrawFormatString(i.Window_x * 0.1 + e, i.Window_y * 0.9, c.White, "戻る");
	DrawCircle(i.Window_x * 0.2 - i.Font_Size, a, p.r, c.Green, true);
	k_1 = 0;
	k_2 = 0;
	k_3 = 0;
	k_4 = 0;
	k_5 = 0;
	title = 0;
	e = 0;
	switch (q) {
	case 0:
		k_1 = i.Window_x * 0.1;
		DrawFormatString(i.Window_x * 0.4, i.Window_y * 0.6, c.Blue, "○○な感じで作りました。");
		break;
	case 1:
		k_2 = i.Window_x * 0.1;
		DrawFormatString(i.Window_x * 0.4, i.Window_y * 0.6, c.Blue, "○○な感じで作りました。");
		break;
	case 2:
		k_3 = i.Window_x * 0.1;
		DrawFormatString(i.Window_x * 0.4, i.Window_y * 0.6, c.Blue, "○○な感じで作りました。");
		break;
	case 3:
		k_4 = i.Window_x * 0.1;
		DrawFormatString(i.Window_x * 0.4, i.Window_y * 0.6, c.Blue, "○○な感じで作りました。");
		break;
	case 4:
		k_5 = i.Window_x * 0.1;
		DrawFormatString(i.Window_x * 0.4, i.Window_y * 0.6, c.Blue, "○○な感じで作りました。");
		break;
	case 5:
		title = i.Window_x * 0.1;
		DrawFormatString(i.Window_x * 0.4, i.Window_y * 0.6, c.Blue, "○○な感じで作りました。");
		break;
	case 6:
		e = i.Window_x * 0.1;
		DrawFormatString(i.Window_x * 0.4, i.Window_y * 0.6, c.Blue, "タイトルに戻ります");
		break;
	}

	switch (q) {
	case 0:
		if (CheckHitKey(KEY_INPUT_Z) == 1) {
			if (CheckMusicMem(bg.Game_BGM_1) == 0) {
				StopMusic();
				PlayMusicMem(bg.Game_BGM_1, DX_PLAYTYPE_LOOP);
			}
		}

		break;
	case 1:
		if (CheckHitKey(KEY_INPUT_Z) == 1) {
			if (CheckMusicMem(bg.Game_BGM_2) == 0) {
				StopMusic();
				PlayMusicMem(bg.Game_BGM_2, DX_PLAYTYPE_LOOP);
			}
		}
		break;
	case 2:
		if (CheckHitKey(KEY_INPUT_Z) == 1) {
			if (CheckMusicMem(bg.Game_BGM_3) == 0) {
				StopMusic();
				PlayMusicMem(bg.Game_BGM_3, DX_PLAYTYPE_LOOP);
			}
		}

		break;
	case 3:
		if (CheckHitKey(KEY_INPUT_Z) == 1) {
			if (CheckMusicMem(bg.Game_BGM_4) == 0) {
				StopMusic();
				PlayMusicMem(bg.Game_BGM_4, DX_PLAYTYPE_LOOP);
			}
		}

		break;
	case 4:
		if (CheckHitKey(KEY_INPUT_Z) == 1) {
			if (CheckMusicMem(bg.Game_BGM_5) == 0) {
				StopMusic();
				PlayMusicMem(bg.Game_BGM_5, DX_PLAYTYPE_LOOP);
			}
		}
		break;
	case 5:
		if (CheckHitKey(KEY_INPUT_Z) == 1) {
			if (CheckMusicMem(bg.Title_BGM) == 0) {
				StopMusic();
				PlayMusicMem(bg.Title_BGM, DX_PLAYTYPE_LOOP);
			}
		}
		break;
	case 6:
		if (i.nowkey[KEY_INPUT_Z] == 1 && i.lastkey[KEY_INPUT_Z] == 0) {
			i.Mode = 0;
			q = 0;
		}
		break;
	}
}

int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC) {
	SetOutApplicationLogValidFlag(false);
	Config_load();

	DxLib_Init();
	SetWaitVSyncFlag(false);
	File_Load();
	i.Play_Area = i.Play_x - i.Play_XX;
	while (i.Mode == 100 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		clsDx();
		ClearDrawScreen();
		//エラーハンドリング
		if (g.BOSS_Bullet_Handle[1] == -1) printfDx("BOSS_Bullet_1.bmpが存在しません\t");
		if (g.BOSS_Bullet_Handle[2] == -1) printfDx("BOSS_Bullet_2.bmpが存在しません\n");
		if (g.BOSS_Bullet_Handle[3] == -1) printfDx("BOSS_Bullet_3.bmpが存在しません\t");
		if (g.BOSS_Bullet_Handle[4] == -1) printfDx("BOSS_Bullet_4.bmpが存在しません\n");
		if (g.BOSS_Bullet_Handle[5] == -1) printfDx("BOSS_Bullet_5.bmpが存在しません\t");
		if (g.BOSS_Bullet_Handle[6] == -1) printfDx("BOSS_Bullet_6.bmpが存在しません\n");
		if (g.BOSS_Bullet_Handle[7] == -1) printfDx("BOSS_Bullet_7.bmpが存在しません\t");
		if (g.BOSS_Bullet_Handle[8] == -1) printfDx("BOSS_Bullet_8.bmpが存在しません\n");
		if (g.BOSS_Bullet_Handle[9] == -1) printfDx("BOSS_Bullet_9.bmpが存在しません\t");
		if (g.BOSS_Bullet_Handle[10] == -1) printfDx("BOSS_Bullet_10.bmpが存在しません\n");
		if (g.BOSS_Handle == -1)printfDx("BOSS.bmpが存在しません\t");
		if (g.Player_Handle == -1)printfDx("Player.bmpが存在しません\n");
		if (g.Player_Main_Bullet_Handle == -1)printfDx("Player_Main_Bullet.bmpが存在しません\t");
		if (g.Player_Sub_Bullet_Handle == -1)printfDx("Player_Sub_Bullet.bmpが存在しません\n");
		if (g.Character_Handle == -1)printfDx("Character.bmpが存在しません\t");
		if (g.Mob_Bullet_Handle == -1)printfDx("Mob_Bullet.bmpが存在しません\n");
		if (g.Item == -1)printfDx("Item.bmpが存在しません\t");
		if (g.Mob_Handle == -1)printfDx("Mob.bmpが存在しません\n\n\n");

		if (s.Gameover == -1)printfDx("Gameover.wavが存在しません\t");
		if (s.Item_get == -1)printfDx("Item_Get.wavが存在しません\n");
		if (s.Mob_Death_Sound == -1)printfDx("Kill.wavが存在しません\t");
		if (s.mob_shot == -1)printfDx("Enemy_Shot.wavが存在しません\n");
		if (s.Player_hit == -1)printfDx("Hit.wavが存在しません\t");
		if (s.Power_down == -1)printfDx("Power_Down.wavが存在しません\n");
		if (s.Power_up == -1)printfDx("Power_Up.wavが存在しません\t");
		if (s.Shot_Sound == -1)printfDx("Shot.wavが存在しません\n\n\n");

		if (bg.Game_BGM_1 == -1)printfDx("BGM_1.mp3が存在しません\t");
		if (bg.Game_BGM_2 == -1)printfDx("BGM_2.mp3が存在しません\n");
		if (bg.Game_BGM_3 == -1)printfDx("BGM_3.mp3が存在しません\t");
		if (bg.Game_BGM_4 == -1)printfDx("BGM_4.mp3が存在しません\n");
		if (bg.Game_BGM_5 == -1)printfDx("BGM_5.mp3が存在しません\t");
		if (bg.Title_BGM == -1)printfDx("Title.mp3が存在しません");



		ScreenFlip();
	}


	a = i.Window_y * 0.5+4;
	while (ProcessMessage()==0&&i.Mode<10)
	{
		StartTime = GetNowCount();
		GetHitKeyStateAll(i.nowkey);
		clsDx();
		ClearDrawScreen();
		

		switch (i.Mode) {
		case 0://Title
			if (i.nowkey[KEY_INPUT_ESCAPE] == 1 && i.lastkey[KEY_INPUT_ESCAPE] == 0)i.Mode = 10;
			DrawFormatString(0, i.Window_y - i.Font_Size, c.Silver, "Zキーで決定、↑↓キーで選択");
			a = q * (i.Window_y/10)+i.Window_y/2+p.r;
		
			if (i.nowkey[KEY_INPUT_X] == 1 && i.lastkey[KEY_INPUT_X] == 0 && q == 3)i.Mode = 10;
			if (i.nowkey[KEY_INPUT_X] == 1 && i.lastkey[KEY_INPUT_X] == 0)q = 3;
			
			DrawFormatString(i.Window_x * 0.1+gg, i.Window_y * 0.5, c.White, "ゲームスタート");
			DrawFormatString(i.Window_x * 0.1+o, i.Window_y * 0.6, c.White, "オプション");
			DrawFormatString(i.Window_x * 0.1+d, i.Window_y * 0.7, c.White, "Music Room(実装あきらめ^^;)");
			DrawFormatString(i.Window_x * 0.1+e, i.Window_y * 0.8, c.White, "終了");
			DrawCircle(i.Window_x * 0.2-i.Font_Size, a, p.r, c.Red, true);
			gg = 0;
			o = 0;
			d = 0;
			e = 0;
			if (i.nowkey[KEY_INPUT_UP] == 1 && i.lastkey[KEY_INPUT_UP] == 0) {
				q = (q - 1) % 4;
			}
			
			if (i.nowkey[KEY_INPUT_DOWN] == 1 && i.lastkey[KEY_INPUT_DOWN] == 0) {
				q = (q + 1) % 4;
			}
			if (q < 0)q = 3;
			switch (q) {
			case 0:
				gg = i.Window_x * 0.1;
				DrawFormatString(i.Window_x * 0.4, i.Window_y * 0.6, c.Blue, "ゲームを開始します");
				break;
			case 1:
				o = i.Window_x * 0.1;
				DrawFormatString(i.Window_x * 0.4, i.Window_y * 0.6, c.Blue, "オプションを開きます");
				break;
			case 2:
				d = i.Window_x * 0.1;
				//DrawFormatString(i.Window_x * 0.4, i.Window_y * 0.6, c.Blue, "プレイ中に流れるBGMの設定と試聴が出来ます");
				DrawFormatString(i.Window_x * 0.4, i.Window_y * 0.6, c.Blue, "押しても特に何もありません");
				break;
			case 3:
				e = i.Window_x * 0.1;
				DrawFormatString(i.Window_x * 0.4, i.Window_y * 0.6, c.Blue, "ゲームを終了します");
				break;
			}
			if (i.nowkey[KEY_INPUT_Z] == 1 && i.lastkey[KEY_INPUT_Z] == 0) {
				
				switch (q) {
				case 0:
					i.Mode = 6;
					break;
				case 1:
					i.Mode = 4;
					break;
				case 2:
					i.Mode = 5;
					break;
				case 3:
					i.Mode = 10;
					break;
				}
				q = 0;
			}
			break;
		case 1://Play
			Item_Get();
			Game();
			State_UP();
			Stage();
			Mob_Summon();
			Mob_Update();
			Time();
			Mob_Bullet_Drawing();
			break;
		case 2://リザルト
			break;
		case 3://一時停止
			break;
		case 4://設定
			Option();
			
			break;
		case 5://BGM
			//Music();
			i.Mode = 0;
			break;
		case 6:
			Clear_Date();
			i.Mode = 1;
			break;

		}//場面管理等

		memcpy(i.lastkey, i.nowkey, 256);
		FpsTimeFanction();
		ScreenFlip();
		int WaitTime = (StartTime + FRAME_TIME) - GetNowCount();
		if (WaitTime > 0) {
			WaitTimer(WaitTime); // 処理が早く終わったら、次のフレーム時間まで待機
		}

	}
	
	

	DxLib_End();
	return 0;
}