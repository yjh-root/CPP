#include <stdio.h>
#include <string.h>

//文件操作
int main() {
    char str[20]="hello\nworld";
    int len=0;//用于保存字符串长度
    long pos;
    int ret;//存储函数的返回值
    FILE *fp;//定义一个FILE类型的指针变量
    fp= fopen("../Files/file.txt","r+");//使用相对路径打开文件
    if(NULL==fp){//判断文件是否打开失败
        perror("fopen");//定位失败原因
        return -1;
    }
    len= strlen(str);
    fwrite(str,sizeof(char),len,fp);
    ret= fseek(fp,-5,SEEK_CUR);
    if(ret!=0){
        perror("fseek");
        fclose(fp);
        return -1;
    }
    pos= ftell(fp);
    printf("now pos=%ld\n",pos);
    memset(str,0,sizeof(str));//清空str
    fread(str,sizeof(char),sizeof(str),fp);
    printf("str=%s\n",str);
    return 0;
}