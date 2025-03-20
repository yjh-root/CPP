#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#define N 10

int setPartition(int a[],int n){
    int pivotkey,low=0,low0=0,high=n-1,high0=n-1,flag=1,k=n/2,i;
    int s1=0,s2=0;
    while (flag){//当low等于k-1,也就是n/2-1时，分割结束
        pivotkey=a[low];//选择枢轴
        while (low<high){//基于枢轴对数据进行划分
            while (low<high && a[high]>=pivotkey)
                --high;
            if(low !=high)
                a[low]=a[high];
            while (low<high && a[low]<=pivotkey)
                ++low;
            if(low != high)
                a[high]=a[low];
        }
        a[low]=pivotkey;//把分割值放到对应位置
        if(low==k-1)//如果枢轴是n/2 小元素，划分成功
            flag=0;
        else{//是否继续划分
            if(low<k-1){
                low0=++low;//low0只是做暂存，为下次使用准备，这里我们++low，low比分割值大1
                high=high0;//把上次暂存的high0拿过来
            } else{
                low=low0;//把上次暂存的low0拿过来
                high0=--high;//high0只是做暂存，为下次使用做准备
            }
        }
    }
    for ( i = 0; i < k; i++)
        s1+=a[i];
    for ( i = k; i < n; i++)
        s2+=a[i];
    return s2-s1;
}

int main() {
    int A[N]={4,1,12,18,7,13,18,16,5,15};
    int difference;
    difference=setPartition(A,N);//考研初试只需要完成setPartition即可，无需编写这个main函数
    printf("%d",difference);
    return 0;
}