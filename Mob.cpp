#include<stdio.h>
#include"main.h"
#include"DxLib.h"
#include<math.h>
#include<cmath>
#include<limits>


//宣言



void Mob_Summon() {//条件を満たすと敵を召喚する関数
	if (m.Summon_Cool <= 0 && i.Mob_Count < m.Summon_Limit) {
		for (int n = 0; n < m.Summon_Limit; n++) {
			if (m.flag[n] == 0) {
				m.x[n] = GetRand(i.Play_Area) + i.Play_XX;
				m.y[n] = 0;
				m.speed[n] = Fate_Speed;
				m.HP[n] = HP;
				i.Mob_Count++;
				m.flag[n] = 1;
				m.Summon_Cool = m.Fate_Cool;
				break;
			}
		}
	}
}

void Mob_Update() {//敵の動作、表示を管理する関数
	for (int n = 0; n < m.Summon_Limit; n++) {
		if (m.flag[n] == 1 && Pause == false) {
			for (int pbh = 0; pbh < MAX_Player_Bullet; pbh++) {//当たり判定
				if (pb.x[pbh] - pb.r < m.x[n] + m.size && // pbの左端 < mの右端
					pb.x[pbh] + pb.r > m.x[n] && // pbの右端 > mの左端
					pb.y[pbh] - pb.r < m.y[n] + m.size && // pbの上端 < mの下端
					pb.y[pbh] + pb.r > m.y[n]	&&pb.flag[pbh]==1)
				{
					m.HP[n] -= pb.Power[pbh];
					pb.flag[pbh] = 0;
					Score(0);
				}
			}
			if (m.Type[n] == 1 && m.Shot_Cool[n] <= 0) {
				Mob_Bullet_Crate(m.x[n],m.y[n]); 
				m.Shot_Cool[n] = m.Fate_Cool;
			}
			if (m.HP[n] <= 0) {
				Score(1);
				m.flag[n] = 0;
				m.Death++;
				i.Mob_Count--;
				Item_Summon(GetRand(m.HP[n] + 1), n);
			}
			if (m.HP[n] > 0) {
				m.xlenge[n] = m.x[n] - p.x;
				m.ylenge[n] = m.y[n] - p.y;
				if (abs(m.xlenge[n]) > (i.Play_Area)/ 2) {
					if (m.xlenge[n] > 0) {
						m.x[n] += m.speed[n];
					}
					else {
						m.x[n] -= m.speed[n];
					}
				}
				else {
					if (m.xlenge[n] > 0) {
						m.x[n] -= m.speed[n];
					}
					else {
						m.x[n] += m.speed[n];
					}
				}
				if (abs(m.ylenge[n]) > i.Window_y/2) {
					if (m.ylenge[n] > 0) {
						m.y[n] += m.speed[n];
					}
					else {
						m.y[n] -= m.speed[n];
					}
				}
				else {
					if (m.ylenge[n] >0 ) {
						m.y[n] -= m.speed[n];
					}
					else {
						m.y[n] += m.speed[n];
					}
				}
				if (m.x[n] < i.Play_XX) {
					m.x[n] =  i.Play_x;
				}
				if (m.x[n] > i.Play_x) {
					m.x[n] = i.Play_XX;
				}
				if (m.y[n] < 0) {
					m.y[n] = i.Window_y;
				}
				if (m.y[n] > i.Window_y) {
					m.y[n] = 0;
				}
				DrawGra_Mob(m.x[n], m.y[n], g.Mob_Handle, true);
			}
		}
		
	}
}



//void Mob_Shot(int x,int y)