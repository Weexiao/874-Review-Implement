#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

// 中序遍历，递归实现
void InOrder(BSTree Tree){
    if (Tree != NULL){
        InOrder(Tree->lchild);
        printf("%d", (Tree->key));
        InOrder(Tree->rchild);
    }
}

void Create_BST(BSTree *Tree, int nums[], int n){
    Tree = NULL;
    int i = 0;
    while (i<n){
        BST_Insert(*Tree, nums[i]);
        i++;
    }
}

// 非递归查找
BSTNode *NoRBST_Search(BSTree Tree, int key){
    // 如果节点不为空或者节点值不相等则继续循环
    while (Tree != NULL && Tree->key != key){
        // 小于去左子树，大于去左子树，等于就返回
        if (key < Tree->key) Tree = Tree->lchild;
        else Tree = Tree->rchild;
    }
    return Tree;
}
// 递归查找
BSTNode *BST_Search(BSTree Tree, int key){
    if (Tree == NULL)
        return NULL;
    if (key == Tree->key)
        return Tree;
    else if (key < Tree->key)
        return BST_Search(Tree->lchild, key);
    else
        return BST_Search(Tree->rchild, key);
}

// 递归插入
int BST_Insert(BSTree *Tree, int key){
    if ((*Tree) == NULL){
        // 直接插入
        (*Tree) = (BSTree)malloc(sizeof(BSTree));
        (*Tree)->key = key;
        (*Tree)->lchild = (*Tree)->rchild = NULL;
        return 1;
    }
    if (key == (*Tree)->key)
        return 0;
    else if (key < (*Tree)->key)
        return BST_Insert(&((*Tree)->lchild), key);
    else
        return BST_Insert(&((*Tree)->rchild), key);
}
// 非递归插入，最差空间复杂度为O(1)
int NoRBST_Insert(BSTree *Tree, int key){
    // 若树为空，则直接插入
    if ((*Tree) == NULL){
        // 直接插入
        (*Tree) = (BSTree)malloc(sizeof(BSTree));
        (*Tree)->key = key;
        (*Tree)->lchild = (*Tree)->rchild = NULL;
        return 1;
    }

    // 树不为空，则记录上一个节点与自己
    BSTree pre = NULL;
    BSTree pnow = (*Tree);
    while (pnow != NULL){
        // 找到最后一个节点
        if (key == pnow->key)
            return 0;
        else if (key < pnow->key){
            // 往左走
            pre = pnow;
            pnow = pnow->lchild;
        } else{
            // 往右走
            pre = pnow;
            pnow = pnow->rchild;
        }
    }

    // 之后判断key值与pre的关系
    if (key < pre->key){
        BSTNode *now = (BSTNode *)malloc(sizeof(BSTNode));
        (*now).key = key;
        (*now).lchild = (*now).rchild = NULL;
        pre->lchild = now;
    } else{
        BSTNode *now = (BSTNode *)malloc(sizeof(BSTNode));
        (*now).key = key;
        (*now).lchild = (*now).rchild = NULL;
        pre->rchild = now;
    }
}

int main() {
    BSTree T = NULL;

    // 插入123456789
    BST_Insert(&T, 1);
    BST_Insert(&T, 2);
    BST_Insert(&T, 3);
    BST_Insert(&T, 4);
    BST_Insert(&T, 5);
    NoRBST_Insert(&T, 6);
    NoRBST_Insert(&T, 7);
    NoRBST_Insert(&T, 8);
    NoRBST_Insert(&T, 9);

    InOrder(T);
    printf("\n");

    // 查找2，9
    printf("%d\n", BST_Search(T, 2)->key);
    printf("%d\n", NoRBST_Search(T, 9)->key);
}
