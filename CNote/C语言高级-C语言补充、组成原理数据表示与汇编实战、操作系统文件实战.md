# 1、C语言语法进阶

## 1.1条件运算符

条件运算符是C语言中唯一的一个三目运算符，三目运算符代表有三个操作数。运算符也称为操作符。条件运算符通过判断问号之前的表达式的真假来确定整体表达式的值

eg.

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

int main() {
    int a=5,b=10,max;
        max=a>b?a:b;//条件运算符的优先级高于赋值运算符
        printf("max=%d",max);
    return 0;
}
```

ie.

```
D:\CLionProjects\CPP\cmake-build-debug\CPP.exe
max=10
Process finished with exit code 0
```

## 1.2逗号运算符

逗号运算符的优先级最低，逗号表达式的整体值是最后一个表达式的值

eg.

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

int main() {
    int i=10,j=1;
    if(i+3,j-1){//逗号表达因为优先级最低，所以它的值是最后一个表达式的值
        printf("if not execute");
    }
    if(i+3,j){//逗号表达因为优先级最低，所以它的值是最后一个表达式的值
        printf("if execute");
    }
    //逗号表达式的常见使用场景，for的表达式1初始化多个变量
    for (i=0,j=1;i<10;i++){
        
    }
    return 0;
}
```

ie.

```
D:\CLionProjects\CPP\cmake-build-debug\CPP.exe
if execute
Process finished with exit code 0
```

## 1.3自增自减运算符

自增、自减运算符和其他运算符有很大的区别，因为其他运算符除赋值运算符可以改变变量本身的值外，不回有这种效果。因为自增、自减会改变变量的值，所以不能用于常量

eg.

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

int main() {
    int i=-1,j;
    j=i++>-1;//后++等价于j=i>-1;i=i+1;
    printf("i=%d,j=%d\n",i,j);
    int a=-1,b;
    b=++a>-1;//前++等价于a=a+1;b=(b+1)>-1
    printf("a=%d,b=%d",a,b);
    return 0;
}
```

ie.

```
D:\CLionProjects\CPP\cmake-build-debug\CPP.exe
i=0,j=0
a=0,b=1
Process finished with exit code 0
```

eg.自增自减运算符与取值运算符

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

//自增自减运算符与取值运算符结合
int main() {
    int a[3]={3,7,8};
    int *p;
    int j;
    p=a;//p指向数组其实元素
    j=*p++;//先把*p的值赋给j，然后对p加1，等价于语句 j=*p;p++;
    printf("a[0]=%d,j=%d,*p=%d\n",a[0],j,*p);
    j=p[0]++;//先把p[0]赋给j，然后对p[0]加一，等价于语句j=p[0];p[0]++
    printf("a[0]=%d,j=%d,*p=%d",a[0],j,*p);
    return 0;
}
```

ie.

```
D:\CLionProjects\CPP\cmake-build-debug\CPP.exe
a[0]=3,j=3,*p=7
a[0]=3,j=7,*p=8
Process finished with exit code 0
```

## 1.4位运算符

位运算符<<,>>,~,|,^,&依次是左移，右移，按位取反，按位或，按位异或，按位与。位运算符只能用于对整型

数据进行操作

左移:高位丢弃，低位补0，相当于乘以2。工作中很多时候申请内存时会用左移，例如要申请$1GB$大小的空间，可以使用$malloc(1<<30)$

右移:低位丢弃，正数的高位补0(无符号数我们认为时正数)，负数的高位补1，相当于除以2。移位比乘法和除发的效率要高，负数右移，对偶数来说时除以2，但对奇数来说试是先减1，后除以2，例如，$-8>>1$，得到的是$-4$,但$-7>>1$得到的并不是$-3$而是$-4$。另外对于$-1$来说，无论右移多少位，值永远是$-1$。

C语言的左移和右移相当于算数左移与算数右移。考研中的逻辑左移与右移，左移和右移空位都补0。

异或:相同数进行异或时，结果为0，任何数和0异或的结果是其本身。

按位取反:数位上的数是1变0，0变1

按位与和按位或:用两个数的每一位进行与和或

eg.左移

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

