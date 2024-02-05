#include "control.h"
#include <stdio.h>
#include <unistd.h>

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

int main(void) {
    init();
    exePython();
    long int a;
    long int k = 1;
    int i,flag=0;
    int z1[7];
    long int z2[15]; 

    while(rk){
        flag = 0;
        int z1[7];
        long int z2[15];

        printf("zombie1\n");
        zombie1(z1);
        if(z1[0]==1){printf("左上 ");}
        if(z1[1]==1){printf("中央上 ");}
        if(z1[2]==1){printf("右上 ");}
        if(z1[3]==1){printf("左下 ");}
        if(z1[4]==1){printf("中央下 ");}
        if(z1[5]==1){printf("右下 ");}
        printf("\n");

        printf("zombie2\n");
        flag = zombie2(z2);//数字がバグっていたらflag=1になる。正常値ならflag=0;
        if(flag==0){
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
        }
        else{printf("error");}
        printf("\n");
        
        sleep(1);
    }
    return 0;
}