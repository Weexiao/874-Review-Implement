//
// Created by 九三 on 2022/3/30.
//

#ifndef THREADTREE_THREADTREE_H
#define THREADTREE_THREADTREE_H

#endif //THREADTREE_THREADTREE_H

typedef struct ThreadNode{
    int data;
    struct ThreadNode *lchild, *rchild;     // 左右子树
    int ltag, rtag;                         // 左右线索标志
}ThreadNode, *ThreadTree;

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
void AssignThreadTree(ThreadTree *tree){
    int i;
    printf("请输入树节点数据\n");
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

// 全局变量pre，指向当前访问节点的前驱
ThreadNode *pre = NULL;

void visit(ThreadNode *q){
    if (q->lchild == NULL)
    {
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre!=NULL && pre->rchild==NULL)
    {
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
    if ((*T) != NULL)
    {
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
    pre=NULL;
    if ((*T) != NULL)
    {
        InThread(T);
        if (pre->rchild == NULL)
        {
            pre->rtag = 1; // 处理最后一个节点
        }
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
ThreadNode *InFirstNode(ThreadNode *p){
    while (p->ltag == 0)
        p = p->lchild;
    return p;
}
// 中序遍历后继
ThreadNode *InNextNode(ThreadNode *p){
    if (p->rtag == 0)
        return InFirstNode(p->rchild);
    else
        return p->rchild;
}
// 中序遍历，非递归
void InOrder(ThreadTree p){
    for (ThreadNode *i = InFirstNode(p); i != NULL ; i = InNextNode(i)) {
        printf("%d ", i->data);
    }
    printf("\n");
}

// 中序遍历最后一个节点
ThreadNode *InLastNode(ThreadNode *p){
    while (p->rtag == 0)
        p = p->rchild;
    return p;
}
// 中序遍历前驱
ThreadNode *InPreNode(ThreadNode *p){
    if (p->ltag == 0)
        return InLastNode(p->lchild);
    else
        return p->lchild;
}
// 逆中序遍历，非递归
void RevInOrder(ThreadTree p){
    for (ThreadNode *i = InLastNode(p); i != NULL; i=InPreNode(i)) {
        printf("%d ", i->data);
    }
    printf("\n");
}

