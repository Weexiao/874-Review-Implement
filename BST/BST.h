//
// Created by 九三 on 2022/4/14.
//

#ifndef BST_BST_H
#define BST_BST_H

#endif //BST_BST_H

typedef struct BSTNode {
    int key;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

// 中序遍历
void InOrder(BSTree Tree);

// 构造
void Create_BST(BSTree *T, int nums[], int n);

// 非递归查找
BSTNode *NoRBST_Search(BSTree Tree, int key);
// 递归查找
BSTNode *BST_Search(BSTree Tree, int key);

// 递归插入
int BST_Insert(BSTree *Tree, int key);
// 非递归插入
int NoRBST_Insert(BSTree *Tree, int key);
