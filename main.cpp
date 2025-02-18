#include <stdio.h>
#include <stdlib.h>

#define maxSize 5
typedef int ElemType;//让顺序表存储其他类型元素时，可以快速完成代码修改
typedef struct LinkNode{//顺序表定义
    ElemType data;
    struct LinkNode *next;
}LinkNode,*LinkList;

typedef struct {//链表队列定义
    LinkNode *front,*rear;//链表头，链表尾
}LinkQueue;//先进先出

typedef struct {//栈定义
    ElemType data[maxSize];//数组，存放栈的元素
    int top;//始终指向栈顶的一个变量
}SqStack;

typedef struct {//循环队列定义
    ElemType data[maxSize];//数组，存储maxSize-1个元素
    int front,rear;//队列头,队列尾
}SqQueue;

//队列的初始化使用的是带头结点的链表实现的
void InitQueue(LinkQueue &Q){
    Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));//头和尾指向同一个结点
    Q.front->next=NULL;//头结点的next指针为NULL
}

//入队
void EnQueue(LinkQueue &Q,ElemType x){
    LinkNode *pNew=(LinkNode*)malloc(sizeof(LinkNode));
    pNew->data=x;
    pNew->next=NULL;//要让next为NULL
    Q.rear->next=pNew;//尾指针的next指向pNew,因为从尾部插入
    Q.rear=pNew;//rear要指向新的尾部
}

//出队
bool DnQueue(LinkQueue &Q,ElemType &x){
    if(Q.rear==Q.front){//队列为空
        return false;
    }
    LinkNode *q=Q.front->next;//链表的第一个结点，存入q
    x=q->data;//获取要出队的元素值
    Q.front->next=q->next;//让一个结点断链
    if(Q.rear==q){//链表只剩余一个结点时，被删除后，要改变rear
        Q.rear=Q.front;
    }
    free(q);
    return true;
}

int main() {
    LinkQueue Q;
    InitQueue(Q);
    for (int i = 3; i <= 7; ++i) {
        EnQueue(Q,i);
    }
    ElemType elemType;
    bool ret;
    for (int i = 0; i < 7; ++i) {
        ret=DnQueue(Q,elemType);
        if(ret){
            printf("DnQueue success element=%d\n",elemType);
        } else{
            printf("DnQueue failed\n");
        }
    }
    return 0;
}