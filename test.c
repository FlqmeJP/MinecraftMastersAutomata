#include "control.h"
#include <stdio.h>
#include <unistd.h>
int main(void) {
    init();
    exePython();
    int a,i,k=1;
    int b[7]; 

    while(rk){
        a = detectZombie1();
        printf("%07d ", a);
        for (i = 0; i < 7; i++) {
            b[6 - i] = a / k % 10;
            k = k * 10;
        }
        k = 1;
        if(b[0]==1){printf("左上 ");}
        if(b[1]==1){printf("中央上 ");}
        if(b[2]==1){printf("右上 ");}
        if(b[3]==1){printf("左下 ");}
        if(b[4]==1){printf("中央下 ");}
        if(b[5]==1){printf("右下 ");}
        printf("\n");
        sleep(1);
    }
    return 0;
}