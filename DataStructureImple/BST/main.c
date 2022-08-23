#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

int main() {
    BSTree T = NULL;
    int num[] = {1,4,7,2,9,3,5,6,8};
    Create_BST(&T, num, 9);

    InOrder(T);
    printf("\n");
    // 查找2，9
    printf("%d\n", BST_Search(T, 2)->key);
    printf("%d\n", NoRBST_Search(T, 9)->key);

    T = NULL;
    NoRCreate_BST(&T, num, 9);

    InOrder(T);
    printf("\n");
    // 查找2，9
    printf("%d\n", BST_Search(T, 2)->key);
    printf("%d\n", NoRBST_Search(T, 9)->key);
}
