#include <stdio.h>
#include <stdlib.h>
#include "ThreadTree.h"

int InitThreadTree(ThreadTree *tree){
    *tree = (ThreadNode *)malloc(sizeof(ThreadNode));
    if ((*tree) == NULL){
        return 0;
    }
    (*tree)->data = -1;
    (*tree)->ltag = 0;
    (*tree)->rtag = 0;
    (*tree)->lchild = NULL;
    (*tree)->rchild = NULL;
    return 1;
}
ThreadTree AssignThreadTree(ThreadTree *tree){
    int i;
    scanf("%d", &i);
    if (i == -1)
        *tree = NULL;
    else{
        InitThreadTree(tree);
        (*tree)->data = i;
        AssignThreadTree(&((*tree)->lchild));
        AssignThreadTree(&((*tree)->rchild));
    }
}

// 全局变量pre
ThreadNode *pre = NULL;

void visit(ThreadNode *q){
    if (q->lchild == NULL){
        // 左孩子为空则指向前驱
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL){
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}

void PreThread(ThreadTree *T){
    if (*T != NULL){
        visit(*T);
        if ((*T)->ltag == 0)
            PreThread(&((*T)->lchild));
        PreThread(&((*T)->rchild));
    }
}
void InThread(ThreadTree *T){
    if (*T != NULL){
        InThread(&((*T)->lchild));
        visit(*T);
        InThread(&((*T)->rchild));
    }
}
void PostThread(ThreadTree *T){
    if (*T != NULL){
        PostThread(&((*T)->lchild));
        PostThread(&((*T)->rchild));
        visit(*T);
    }
}

void CreatePreThread(ThreadTree *T){
    pre = NULL;
    if (*T != NULL){
        PreThread(T);
        if (pre->rchild == NULL)
            pre->rtag = 1;
    }
}
void CreateInThread(ThreadTree *T){
    pre = NULL;
    if (*T != NULL){
        InThread(T);
        if (pre->rchild == NULL)
            pre->rtag = 1;
    }
}
void CreatePostThread(ThreadTree *T){
    pre = NULL;
    if (*T != NULL){
        PostThread(T);
        if (pre->rchild == NULL)
            pre->rtag = 1;
    }
}

// 中序遍历第一个节点
ThreadNode *FirstNode(ThreadNode *p){
    while (p->ltag == 0)
        p = p->lchild;
    return p;
}
// 中序遍历后继
ThreadNode *NextNode(ThreadNode *p){
    if (p->rtag == 0)
        return FirstNode(p->rchild);
    else
        return p->rchild;
}
// 中序遍历，非递归
void InOrder(ThreadTree p){
    for (ThreadNode *i = FirstNode(p); i != NULL ; i = NextNode(i)) {
        printf("%d ", i->data);
    }
    printf("\n");
}

// 中序遍历最后一个节点
ThreadNode *LastNode(ThreadNode *p){
    while (p->rtag == 0)
        p = p->rchild;
    return p;
}
// 中序遍历前驱
ThreadNode *PreNode(ThreadNode *p){
    if (p->ltag == 0)
        return LastNode(p->lchild);
    else
        return p->lchild;
}
// 逆中序遍历，非递归
void RevInOrder(ThreadTree p){
    for (ThreadNode *i = LastNode(p); i != NULL; i=PreNode(i)) {
        printf("%d ", i->data);
    }
    printf("\n");
}

int main() {
    ThreadTree tree;
    InitThreadTree(&tree);
    AssignThreadTree(&tree);
    CreateInThread(&tree);
    InOrder(tree);
    RevInOrder(tree);
    printf("Hello, World!\n");
    return 0;
}
