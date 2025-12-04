#pragma once
#include"DxLib.h"


const int MAX_MOB = 100;
const int MAX_Player_Bullet = 200;
const int MAX_Mob_Bullet = 200;
const int MAX_BOSS_Bullet = 200;
const int MAX_BOSS = 50;
extern int counter;
extern int FpsTime[2];
extern int FpsTime_i;
extern double Fps;



struct Player {
public:
	double x;
	double y;
	int Life = 3;
	int first_life = 0;
	int Bom = 0;
	int normal_speed = 10;//通常移動時の速度
	int low_speed = 3;//低速移動時の速度
	int r=6;//size
	int hit_flag = 0;//0のとき被弾可能
	int flag = 0;//1のとき表示
	int cool_time;
	int angle = 1;//4方向の管理
	int Power = 1;
	int score = 0;//スコア
};
extern Player p;

struct Mob {
public:
	double x[MAX_MOB];
	double y[MAX_MOB];
	int  size = 20;//四角のため
	int flag[MAX_MOB];
	int speed[MAX_MOB];
	int Type[MAX_MOB];//弾を発射する敵かどうか
	int Death = 0;//撃破数をカウント
	int Summon_Limit = 0;//最大出現数を設定
	int Shot_Cool[MAX_MOB];//ショットクールタイム
	int Fate_Cool = 1;//レベルごとの出現クールタイム
	int Summon_Cool = 0;//出現クールタイム
	int HP[MAX_MOB];
	double xlenge[MAX_MOB];
	double ylenge[MAX_MOB];
	
};
extern Mob m;

struct Player_Bullet {
public:
	double x[MAX_Player_Bullet];
	double x_sub1[MAX_Player_Bullet];
	double x_sub2[MAX_Player_Bullet];
	double x_sub3[MAX_Player_Bullet];
	double x_sub4[MAX_Player_Bullet];
	double y[MAX_Player_Bullet];
	double y_sub1[MAX_Player_Bullet];
	double y_sub2[MAX_Player_Bullet];
	double y_sub3[MAX_Player_Bullet];
	double y_sub4[MAX_Player_Bullet];
	double angle_sub1[MAX_Player_Bullet];
	double angle_sub2[MAX_Player_Bullet];
	double angle_sub3[MAX_Player_Bullet];
	double angle_sub4[MAX_Player_Bullet];
	int speed = 8;
	int r = 4;//size
	int Power[MAX_Player_Bullet];
	int Sub_flag = 0;
	int flag[MAX_Player_Bullet];
	int flag_sub1[MAX_Player_Bullet];
	int flag_sub2[MAX_Player_Bullet];
	int flag_sub3[MAX_Player_Bullet];
	int flag_sub4[MAX_Player_Bullet];
	int pattern[MAX_Player_Bullet];


};
extern Player_Bullet pb;

struct Mob_Bullet {
public:
	double x[MAX_Mob_Bullet];
	double y[MAX_Mob_Bullet];
	int flag[MAX_Mob_Bullet];
	int r = 3;//size
	double angle[MAX_Mob_Bullet];
	int speed = 8;
};
extern Mob_Bullet mb;

struct Color {
public:
	int Red = GetColor(255, 0, 0);
	int Blue = GetColor(0, 0, 255);
	int Green = GetColor(0, 255, 0);
	int White = GetColor(255, 255, 255);
	int Purple = GetColor(255, 0, 255);
	int Yellow = GetColor(255, 255, 0);
	int Pink = GetColor(255, 192, 203);
	int Gold = GetColor(255, 175, 55);
	int Silver = GetColor(192, 192, 192);
	int Black = GetColor(0, 0, 0);
};
extern Color c;

