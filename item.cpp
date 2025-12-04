#include <stdio.h>
#include <math.h>
#include "DxLib.h"
#include "main.h"

// 吸い寄せの設定
const int ATTRACTION_RADIUS = 80;     // この距離まで近づくと吸い寄せる
const double ATTRACTION_SPEED = 12.0; // 吸い寄せられるスピード

// ■毎フレーム呼ばれる関数
void Item_Get() {
	for (int q = 0; q < 1000; q++) {
		// flagが0以外ならアイテムが存在する
		if (it.flag[q] != 0 && Pause == false) {

			// プレイヤーとの距離計算
			double x_diff = p.x - it.x[q];
			double y_diff = p.y - it.y[q];
			double distance = sqrt(x_diff * x_diff + y_diff * y_diff);

			// -------------------------------------------------
			// 状態A: 通常モード (フラグが10以上)
			// 散らばりながら落下する
			// -------------------------------------------------
			if (it.flag[q] >= 10) {
				// 1. 吸い寄せ判定
				if (distance < ATTRACTION_RADIUS) {
					it.flag[q] = 2; // 吸い寄せモード(2)へ切り替え
				}
				else {
					// 2. タイマー進行
					if (it.flag[q] < 1000) it.flag[q]++;

					// 3. 移動計算 (散らばってから落ちる)
					int timer = it.flag[q] - 10; // 0からスタートするように補正
					double transition_time = 20.0;

					// 拡散の強さを計算 (最初強く、徐々に弱く)
					double factor = 1.0;
					if (timer < transition_time) {
						factor = (transition_time - timer) / transition_time;
					}
					else {
						factor = 0.0;
					}

					// 拡散移動 (cos/sin)
					double scatter_speed = 4.0;
					it.x[q] += cos(it.angle[q]) * scatter_speed * factor;
					it.y[q] += sin(it.angle[q]) * scatter_speed * factor;

					// 重力落下 (徐々に強く)
					double fall_speed = 5.0;
					it.y[q] += fall_speed * (1.0 - factor);
				}
			}
			// -------------------------------------------------
			// 状態B: 吸い寄せモード (フラグが2)
			// プレイヤーに向かって飛んでいく
			// -------------------------------------------------
			else if (it.flag[q] == 2) {
				if (distance > 0) {
					it.x[q] += (x_diff / distance) * ATTRACTION_SPEED;
					it.y[q] += (y_diff / distance) * ATTRACTION_SPEED;
				}
			}

			// -------------------------------------------------
			// 共通処理: 描画・消滅・取得
			// -------------------------------------------------

			// 描画 (中心座標を合わせる)
			DrawGra_Item(it.x[q] - 10, it.y[q] - 10, g.Item, true);

			// 画面外（下）に出たら消す
			if (it.y[q] > i.Window_y) {
				it.flag[q] = 0;
				
			}

			// 取得判定
			double hit_r = 20 + p.r;
			if (distance < hit_r) {
				it.flag[q] = 0; // 消す
				p.Power++;
				Score(3);       // スコア加算
				PlaySoundMem(s.Item_get, DX_PLAYTYPE_BACK);
			}
		}
	}
}

// ■アイテム出現関数
void Item_Summon(int summon, int Index) {
	int count = 0;
	for (int q = 0; q < 1000; q++) {
		if (it.flag[q] == 0) {
			it.x[q] = m.x[Index];
			it.y[q] = m.y[Index];
			it.angle[q] = (GetRand(360) * (DX_PI / 180.0));

			// ★ここが重要: 10からスタートさせます
			// (2は吸い寄せモードとして予約するため)
			it.flag[q] = 10;

			count++;
			if (count >= summon) break;
		}
	}
}