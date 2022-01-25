#include<stdlib.h>
void exit(int status);
void _Exit(int status);
#include<unistd.h>
void _exit(int status);
/*
进程终止方式：
正常终止：
（1）从main返回
（2）调用exit
（3）调用_exit 或者_Exit
（4）最后一个线程从其启动例程返回
（5）从最后一个线程调用pthead_exit
异常终止：
（6）调用abort
（7）接受到一个信号
（8）最后一个线程对取消请求做出响应
*/


int atexit(void (*func)(void));
/*
登记终止处理函数，由exit()调用，调用顺序与登记顺序相反，可以重复登记同一个函数
*/


/*
argv[arc]是空指针，命令行参数遍历循环可写为两种形式
for(i=0;i<argc;i++)或者 for(i=0;argv[i]!=NULL;i++)
*/


extern char ** envrion 
/*
 envrion为环境指针，指向的指针数组为环境表，环境表以null指针结尾，与argv类似
*/


/* 
gcc -static 
使用静态链接的方式编译
*/


void *malloc(size_t size);
void *calloc(size_t nobj,size_t size);
void realloc(void *ptr,size_t newsize);
void free(void *ptr);
/* 
分配函数满足最苛刻的内存对齐要求

free函数释放的空间通常放入存储区池而不是交还给内核
 */


char *getenv(const char *name);
/* 
返回指向name=value中value的字符串指针
*/
int putenv(char *str);
int setenv(const char *name,const char *value,int rewrite);
int unsetenv(const char *name);
/*
putenv将name=value的字符串放入环境表，如果name已经存在则删除原先定义

setenv中rewrite为非0，先删除现有定义，为0时不进行若name已存在则不进行任何操作

unsetenv删除name的定义，name也可不存在
*/