struct Index {
public:
	int Window_x = 854;//標準
	int Window_y = 480;
	int Volume_SE = 255;//計算時は割合計算する
	int Volume_BGM = 255;//int宣言なためV*%/100の形
	int Full_Screen_Flag = 0;//0がフルスクリーン
	int Mode = 0;//0がタイトル、1がプレイ中、2がリザルト、3が一時停止、4が設定、5がプレイデータ,6が初期化,10以上で終了,100でエラーハンドリング
	char nowkey[256];
	char lastkey[256];
	int Window_Setting = 1;//1が標準、2が1280x720、3が1920x1080
	char Config_Life[256];
	char Config_Window_Mode[256];
	char Config_Window_Size[256];
	int Play_x = 0;//右端
	int Play_XX = 0;//左端
	int Font_Size = 20;
	int Mob_Count = 0;//出現している敵の数を計測
	int Play_Area = 0;//プレイに使用する横幅
};
extern Index i;

struct BOSS {
public:
	double x[MAX_BOSS];
	double y[MAX_BOSS];
	int HP[MAX_BOSS];
	int count = 0;//出現撃破数をカウント
	int size = 50;
	int speed=7;
	int flag[MAX_BOSS];
	int shot_cool[MAX_BOSS];
	int pattern[MAX_BOSS];
};

extern BOSS b;

struct BOSS_Bullet {
public:
	int First_x[MAX_BOSS_Bullet];
	int First_y[MAX_BOSS_Bullet];
	double x[MAX_BOSS_Bullet];
	double y[MAX_BOSS_Bullet];
	int flag[MAX_BOSS_Bullet];
	int speed[MAX_BOSS_Bullet];
	int First_Speed = 10;//初期速さ設定
	int r[MAX_BOSS_Bullet];//半径
	int First_r = 4;//初期設定の半径
	int Exe[MAX_BOSS_Bullet];//爆発範囲
	int Exe_MAX = 40;//爆発最大範囲
	double Exe_Plus = 0.5;//爆発拡大数値
	double angle[MAX_BOSS_Bullet];
	int speed_x[MAX_BOSS_Bullet];
	int speed_y[MAX_BOSS_Bullet];
	int life[MAX_BOSS_Bullet];
	bool grazed[MAX_BOSS_Bullet];//グレイス判定

}; 
extern BOSS_Bullet bb;



struct Item {
public:
	int flag[1000];
	double x[1000];
	double y[1000];
	double angle[1000];
	int size = 15;

};
extern Item it;

struct Sound {
public:
	int Shot_Sound;
	int Mob_Death_Sound;
	int Item_get;
	int mob_shot;
	int Player_hit;
	int Power_up;
	int Power_down;

	int Gameover;
};
extern Sound s;

struct BGM {
public:
	int Game_BGM_1;
	int Game_BGM_2;
	int Game_BGM_3;
	int Game_BGM_4;
	int Game_BGM_5;

	int Title_BGM;
};
extern BGM bg;

struct BOM {
public:
	int x[100];
	int y[100];
	int Lenge[100];
	int flag[100];
};
extern BOM bo;

struct Graph {
	int Character_Handle;
	int Player_Handle;
	int Player_Main_Bullet_Handle;
	int Player_Sub_Bullet_Handle;
	int Mob_Handle;
	int Mob_Bullet_Handle;
	int BOSS_Handle;
	int BOSS_Bullet_Handle[10];
	int Item;
	
};
extern Graph g;


//void
extern void  Size_Change(int mode);
extern void Config_load();
extern void Game();
extern void Load_Play_Date();	
extern void File_Load();
extern void Player_Shot();
extern void FpsTimeFanction();
extern void Item_Get();
extern void Bullet_Drawing();
extern void Score(int a);
extern void Clear_Date();
extern void DrawGra_Bullet(int x, int y, int GrHandle, int TransFlag);
extern void State_UP();
extern void Stage();
extern void Item_Summon(int summon,int Index);
extern void Mob_Summon();
extern void Mob_Update();
extern void Time();
extern void DrawGra_Item(int x, int y, int GrHandle, int TransFlag);
extern void DrawGra_Mob(int x, int y, int Grhandle, int TransFlag);
extern void DrawGra_Mob_Bullet(int x, int y, int Grhandle, int TransFlag);
extern void Mob_Bullet_Drawing();
extern void Mob_Bullet_Crate(int x, int y);


//int 
extern int N_Play_Count;
extern int Fate_Speed;
extern int HP;
extern bool Pause;