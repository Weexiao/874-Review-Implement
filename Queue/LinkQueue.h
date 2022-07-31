typedef struct LinkNode         // 链式队列节点
{
    int data;
    struct LinkNode *next;
}LinkNode;

typedef struct                  // 链式队列
{
    LinkNode *front, *rear;
}LinkQueue;

// 带头节点
void InitLQueue(LinkQueue *Q){
    Q->front=Q->rear=(LinkNode *)malloc(sizeof(LinkNode));
    Q->front->next = NULL;
}
int LQueueEmpty(LinkQueue Q){
    return Q.rear==Q.front;
}
int EnLQueue(LinkQueue *Q, int x){
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data=x;
    s->next=NULL;
    Q->rear->next = s;
    Q->rear = s;
}
int DeLQueue(LinkQueue *Q, int *x){
    if (LQueueEmpty(*Q))
    {
        printf("该队列为空");
        return 0;
    }
    LinkNode *p = Q->front->next;
    (*x) = p->data;
    Q->front->next = p->next;
    if (Q->rear == p)
    {
        // p是最后一个节点
        Q->rear = Q->front;
    }
    free(p);
    return 1;
}

// 不带头节点
// void InitLQueue(LinkQueue *Q){
//     Q->front = NULL;
//     Q->rear = NULL;
// }
// int LQueueEmpty(LinkQueue Q){
//     return Q.front==NULL;
// }
// int EnLQueue(LinkQueue *Q, int x){
//     LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
//     s->data=x;
//     s->next=NULL;
//     if (LQueueEmpty(*Q))
//     {
//         Q->front=Q->rear=s;
//     } 
//     else
//     {
//         Q->rear->next = s;
//         Q->rear = s;
//     }
//     return 1;
// }
// int DeLQueue(LinkQueue *Q, int *x){
//     if (LQueueEmpty(*Q))
//     {
//         printf("该队列为空");
//         return 0;
//     }
//     LinkNode *p = Q->front;
//     (*x) = p->data;
//     Q->front = p->next;
//     if (Q->rear == p)
//     {
//         Q->front = NULL;
//         Q->rear = NULL;
//     }
//     free(p);
//     return 1;
// }