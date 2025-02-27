#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int keyType;//让顺序表存储其他类型元素时，可以快速完成代码修改
typedef struct BSTNode{
    keyType key;
    struct BSTNode *lChild,*rChild;
}BSTNode,*BiTree;

//递归创建二叉排序树
int BSTInsert1(BiTree &T,keyType key){
    if(NULL==T){//为新结点申请空间，第一个结点作为树根,后面递归再进入的不是树根，是为叶子结点
        T=(BiTree) malloc(sizeof(BSTNode));
        T->key=key;
        T->lChild=T->rChild=NULL;
        return 0;//代表插入成功
    } else if(key==T->key)
        return -1;//发现相同元素，就不插入
    else if(key<T->key)//如果要插入的结点，小于当前结点
        //函数调用结束后，左孩子和原来的父亲会关联起来，巧妙利用了引用机制
        return BSTInsert1(T->lChild,key);
    else
        return BSTInsert1(T->rChild,key);
}

//非递归创建二叉排序树
int BSTInsert(BiTree &T,keyType key){
    BiTree treeNew= (BiTree)calloc(1,sizeof(BSTNode));//新结点申请空间
    treeNew->key=key;//把值放入
    if(NULL==T){//树为空，新结点作为树根
        T=treeNew;
        return 0;
    }
    BiTree p=T,parent;//用来查找树
    while (p){
        parent=p;//parent用来存p的父亲
        if(key>p->key){
            p=p->rChild;
        } else if(key<p->key){
            p=p->lChild;
        } else{
            return -1;//相等的元素不可以放入查找树(考研不会考)
        }
    }
    //接下来要判断放到父亲的左边还是右边
    if(key>parent->key){//放到父亲的右边
        parent->rChild=treeNew;
    } else{//放到父亲的左边
        parent->lChild=treeNew;
    }
    return 0;
}

//树中不放入相等元素
void creatBST(BiTree &T,keyType* str,int len){
    for (int i = 0; i < len; ++i) {
        BSTInsert(T,str[i]);//把某一结点放入二叉排序树
    }

}

//中序遍历
void inOrder(BiTree T){
    if(NULL!=T){
        inOrder(T->lChild);
        printf("%3d",T->key);
        inOrder(T->rChild);
    }
}

BiTree BSTSearch(BiTree T,keyType k,BiTree &parent){
    parent=NULL;//存储要找的结点的父亲
    while (T!=NULL&&k!=T->key){
        parent=T;
        if(k<T->key)
            T=T->lChild;//比当前结点小，就左边找
        else
            T=T->rChild;//比当前结点大，就右边找
    }
    return T;
}
//二叉排序树新建，中序遍历，查找
int main() {

    BiTree T=NULL;//树根
    keyType str[7]={97,54,87,51,22,98,15};
    creatBST(T,str,7);
    inOrder(T);//中序遍历二叉查找树是由小到大的
    printf("\n");
    BiTree search,parent;
    search=BSTSearch(T,98,parent);
    if(search){
        printf("find key %d\n",search->key);
    } else{
        printf("not find");
    }
    return 0;
}