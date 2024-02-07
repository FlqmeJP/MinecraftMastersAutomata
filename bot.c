#include "control.h"
#include <stdio.h>
#include <unistd.h>

int zombie1(int z1[]);
int zombie2(long int z2[]);
void z1print(int z1[]);
void z2print(long int z2[]);
void z1judge(int z1[]);
void z2judge(long int z2[]);
int notz1(int z1[],int cnt3);
int notz2(long int z2[],int cnt3);
int attackz1(int z1[],int cnt3);
int attackz2(long int z2[],int cnt3);
int reset(int cnt3);
void attack5(void);

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
    z1print(z1);
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

    if(b==0){flag=1;}
    for(i=0;i<15;i++){
        if(z2[i]!=0){
            if(z2[i]!=1){
                flag=1;
            }
        }
    }
    z2print(z2);
    return flag;
}

void z1print(int z1[]){
    if(z1[0]==1){printf("左上 ");}
    if(z1[1]==1){printf("中央上 ");}
    if(z1[2]==1){printf("右上 ");}
    if(z1[3]==1){printf("左下 ");}
    if(z1[4]==1){printf("中央下 ");}
    if(z1[5]==1){printf("右下 ");}
    printf("\n");
}

void z2print(long int z2[]){
    if(z2[0]==1){printf("右下遠 ");}
    if(z2[1]==1){printf("右下中 ");}
    if(z2[2]==1){printf("右下近 ");}
    if(z2[3]==1){printf("左下遠 ");}
    if(z2[4]==1){printf("左下中 ");}
    if(z2[5]==1){printf("左下近 ");}
    if(z2[6]==1){printf("右上遠 ");}
    if(z2[7]==1){printf("右上中 ");}
    if(z2[8]==1){printf("右上近 ");}
    if(z2[9]==1){printf("左上遠 ");}
    if(z2[10]==1){printf("左上中 ");}
    if(z2[11]==1){printf("左上近 ");}
    if(z2[12]==1){printf("中央遠 ");}
    if(z2[13]==1){printf("中央中 ");}
    if(z2[14]==1){printf("中央近 ");}
    printf("\n");
}

void z1judge(int z1[]){ 
    int i;
    zombie1(z1);
    if (z1[4] == 1) {
    } else if (z1[3] == 1) {
        printf("後ろに移動\n");
        moveBack(1);
        attack5();
    } else if (z1[5] == 1) {
        printf("後ろに移動\n");
        moveBack(1);
        attack5();
    } else if (z1[0] == 1) {
        printf("視点左\n");
        pushKey("h");
    } else if (z1[2] == 1) {
        printf("視点右\n");
        pushKey("k");
    } 
}

void z2judge(long int z2[]){    //0,1,2 右下 3,4,5 左下 6,7,8 右上 9,10,11 左上 12,13,14 中央   遠い←→近い
    int i;
    zombie2(z2);
    if (z2[13]==1||z2[14]==1||z2[12]==1) {
        printf("後ろに移動\n");
        moveBack(0.7);
        attack5();
    } else if (z2[2] == 1||z2[5] == 1||z2[8] == 1||z2[11]== 1) {
        printf("後ろに移動\n");
        moveBack(1);
        attack5();
    } else if (z2[4] == 1||z2[10] == 1) {
        printf("視点左\n");
        pushKey("h");
        attack5();
    } else if (z2[1] == 1||z2[7] ==1) {
        printf("視点右\n");
        pushKey("k");
        attack5();
    } else if (z2[3] == 1||z2[9] == 1){
        printf("視点左\n");
        pushKey("h");
        attack5();
    } else if(z2[0] == 1||z2[6] == 1){
        printf("視点右\n");
        pushKey("k");
        attack5();
    }
}

int notz1(int z1[],int cnt3){   // 画面内にゾンビがいない間、視点を右に移動させ、定期的に前に移動する。
    int flag = 1;
    int a,i;
    int cnt1 = 1;
    flag = zombie1(z1);
    while (rk != 0 && flag == 1) { 
        flag = zombie1(z1);
        if (flag == 1) {
        printf("視点右\n");
        pushKey("l");
        }
        flag = zombie1(z1);
        if (flag == 1) {
        pushKey("k");
        }
        flag = zombie1(z1);
        if (flag == 1) {
            attack5();
        }
        flag = zombie1(z1);
        if (flag == 1) {
            printf("ダッシュ\n");
            moveDash(3);
            flag = zombie1(z1);
            if (flag == 1) {
                printf("ダッシュ\n");
                moveDash(2.5);
            }
        }
        
        flag = zombie1(z1);
        cnt1++;
        cnt3++;
    }
    return cnt3;
}

int notz2(long int z2[],int cnt3){   // 画面内にゾンビがいない間、視点を右に移動させ、定期的に前に移動する。
    int flag = 1;
    int a,i;
    int cnt1 = 1;
    flag = zombie2(z2);
    while (rk != 0 && flag == 1) { 
        flag = zombie2(z2);
        if (flag == 1) {
        printf("視点右\n");
        pushKey("l");
        }
        flag = zombie2(z2);
        if (flag == 1) {
        pushKey("k");
        }
        flag = zombie2(z2);
        if (flag == 1) {
            attack5();
        }
        flag = zombie2(z2);
        if (flag == 1) {
            printf("ダッシュ\n");
            moveDash(3);
            flag = zombie2(z2);
            if (flag == 1) {
                printf("ダッシュ\n");
                moveDash(2.5);
            }
        }
        
        flag = zombie2(z2);
        cnt1++;
        cnt3++;
    }
    return cnt3;
}

int attackz1(int z1[],int cnt3){  // 中央にゾンビがいる間、攻撃する。
    int flag=0;
    int cnt2=1;
    while (rk != 0 && flag == 0) { 
    zombie1(z1);
    if (cnt2 == 5||cnt2 == 10||cnt2 == 15) {
        printf("後ろに移動\n");
        moveBack(0.7);
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

int attackz2(long int z2[],int cnt3){  // 中央にゾンビがいる間、攻撃する。
    int flag=0;
    int cnt2=1;
    while (rk != 0 && flag == 0) { 
    zombie2(z2);
    if (cnt2 == 5||cnt2 == 10||cnt2 == 15) {
        printf("後ろに移動\n");
        moveBack(0.7);
    }

    if (cnt2 == 20) {
        printf("ダッシュ\n");
        moveDash(2);
    }
    if ((z2[13] == 0 && z2[14] == 0)|| cnt2 > 20) {
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

int reset(int cnt3){   // 子どもゾンビ用に視点を調整
    if (cnt3 > 20) {cnt3 = 0;}
    if (cnt3 == 0) { 
        printf("視点リセット\n");
        pushKey("c"); 
        pushKey("j");
        cnt3++;
    }
    return cnt3;
}

void attack5(void){
    int i;
    printf("攻撃*5\n");
    for(i=0;i<5;i++){
        attackLeft();
        if(i==2){moveBack(0.7);}
    }
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
        cnt3 = reset(cnt3); //画面をリセットする
        z2judge(z2);    //ゾンビを検出し、画面の移動と攻撃をする。
        cnt3 = notz2(z2,cnt3);  // 画面内にゾンビがいない間、視点を右に移動させ、定期的に前に移動する。
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
スムース回転スピード 15
中心を見る C
スムースに下を見る J
スムースに右を見る K
スムースに左を見る H
右を見る L
左を見る G
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
雲を表示する オフ
美しい空 オフ
MINECRAFT_CONTEST/python/minecraft/pushKey.py sleep_time = 0.05
*/
