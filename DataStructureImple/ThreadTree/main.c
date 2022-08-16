#include <stdio.h>
#include <stdlib.h>
#include "ThreadTree.h"

int main() {
    ThreadTree tree;
    InitThreadTree(&tree);
    AssignThreadTree(&tree);

    // 中序线索树
    CreateInThread(&tree);

    printf("InOrder:");
    InOrder(tree);

    printf("RevInOrder:");
    RevInOrder(tree);
    return 0;
}
