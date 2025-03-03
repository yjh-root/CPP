#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//二分查找中位数
int midSearch(int *A,int *B,int n){
    //分别表示序列A和B的首位数，末位数和中位数,s是start简写，d是end的简写
    int s1=0,d1=n-1,m1,s2=0,d2=n-1,m2;
    //循环判断结束条件是，两个数组均不断删除最后均只能剩余一个元素
    while (s1!=d1||s2!=d2){
        m1=(s1+d1)/2;
        m2=(s2+d2)/2;
        if(A[m1]==B[m2]){
            return A[m1];
        } else if(A[m1]<B[m2]){
            if((s1+d1)%2==0){//若元素个数为奇数，这里注意数组下标从0开始
                s1=m1;//舍弃A中间点以前的部分保留中间点
                d2=m2;//舍弃B中间点以后的部分保留中间点
            } else{//元素个数为偶数
                s1=m1+1;//舍弃A中间点及中间点以前的部分
                d2=m2;//舍弃B中间点以前的部分
            }
        } else{
            if((s1+d1)%2==0){//若元素个数为奇数，这里注意数组下标从0开始
                d1=m1;//舍弃A中间点以后的部分保留中间点
                s2=m2;//舍弃B中间点以前的部分保留中间点
            } else{//元素个数为偶数
                d1=m1;//舍弃A中间点以后的部分
                s2=m2+1;//舍弃B中间点及中间点以前的部分
            }
        }
    }
    return A[s1]<B[s2]?A[s1]:B[s2];
}
int main() {
    int A[]={11,13,15,17,19};
    int B[]={2,4,6,8,20};
    int mid=midSearch(A,B,5);
    printf("mid=%d\n",mid);
    return 0;
}