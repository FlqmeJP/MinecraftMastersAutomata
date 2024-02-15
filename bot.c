#include "control.h"
#include <stdio.h>
#include <unistd.h>

int zombie2(long int z2[]);
int sketeton(int s[]);
void z2print(long int z2[]);
void sprint(int s[]);
int z2judge(long int z2[],int s[],int cnt3);
int notz2(long int z2[],int s[],int cnt3);
int reset(int cnt3);
void attack1(void);

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

int skeleton(int s[]){
    int c,i,k=1;
    int flag = 0;
    c = detectSkeleton();
    printf("%06d \n", c);
    for (i = 0; i < 6; i++) {
        s[6 - 1 - i] = c / k % 10;
        k = k * 10;
    }
    k = 1;
    if(c==0){flag=1;}
    sprint(s);
    return flag;
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

void sprint(int s[]){
    if(s[0]==1){printf("左1 ");}
    if(s[1]==1){printf("左2 ");}
    if(s[2]==1){printf("左3 ");}
    if(s[3]==1){printf("右3 ");}
    if(s[4]==1){printf("右2 ");}
    if(s[5]==1){printf("右1 ");}
    printf("\n");
}

int z2judge(long int z2[],int s[],int cnt3){    //0,1,2 右下 3,4,5 左下 6,7,8 右上 9,10,11 左上 12,13,14 中央   遠い←→近い
    int i;
    zombie2(z2);
    skeleton(s);
    if (z2[13]==1||z2[14]==1) { //中央近・中
        attack1();
    } else if (z2[5] == 1||z2[11]== 1||s[2]==1) {    //左下近・左上近
        printf("後ろに移動\n");
        moveBack(0.3);
        printf("視点左\n");
        pushKey("h");
        attack1();
    } else if (z2[2] == 1||z2[8] == 1||s[3]==1) {    //右下近・右上近 
        printf("後ろに移動\n");
        moveBack(0.3);
        printf("視点右\n");
        pushKey("k");
        attack1();
    } else if (z2[4] == 1||z2[10] == 1||s[1]==1) {   //左下中・左上中
        printf("視点左\n");
        pushKey("h");
        attack1();
    } else if (z2[1] == 1||z2[7] ==1||s[4]==1) {     //右下中・右上中
        printf("視点右\n");
        pushKey("k");
        attack1();
    } else if (z2[3] == 1||s[0]==1) {    //左下遠
        printf("視点左\n");
        pushKey("h");
        attack1();
    } else if (z2[0] == 1||s[5]==1){    //右下遠
        printf("視点右\n");
        pushKey("k");
        attack1();
    } else if (z2[12] == 1){    //中央遠
        attack1();
    } else if (z2[9] == 1){    //左上遠
        printf("ダッシュ\n");
        dash1();
    } else if (z2[6] == 1){    //右上遠
        printf("ダッシュ\n");
        dash1();
    }
    cnt3++;
    return cnt3;
}


int notz2(long int z2[],int s[],int cnt3){   // 画面内にゾンビがいない間、視点を右に移動させ、前に移動する。
    int flag = 1;
    int flag2 = 1;
    int a,i;
    int cnt1 = 1;
    flag = zombie2(z2);
    flag2 = skeleton(s);
    while (rk != 0 && flag == 1 && flag2 == 1) { 
        printf("ダッシュ\n");
        dash2();
        flag = zombie2(z2);
        flag2 = skeleton(s);
        if (flag == 1 && flag2 == 1) {
            printf("ダッシュ\n");
            dash2();
        }
        
        flag = zombie2(z2);
        flag2 = skeleton(s);
        if (flag == 1 && flag2 == 1) {
            printf("視点右\n");
            pushKey("l");
        }
        flag = zombie2(z2);
        flag2 = skeleton(s);
        if (flag == 1 && flag2 == 1) {
            printf("視点右\n");
            pushKey("k");
        }
        flag = zombie2(z2);
        flag2 = skeleton(s);
        if (flag == 1 && flag2 == 1) {
            printf("視点右\n");
            pushKey("k");
        }
        flag = zombie2(z2);
        flag2 = skeleton(s);
        cnt1++;
        cnt3++;
    }
    return cnt3;
}

int reset(int cnt3){   // 視点を調整
    if (cnt3 == 0) { 
        printf("視点リセット\n");
        pushKey("c"); 
        cnt3++;
    }
    if (cnt3 % 10 == 0){
        eat();
    }
    return cnt3;
}

void attack1(void){
    int i;
    printf("攻撃*10\n");
    attackLeft_long();
}

int main(int argc, char *argv[]) {
    long int b; // detectZombie2から値を受け取る
    long int z2[15];    //bの値を配列に入れる
    int s[6];
    int cnt3 = 0;   //視点リセット用
    int flag;
    int flag2;

    init(); // Minecraftのゲームコントロール関数．ウィンドウサイズを設定する等を行う．
    setTime();   // Minecraft上で時間を夜にしてくれる．
    exePython(); // 画像処理プログラムを実行する関数．実行結果はdetectZombie，detectZombie2，detectMobs関数で取得できる．
    setSurvival(); // サバイバルモードにする．

    while (rk) { // 無限loopする．rkはF12キーを押すと0となり，プログラムが停止します．
        cnt3 = reset(cnt3); //画面をリセットする
        cnt3 = z2judge(z2,s,cnt3);    //ゾンビを検出し、画面の移動と攻撃をする。
        flag = zombie2(z2);
        flag2 = skeleton(s);
        if(flag==1&&flag2==1){cnt3 = notz2(z2,s,cnt3);}  // 画面内にゾンビがいない間、視点を右に移動させ、定期的に前に移動する。
        sleep(0.1);
    }
    setCreative(); // クリエイティブモードにする．
    setMorning();  // 朝にする．
    return 0;
}

/*
・ゲーム
難易度 イージー
即時リスポーン オン
持ち物の保持 オン
モブのスポーン オフ
自然再生 オン

・キーボード＆マウス
フルキーボードゲームプレイ オン
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
ダッシュ Z

・ビデオ
明るさ 100
カメラ視点 一人称
手の非表示 オン
視野 60度
手ぶれ オフ
画面の揺れ オフ
雲を表示する オフ
美しい空 オフ

MINECRAFT_CONTEST/python/minecraft/pushKey.py 
MINECRAFT_CONTEST/python/minecraft/clickLeft_Long.py
MINECRAFT_CONTEST/python/minecraft/moveDash1.py
MINECRAFT_CONTEST/python/minecraft/moveDash2.py
MINECRAFT_CONTEST/python/minecraft/eat.py
MINECRAFT_CONTEST/control.c
*/

