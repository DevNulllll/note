#include<stdio.h>
#include<sys/types.h>


/*
stdin  stdout  stderr  为文件指针 FILE* 类型，定义在stdio.h中
*/


/*
缓冲类型
（1）全缓冲
    通常为malloc函数获取，缓冲区满或者调用fflush时执行IO
（2）行缓冲
    遇到换行符或者缓冲满时执行IO
（3）不缓冲
    标准库不对字符进行缓冲，标准错误输出stderr为无缓冲
*/


void setbuf(FILE *restrict fp,char * restrict buf);
int setvbuf(FILE *restrict fp,char * restrict buf,int mode,int size);
/*
setbuf中buf置为NULL则关闭缓冲，否则指向长度为BUFFSIZE的缓冲区，通常为全缓冲，若关联到终端设备也可以是行缓冲

setvbuf中mode可以为 _IOFBUF  _IOLBUF  _IONBUF
若指定为不带缓冲的流，则忽略buf和size
若为行缓冲或者全缓冲且buf为NULL，则标准库分配适当长度的缓冲区，通常为st_blksize
*/


int fflush(FILE *fp);
/*
使流的所有未写数据送至内核，若fp为NULL，将导致多有输出流被冲洗
*/


FILE *fopen(const char *restrict pathname, const char *type);
FILE *freopen(const char *restrict pathname.const char *type,FILE *restrict fp);
FILE *fdopen(int fd,const char *type);
/*
除非引用终端设备，否则按系统默认，打开流都是全缓冲的，引用终端设备的流是行缓冲

指定w或a创建文件时，无法说明文件权限

文件以读写类型打开（带+号）时具有如下限制
（1）若中间没有 fflush  fseek  fsetops  rewind,则输出后不能直接跟输入
（2）若中间没有 fseek fsetops rewind ,或者输入操作没有到达文件尾端，则输入后不能直接跟输出
*/


int fclose(FILE * fp);
/*
关闭一个流，冲洗缓冲区中的输出数据，所有输入数据被丢弃
*/


/*
打开流对应三种不同类型的非格式化IO
（1）每次一个字符的IO 包括 getc  fgetc  getchar  putc  fputc  putchar
（2）每次一行的IO  包括 fgetc  fputs
（3）直接IO（二进制IO） 包括 fwrite fread
*/


int getc(FILE *fp);
int fgetc(FILE *fp);
int getchar(void);
/*
getchar等同于getc(stdin)

getc可实现为宏，fgetc实现为函数
*/


int ferror(FILE *fp);
int feof(FILE *fp);
int clearerr(FILE * fp);
/*
每个流在FILE对象中维护两个标志： 文件结束标志和出错标志
ferror  ferr测试对应标志是否置位，条件为真返回非0

clearerr清除这两个标志
*/


int ungetc(int c,FILE *fp);
/*
将字符压回到流中，不要求刚读出的字符，不能回送EOF
*/


int putc(int c,FILE *fp);
int fputc(int c,FILE *fp);
int puchar(int c);


char *fgets(char *restrict buf,int n,FILE *fp);
char *gets(char *buf);
/*
gets从标准输入读

缓冲区总是null字节结尾
*/


int fputs(const char *buf,FILE *fp);
int puts(const char *str);
/*
fputs将null字节结尾的字符串写到指定的流中，null字节不写出，不一定是每次写入一行（不要求Null前是换行符）

puts将null字节结尾的字符串写入标准输出，null不写出，随后加上换行符
*/


size_t fwrite(const char *restrict ptr,size_t size,size_t nobj,FILE *restrict fp);
size_t fread(char *restrict ptr,size_t size,size_t nobj,FILE *restrict fp);
/*
函数返回读写的对象个数

读到对象个数少于nboj可能为出错或到达文件末尾，需调用ferror或feof

只能用于同一系统结构对象的读写，不同系统中结构的存储方式可能不同
*/


long ftell(FILE *fp);
int fseek(FILE *fp,long offset,int whence);

off_t ftello(FILE *fp);
int fseeko(FILE *fp,off_t offset,int whence);
/*
前两个函数偏移类型为长整数，后两个为off_t类型
*/


int fgetops(FILE *restrict fp,fpos_t *restrict pos);
int fetops(FILE *fp,const fpos_t *pos);
/*
这两个函数在结构fpos_t中保存文件位置，目的是程序的可移植性
*/


int printf(const char *restrict fmt,...);
int fprintf(FILE* fp,const char * restrict fmt,...);
int dprintf(itn fd,const char * restrict fmt,...);
/*
函数返回输出字符数
*/
int sprintf(char *restrict buf,const char *restrict fmt,...);
int snprintf(char * restrict buf,size_t n,const char * restrict fmt,...);
/*
函数在字符串末尾加上null字符，但不计入返回值；
*/


int scanf(const char *restrict fmt,...);
int fscanf(FILE *fp,const char* restrict fmt,...);
int sscanf(const char * restrict buf,const char *restrict fmt,...);


int filno(FILE* fp);
/*
可以对一个流调用fileno以获得其文件描述符
*/