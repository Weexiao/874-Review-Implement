#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// 初始化一个空的链表 (无头节点)
// int InitList(LinkList *L){
//     (*L) = NULL;
//     return 1;
// }


//// 初始化一个空的链表 (带头节点)
int InitList(LinkList *L){
    (*L) = (LNode *)malloc(sizeof(LNode));
    if ((*L)->next == NULL)
    {
        return 0;
    }
    (*L)->next = NULL;
    return 1;
}

// 判断单链表是否为空 (无头节点)
// int Empty(LinkList L){
//     return L == NULL;
// }

// 判断单链表是否为空 (有头节点)
int Empty(LinkList L){
    return L->next == NULL;
}

// 求表长度
int Length(LinkList L){
    int length = 0;
    if (L == NULL)
    {
        return 0;
    }
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        length++;
    }
    return length;
}

// 基本操作--按位序插入 (有头节点)
int ListInsert(LinkList *L, int i, int e){
    LNode *p = GetElem(*L, i-1);
    return InsertNextNode(p, e);
}

// 后插操作：在p节点后插入元素e
int InsertNextNode(LNode *p, int e){
    LNode *q = (LNode *)malloc(sizeof(LNode));
    if (p == NULL || q == NULL)
    {
        printf("输入节点为空或新节点创建失败");
        return 0;
    }
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 1;
}

// 前插操作：在p节点前插入元素e
int InsertPriorNode(LNode *p, int e){
    LNode *q = (LNode *)malloc(sizeof(LNode));
    if (p == NULL || q == NULL)
    {
        printf("输入节点为空或新节点创建失败");
        return 0;
    }
    q->data = p->data;
    p->data = e;
    q->next = p->next;
    p->next = q;
    return 1;
}

// 基本操作--按位序插入 (无头节点)
// int ListInsert(LinkList *L, int i, int e){
//     if (Empty(L))
//     {
//         printf("输入的链表为空");
//         return 0;
//     }
//     if (i < 1) {
//         printf("请输入合法的位序");
//         return 0;
//     }
//     LNode *p = (*L);
//     LNode *q = (LNode *)malloc(sizeof(LNode));
//     if (q == NULL)
//     {
//         printf("新节点创建失败");
//         return 0;
//     }
//     q->data = e;
//     if (i == 1){
//         q->next = (*L);
//         p = q;
//     }
//     while (p != NULL && j < i-1)
//     {
//         p = p->next;
//         j++;
//     }
//     if (p == NULL)
//     {
//         printf("位序超过链表长度");
//         return 0;
//     }
//     q->next = p->next;
//     p->next = q;
//     return 1;
// }

// 基本操作--按位序删除 (有头节点)
int ListDelete(LinkList *L, int i, int *e){
    LNode *p = GetElem(*L, i-1);
    if (p == NULL || p->next == NULL)
    {
        printf("当前位序无元素");
        return 0;
    }
    LNode *q = p->next; // 要删除的节点
    *e = q->data;
    p->next = q->next;
    free(q);
    return 1;
}

// 删除指定结点
int DeleteNode(LNode *p){
    if (p == NULL)
    {
        printf("当前输入的节点为空无法删除");
        return 0;
    }
    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return 1;
}

// 按位查找 (有头节点)
LNode *GetElem(LinkList L, int i) {
    if (i < 0)
    {
        printf("请输入正确的位序");
        return L;
    }
    int j = 0;
    LNode *p = L;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找
LNode *LocateElem(LinkList L, int e){
    if (L == NULL) {
        printf("输入的链表为空");
        return NULL;
    }
    LNode *p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}

// 建立
// 尾插法
LinkList List_TailInsert(LinkList *L){
    int x;
    *L = (LinkList)malloc(sizeof(LNode));
    LNode *p, *q = *L;
    printf("input x = ");
    scanf("%d", &x);
    while (x != -1)
    {
        p = (LNode *)malloc(sizeof(LNode));
        p->data = x;
        q->next = p;
        q = p;
        printf("input x = ");
        scanf("%d", &x);
    }
    q->next = NULL;
    return *L;
}

// 头插法
LinkList List_HeadInsert(LinkList *L){
    int x;
    InitList(L);
    printf("input x = ");
    scanf("%d", &x);
    while (x != -1)
    {
        InsertNextNode(*L, x);
        printf("input x = ");
        scanf("%d", &x);
    }
    return *L;
}

// 链表逆置
LinkList Reverse(LinkList *L){
    LNode *p;
    p = (*L)->next;
    (*L)->next = NULL;
    while (p != NULL)
    {
        LNode *temp;
        temp = p->next;
        p->next = (*L)->next;       // 插到链表头
        (*L)->next = p;             // 更新链表头指针
        p = temp;
    }
    return *L;
}

// 初始化双链表
int InitDLinkList(DLinkList *L){
    (*L) = (DNode *)malloc(sizeof(DNode));
    if ((*L) == NULL)
    {
        printf("头节点创建失败");
        return 0;
    }
    (*L)->next = NULL;
    (*L)->prior = NULL;
    return 1;
}
// 判断双链表是否为空(带头节点)
int DEmpty(DLinkList L){
    if(L == NULL)
    {
        printf("输入的双链表为空");
        return 0;
    }
    return L->next==NULL;
}
// 在p节点后插入q节点
int InsertNextDNode(DNode *p, DNode *q){
    if (p==NULL || q==NULL)
    {
        printf("输入的双链表节点为空");
        return 0;
    }
    q->next = p->next;
    if (p->next != NULL)
    {
        p->next->prior = q;
    }
    p->next = q;
    q->prior = p;
    return 1;
}
// 删除p节点的后继节点
int DeleteNextDNode(DNode *p){
    if (p == NULL)
    {
        printf("输入的双链表节点为空");
        return 0;
    }
    DNode *q = p->next;
    if (q == NULL)
    {
        printf("当前节点无后继节点");
        return 0;
    }
    p->next = q->next;
    if (q->next != NULL)
    {
        q->next->prior = p;
    }
    free(q);
    return 1;
}
// 删除双链表
void DestoryDList(DLinkList *L){
    while ((*L)->next != NULL)
    {
        DeleteNextDNode((*L));
    }
    free(*L);
    *L=NULL;
}

int main(){
    LinkList L;
    InitList(&L);
    printf("len = %d\n", Length(L));
    ListInsert(&L, 1, 4);
    InsertNextNode(L, 5);
    InsertPriorNode(L->next->next, 8);
    InsertPriorNode(L->next->next, 9);
    Reverse(&L);
    int x;
    ListDelete(&L, 2, &x);
    DeleteNode(L->next->next);
    printf("x = %d\n", x);
    printf("L is empty ? true:1 or false:0 | %d\n", Empty(L));
    printf("len = %d\n", Length(L));

    // 循环链表
    DLinkList DL;
    InitDLinkList(&DL);
    printf("DL is empty ? true:1 or false:0 | %d\n", DEmpty(DL));
    DNode *p = (DNode *)malloc(sizeof(DNode));
    p->data=1;
    p->next=NULL;
    p->prior=NULL;
    InsertNextDNode(DL, p);
    printf("DL is empty ? true:1 or false:0 | %d\n", DEmpty(DL));
    DeleteNextDNode(DL);
    printf("DL is empty ? true:1 or false:0 | %d\n", DEmpty(DL));
    DestoryDList(&DL);
    printf("DL is NULL ? true:1 or false:0 | %d\n", DL==NULL);
    return 0;
}