//位运算符:左移
int main() {
    short i=5;//short是2个字节的整型，int是4个字节
    short j;
    j=i<<1;//一个变量移动以后自身不会变化
    printf("j=%d",j);
    return 0;
}
```

ie.

```
D:\CLionProjects\CPP\cmake-build-debug\CPP.exe
j=10
Process finished with exit code 0
```

解析:
$$
代码输入:十进制:5\\
Clion内存视图:十六进制:00\quad 05\\
实际计算:二进制:0000\quad 0000\quad 0000\quad 0101\\
高位丢弃:000\quad 0000\quad 0000\quad 0101\\
低位补0:0000\quad 0000\quad 0000\quad 1010\\
Clion内存视图:十六进制:0a\quad 00\\
控制台输出:十进制:10
$$
内存视图:

![image-20250325165252809](C语言高级-C语言补充、组成原理数据表示与汇编实战、操作系统文件实战.assets/image-20250325165252809.png)

![image-20250325165326340](C语言高级-C语言补充、组成原理数据表示与汇编实战、操作系统文件实战.assets/image-20250325165326340.png)

eg.有符号右移

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

//位运算符：左移与右移
int main() {
    short i=5;//short是2个字节的整型，int是4个字节
    short j;
    j=i<<1;//一个变量移动以后自身不会变化
    printf("j=%d\n",j);//左移是乘2，结果是10
    j=i>>1;
    printf("j=%d",j);//右移是除以2，结果是2
    return 0;
}
```

ie.

```
D:\CLionProjects\CPP\cmake-build-debug\CPP.exe
j=10
j=2
Process finished with exit code 0
```

解析
$$
代码输入:十进制:5\\
Clion内存视图:十六进制:00\quad 05\\
实际计算:二进制:0000\quad 0000\quad 0000\quad 0101\\
short类型，高位为0，视为正数\\
高位补0:00000\quad 0000\quad 0000\quad 0101\\
低位丢弃:0000\quad 0000\quad 0000\quad 0010\\
Clion内存视图:十六进制:02\quad 00\\
控制台输出:十进制:2
$$
内存视图:

![image-20250325165923742](C语言高级-C语言补充、组成原理数据表示与汇编实战、操作系统文件实战.assets/image-20250325165923742.png)

![image-20250325165956068](C语言高级-C语言补充、组成原理数据表示与汇编实战、操作系统文件实战.assets/image-20250325165956068.png)

eg.无符号右移

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

//位运算符:右移
int main() {
    short i=0x8011,j=0;
    unsigned short s=0x8011;//在short前加unsigned,无符号数是非负数
    unsigned short r=0;
    j=i>>1;//对i右移，对有符号数进行右移
    r=s>>1;//对s右移，对无符号数进行右移
    printf("j=%d,r=%d",j,r);
    return 0;
}
```

ie.

```
D:\CLionProjects\CPP\cmake-build-debug\CPP.exe
j=-16376,r=16392
Process finished with exit code 0
```

解析:
$$
有符号右移:\\
代码输入:i,十六进制:8011\\
Clion内存视图:十六进制:1180(小端)\\
实际计算:二进制:1000\quad 0000\quad 0001\quad 0001\\
short类型\quad 高位为1，负数\\
高位补1:二进制:11000\quad 0000\quad 0001\quad 0001\\
低位丢弃:二进制:1100\quad 0000\quad 0000\quad 1000\\
Clion内存视图:十六进制:08\quad c0\\
控制台输出:j,十进制:-16376\\
无符号右移:\\
代码输入:s,十六进制:8011\\
Clion内存视图:十六进制:1180(小端)\\
实际计算:二进制:1000\quad 0000\quad 0001\quad 0001\\
unsigned\quad short类型,视为正数\\
高位补1:二进制:01000\quad 0000\quad 0001\quad 0001\\
低位丢弃:二进制:0100\quad 0000\quad 0000\quad 1000\\
Clion内存视图:十六进制:08\quad 40\\
控制台输出:r,十进制:-16392\\
$$
内存视图:

![image-20250327105629417](C语言高级-C语言补充、组成原理数据表示与汇编实战、操作系统文件实战.assets/image-20250327105629417.png)

![image-20250327105655472](C语言高级-C语言补充、组成原理数据表示与汇编实战、操作系统文件实战.assets/image-20250327105655472.png)

![image-20250327105725535](C语言高级-C语言补充、组成原理数据表示与汇编实战、操作系统文件实战.assets/image-20250327105725535.png)

![image-20250327105754129](C语言高级-C语言补充、组成原理数据表示与汇编实战、操作系统文件实战.assets/image-20250327105754129.png)

eg.按位与，按位或，按位异或，按位取反

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

//位运算符:按位与，按位或，按位异或，按位取反
int main() {
    short i=5,j=7;
    printf("i & j=%d\n",i&j);//按位与
    printf("i | j=%d\n",i|j);//按位或
    printf("i ^ j=%d\n",i^j);//按位异或
    printf("~i=%d",~i);//按位取反
    return 0;
}
```

.ie

```
D:\CLionProjects\CPP\cmake-build-debug\CPP.exe
i & j=5
i | j=7
i ^ j=2
~i=-6
Process finished with exit code 0
```

