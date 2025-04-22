#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

int add(int a,int b){
    int ret;
    ret=a+b;
    return ret;
}
int main() {
    int a,b,ret;
    int *p;
    a=5;
    p=&a;
    b=*p+2;
    ret= add(a,b);
    printf("add result=%d\n",ret);
    return 0;
}