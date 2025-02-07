#include <stdio.h>
#include <stdlib.h>

#define maxSize 50
typedef int ElemType;//让顺序表存储其他类型元素时，可以快速完成代码修改
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

void lest_tail_insert(LinkList &L){//尾插法新建链表
    L=(LinkList) malloc(sizeof (LNode));
    L->next=NULL;
    ElemType x;
    scanf("%d",&x);
    LNode *s,*r=L;//s是指向申请的新结点，r始终指向链表尾部
    while (x!=9999){
        s=(LinkList) malloc(sizeof (LNode));//为新结点申请空间
        s ->data=x;
        r->next=s;//新结点给尾结点的next指针
        r=s;//r要指向新的尾部
        scanf("%d",&x);
    }
    r->next=NULL;//让尾结点的next为NULL
}
void print_list(LinkList L){//链表打印
    L=L->next;
    while (L!=NULL){
        printf("%3d",L->data);
        L=L->next;
    }
    printf("\n");
}

//找到链表中间结点，并设计好L2结点
void find_middle(LinkList L,LinkList &L2){
    L2=(LinkList) malloc(sizeof(LNode));//第二条链表的头结点
    LinkList pcur,ppre;//双指针法遍历(考研初试常考内容)
    ppre=pcur=L->next;
    while (pcur){
        pcur=pcur->next;
        if(NULL==pcur){//为了防止pcur为NULL
            break;
        }
        pcur=pcur->next;
        if(NULL==pcur){//为了使得偶数个时,ppre取值正确
            break;
        }
        ppre=ppre->next;
    }
    L2->next=ppre->next;//由L2头结点指向后面一半链表
    ppre->next=NULL;//前一半链表的最后一个结点,next要为NULL
}

void reverse(LinkList L2){
    LinkList r,s,t;
    r=L2->next;
    if(NULL==r){
        return;//链表为空
    }
    s=r->next;
    if(NULL==s){
        return;//链表只有1个结点
    }
    t=s->next;
    while (t){
        s->next=r;//原地逆置
        r=s;//一下3句是3个指针同时向后走一步
        s=t;
        t=t->next;
    }
    s->next=r;
    L2->next->next=NULL;//逆置后，链表第一个结点的next要为NULL
    L2->next=s;//s是链表的第一个结点
}

void merge(LinkList L,LinkList L2){
    LinkList pcur,p,q;
    pcur=L->next;//pcur始终指向组合后链表的链表尾
    p=pcur->next;//p用来遍历L链表
    q=L2->next;//q指向L2第一个结点,q用来遍历L2链表
    while (p!=NULL&&q!=NULL){
        pcur->next=q;
        q=q->next;//指向下一个
        pcur=pcur->next;
        pcur->next=p;
        p=p->next;
        pcur=pcur->next;
        //任何一个链表都可能剩余一个结点，放进来即可
        if(p!=NULL){
            pcur->next=p;
        }
        if(q!=NULL){
            pcur->next=q;
        }
    }
}

int main() {
    LinkList L;//链表头，是结构体指针类型
    lest_tail_insert(L);//使用尾插法新建链表
    print_list(L);//链表打印
    LinkList L2=NULL;
    find_middle(L,L2);//只用一个结点时，L2中是没有结点的
    printf("===========================\n");
    print_list(L);
    print_list(L2);
    reverse(L2);
    printf("===========================\n");
    print_list(L2);
    printf("===========================\n");
    merge(L,L2);
    free(L2);
    print_list(L);
    return 0;
}