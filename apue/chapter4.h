#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<dirent.h>




int stat(const char *restrict pathname,struct stat *restrict buf);
int lstat(const char *restrict pathname,struct stat *restrict buf);
int fstat(int fd,struct stat *buf);
int fstatat(int fd,const char *restrict pathname,struct stat *restrict buf,int flag);
/*
当文件是符号链接时，lstat返回链接本身的信息而不是所引用文件的信息

flag控制是否跟随符号链接，AT_SYNLINK_NOFOLLOW被设置时不跟随符号链接
*/


/*
文件类型测试宏，参数为st_mode
S_ISREG()
S_ISDIR()
S_ISCHR()
S_ISBLK()
S_ISFIFO()
S_ISSOCK()
S_ISLNK()

测试宏实现为st_mode与屏蔽字S_IFMT与运算，结果与相应常量S_IFxxx比较
*/


/*
有效用户ID和有效组ID是相对于进程来说，表示进程实际在以谁的身份运行

设置用户ID位与设置组ID位包含在st_mode中，可用常量S_ISUID和S_ISGID测试

进程打开，创建，删除一个文件时，对文件的所有者ID,组ID，进程有效用户ID，有效组ID，附属组ID，相应权限位进行测试
*/


/*
新建文件用户ID为进程有效用户ID

新建文件组ID为进程有效组ID或者所在目录组ID(取决于所在目录的设置组ID是否被设置)
*/


int access(const char *pathname,int mode);
int faccessat(int fd,const char *pathname,int mode,int flag);
/*
以进程实际用户ID和实际组ID测试权限，
mode取值 F_OK测试文件是否存在，R_OK,W_OK,X_OK测试读写执行权限

flag为AT_EACCESS时使用有效用户和有效组ID测试
*/


mode_t umask(mode_t cmask);
/*
设置文件模式创建屏蔽字，返回之前的值

屏蔽字中为1的位，文件mode中相应的位被关闭
*/


int chmod(const char *pathname,mode_t mode);
int fchmod(int fd,mode_t mode);
int fchmodat(int fd,const char *pathname,mode_t mode,int flag);
/*
为了改变文件的一个权限位，进程有效ID为文件ID或进程具有超级用户权限

flag为AT_SYMLNK_NOFOLLOW时不跟随符号链接

fchmod改变已打开文件的权限位
*/


int chown(const char *pathname,uid_t owner,git_t group);
int fchown(int fd,uid_t owner,gid_t group);
int fchownat(int fd,const char *pathname,uid_t owner,gid_t group,int flag);
int lchown(const char *pathname,uid_t owner,gid_t group);
/*
owner=-1时设置文件的组ID为进程有效组ID或附属组ID之一，若该函数由非超级用户调用，则成功返回时，文件的设置用户和设置组ID位被清除
*/


/*
文件长度st_size不包含名字结尾的null字节
*/


int truncate(const char *pathname,off_t length);
int ftruncate(int fd,off_t length);
/*
截断文件长度为length，若原文件长度小于length，则实际文件长度增加（文件中间形成空洞）
*/


int link(const char *existingpath,const char *newpath);
int lintat(int efd,const char *existingpath,int nfd,const char *newpath,int flag);
/*
只创建newpath的最后一部分，路径的其他部分应保证以存在
*/
int unlink(const char *pathname);
int unlinkat(int fd,const char *pathname,int flag);
/*
删除目录项，对应文件链接计数减一

只要有进程打开了该文件，文件就不能被删除，文件关闭时检查打开文件的进程个数，为零时检查链接技术，同为0则删除

flag被设置为AT_REMOVEDIR时unlinkat可以删除目录

如果pathname时符号链接，unlink删除符号链接而不是引用的文件，没有一个函数能在只给出符号链接的情况下删除引用的文件

进程用open或creat创建文件后立即调用unlink可保证即时进程崩溃它创建的文件也不会遗留下来
*/


int rename(const char *oldname,const char* newname);
int renameat(int ofd,const char *oldname,int nfd,const char *newname);
/*
oldname指文件时，若newname为目录则出错，若为文件且已经存在，则删除并重命名

oldname指目录时，若newname以存在则必须为空目录，且不能包含oldname为其路径前缀
*/


int symlink(const char *actualpath,const char *sympath);
int symlinkat(const char *actualpath,int fd,const char *sympath);
/*
创建符号链接时并不要求actualpath已经存在
*/
int readlink(const char* restrict pathname,char *restrict buf,size_t bufsize);
int readlintat(int fd,const char* restrict pathname,char *restrict buf,size_t bufsize);
/*
open会跟随符号链接，因此需readlink读取符号链接本身保存的路径名称，buf中返回的内容不以null结束
*/



int mkdir(const char *pathname,mode_t mode);
int mkdirat(int fd,const char *pathname,mode_t mode);
int rmdir(const char *pathname);


/*
任何用户都可以读其具有访问权限的目录，只有内核才能写目录
*/
 DIR *opendir(const char *pathname);
 DIR *fdopendir(int fd);
struct dirent *readdir(DIR *dp);
void  rewinddir(DIR *dp); //重设目录读取位置为开始位置
int closedir(DIR *dp);
long telldir(DIR *dp);//返回当前距离目录文件开头的偏移量
void seekdir(DIR *dp,long loc);//设置目录当前读取位置
/*
opendir执行初始化，使readdir返回第一个目录项
fdopendir创建的DIR取决于当前fd的偏移量
*/


int chdir(const char *pathname);
int fchdir(int fd);
int getcwd(char *buf,size_t size);
/*
getcwd返回当前工作目录的绝对路径，buf必需能够存储最大路径名长度
*/

