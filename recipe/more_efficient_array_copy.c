#define SIZE 50

int x[SIZE];
int y[SIZE];

void copy(){
    register int *p1,*p2;

    for(p1=x,p2=y;p1<&x[SIZE];){
        *p1++=*p2++;
    }
}

//使用寄存器变量（必须被声明为局部变量），可以不用复制指针值，效率更高
//指针与&x[SIZE]比较，而不是用计数器，汇编指令更紧凑，因为&x[SIZE]是常量表达式，可以在编译期计算
