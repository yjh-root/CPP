#include <stdio.h>

typedef struct student{
    int num;
    char name[20];
    char sex;
}stu,*pStu;

int main() {
    stu s;
    scanf("%d%s %c",&s.num,s.name,&s.sex);
    printf("num:%d,name:%s,sex:%c",s.num,s.name,s.sex);
}