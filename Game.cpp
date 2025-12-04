#include<stdio.h>
#include"main.h"
#include"DxLib.h"

//低速移動フラグ
bool Slow_flag;

void Game() {
	
	if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)i.Mode = 0;
	
	if(i.Mode == 1&&Pause==false) {
		
	
		DrawFormatString(i.Play_XX, i.Window_y / 2, c.Purple, "ゲーム画面だよ", i.Play_x);
		DrawBox(i.Play_x, 0, i.Window_x, i.Window_y, c.White, true);
		DrawBox(0, 0, i.Play_XX, i.Window_y, c.White, true);
		
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)i.Mode = 0;
		if (p.cool_time > 0)p.cool_time--;//自機発射クールタイム
		if (CheckHitKey(KEY_INPUT_LSHIFT) == 1) {//低速移動
			if (CheckHitKey(KEY_INPUT_UP) == 1)p.y -= p.low_speed;
			if (CheckHitKey(KEY_INPUT_DOWN) == 1)p.y += p.low_speed;
			if (CheckHitKey(KEY_INPUT_LEFT) == 1)p.x -= p.low_speed;
			if (CheckHitKey(KEY_INPUT_RIGHT) == 1)p.x += p.low_speed;
			Slow_flag = true;
			switch (p.angle) {
			case 1:
				DrawLine(p.x, p.y, p.x, 0, c.Red, true);
				break;
			case 2:
				DrawLine(p.x, p.y, i.Play_x, p.y, c.Red, true);
				break;
			case 3:
				DrawLine(p.x, p.y, p.x, i.Window_y, c.Red, true);
				break;
			case 4:
				DrawLine(p.x, p.y, i.Play_XX, p.y, c.Red, true);
				break;
			}
		}
		else {//通常移動
			if (CheckHitKey(KEY_INPUT_UP) == 1)p.y -= p.normal_speed;
			if (CheckHitKey(KEY_INPUT_DOWN) == 1)p.y += p.normal_speed;
			if (CheckHitKey(KEY_INPUT_LEFT) == 1)p.x -= p.normal_speed;
			if (CheckHitKey(KEY_INPUT_RIGHT) == 1)p.x += p.normal_speed;
			Slow_flag = false;
		}
		if (CheckHitKey(KEY_INPUT_Z) == 1 && p.cool_time <= 0) {
			Player_Shot();
			p.cool_time = 8;
		}
		if (i.nowkey[KEY_INPUT_C] == 1 && i.lastkey[KEY_INPUT_C] == 0) {
			p.angle = (p.angle % 4) + 1;
		}
		if (p.x < i.Play_XX)p.x = i.Play_x;
		if (p.x > i.Play_x)p.x = i.Play_XX;
		if (p.y < 0)p.y = i.Window_y;
		if (p.y > i.Window_y)p.y = 0;
		if (Slow_flag == true) {
			DrawCircle(p.x, p.y, p.r, c.Red, true);
		}
		else {
			DrawCircle(p.x, p.y, p.r, c.Blue, true);
		}
		DrawFormatString(0, 0, c.Black, "Cool-Time:%d", p.cool_time);
		Bullet_Drawing();
		DrawFormatString(0, i.Font_Size, c.Black,"X:%3.1f Y:%3.1f", p.x, p.y);
		DrawFormatString(0, i.Font_Size * 2, c.Black, "MOB-%d", m.Summon_Cool);
		DrawFormatString(i.Play_x, 5, c.Green, "Score:%d", p.score);
		DrawFormatString(i.Play_x, i.Font_Size + 5, c.Silver, "Power:%d", p.Power);
	
	
	}
	

}