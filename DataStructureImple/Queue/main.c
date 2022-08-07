#include<stdio.h>
#include<stdlib.h>
#include"SqQueue.h"
#include"LinkQueue.h"

int main(){
    SqQueue *Q = (SqQueue *)malloc(sizeof(SqQueue));
    InitQueue(Q);
    printf("Is Queue Empty ? : %d\n", QueueEmpty(*Q));
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    printf("Is Queue Empty ? : %d\n", QueueEmpty(*Q));
    int *x = (int *)malloc(sizeof(int));
    DeQueue(Q, x);
    printf("x = %d\n", *x);
    DeQueue(Q, x);
    printf("x = %d\n", *x);
    printf("Is Queue Empty ? : %d\n", QueueEmpty(*Q));

    printf("--------------------------------------------\n");

    LinkQueue LQ;
    InitLQueue(&LQ);
    printf("Is LQueue Empty ? : %d\n", LQueueEmpty(LQ));
    EnLQueue(&LQ, 1);
    EnLQueue(&LQ, 2);
    printf("Is LQueue Empty ? : %d\n", LQueueEmpty(LQ));
    DeLQueue(&LQ, x);
    printf("x = %d\n", *x);
    DeLQueue(&LQ, x);
    printf("x = %d\n", *x);
    printf("Is LQueue Empty ? : %d\n", LQueueEmpty(LQ));
    return 1;
}