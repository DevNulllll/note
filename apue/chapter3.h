#include<fcntl.h>
/*
内核关联标准输入输出文件描述符的符号常量STDIN_FILENO  STDOUT_FILENO  STDERR_FILENO

文件描述符打开范围 0-OPEN_MAX-1
*/


int open(const char *path,int oflag,.../*mode_t mode */);
int openat(int fd, const char *path,int oflag,.../*mode_t mode*/);
/*
O_SYNC使每次write操作等待IO完成才返回，包括属性更新引起的IO  （数据和属性同步更新）
O_DSYNC在数据部分IO完成后write返回，不等待属性更新
O_RSYNC是read操作等待，直到所有对文件同一部分挂起的写操作都完成

fd为AT_FDCWD，openat从当前目录开始索引，否则从fd打开的目录开始索引，若path为绝对路径，则open和openat相同
*/


int creat(const char *path,mode_t mode);
/*
等效于open(path,O_WRONLY|O_CREAT|O_TRUNC,mode)
*/


off_t lseek(int fd,off_t offset,int whence);
/*
whence取值有SEEK_SET, SEEK_CUR, SEEK_END

出错返回-1

文件中的空洞被读为0
*/


ssize_t read(int fd,void *buf,size_t nbytes);

ssize_t write(int fd,const void * buf,size_t nbytes);
/*
出错常见原因为磁盘满或超过进程的文件长度限制
*/


/*
每个进程维护一个打开文件描述符表
每个文件描述符表项包含文件描述符标志和文件表项的指针

文件表项包含文件状态标志，当前偏移量，指向V节点的指针

所有打开文件都有一个V节点结构，其中包含文件操作的指针，指向i节点的指针
*/


int dup(int fd);
int dup2(int fd,int fd2);
/*
如果fd2已经打开，则先关闭再打开
如果fd2与fd相等，则返回fd2
fd2的FD_CLOEXEC被清除，在进程调用exec时fd2是打开状态
*/


void sync();
int fsync(int fd);
int fdatasync(int fd);
/*
sync 将所有修改过的块排入写队列，不等实际写操作结束就返回
fsync只对指定fd起作用，并等写操作结束后返回
fdatasync只对文件的数据部分起作用
*/


int fcntl(int fd,int cmd,.../*int args*/);
/*
cmd=F_DUPFD  F_DUPFD_CLOEXEC复制已有文件描述符
cmd=F_SETFD  F_GETFD设置或取得文件描述符标志
cmd=F_SETFL  F_GETFL设置或取得文件状态标志
cmd=F_SETOWN F_GETOWN设置或取得异步IO所有权
cmd=F_SETLK  F_SETLKW   

F_GETFL返回与O_ACCMODE作与运算确定访问模式（O_WRONLY  O_RDONLY O_RDWR)
*/

