#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10                  //定义最大长度
typedef struct{
    int data[MaxSize] ;             //用静态的“数组”存放数据元素
    int Length;                     //顺序表的当前长度
}SqList;                            //顺序表的类型定义(静态分配方式)

#define InitSize 10                 //顺序表初始长度
typedef struct{
    int *data;                      //指示动态分配数组的指针
    int Maxsize;                    //顺序表的最大容量
    int Length;                     //顺序表的当前长度
}SeqList;                           //顺序表的类型定义(动态分配方式)

// 基本操作--初始化顺序表
void InitSqList(SqList *L){
    for (int i = 0; i < L->Length; i++)
    {
        L->data[i] = 0;
    }
    L->Length = 0;
}

// 基本操作--插入元素
int ListInsert(SqList *L, int i, int e){
    if (L->Length == MaxSize)
    {
        printf("Sorry, this list is full");
        return 0;
    }
    if (i < 1 || i > L->Length)
    {
        printf("Sorry, this list is not that long");
        return 0;
    }
    for (int j = L->Length; j >= i; j--)
    {
        L->data[j] = L->data[j-1];
    }
    L->data[i-1] = e;
    L->Length++;
    return 1;
}

int ListDelete(SqList *L, int i, int *e){
    if (L->Length == 0)
    {
        printf("Sorry, this list has nothing");
        return 0;
    }
    if (i < 1 || i > L->Length)
    {
        printf("Sorry, this list is not that long");
        return 0;
    }
    *e = L->data[i-1];
    for (int j = i; j < L->Length ; j++)
    {
        L->data[j-1] = L->data[j];
    }
    L->Length--;
    return 1;
}

// 基本操作--初始化顺序表
void InitSeqList(SeqList *L){
    L->data = (int *)malloc(sizeof(int)*InitSize);
    L->Maxsize = InitSize;
    L->Length = 0;
}

// 基本操作--动态增加数组的长度
void IncreaseSize(SeqList *L, int len){
    int *p = L->data;
    L->data = (int *)malloc(sizeof(int)*(L->Maxsize+len));
    for (int i = 0; i < L->Length; i++)
    {
        L->data[i] = p[i];
    }
    L->Maxsize = L->Maxsize + len;
    free(p);
}

// 基本操作--按位查找
int GetElem(SqList L, int *i){
    return L.data[*i-1];
}

// 基本操作--按值查找
int LocateElem(SqList L, int e){
    for (int i = 0; i < L.Length; i++)
    {
        if (e == L.data[i])
        {
            return i+1;
        }
        
    }
    return 0;
}

void PrintSqList(SqList L){
    for (int i = 0; i < L.Length; ++i) {
        printf("data[%d]=%d \n", i, L.data[i]);
    }
    printf("SqList.Length = %d \n", L.Length);
}

void PrintSeqList(SeqList L){
    for (int i = 0; i < L.Length; ++i) {
        printf("data[%d]=%d \n", i, L.data[i]);
    }
    printf("SeqList.Length = %d \n", L.Length);
    printf("SeqList.Maxsize = %d \n", L.Maxsize);
}

int main() {
    SqList L;
    InitSqList(&L);
    for (int i = 0; i < 3; ++i) {
        L.data[i] = i;
    }
    L.Length = 3;
    PrintSqList(L);
    ListInsert(&L, 3, 3);
    PrintSqList(L);
    int x;
    ListDelete(&L, 2, &x);
    PrintSqList(L);
    printf("x = %d \n", x);

    SeqList LL;
    InitSeqList(&LL);
    for (int i = 0; i < 3; ++i) {
        LL.data[i] = i;
    }
    LL.Length = 3;
    PrintSeqList(LL);
    IncreaseSize(&LL, 3);
    PrintSeqList(LL);
    return 0;
}