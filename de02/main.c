#include <stdio.h>
#include "libA.h"



void loop(int n){
    int m = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            m++;
        }
    }
}

void fun2(){
    return;
}

void fun1(){
    fun2();
}

int main(void) {

    loop(10000);
    fun1();
    printf("Hello, World!\n");
    functionA();
    return 0;
}
