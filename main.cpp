#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode{
    int data;
    struct Lnode *next;
}Lnode,*LinkList;
int main() {
    Lnode *L;
    L=(LinkList) malloc(sizeof(Lnode));
    return 0;
}