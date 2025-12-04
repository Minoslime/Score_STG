#include<stdio.h>
#include"main.h"
#include"DxLib.h"
#include<math.h>





void Player_Shot() {
	for (int i = 0; i < MAX_Player_Bullet; i++) {
		if (pb.flag[i] == 0) {
			pb.x[i] = p.x;
			pb.y[i] = p.y;
			pb.pattern[i] = p.angle;
			pb.Power[i] = p.Power;
			pb.flag[i] = 1;
			break;
		}
	}
}

void Bullet_Drawing() {
	for (int j = 0; j < MAX_Player_Bullet; j++) {
		if (pb.flag[j] == 1) {
			switch (pb.pattern[j]) {
			case 1:
				pb.y[j] -= pb.speed;
				break;
			case 2:
				pb.x[j] += pb.speed;
				break;
			case 3:
				pb.y[j] += pb.speed;
				break;
			case 4:
				pb.x[j] -= pb.speed;
				break;
			}
			DrawGra_Bullet(pb.x[j], pb.y[j], g.Player_Main_Bullet_Handle, true);
			printfDx("%d\n", j);
			if (pb.x[j]<i.Play_XX || pb.x[j]>i.Play_x || pb.y[j]<0 || pb.y[j]>i.Window_y) {
				pb.flag[j] = 0;

			}
		}
	}
}


void Mob_Bullet_Drawing() {
	for (int md = 0; md < MAX_Mob_Bullet; md++) {
		if (mb.flag[md] == 1) {
			mb.x[md] += cos(mb.angle[md]) * mb.speed;
			mb.y[md] += sin(mb.angle[md]) * mb.speed;
			DrawGra_Mob_Bullet(mb.x[md], mb.y[md], g.Mob_Bullet_Handle, true);
			if (mb.x[md]<i.Play_XX || mb.x[md]>i.Play_x || mb.y[md]<0 || mb.y[md]>i.Window_y) {
				mb.flag[md] = 0;
			}
		}
	}
}

void Mob_Bullet_Crate(int x, int y) {
	for (int mc = 0; mc < MAX_Mob_Bullet; mc++) {
		if (mb.flag[mc] == 0&&m.Shot_Cool[mc]<=0) {
			mb.x[mc] = x;
			mb.y[mc] = y;
			mb.angle[mc] = atan2(p.y - mb.y[mc], p.x - mb.x[mc]);
			mb.flag[mc] = 1;
			break;
		}
	}

}

void Bullet_Reset() {
	for (int r = 0; r < MAX_Player_Bullet; r++) {
		if (pb.flag[r] == 0) {
			pb.x[r] = 0;
			pb.y[r] = 0;
			pb.pattern[r] = 0;
			pb.Power[r] = 0;
		}
	}
}