#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

int main(){
    BiTree tree;
    InitBiTree(&tree);
    AssignBiTree(&tree);

    printf("PreOrder:");
    PreOrder(tree);
    printf("\n");

    printf("InOrder:");
    InOrder(tree);
    printf("\n");

    printf("PostOrder:");
    PostOrder(tree);
    printf("\n");

    printf("该树的深度为：%d", BiTreeDepth(tree));

    // printf("LevelOrder:");
    // LevelOrder(tree);
    // printf("\n");
    return 1;
}