解析:
$$
i:二进制:0000\quad 0000\quad 0000 \quad 0101\\
j:二进制:0000\quad 0000\quad 0000 \quad 0111\\
按位与计算:\\
101\&111=(1\&1)(0\&1)(1\&1)=(1)(0)(1)=101\\
i\&j:二进制:0000\quad 0000\quad 0000 \quad 0101\\
i\&j:十进制:5\\
按位或计算:\\
101|111=(1|1)(0|1)(1|1)=(1)(1)(1)=111\\
i\&j:二进制:0000\quad 0000\quad 0000 \quad 0111\\
i\&j:十进制:7\\
按位取反计算:\\
i:二进制:0000\quad 0000\quad 0000 \quad 0101\\
\~i:二进制:1111\quad 1111\quad 1111 \quad 1010\\
~i:十进制:-6\\
解析:\\
①~i最高位为1，是负数\\
②然后再次进行取反+1\\
~~i:二进制:0000\quad 0000\quad 0000 \quad 0110(补码)\\
~~i:十进制:6\\
综合①，②得~i=-6\\
异或计算\\
异或计算规则:相同为0，相异为1\\
i:二进制:0000\quad 0000\quad 0000 \quad 0101\\
j:二进制:0000\quad 0000\quad 0000 \quad 0111\\
i^j:二进制:0000\quad 0000\quad 0000\quad 0010\\
十进制:2
$$
<font color="red">异或运算有两个特性，一个是任何数和零异或得到的是自身，两个相等的数异或得到的是零，异或满足交换律</font>

例题，数组$A=\{8,5,3,5,8\}$,找出只出现了一次的那个数

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

int main() {
    int A[5]={5,8,3,8,5};
    int result=0;
    for (int i = 0; i < 5; ++i) {
        result ^=A[i];
    }
    printf("result=%d",result);
    return 0;
}
```

```
D:\CLionProjects\CPP\cmake-build-debug\CPP.exe
result=3
Process finished with exit code 0
```

## 1.5二维数组

二维数组定义的一般形式如下:

```
类型说明符 数组名[常量表达式][常量表达式]
```

eg.定义$a为3\times4(3行4列)$的数组，$b为5\times10(5行10列)$的数组

```
float a[3][4],b[5][10]
```

可以将二维数组视为一种特殊的一维数组:一个数组中的元素类型是一维数组的一维数组

eg.可以把二维数组$a[3][4]$视为一个一维数组，它有三个元素$a[0],a[1]和[a2]$,每个元素又是一个包含4个元素的一维数组

![image-20250327144638172](C语言高级-C语言补充、组成原理数据表示与汇编实战、操作系统文件实战.assets/image-20250327144638172.png)

二维数组中的元素在内存中的存储规则是按行存储，即先顺序存储第一个的元素，后顺序存储第二行的元素，数组元素的获取一次是从$a[0][0]到a[0][1]$,直到最后一个元素$a[2][]3$

![image-20250327145133764](C语言高级-C语言补充、组成原理数据表示与汇编实战、操作系统文件实战.assets/image-20250327145133764.png)

eg.

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

int main() {
    int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    printf("sizeof(a)=%d\n",sizeof(a));
    printf("a[2][3]=%d",a[2][3]);
    return 0;
}
```

ie.

```
D:\CLionProjects\CPP\cmake-build-debug\CPP.exe
sizeof(a)=48
a[2][3]=12
Process finished with exit code 0
```

内存视图

![image-20250327153238080](C语言高级-C语言补充、组成原理数据表示与汇编实战、操作系统文件实战.assets/image-20250327153238080.png)

# 2、数据的机器级表示

## 2.1补码

计算机的$CPU$无法做减法操作(硬件上没有减法器)，只能做加法操作，$CPU$中有一个逻辑单元叫<font color="red">加法器。计算机所作的减法，都是通过加法器将其变化为加法实现的。</font>例如实现$2-5的方法是2+(-5)$。由于计算机只能存储0和1，因此我们编写程序来查看计算机是如何存储$-5$的，5的二进制数为$101$，称为<font color="red">原码</font>。计算机用补码表示$-5$，补码是对原码取反后加1的结果，即计算机表示$-5$时会对5的二进制($101$)取反后加1。

![image-20250327160830977](C语言高级-C语言补充、组成原理数据表示与汇编实战、操作系统文件实战.assets/image-20250327160830977.png)

$-5$在内存中存储为$0xfffffffb$,因为对5取反后得到$0xfffffffa$,加1后得到$0xfffffffb$(由于是$x86$架构是小端存储，小端存储是低字节在前，高字节在后，即低字节在低地址，高字节在高地址，$fb$对于$0xfffffffb$是最低字节，因此$fb$在最前面，大端和小端相反)，对其加2后得$0xfffffffd$它就是k的值

