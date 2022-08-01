#include<stdio.h>
#include<stdlib.h>
#include"SqStack.h"
#include"LiStack.h"

int main(){
    SqStack S;
    InitStack(&S);
    Push(&S, '1');
    Push(&S, '2');
    char *x = (char *)malloc(sizeof(char));
    Pop(&S, x);
    printf("x = %c\n", *x);
    GetTop(S, x);
    printf("x = %c\n", *x);
    printf("Is Stack Empty ? %d\n", StackEmpty(S));
    free(x);

    printf("-----------------------------------\n");

    printf("开始括号匹配，请输入括号序列长度\n");
    int length;
    scanf("%d", &length);
    printf("开始括号匹配，请输入不超过指定长度的括号序列\n");
    char str[length];
    scanf("%s", str);
    printf("判断结果：%d\n", bracketCheck(str, length));
    return 1;
}