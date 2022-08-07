// 链式栈的定义
typedef struct Linknode
{
    int data;
    struct Linknode *next;
} *LinkStack;

// 基本操作，可以将头指针作为栈顶指针故此处使用头插法，头删法即可