![image-20250327162029442](C语言高级-C语言补充、组成原理数据表示与汇编实战、操作系统文件实战.assets/image-20250327162029442.png)


$$
5的原码:0000\quad 0000\quad 0000\quad 0000\quad 0000\quad 0000\quad 0000\quad 0101\\
原码的补码表示其负数\\
原码取反后加一得补码\\
补码-5:1111\quad 1111\quad 1111\quad 1111\quad 1111\quad 1111\quad 1111\quad 1011\\
对于有符号数，最高位为1就是负数，最高位为0就是正数\\
2的原码:0000\quad 0000\quad 0000\quad 0000\quad 0000\quad 0000\quad 0000\quad 0010\\
-5与2两者相加:1111\quad 1111\quad 1111\quad 1111\quad 1111\quad 1111\quad 1111\quad 1101(补码-3)\\
补码变原码依然可以通过取反加1获得\\
原码:0000\quad 0000\quad 0000\quad 0000\quad 0000\quad 0000\quad 0000\quad 0011(原码3)\\
$$
当最高位为1(代表负数)时，要取得原码才知道$0xfffffffd$的值，即对其取反后加1(当然，也可减1后取反，结果是一样的)得到3，所以其值为$-3$。

反码:反码是一种在计算机中数的机器码表示，对于单个数值(二进制的0和1)而言，对其进行取反操作就是将0变为1，1变为0，正数的反码和原码一样，负数的反码就是在原码的基础上符号保持不变，其他位取反

| 十进制 |   原码    |   反码    |
| :----: | :-------: | :-------: |
|   6    | 0000 0110 | 0000 0110 |
|   -3   | 1000 0011 | 1111 1100 |

## 2.2整型不同类型解析

整型变量包括六种类型，其中有符号短整型与无符号短整型的最高位所代表的意义不同。不同整型变量表示的整型的范围不同。超出范围会发生溢出现象，导致计算报错。

![image-20250328104230001](C语言高级-C语言补充、组成原理数据表示与汇编实战、操作系统文件实战.assets/image-20250328104230001.png)![image-20250328104343223](C语言高级-C语言补充、组成原理数据表示与汇编实战、操作系统文件实战.assets/image-20250328104343223.png)

<center>不同整型变量表示的整型数的范围</center>

| 类型         | 类型说明符            | 长度               | 整形术的范围                                       | 十进制             |
| ------------ | --------------------- | ------------------ | -------------------------------------------------- | ------------------ |
| 基本整型     | $int$                 | 4字节              | $-2^{31} \sim(2^{31}-1)$                           | $-21亿\sim21亿$    |
| 短整型       | $short$               | 2字节              | $-2^{15} \sim(2^{15}-1)$                           | $-32768\sim 32767$ |
| 长整型       | $long$                | 4字节(64位为8字节) | $-2^{31} \sim(2^{31}-1)$或$-2^{63} \sim(2^{63}-1)$ |                    |
| 无符号整型   | $unsigned\quad int$   | 4字节              | $0\sim(2^{32}-1)$                                  | $0\sim21亿$        |
| 无符号短整型 | $unsigned\quad short$ | 2字节              | $0\sim (2^{16}-1)$                                 | $0\sim 65535$      |
| 无符号长整形 | $unsigned\quad long$  | 4字节(64位为8字节) | $0\sim(2^{32}-1)$或$0\sim(2^{64}-1)$               |                    |

## 2.3溢出解析

有符号短整型数可以表示的最大值为32767，我们对其加1时，值会变为多少呢，实际运行打印得到的是$-32768$

解析：
$$
十进制:32767\\
二进制:0111\quad1111\quad1111\quad1111\\
加1后:1000\quad0000\quad0000\quad0000\\
十进制:-32768\\
$$
eg.

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

