#include <stdio.h>
#include <stdlib.h>

#define maxSize 50
typedef int ElemType;//让顺序表存储其他类型元素时，可以快速完成代码修改
typedef struct{
    ElemType data[maxSize];
    int len;
}sqList;
bool insertValue(sqList &L,ElemType value,int pos){
    if(1>pos||pos>L.len+1){
        printf("false\n");
        return false;
    }
    if(L.len==maxSize){
        printf("false\n");
        return false;
    }
    for (int j = L.len; j >=  pos; j--) {
        L.data[j]=L.data[j-1];
    }
    L.data[pos-1]=value;
    L.len++;
    for (int i = 0; i < L.len; ++i) {
        printf("%3d",L.data[i]);
    }
    return true;
}
bool deletePost(sqList &L,int delPos){
    if(delPos>L.len){
        printf("false\n");
        return false;
    }
    for (int i = delPos-1; i < L.len; ++i) {
        L.data[i-1]=L.data[i];
    }
    L.len--;
    for (int i = 0; i < L.len; ++i) {
        printf("%3d",L.data[i]);
    }
    return true;
}
int main() {
    sqList L;
    L.data[0]=1;
    L.data[1]=2;
    L.data[2]=3;
    L.len=3;
    for (int i = 0; i < L.len; ++i) {
        printf("%3d",L.data[i]);
    }
    printf("\n");
    fflush(stdout);
    ElemType value;
    int pos=2;
    scanf("%d",&value);
    fflush(stdout);
    insertValue(L,value,pos);
    printf("\n");
    int delPos;
    fflush(stdout);
    scanf("%d",&delPos);
    fflush(stdout);
    deletePost(L,delPos);
    return 0;
}