// 循环队列的顺序实现
#define MAXSIZE 10
typedef struct 
{
    int data[MAXSIZE];
    int front, rear;
} SqQueue;


// 基本操作
void InitQueue(SqQueue *Q){
    Q->rear=Q->front = 0;
}
int QueueEmpty(SqQueue Q){
    return Q.rear == Q.front;
}
int EnQueue(SqQueue *Q, int x){
    // 判断是否队满
    if ((Q->rear+1)%MAXSIZE==Q->front)
    {
        printf("该队列已满");
        return 0;
    }
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return 1;
}
int DeQueue(SqQueue *Q, int *x){
    // 判断是否队空
    if (QueueEmpty(*Q))
    {
        printf("该队列为空队列");
        return 0;
    }
    (*x) = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 1;
}
int GetHead(SqQueue Q, int *x){
    // 判断是否队空
    if (QueueEmpty(Q))
    {
        printf("该队列为空队列");
        return 0;
    }
    (*x) = Q.data[Q.front];
    return 1;
}