//整型不同类型及溢出演示
int main() {
    int i=10;
    short a=32767;
    short b=0;
    long c;//32位的程序是4字节，64位程序是8字节
    b=a+1;//发生了溢出，解决溢出的办法是用更大的空间来从存
    printf("b=%d\n",b);
    unsigned int m=3;
    unsigned short n=0x8056;//无符号类型，最高位不认为是符号位
    unsigned long k=5;
    b=0x8056;
    printf("b=%d\n",b);//b是有符号类型，所以输出是负值
    printf("n=%u",n);//无符号类型要用%u,用%d是不规范的
}
```

ie.

```
D:\CLionProjects\CPP\cmake-build-debug\CPP.exe
b=-32768
b=-32682
n=32854
Process finished with exit code 0
```

## 2.4浮点数IEEE754标准解析

在C语言中，要使用$float$关键字或$double$关键字定义浮点型变量。***$float$型变量占用内存空间为4个字节，$double$型变量占用的内存空间为8个字节***。与整型数据的存储方式不同，浮点型数据是按照指数形式存储的。系统把一个浮点型数据分为小数部分(用$M$表示)和指数部分(用$E$表示)并分别存放。指数部分采用规范化的指数形式，指数也分正、负(符号位，用$S$表示)。

数符(即符号位)占1位，是0时代表正数，是1时代表负数

![image-20250328143826935](C语言高级-C语言补充、组成原理数据表示与汇编实战、操作系统文件实战.assets/image-20250328143826935.png)

<center>IEEE-754浮点型变量存储标准</center>

|    格式    | $SEEEEEEE$ | $EMMMMMMM$ | $MMMMMMMM$ | $MMMMMMMM$ |
| :--------: | :--------: | :--------: | :--------: | :--------: |
|  二进制数  |  01000000  |  10010000  |  00000000  |  00000000  |
| 十六进制数 |     40     |     90     |     00     |     00     |

$S:S$是符号位，用来表示正、负，是1是代表负数，是0时代表正数。

$E:E$代表指数部分(指数部分的值规定只能是1到254，不能是全0，全1)，指数部分运算前都要减去127(这是$IEEE-754$的规定)，因为还要表示负指数，这里的1000001转化为十进制数为129，$129-127=2$,即实际指数部分为2。

$M:M$代表小数部分，这里为$0010\quad0000\quad0000\quad0000\quad0000\quad000$,底数左边省略存储了一个1(这是$IEEE-754$的规定)，使用的实际底数表示为$1.00100000000000000000000$

<center>上表可转换如下</center>

|  S   |   阶码   |             尾数             |
| :--: | :------: | :--------------------------: |
|  0   | 10000001 | 0010 0000 0000 0000 0000 000 |

eg.

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

//IEEE-754
int main() {
    float f=4.5;
    return 0;
}
```

内存视图

![image-20250331104517990](C语言高级-C语言补充、组成原理数据表示与汇编实战、操作系统文件实战.assets/image-20250331104517990.png)

![image-20250331105504679](C语言高级-C语言补充、组成原理数据表示与汇编实战、操作系统文件实战.assets/image-20250331105504679.png)

##  2.5浮点数精度丢失

浮点型变量分为单精度($float$)型和双精度($double$)型。

|   类型   | 位数 |                    数值范围                    |        有效数字(精度)         |
| :------: | :--: | :--------------------------------------------: | :---------------------------: |
| $float$  |  32  |   $10^{-37}\sim10^{38}(2^{-126}\sim2^{127})$   |  6~7位(因为23位二进制来表示)  |
| $double$ |  64  | $10^{-307}\sim10^{308}(2^{-1022}\sim2^{1023})$ | 15~16位(因为52位二进制来表示) |

![image-20250331165943816](C语言高级-C语言补充、组成原理数据表示与汇编实战、操作系统文件实战.assets/image-20250331165943816.png)

eg.

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

