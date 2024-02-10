#include "control.h"
#include <stdio.h>
#include <unistd.h>

int zombie1(int z1[]);
int zombie2(long int z2[]);
void z1print(int z1[]);
void z2print(long int z2[]);

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

        zombie2(z2);
        printf("\n");

        sleep(1);
    }
    return 0;
}