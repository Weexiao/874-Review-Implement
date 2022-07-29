#include<stdio.h>
#include<stdlib.h>
#include"SqStack.h"
#include"LiStack.h"

int main(){
    SqStack S;
    InitStack(&S);
    Push(&S, 1);
    Push(&S, 2);
    int *x = (int *)malloc(sizeof(int));
    Pop(&S, x);
    printf("x = %d\n", *x);
    GetTop(S, x);
    printf("x = %d\n", *x);
    printf("Is Stack Empty ? %d\n", StackEmpty(S));
    free(x);
    return 1;
}