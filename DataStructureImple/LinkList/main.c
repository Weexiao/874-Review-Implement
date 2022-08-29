#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

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

    InsertPriorNode(L->next->next, 8);
    InsertPriorNode(L->next->next, 9);
    // 修改链表
    Change_List(&L);
    printf("len = %d\n", Length(L));
    LNode *s = L->next;
    while (s != NULL)
    {
        printf("x = %d\n", s->data);
        s = s->next;
    }

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
