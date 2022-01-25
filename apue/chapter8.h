/*
0号进程为调度进程，1号进程为init进程，负责引导系统到一个初始化状态
 */
#include<unistd.h>
#include<sys/types.h>
pid_t getpid(void);
pid_t getpid(void);
uid_t getuid(void);
uid_t geteuid(void);
gid_t getgid(void);
gid_t getegid(void);


pid_t fork(void);
/* 子进程返回0，父进程返回子进程ID，出错返回-1
 */



/*
一个进程终止时，内核检查所有活动进程，若有进程以该进程为父进程，则将其父进程ID改为1

一个已经终止，但父进程尚未对其进行善后处理的进程（获取终止信息，释放占用的资源），称为僵尸进程

init调用wait获得其子进程的终止状态，防止系统塞满僵死进程
 */


#include<sys/wait.h>

pid_t wait(int *statloc);
pid waitid(pid_t pid,int *statloc,int options);