//精度丢失
int main() {
    //赋值的一瞬间发生精度丢失，因为浮点数常量默认是8个字节存储float型
    float a=1.23456789e10,b;//12345678900
    double c=1.23456789e10,d,f;//12345678900
    //理论上结果应该是12345678920
    b=a+20;//精度丢失
    d=c+20;//精度未丢失
    f=a+20;//精度丢失
    printf("b=%f\n",b);//%f即可输出float，也可输出double
    printf("d=%f\n",d);//%f即可输出float，也可输出double
    printf("f=%f",f);//%f即可输出float，也可输出double
    return 0;
}
```

ie.

```
D:\CLionProjects\CPP\cmake-build-debug\CPP.exe
b=12345678848.000000
d=12345678920.000000
f=12345678848.000000
Process finished with exit code 0
```

# 3、汇编语言

## 3.1汇编指令格式

我们编译后的可执行程序，也就是$main.exe$是放在代码段的，$PC$指针寄存器存储了一个指针，始终指向要执行的指令，读取了代码段的某一条指令后，会交给译码器来解析，这时候译码器就知道要做什么事情了，$CPU$中的计算单元加法器不能直接对栈上的某个变量$a$，直接做加1操作，需要首先将栈，也就是内存上的数据，加载到寄存器中，然后再用加法器做加1操作，再从寄存器搬到内存上去。$CPU$读写寄存器的速度比读写内存的速度要快很多

![image-20250402102424228](C语言高级-C语言补充、组成原理数据表示与汇编实战、操作系统文件实战.assets/image-20250402102424228.png)

<font color="red">操作码字段</font>:表征指令的操作特性与功能(指令的唯一标识)，不同指令操作码不能相同

<font color="red">地址码字段</font>:指定参与操作的操作数的地址码

指令中指定操作数存储位置的字段称为地址码，地址码中可以包含存储器地址。也可包含寄存器编号。

指令可以有一个，两个或者三个操作数，也可以没有操作数，根据一条指令有几个操作数地址，可将指令分为零地址指令，一地址指令，二地址指令，三地址指令

| 操作码字段 | 地址码   |            |
| ---------- | -------- | ---------- |
| 操作码     | A1 A2 A3 | 三地址指令 |
| 操作码     | A1 A2    | 二地址指令 |
| 操作码     | A1       | 一地址指令 |
| 操作码     |          | 零地址指令 |

<font color="red">零地址指令</font>：只用操作码，没有地址码(空操作 停止等)

<font color="red">一地址指令</font>：指令编码中只有一个地址码，指出了参加操作的一个操作数的存储位置，如果还有另一个操作数则隐含在累加器中

eg.INC AL 自加指令

<font color="red">二地址指令</font>：指令编码中有两个地址，分别指出了参加操作的两个操作数的存储位置，结果存储在其中一个地址中

(op a1,a2)a1和a2的操作结果放入a1

eg. MOV AL,BL

ADD AL,30

<font color="red">三地址指令</font>：指令编码中有三个地址，指出了参加操作的两个操作数的存储位置和一个结果的地址

(op a1,a2,a3;a1和a2的结果放入a3)

<font color="red">二地址指令格式中，从操作数的物理位置来说可归为三种类型</font>

寄存器-寄存器(RR)型指令:需要多个通用寄存器或个别专用寄存器，<font color="red">从寄存器中取操作数，把操作结果放入另一个寄存器</font>，机器执行寄存器-寄存器型的指令非常快，不需要访存。

寄存器-存储器(RS)型指令:执行此类指令时，纪要访问内存单元，又要访问寄存器。

存储器-存储器(SS)型指令:操作时都是涉及内存单元，参与操作的数都是放在内存里，从内存某单元中取操作数，操作结果存放至内存另一个单元中，因此机器执行指令需要多次访问内存

寄存器英文:$register$

存储器英文:$storage$

复杂指令集:变长 $x86\quad CISC\quad Complex\quad Instruction\quad Set\quad Computer$

精简指令集:变长 $arm\quad RISC\quad Reduced\quad Instruction\quad Set\quad Computin$

## 3.2生成汇编方法

编译过程:
$$
第一步：main.c\implies编译器\implies main.s文件(.s文件就是汇编文件，文件内时汇编代码)\\
第二步:我们的main.s汇编文件\implies汇编器\implies main.obj\\
第三步:main.obj文件\implies链接器\implies可执行文件exe
$$
配置好$mingw64$或$MinGW$的环境变量后在控制台输入$gcc -S -fverbose-asm main.cpp$即可生成汇编文件

## 3.3汇编常用指令

### 3.3.1相关寄存器

![image-20250402141600963](C语言高级-C语言补充、组成原理数据表示与汇编实战、操作系统文件实战.assets/image-20250402141600963.png)

除了$EBP和ESP$外，其他几个寄存器的用途是比较随意的，也就是什么都可以存

### 3.3.2常用指令

汇编指令通常可以分为数据传送指令、逻辑计算指令和控制流指令，下面以$Intel$格式为例，介绍一些重要的指令。以下用于操作数的标记分别表示寄存器、内存和常数

![image-20250402142317447](C语言高级-C语言补充、组成原理数据表示与汇编实战、操作系统文件实战.assets/image-20250402142317447.png)

(1)数据传送指令

①$mov$指令。将第二个操作数(寄存器的内容，内存中的内容或常数值)复制到第一个操作数(寄存器或内存)，但不能用于直接从内存复制到内存

其语法如下:

```
	mov <reg>,<reg>
	mov <reg>,<mem>
	mov <mem>,<reg>
	mov <reg>,<con>
	mov <mem>,<con>
```

eg.

```
	mov eax,ebx #将ebx值复制到eax
	mov byte ptr [var],5 #将5保存到var值指示的内存地址的一字节中
```

②$push$指令。将操作数压入内存的栈，常用于函数调用。$ESP$是栈顶，压栈前先将$ESP$值减4(栈增长方向与内存地址增长方向相反)，然后将操作数压入$ESP$指令的地址。

其语法如下:

```
	push <reg32>
	push <mem>
	push <con32>
```

eg.(注意，栈中元素固定为32位)

```
	push eax #将eax值压栈
	push [var] #将var值指示的内存地址的4字节值压栈
```

③$pop$指令。与$push$指令相反，$pop$指令执行的是出栈工作，出栈前先将$ESP$指示的地址中的内容出栈，然后将$ESP$的值加4

其语法如下:

```
	pop edi #弹出栈顶元素送到edi
	pop [ebx] #弹出栈顶元素送到ebx值指示的内存地址的4字节中
