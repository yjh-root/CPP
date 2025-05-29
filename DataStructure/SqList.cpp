#include <stdio.h>
#include <stdlib.h>

/**
 * 顺序表实战代码
 */
#define MaxSize 10 //顺序表的初始长度
typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;

//初始化
void InitLst(SqList &L){
    for (int i = 0; i < MaxSize; ++i)
        L.data[i]=0;
    L.length=0;
}

//校验是否为空
bool EmptyList(SqList L){
    if(L.length==0)
        return true;
    else
        return false;
}

// 插入元素到顺序表
bool InsertElem(SqList &L, ElemType elem) {
    if (L.length == MaxSize) {  // 检查是否已满
        printf("List is full, cannot insert\n");
        return false;
    }
    L.data[L.length] = elem;  // 插入元素
    L.length++;               // 更新顺序表的长度
    return true;
}

//插入元素到顺序表
bool InsertList(SqList &L,int i,ElemType e){
    if(i<1||i>L.length+1)
        return false;
    if(L.length>MaxSize)
        return false;
    for (int j = L.length; j >=i ; --j)
        L.data[j]=L.data[j-1];
    L.data[i-1]=e;
    L.length++;
    return true;
}

//删除顺序表中某个位置的元素
bool DeleteList(SqList &L,int i,ElemType &e){
    if(i<1||i>MaxSize)
        return false;
    e=L.data[i-1];
    for (int j = i; j < L.length; ++j)
        L.data[j-1]=L.data[j];
    L.length--;
    return true;
}

//顺序查找
int LocalElem(SqList L,ElemType elemType){
    int i;
    for (i = 0; i < L.length; ++i) {
        if(L.data[i]==elemType)
            return i+1;
    }
    return 0;
}

//打印
void printList(SqList L){
    printf("Elements in the list: ");
    for (int i = 0; i < L.length; ++i) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int sxb() {
    SqList L;
    InitLst(L);
    EmptyList(L);
    for (int i = 1; i < 6; ++i) {
        InsertElem(L,i);
    }
    // 打印顺序表中的元素
    printList(L);
    InsertList(L,3,8);
    printList(L);
    ElemType elemType;
    DeleteList(L,5,elemType);
    printList(L);
    printf("local elem num is %d",LocalElem(L,3));
    int target=9;
    int array[2];
    int nums[4]= {2,7,11,15};
    for (int i = 0; i <sizeof(nums)/sizeof(nums[0]); ++i) {
        for (int j = i+1; j <sizeof(nums)/sizeof(nums[0]); ++j) {
            if(nums[i]+nums[j]==target){
                array[0]=i;
                array[1]=j;
                break;
            }
        }
    }
    return 0;
}