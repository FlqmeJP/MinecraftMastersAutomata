#include "control.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    long int a;
    int b[15];
    int c;
    int i;
    int k=1;
    int flag = 0;
    int flag2 = 0;
    int cnt = 0;

    init(); // Minecraftのゲームコントロール関数．ウィンドウサイズを設定する等を行う．
    setTime();   // Minecraft上で時間を夜にしてくれる．
    exePython(); // 画像処理プログラムを実行する関数．実行結果はdetectZombie，detectZombie2，detectMobs関数で取得できる．
    setSurvival(); // サバイバルモードにする．
    cameraCenter();
    
    while(rk) { // 無限loopする．rkはF12キーを押すと0となり，プログラムが停止します．
        if(flag2==0){
            cameraCenter();
            attackLeft();
            cameraUp(0.3);
            attackLeft();
            cameraDown(0.4);
            attackLeft();
            flag2=1;
        }

        a = detectZombie2();
        printf("A%015ld\n",a);
        for(i=0;i<15;i++){
            b[14-i]=a/k%10;
            k=k*10;
        }
        k=1;

        if(b[12]==1||b[13]==1||b[14]==1){

        }
        else if(b[0]==1||b[1]==1||b[2]==1){
            moveBack(0.5);
            cameraRight(0.25);
        }
        else if(b[3]==1||b[4]==1||b[5]==1){
            moveBack(0.5);
            cameraLeft(0.25);
        }
        else if(b[6]==1||b[7]==1||b[8]==1){
            cameraRight(0.25);
        }
        else if(b[9]==1||b[10]==1||b[11]==1){
            cameraLeft(0.25);
        }
        else{
            moveDash(2);
            while (rk!=0&&flag == 0) {
                cameraRight(0.5);
                a = detectZombie2();
                printf("B%015ld\n",a);
                if(a!=0){flag=1;}
                cnt++;
                if(cnt==10){
                    moveDash(1);
                    cnt=0;
                }
            }
            flag=0;
        }

        while (rk!=0&&flag == 0) {
            a = detectZombie2();
            printf("C%015ld\n",a);
            c = a % 10;
            if(c==0){
                flag=1;
            }
            attackLeft();
            
        }
        flag=0;
        sleep(0.1);
    }
    setCreative(); // クリエイティブモードにする．
    setMorning();  // 朝にする．
}