```

(2)算数和逻辑运算指令

①$add/sub$指令。$add$指令将两个操作数相加，相加的结果保存到第一个操作数中。$sub$指令用于两个操作数相减，相减的结果保存到第一个操作数中

它们的语法如下:

```
	add <reg><reg> / sub <reg><reg>
	add <reg><mem> / sub <reg><mem>
	add <mem><reg> / sub <mem><reg>
	add <reg><con> / sub <reg><con>
	add <mem><con> / sub <mem><con>
```

eg.

```
	sub eax, 10 #eax⇦ eax-10
	add byte ptr [var], 10 #10与var值指示的内存地址的一字节值相加，
	并将结果保存在var值指示的内存地址的字节中
```

②$inc/dec$指令。$inc,dec$指令分别表示将操作数自加1、自减1

它们的语法如下:

```
	inc <reg> / dec <reg>
	inc <mem> / dec <mem>
```

eg.

```
	dec eax #eax值自减1
	inc dword ptr [var] #var值指示的内存地址的4字节值自加1
```

③$imul$指令。带符号整数乘法指令，有两种格式：1.两个操作数，将两个操作数相乘，将结果保存在第一个操作数中，第一个操作数必须为寄存器。2.三个操作数，将第二个和第三个操作数相乘，将结果保存在第一个操作数中，第一个操作数必须为寄存器。

其语法如下:

```
	imul <reg32>,<reg32>
	imul <reg32>,<mem>
	imul <reg32>,<reg32>,<con>
	imul <reg32>,<mem>,<con>
```

eg.

```
	imul eax, [var] #eax⇦ eax * [var]
	imul esi,edi,25 #esi⇦ edi *25
```

乘法操作结果可能溢出，则编译器置溢出标志$OF=1$,以使$CPU$调用溢出异常处理程序。

④$idiv$指令。带符号整数除法指令，它只有一个操作数，即除数，而被除数为$edx:eax$中的内容(64位整数)，操作结果有两部分:商和余数，商送到$eax$,余数则送到$edx$

其语法如下:

```
	idiv <reg32>
	idiv <mem>
```

eg.

```
	idiv ebx
	idiv dword ptr [var]
```

⑤$and/or/xor$指令。$and、or，xor$指令分别是逻辑与、逻辑或、逻辑异或操作指令，用于操作数的位操作，操作结果放在第一个操作数中

它们的语法如下:

```
	and <reg>,<reg> / or <reg>,<reg> / xor <reg>,<reg>
	and <reg>,<mem> / or <reg>,<mem> / xor <reg>,<mem>
	and <mem>,<reg> / or <mem>,<reg> / xor <mem>,<reg>
	and <reg>,<con> / or <reg>,<con> / xor <reg>,<con>
	and <mem>,<con> / or <mem>,<con> / xor <mem>,<con>
```

eg.

```
	and eax,0fH #将eax中的前28位全部置为0，最后4位保持不变
	xor edx,edx #置edx中的内容为0
```

⑥$not$指令。位翻转指令，将操作数中的每一位翻转，即$0\rightarrow1,1\rightarrow0$

其语法如下:

```
	not <reg>
	not <mem>
```

eg.

```
	not byte ptr [var] #将var值指示的内存地址的一个字节的所有位翻转
```

⑦$neg$指令。取负指令。

其语法如下:

```
	neg <reg>
	neg <mem>
```

eg.

```
	neg eax #eax⇦-eax
```

⑧$shl/shr$指令。逻辑移位指令，$shl$位逻辑左移，$shr$为逻辑右移，第一个操作数表示被操作数，第二个操作数指示移位的位数

它们的语法如下:

```
	shl <reg>,<con8> /shr <reg>,<con8>
	shl <mem>,<con8> /shr <mem>,<con8>
	shl <reg>,<cl> /shr <reg>,<cl>
	shl <mem>,<cl> /shr <mem>,<cl>
```

eg.

```
	shl eax,1 #将eax值左移1位，相当于乘以2
	shr ebx,cl #将ebx值右移n位(n位cl中的值)，相当于除以2^n
```

⑨$lea$指令。地址传送指令，将有效地址传送逗号指定的寄存器

eg.

```
	lea eax,DWORD PTR _arr$[ebp]
	#lea指令的作用，是DWORD PTR _arr$[ebq]对应空间的内存地址值放到eax中
```

(2)控制流指令

$x86$处理器维持着一个指示当前执行指令的指令指针($IP$),当一条指令执行后，此指针自动指向下一条指令。$IP$寄存器不能直接操作，但可以用控制流指令更新，通常用标签($label$)指示程序中的指令地址，在$x86$汇编代码中，可在任何指令前加入标签。eg.

```
		mov esi,[ebq+8]
	begin:xor ecx,ecx
		mov eax,[esi]
