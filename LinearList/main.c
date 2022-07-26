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
    for(int i = 0; i < MaxSize; i++)
        L->data[i] = 0;
    L->Length = 0;
}

// 基本操作--插入元素
int ListInsert(SqList *L, int i, int e){
    if (L->Length == MaxSize) {
        printf("Sorry, this list is full!");
        return 0;
    }
    if (i <= 1 || i >= L->Length+1) {
        printf("Sorry, this list is not that long");
        return 0;
    }
    for (int j = L->Length; j >=i ; j--) {
        L->data[j] = L->data[j-1];     // 整体往后移
    }
    L->data[i-1] = e;                  // 插入
    L->Length++;                       // 长度加1

    return 1;
}

int ListDelete(SqList *L, int i, int *e){
    if (i <= 1 || i >= L->Length+1) {
        printf("Sorry, this list is not that long");
        return 0;
    }
    *e = L->data[i-1];                  // 保存删除的值
    for (int j = i; j < L->Length; ++j) {
        L->data[j-1] = L->data[j];      // 将i+1后的元素往前移动
    }
    L->Length--;                        //长度减1
}

// 基本操作--初始化顺序表
void InitSeqList(SeqList *L){
    // 使用malloc函数申请一篇连续的存储空间
    L->data = (int *)malloc(InitSize * sizeof(int));
    L->Length = 0;
    L->Maxsize = InitSize;
}

// 基本操作--动态增加数组的长度
void IncreaseSize(SeqList *L, int len){
    int *p = L->data;
    L->data = (int *)malloc((L->Maxsize + len) * sizeof(int));
    for (int i = 0; i < L->Length; ++i) {
        L->data[i] = p[i];           //将数据复制到新区域
    }
    L->Maxsize = L->Maxsize+len;    //修改顺序表最大长度
    free(p);                        //释放原来的内存空间
}

// 基本操作--按位查找
int GetElem(SqList L, int *i){
    return L.data[*i-1];
}

// 基本操作--按值查找
int LocateElem(SqList L, int e){
    for (int i = 0; i < L.Length; ++i) {
        if (e == L.data[i]){
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