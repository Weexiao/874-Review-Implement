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

int InitThreadTree(ThreadTree *tree);
ThreadTree AssignThreadTree(ThreadTree *tree);

void visit(ThreadNode *q);

void PreThread(ThreadTree *T);
void InThread(ThreadTree *T);
void PostThread(ThreadTree *T);

void CreatePreThread(ThreadTree *T);
void CreateInThread(ThreadTree *T);
void CreatePostThread(ThreadTree *T);

// 中序遍历第一个节点
ThreadNode *FirstNode(ThreadNode *p);
// 中序遍历后继
ThreadNode *NextNode(ThreadNode *p);
// 中序遍历，非递归
void InOrder(ThreadTree p);

// 中序遍历最后一个节点
ThreadNode *LastNode(ThreadNode *p);
// 中序遍历前驱
ThreadNode *PreNode(ThreadNode *p);
// 逆中序遍历，非递归
void RevInOrder(ThreadTree p);