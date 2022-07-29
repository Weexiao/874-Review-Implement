// 顺序栈的定义
#define MAXSIZE 20
typedef struct
{
    int data[MAXSIZE];
    int top;
}SqStack;

// 建立共享栈时只需要建立两个栈顶指针，且初始化时将一个栈顶指针置为-1，另一个置为MAXSIZE即可;

// 基本操作
void InitStack(SqStack *S){
    (*S).top = -1;
}
int StackEmpty(SqStack S){
    return S.top == -1;
}
int Push(SqStack *S, int x){
    // 判满
    if ((*S).top == MAXSIZE-1)
    {
        printf("栈已满，无法插入");
        return 0;
    }
    (*S).top += 1;
    (*S).data[(*S).top] = x;
    return 1;
}
int Pop(SqStack *S, int *x){
    // 判空
    if (StackEmpty(*S))
    {
        printf("栈空，无法弹出");
        return 0;
    }
    (*x) = (*S).data[(*S).top];
    (*S).top -= 1;
    return 1;
}
int GetTop(SqStack S, int *x){
    if (StackEmpty(S))
    {
        printf("栈空，无法弹出");
        return 0;
    }
    *x = S.data[S.top];
    return 1;
}
