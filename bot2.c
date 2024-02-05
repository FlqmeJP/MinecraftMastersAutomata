#include "control.h"
#include <stdio.h>
#include <unistd.h>

int zombie1(int z1[]);
int zombie2(long int z2[]);
int reset(int cnt3);
int notz1(int z1[],int cnt3);
void z1judge(int z1[]);
int attack(int z1[],int cnt3);

int zombie1(int z1[]){
    int a,i,k=1;
    int flag = 0;
    a = detectZombie1();
    printf("%07d \n", a);
    for (i = 0; i < 7; i++) {
        z1[7 - 1 - i] = a / k % 10;
        k = k * 10;
    }
    k = 1;
    if(a==0){flag=1;}
    return flag;
}

int zombie2(long int z2[]){
    long int b;
    int i;
    long int k=1;
    int flag = 0;
    b = detectZombie2();
    printf("%015ld \n", b);
    for (i = 0; i < 15; i++) {
        z2[15 - 1 - i] = b / k % 10;
        k = k * 10;
    }
    k = 1;
    for(i=0;i<15;i++){
        if(z2[i]!=0){
            if(z2[i]!=1){
                flag=1;
            }
        }
    }
    return flag;
}

int reset(int cnt3){   // 子どもゾンビ用に視点を調整
    if (cnt3 > 40) {cnt3 = 0;}
    if (cnt3 == 0) { 
        printf("視点リセット\n");
        pushKey("c");
        pushKey("j");
        cnt3++;
    }
    return cnt3;
}

int notz1(int z1[],int cnt3){   // 画面内にゾンビがいない間、視点を右に移動させ、定期的に前に移動する。
    int flag = 1;
    int a,i;
    int cnt1 = 1;
    flag = zombie1(z1);
    while (rk != 0 && flag == 1) { 
        printf("視点右\n");
        pushKey("k");
        flag = zombie1(z1);
                
        if (cnt1 % 6 == 0) {
            printf("攻撃*5\n");
            for(i=0;i<5;i++){
                attackLeft();
            }
            flag = zombie1(z1);
            if (flag == 1) {
                printf("ダッシュ\n");
                moveDash(3);
                flag = zombie1(z1);
                if (flag == 1) {
                    printf("ダッシュ\n");
                    moveDash(3);
                }
            }
        }
        flag = zombie1(z1);
        cnt1++;
        cnt3++;
    }
    return cnt3;
}

void z1judge(int z1[]){
    int i;
    zombie1(z1);
    if (z1[4] == 1) {
    } else if (z1[3] == 1) {
        printf("後ろに移動\n");
        moveBack(1);
        printf("攻撃*5\n");
        for(i=0;i<5;i++){
            attackLeft();
        }
    } else if (z1[5] == 1) {
        printf("後ろに移動\n");
        moveBack(1);
        printf("攻撃*5\n");
        for(i=0;i<5;i++){
            attackLeft();
        }
    } else if (z1[0] == 1) {
        printf("視点左\n");
        pushKey("h");
    } else if (z1[2] == 1) {
        printf("視点右\n");
        pushKey("k");
    } 
}

int attack(int z1[],int cnt3){  // 中央にゾンビがいる間、攻撃する。
    int flag=0;
    int cnt2=1;
    while (rk != 0 && flag == 0) { 
    zombie1(z1);
    if (cnt2 == 5||cnt2 == 15) {
        printf("視点左\n");
        pushKey("h");
    }
    if (cnt2 == 10) {
        printf("視点右\n");
        pushKey("k");
    }

    if (cnt2 == 20) {
        printf("ダッシュ\n");
        moveDash(3);
    }
    if ((z1[4] == 0)|| cnt2 > 20) {
        flag = 1;
        cnt2 = 0;
    }
    printf("攻撃\n");
    attackLeft();
    cnt2++;
    cnt3++;
    }
    return cnt3;
}

int main(int argc, char *argv[]) {
    int a;     // detectZombie1から値を受け取る
    long int b; // detectZombie2から値を受け取る
    int z1[7];  // aの値を配列に入れる
    long int z2[15];    //bの値を配列に入れる
    int cnt3 = 0;   //視点リセット用

    init(); // Minecraftのゲームコントロール関数．ウィンドウサイズを設定する等を行う．
    setTime();   // Minecraft上で時間を夜にしてくれる．
    exePython(); // 画像処理プログラムを実行する関数．実行結果はdetectZombie，detectZombie2，detectMobs関数で取得できる．
    setSurvival(); // サバイバルモードにする．

    while (rk) { // 無限loopする．rkはF12キーを押すと0となり，プログラムが停止します．
        cnt3 = reset(cnt3);    //視点リセット
        z1judge(z1);
        cnt3 = notz1(z1,cnt3);  // 画面内にゾンビがいない間、視点を右に移動させ、定期的に前に移動する。
        cnt3 = attack(z1,cnt3); // 中央にゾンビがいる間、攻撃する。
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
スムース回転スピード 5
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
視野　50度
手ぶれ　オフ
画面の揺れ　オフ
*/