```

这样就用$begin$($begin$代表标签名，可以为别的名字)指示了第二条指令，控制流指令通过标签就可以实现程序指令的跳转。

①$jmp$指令。$jmp$指令控制$IP$转移到$label$所指示的地址(从$label$中取出指令执行)。

其语法如下:

```
	jmp <lable>
```

eg.

```
	jmp begin #跳转到begin标记的指令执行
```

②$jcondition$指令。条件转移指令，依据$CPU$状态字中的一系列状态转移。$CPU$状态字中包括指示最后一个算术运算符结果是否为0，运算结果是否为负数等。

其语法如下:

```
	je <label> (jump when equal)
	jne <label> (jump when not equal)
	jz <label> (jump when last result was zero)
	jg <label> (jump when greater than)
	jge <label> (jump when greater than or equal to)
	jl <label> (jump when less than)
	jle <label> (jump when less than or equal to)
```

eg.

```
	cmp eax,ebx
	jle done
	#如果eax的值小于ebx值，跳转到done指示的指令执行，否则执行下一条指令
```

③$cmp/test$指令。$cmp$指令用于比较两个操作数的值，$test$指令对两个操作数进行逐位与运算，这两类指令都不保存操作结果，仅根据运算结果设置$CPU$状态字中的<font color="red">条件码</font>。

其语法如下:

```
	cmp <reg>,<reg> / test<reg><reg>
	cmp <reg>,<mem> / test<reg><mem>
	cmp <mem>,<reg> / test<mem><reg>
	cmp <reg>,<con> / test<reg><con>
```

$cmp$和$test$指令通常和$jcondition$指令搭配使用

eg.

```
	cmp dwordd ptr [var],10 #将var指示的主存地址的4字符内容，与10比较
	jne loop #如果相等则继续顺序执行否则跳转到loop处执行
	test eax,eax #测试eax是否为零
	jz xxxx #为零则置标志ZF为1，跳转到xxxx处执行
```

④$call/ret$指令。分别用于实现子程序(过程，函数等)的调用及返回。

其语法如下:

```
	call <label>
	ret
```

$call$指令首先将当前执行指令地址入栈，然后无条件转移到由标签指示的指令。与其他简单的跳转指令不同，$call$指令保存调用之前的地址信息(当$call$指令结束后，返回调用之前的地址)。$ret$指令实现子程序的返回机制，$ret$指令弹出栈中保存的指令地址，然后无条件转移到保存的指令地址执行。$call$和$ret$是程序(函数)调用中最关键的两条指令。

### 3.3.3条件码

编译器通过条件码(标志位)设置指令和各类转移指令类实现程序中的选择结构语句。

(1)条件码(标志位)

除了整数寄存器，CPU还维护着一组条件码(标志位)寄存器，它们描述了最近的算术或逻辑运算操作的属性。可以检测这些寄存器来执行条件分支指令，最常用的条件码有:

$CF$:进(借)位标志。最近无符号整数加(减)运算后的进(借)位情况。有进(借)位，$CF=1$;否则$CF=0$。如$(unsigned)t<(unsigned)a$,因为判断大小是相减。

$ZF$:零标志。最近的操作的运算结果是否为0.若为0，$ZF=1$;否则$ZF=0$。如$(t==0)$。

$SF$:符号标志。最近的带符号数运算结果的符号。负数时，$SF=1$;否则$SF=0$。

$OF$:溢出标志。最近带符号数运算的结果是否溢出，若溢出，$OF=1$;否则$OF=0$。

可见，$OF$和$SF$对无符号数运算来说没有意义，而$CF$对带符号数运算来说没有意义。

如何判断溢出，简单的就是正数相加变负数为溢出，负数相加变正数为溢出，但是考研不这么考，考研往往给你十六进制的两个数考溢出，通过如下手法判断即可。

①数据高位进位，符号位进位未进位，溢出。

②数据位高位未进位，符号位进位，溢出。

③数据高位进位，符号位进位，不溢出。(负数)

④数据位高位未进位，符号位进位未进位，不溢出。(正数)

<font color="red">简单一句话就是数据高位和符号位高位进位不一样的时候会溢出</font>

常见的算术逻辑运算指令($add,sub,imul,or,and,shl,inc,dec,not,sal$等)会设置条件码。但有两类指令只设置条件码而不改变任何其他寄存器，即$cmp$和$test$指令，$cmp$指令和$sub$指令的行为一样，$test$和$and$指令的行为一样,但它们只设置条件码，而不更新目的寄存器

<font color="red">Jcondition条件转移指令，就是根据条件码ZF和SF来实现跳转</font>

