#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

//typedef struct LNode{                   // 定义单链表结点类型
//    int data;                      // 每个结点存放一个数据元素
//    struct LNode *next;                 // 指针指向下一个结点
//}LNode, *LinkList;

//typedef struct LNode LNode;             // 结点重命名为LNode
//typedef struct LNode *LinkList;          // 结点指针重命名为LinkList

// 初始化一个空的链表 (无头节点)
//int InitList(LinkList *L){
//    *L = NULL; //空表，暂时没有结点
//    return 1;
//}


//// 初始化一个空的链表 (带头节点)
int InitList(LinkList *L){
    *L = (LNode *)malloc(sizeof(LNode));         // 分配一个头节点
    if ((*L) == NULL)                            // 内存不足，分配失败
        return 0;
    (*L)->next = NULL;                           // 其无后续结点
    return 1;
}

// 判断单链表是否为空 (无头节点)
//int Empty(LinkList L){
//    return (L == NULL);
//}

// 判断单链表是否为空 (有头节点)
int Empty(LinkList L){
    return (L->next == NULL);
}

// 求表长度
int Length(LinkList L){
    int len = 0;
    LNode *p = L;
    while (p->next != NULL){
        p = p->next;
        len++;
    }
    return len;
}

// 基本操作--按位序插入 (有头节点)
int ListInsert(LinkList *L, int i, int e){
//    if (i < 1)
//        return 0;
//    LNode *p;                           // 指针p指向当前扫描的结点
//    int j = 0;                          // 当前p指向的是第几个结点
//    p = *L;                             // L指向头结点，头节点是第0个结点 (不存数据)
//    while (p != NULL && j < i-1){       // 循环找到第 i-1 个结点
//        p = p->next;
//        j++;
//    }
    LNode *p = GetElem(*L, i-1);
    return InsertNextNode(p, e);
//    if (p == NULL){                     // i 值不合法
//        return 0;
//    }
//    LNode *s = (LNode *)malloc(sizeof(LNode));
//    s->data = e;
//    s->next = p->next;
//    p->next = s;
//    return 1;
}

// 后插操作：在p节点后插入元素e
int InsertNextNode(LNode *p, int e){
    if (p == NULL)
        return 0;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)              // 内存分配失败
        return 0;
    s->data = e;                // 用结点s保存e
    s->next = p->next;
    p->next = s;                // 将s接到p后
    return 1;
}

// 前插操作：在p节点前插入元素e
int InsertPriorNode(LNode *p, int e){
    if (p == NULL)
        return 0;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)              // 内存分配失败
        return 0;
    s->next = p->next;          // 保存p后的结点
    p->next = s;                // 新节点插入p后
    s->data = p->data;          // 复制p中的数据
    p->data = e;                // 覆盖
    return 1;
}

// 基本操作--按位序插入 (无头节点)
//int ListInsert(LinkList *L, int i, int e){
//    if (i < 1){
//        return 0;
//    }
//    if (i == 1){                        //插入第 1 个结点的操作与其他结点不同
//        LNode *s = (LNode *)malloc(sizeof(LNode));
//        s->data = e;
//        s->next = *L;
//        *L = s;                         // 头指针指向新结点
//        return 1;
//    }
//    LNode *p;                           // 指针p指向当前扫描的结点
//    int j = 1;                          // 当前p指向的是第1个结点
//    p = *L;                             // L指向第1个结点
//    while (p != NULL && j < i-1){       // 循环找到第 i-1 个结点
//        p = p->next;
//        j++;
//    }
//    if (p == NULL){                     // i 值不合法
//        return 0;
//    }
//    LNode *s = (LNode *)malloc(sizeof(LNode));
//    s->data = e;
//    s->next = p->next;
//    p->next = s;
//    return 1;
//}

// 基本操作--按位序删除 (有头节点)
int ListDelete(LinkList *L, int i, int *e){
//    if (i < 1){
//        return 0;
//    }
//    LNode *p;
//    int j = 0;
//    p = *L;
//    if (p != NULL && j < i-1){
//        p = p->next;
//        j++;
//    }
    LNode *p = GetElem(*L, i-1);
    if (p == NULL || p->next == NULL){
        return 0;
    }
    LNode *q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return 1;
}

// 删除指定结点
int DeleteNode(LNode *p){
    if (p == NULL)
        return 0;
    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;        // 删除结点
    free(q);
    return 1;
}

// 按位查找 (有头节点)
LNode *GetElem(LinkList L, int i) {
    if (i < 0)
        return L;
    int j = 0;
    LNode *p = L;
    while (p != NULL && j<i){
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找
LNode *LocateElem(LinkList L, int e){
    if (L == NULL)
        return NULL;
    LNode *p = L->next;
    // 从第一个结点开始赵
    while (p != NULL && p->data != e)
        p = p->next;
    return p;
}

// 建立
// 尾插法
LinkList List_TailInsert(LinkList *L){
    int x;
    *L = (LinkList)malloc(sizeof(LNode));       // 建立头节点
    LNode *s, *r = *L;                          // r为表尾指针
    printf("input x =");
    scanf("%d", &x);                    // 输入x的值
    while (x != -1){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;                            // 将s接入链表
        r = s;                                  // r指向新的表尾
        printf("input x =");
        scanf("%d", &x);
    }
    r->next = NULL;                             // 尾结点指针置空
    return *L;
}

// 头插法
LinkList List_HeadInsert(LinkList *L){
    int x;
    InitList(L);
    printf("input x =");
    scanf("%d", &x);                    // 输入x的值
    while (x != -1){
        InsertNextNode(*L, x);
        printf("input x =");
        scanf("%d", &x);
    }
    return *L;
}

// 链表逆置
LinkList Reverse(LinkList *L){
    LNode *p;
    p = (*L)->next;             // p指向第一个结点
    (*L)->next = NULL;          // 更新L
    while (p != NULL){
        LNode *tmp;
        tmp = p->next;          // 保存下一个结点
        p->next = (*L)->next;   // 将当前结点头插
        (*L)->next = p;
        p = tmp;                // 更新p
    }
    return *L;
}

int main(){
    LinkList L;
    InitList(&L);
    printf("len = %d\n", Length(L));
//    List_TailInsert(&L);
//    List_HeadInsert(&L);
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
    return 0;
}
