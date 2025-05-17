#include <stdio.h>
#include <string.h>

void loveYou(int n){
    for (int i = 1; i <= n; ++i) {
        printf("I Love you %d num\n",i);
    }
    printf("I Love you more than %d num\n",n);
}
//文件操作
int main() {
    loveYou(1000);
    return 0;
}