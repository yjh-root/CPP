#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

//精度丢失
int main() {
    //赋值的一瞬间发生精度丢失，因为浮点数常量默认是8个字节存储float型
    float a=1.23456789e10,b;//12345678900
    double c=1.23456789e10,d,f;//12345678900
    //理论上结果应该是12345678920
    b=a+20;//精度丢失
    d=c+20;//精度未丢失
    f=a+20;//精度丢失
    printf("b=%f\n",b);//%f即可输出float，也可输出double
    printf("d=%f\n",d);//%f即可输出float，也可输出double
    printf("f=%f\n",f);//%f即可输出float，也可输出double
    return 0;
}