#include<stdio.h>
#include"main.h"
#include"DxLib.h"

char* High_Score[256];
FILE* Play_date_Handle;
int Playcount = 0;
char MAX_SCORE[256];
char Play_Count[256];
int N_High_Score[256];
int N_MAX_SCORE;
int N_Play_Count=0;

void Load_Play_Date() {
	Play_date_Handle = fopen("Player_Date.txt", "r");
	if (Play_date_Handle == 0)i.Mode=0;
	if (Play_date_Handle != 0) {
		char Date_line[256]; // 1行を読み込むためのバッファ
		char Date_key[128];  // 設定項目名を格納する変数
		char* Date_value;      // 設定値を格納する変数
		char Date_Line[256];
		int score_index = 0;
		// 3. ファイルの終端まで1行ずつループ
		while (fgets(Date_line, sizeof(Date_line), Play_date_Handle) && score_index < 256) {
			char Date_key[128];
			char Date_value[128];

			// "キー:値" の形式で読み取る (例: "スコア:12345")
			if (sscanf_s(Date_line, "%127[^:]:%127s", Date_key, (unsigned)_countof(Date_key), Date_value, (unsigned)_countof(Date_value)) == 2) {

				if (strcmp(Date_key, "プレイ回数") == 0) {
					strcpy_s(Play_Count, sizeof(Play_Count), Date_value);
				}
				else if (strcmp(Date_key, "スコア") == 0) {
					// High_Scoreはポインタの配列なので、文字列を格納するためのメモリを確保してコピーします
					// _strdup は文字列を複製して新しいメモリ領域を確保する便利な関数です
					High_Score[score_index] = _strdup(Date_value);
					if (High_Score[score_index] != NULL) {
						score_index++; // 次のスコアのためにインデックスを増やす
					}
				}
			}
		}
		// 6. ファイルを閉じる
		fclose(Play_date_Handle);

		N_MAX_SCORE = 0;
		for (int i = 0; i < score_index; i++) {
			N_High_Score[i] = atoi(High_Score[i]); // 文字列を整数に変換
			if (N_MAX_SCORE < N_High_Score[i]) {
				N_MAX_SCORE = N_High_Score[i];
				// 最大スコアの文字列も更新
				strcpy_s(MAX_SCORE, sizeof(MAX_SCORE), High_Score[i]);
			}


		}
	}
	N_Play_Count = atoi(Play_Count);
	N_MAX_SCORE = atoi(MAX_SCORE);

}


void File_Load() {
	DrawFormatString(0, 0, c.Red, "Loading...");
	//画像データ
	g.Player_Handle = LoadGraph("Graph\\Player.bmp");
	g.Player_Main_Bullet_Handle = LoadGraph("Graph\\Player_Main_Bullet.bmp");
	g.Player_Sub_Bullet_Handle = LoadGraph("Graph\\Player_Sub_Bullet.bmp");
	g.Character_Handle = LoadGraph("Graph\\Character.bmp");
	g.Mob_Handle = LoadGraph("Graph\\Mob.bmp");
	g.Mob_Bullet_Handle = LoadGraph("Graph\\Mob_Bullet.bmp");
	g.BOSS_Handle = LoadGraph("Graph\\BOSS.bmp");
	g.BOSS_Bullet_Handle[1] = LoadGraph("Graph\\BOSS_Bullet_1.bmp");
	g.BOSS_Bullet_Handle[2] = LoadGraph("Graph\\BOSS_Bullet_2.bmp");
	g.BOSS_Bullet_Handle[3] = LoadGraph("Graph\\BOSS_Bullet_3.bmp");
	g.BOSS_Bullet_Handle[4] = LoadGraph("Graph\\BOSS_Bullet_4.bmp");
	g.BOSS_Bullet_Handle[5] = LoadGraph("Graph\\BOSS_Bullet_5.bmp");
	g.BOSS_Bullet_Handle[6] = LoadGraph("Graph\\BOSS_Bullet_6.bmp");
	g.BOSS_Bullet_Handle[7] = LoadGraph("Graph\\BOSS_Bullet_7.bmp");
	g.BOSS_Bullet_Handle[8] = LoadGraph("Graph\\BOSS_Bullet_8.bmp");
	g.BOSS_Bullet_Handle[9] = LoadGraph("Graph\\BOSS_Bullet_9.bmp");
	g.BOSS_Bullet_Handle[10] = LoadGraph("Graph\\BOSS_Bullet_10.bmp");
	g.Item = LoadGraph("Graph\\Item.bmp");
	//効果音
	s.Gameover = LoadSoundMem("Sound\\Gameover.wav");
	s.Item_get = LoadSoundMem("Sound\\Item_Get.wav");
	s.Mob_Death_Sound = LoadSoundMem("Sound\\Kill.wav");
	s.mob_shot = LoadSoundMem("Sound\\Enemy_Shot.wav");
	s.Player_hit = LoadSoundMem("Sound\\Hit.wav");
	s.Power_down = LoadSoundMem("Sound\\Power_Down.wav");
	s.Power_up = LoadSoundMem("Sound\\Power_Up.wav");
	s.Shot_Sound = LoadSoundMem("Sound\\Shot.wav");
	//BGM
	bg.Game_BGM_1 = LoadMusicMem("BGM\\BGM_1.mp3");
	bg.Game_BGM_2 = LoadMusicMem("BGM\\BGM_2.mp3");
	bg.Game_BGM_3 = LoadMusicMem("BGM\\BGM_3.mp3");
	bg.Game_BGM_4 = LoadMusicMem("BGM\\BGM_4.mp3");
	bg.Game_BGM_5 = LoadMusicMem("BGM\\BGM_5.mp3");
	bg.Title_BGM = LoadMusicMem("BGM\\Title.mp3");
	


	if (g.Player_Handle == -1 || g.Player_Main_Bullet_Handle == -1 || g.Player_Sub_Bullet_Handle == -1 ||
		g.Character_Handle == -1 || g.Mob_Handle == -1 || g.Mob_Bullet_Handle == -1 || g.BOSS_Handle == -1 ||
		g.BOSS_Bullet_Handle[1] == -1 || g.BOSS_Bullet_Handle[2] == -1 || g.BOSS_Bullet_Handle[3] == -1 ||
		g.BOSS_Bullet_Handle[4] == -1 || g.BOSS_Bullet_Handle[5] == -1 || g.BOSS_Bullet_Handle[6] == -1 ||
		g.BOSS_Bullet_Handle[7] == -1 || g.BOSS_Bullet_Handle[8] == -1 || g.BOSS_Bullet_Handle[9] == -1 ||
		g.BOSS_Bullet_Handle[10] == -1 || s.Gameover == -1 || s.Item_get == -1 || s.Mob_Death_Sound == -1 ||
		s.mob_shot == -1 || s.Player_hit == -1 || s.Power_down == -1 || s.Power_up == -1 ||
		s.Shot_Sound == -1 || bg.Game_BGM_1 == -1 || bg.Game_BGM_2 == -1 || bg.Game_BGM_3 == -1 ||
		bg.Game_BGM_4 == -1 || bg.Game_BGM_5 == -1 || bg.Title_BGM == -1||g.Item==-1)
	{
		i.Mode = 100;
	}
}

