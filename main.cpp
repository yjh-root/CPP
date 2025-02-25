#include <stdio.h>
#include <stdlib.h>

typedef int BiElemType;//让顺序表存储其他类型元素时，可以快速完成代码修改
int wpl=0;
typedef struct BiTNode{//二叉树定义
    BiElemType weight;
    struct BiTNode *lChild;
    struct BiTNode *rChild;
}BiTNode,*BiTree;

//tag结构体是辅助队列使用的
typedef struct tag{
    BiTree p;//树的某一个结点的地址值
    struct tag *pNext;
}tag_t,*pTag_t;

void preOrder(BiTree tree,int deep){
    if(tree!=NULL){
        if(tree->rChild==NULL&& tree->lChild==NULL){
            wpl=wpl+tree->weight*deep;
        }
        printf("ele%c--%d\n",tree->weight,deep);
        preOrder(tree->lChild,deep+1);
        preOrder(tree->rChild,deep+1);
    }
}

int main() {
    BiTree pNew;//用来指向新申请的树结点
    BiTree tree=NULL;//tree是指向树根的，代表树
    pTag_t pHead=NULL,pTail=NULL,listPNew=NULL,pCur;
    char c;
    //层次建树
    while (scanf("%c",&c)){
        if(c=='\n'){//读到换行就结束
            break;
        }
        //calloc申请的空间大小是两个参数直接相乘，并对空间初始化，赋值为0
        pNew= (BiTree)calloc(1,sizeof(BiTNode));
        pNew->weight=c;
        listPNew=(pTag_t) calloc(1,sizeof (tag_t ));//给队列结点申请空间
        listPNew->p=pNew;
        //如果是树的第一个结点
        if(NULL==tree){
            tree=pNew;//tree指向树的根结点
            pHead=listPNew;//第一个结点既是队列头也是队列尾
            pTail=listPNew;
            pCur=listPNew;//pCur要指向要进入树的父亲元素
        } else{
            //让元素先入队列
            pTail->pNext=listPNew;
            pTail=listPNew;
            //接下来把b结点放入树中
            if(NULL==pCur->p->lChild){
                pCur->p->lChild=pNew;//pCur->p左孩子为空就放入左孩子
            } else if(NULL==pCur->p->rChild){
                pCur->p->rChild=pNew;//pCur->p右孩子为空就放入右孩子
                pCur=pCur->pNext;//当前结点左右孩子都有了，pCur就指向下一个
            }
        }
    }
    preOrder(tree,1);
    printf("wpl=%d\n",wpl);
    return 0;
}