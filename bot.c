#include "control.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int a;     // detectZombie1から値を受け取る
    int b[7];  // aの値を配列に入れる
    int k = 1; // 配列に値を入れるときに使用する
    int i;
    int flag = 0;
    int cnt1 = 1;
    int cnt2 = 1;
    int cnt3 = 0;

    init(); // Minecraftのゲームコントロール関数．ウィンドウサイズを設定する等を行う．
    setTime();   // Minecraft上で時間を夜にしてくれる．
    exePython(); // 画像処理プログラムを実行する関数．実行結果はdetectZombie，detectZombie2，detectMobs関数で取得できる．
    setSurvival(); // サバイバルモードにする．

    while (rk) { // 無限loopする．rkはF12キーを押すと0となり，プログラムが停止します．
        if (cnt3 == 0) { // 子どもゾンビ用に視点を調整
            printf("視点リセット\n");
            pushKey("c");
            pushKey("j");
            cnt3++;
        }

        a = detectZombie1();
        printf("A %07d\n", a);
        for (i = 0; i < 7; i++) {
            b[6 - i] = a / k % 10;
            k = k * 10;
        }
        k = 1;
        // 0:左上 1:中央上(常に1になる) 2:右上 3:左下 4:中央下 5:右下 6:ヒット判定(使わない)
        if (b[4] == 1) {

        } else if (b[3] == 1) {
            printf("A 後ろに移動\n");
            moveBack(1);
            printf("A 攻撃*5\n");
            attackLeft();
            attackLeft();
            attackLeft();
            attackLeft();
            attackLeft();
        } else if (b[5] == 1) {
            printf("A 後ろに移動\n");
            moveBack(1);
            printf("A 攻撃*5\n");
            attackLeft();
            attackLeft();
            attackLeft();
            attackLeft();
            attackLeft();
        } else if (b[0] == 1) {
            printf("A 視点左\n");
            pushKey("h");
        } else if (b[2] == 1) {
            printf("A 視点右\n");
            pushKey("k");
        } else {
            while (rk != 0 &&flag ==0) { // 画面内にゾンビがいない間、視点を右に移動させ、定期的に前に移動する。
                flag = 1;
                printf("B 視点右\n");
                pushKey("k");
                a = detectZombie1();
                printf("B %07d\n", a);
                if (a == 0 || a == 100000) {
                    flag = 0;
                }
                
                if (cnt1 % 7 == 0) {
                    printf("B 攻撃*5\n");
                    attackLeft();
                    attackLeft();
                    attackLeft();
                    attackLeft();
                    attackLeft();
                    printf("B ダッシュ\n");
                    moveDash(3);
                    a = detectZombie1();
                    printf("B %07d\n", a);
                    if (a == 0 || a == 100000) {
                        printf("B ダッシュ\n");
                        moveDash(3);
                    }
                }
            cnt1++;
            cnt3++;
            }
            flag = 0;
        }

        while (rk != 0 && flag == 0) { // 中央にゾンビがいる間、攻撃する。
            a = detectZombie1();
            printf("C %07d\n", a);
            for (i = 0; i < 7; i++) {
                b[6 - i] = a / k % 10;
                k = k * 10;
            }
            k = 1;
            if (cnt2 == 5||cnt2 == 5) {
                printf("C 視点左\n");
                cameraLeft(0.5);
            }
            if (cnt2 == 15) {
                printf("C ダッシュ\n");
                moveDash(3);
            }
            if (b[4] == 0 || cnt2 > 15) {
                flag = 1;
                cnt2 = 0;
            }
            printf("C 攻撃\n");
            attackLeft();
            cnt2++;
            cnt3++;
        }
        flag = 0;

        if (cnt3 > 50) {
            cnt3 = 0;
        }

        sleep(0.1);
    }
    setCreative(); // クリエイティブモードにする．
    setMorning();  // 朝にする．
}

/*
・ゲーム
難易度　イージー
即時リスポーン オン
持ち物の保持　オン
モブのスポーン オフ
自然再生　オン

・キーボード＆マウス
フルキーボードゲームプレイ　オン
スムース回転スピード 4
中心を見る C
スムースに下を見る J
スムースに左を見る H
スムースに右を見る K
インベントリ I
攻撃する Q
移動 AWSD
コマンドライン /
ダッシュ CTRL

・ビデオ
明るさ 100
カメラ視点　一人称
手の表示　オフ
視野　70度
手ぶれ　オフ
画面の揺れ　オフ
*/
