#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10 //顺序表的初始长度
typedef int ElemType;

typedef struct LNode{//定义单链表结构类型
    ElemType data;//每个节点存放一个数据元素
    struct LNode * next;//指针指向下一个节点
} LNode,*LinkList;//给struct LNode取的两个别名
//要表示一个单链表时，需要声明一个头指针L，指向单链表的第一个节点
// LNode * L;或LinkList L;都是声明一个指向单链表第一个节点的指针
//定义LNode*是想强调这是一个节点
//定义LinkList是想强调这是一个单链表

//初始化一个空的单链表
bool InitList(LinkList &L){
    L=(LNode *) malloc(sizeof(LNode));//分配一个头节点
    if (L==NULL)//内存不足,分配失败
        return false;
    L->next=NULL;//头节点之后暂时还没有节点
    return true;
}

//链表判断是否为空
bool Empty(LinkList L){
    return (L->next==NULL);
}

//后插操作:在p节点之后插入元素e
bool InsertNextNode(LNode *p,ElemType e){
    if(p==NULL)//i不合法
        return false;
    LNode *s=(LNode *) malloc(sizeof (LNode));
    if(s==NULL)//内存分配失败
        return false;
    s->data=e;
    s->next=p->next;
    p->next=s;//将节点s连到p之后
    return true;//插入成功
}

//前插操作:在p节点之前插入元素e
bool InsertPriorNode(LNode *p,ElemType e){
    if(p==NULL)
        return false;
    LNode *s=(LNode *) malloc(sizeof(LNode));
    if(s==NULL)//内存分配失败
        return false;
    s->next=p->next;
    p->next=s;//将新节点s连到p之后
    s->data=p->data;//将p中的元素复制到s中
    p->data=e;//p中元素覆盖为e
    return true;
}

//按位查找(带头节点)
LNode *GetElem(LinkList L,int i){
    if(i<0)
        return NULL;
    LNode *p=L;//指针p指向当前扫描到的节点,L指向头节点,头节点是第0个节点(不存数据)
    for (int j = 0;p!=0&&j < i; ++j)//j从0开始循环找到第i-1个节点
        p=p->next;
    return p;
}

//在第i个位置插入元素e(带头节点)
bool ListInsert(LinkList &L,int i,ElemType e){
    LNode *p=GetElem(L,i-1);//找到第i-1个节点
    return InsertNextNode(p,e);
}

//按位删除(带头节点)
bool ListDelete(LinkList &L,int i,ElemType &e){
    LNode *p=GetElem(L,i-1);//找到第i-1个节点
    if(p==NULL||p->next==NULL)
        return false;
    LNode *q=p->next;
    e=q->data;
    p->next=q->next;
    free(q);
    return true;
}

//按值查找
LNode * LocateElem(LinkList L,ElemType e){
    LNode *p=L->next;
    while (p!=NULL&&p->data!=e)
        p=p->next;
    return p;
}

//表长
int Length(LinkList L){
    int len=0;
    LNode *p=L;
    while (p->next!=NULL){
        p=p->next;
        len++;
    }
    return len;
}

//尾插法
LinkList ListTailInsert(LinkList &L){
    ElemType x;
    L=(LinkList)malloc(sizeof(LNode));//创建头节点
    L->next=NULL;//初始化为空链表
    LNode *s,*r=L;//r为表尾指针
    scanf("%d",&x);//输入节点
    while (x!=9999){//输入9999表示结束
        s=(LNode*) malloc(sizeof(LNode));
        s->data=x;
        r->next=s;//在r节点值后插入元素x
        r=s;//永远保持r指向最后一个节点
        scanf("%d",&x);
    }
    r->next=NULL;//尾指针置空
    return L;
}

//头插法
LinkList ListHeadInsert(LinkList &L){
    LNode *s;
    int x;
    L=(LinkList) malloc(sizeof (LNode));//创建头节点
    L->next=NULL;//初始化为空链表
    scanf("%d",&x);//输入节点
    while (x!=9999){//输入9999表示结束
        s=(LNode *) malloc(sizeof (LNode));//创建新节点
        s->data=x;
        s->next=L->next;
        L->next=s;//将新节点插入表中，L为头指针
        scanf("%d",&x);
    }
    return L;
}

// 打印链表元素
void PrintList(LinkList L) {
    LNode *p = L->next; // 从第一个实际节点开始
    printf("链表内容：");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int LB() {
    LinkList L;//声明一个指向单链表的指针。
    InitList(L);
    Empty(L);
    ElemType e;
    for (int i = 1,j=3; i<=6;++i,++j) {
        ListInsert(L,i,j);
    }
    PrintList(L);
    ListInsert(L,6,10);
    PrintList(L);
    ListDelete(L,3,e);
    PrintList(L);
    printf("被删掉的数据是%d",e);
    return 0;
}