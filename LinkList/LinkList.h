//
// Created by 九三 on 2022/1/25.
//

#ifndef LINKLIST_LINKLIST_H
#define LINKLIST_LINKLIST_H

#endif //LINKLIST_LINKLIST_H

typedef struct LNode{                   // 定义单链表结点类型
    int data;                      // 每个结点存放一个数据元素
    struct LNode *next;                 // 指针指向下一个结点
}LNode, *LinkList;

//typedef struct DNode{                        // 定义双链表结点类型
//    ElemType data;                           // 每个结点存放一个数据元素
//    struct DNode *prior, *next;              // 前驱和后继结点
//}DNode, *DLinkList;

// 初始化
// 初始化一个空的链表 (带头节点)
int InitList(LinkList *L);
// 判断单链表是否为空 (有头节点)
int Empty(LinkList L);
// 求表长度
int Length(LinkList L);

// 插入
// 按位序插入 (有头节点)
int ListInsert(LinkList *L, int i, int e);
// 后插操作：在p节点后插入元素e
int InsertNextNode(LNode *p, int e);
// 前插操作：在p节点前插入元素e
int InsertPriorNode(LNode *p, int e);

// 删除
// 按位序删除 (有头节点)
int ListDelete(LinkList *L, int i, int *e);
// 删除指定结点
int DeleteNode(LNode *p);

// 查找
// 按位查找 (有头节点)
LNode *GetElem(LinkList L, int i);
// 按值查找
LNode *LocateElem(LinkList L, int e);

// 建立
// 尾插法
LinkList List_TailInsert(LinkList *L);
// 头插法
LinkList List_HeadInsert(LinkList *L);

// 链表逆置
LinkList Reverse(LinkList *L);