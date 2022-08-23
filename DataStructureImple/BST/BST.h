typedef struct BSTNode {
    int key;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

// 非递归查找
BSTNode *NoRBST_Search(BSTree T, int key){
    // 如果节点不为空且节点值不相等则继续循环
    while (T != NULL && key != T->key)
    {
        if (key < T->key)
            T = T->lchild;
        else
            T = T->rchild;
    }
    return T;
}
// 递归查找
BSTNode *BST_Search(BSTree T, int key){
    if (T == NULL)
        return NULL;
    else if (key == T->key)
        return T;
    else if (key < T->key)
        return BST_Search(T->lchild, key);
    else
        return BST_Search(T->rchild, key);
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

// 中序遍历，递归实现
void InOrder(BSTree Tree){
    if (Tree != NULL){
        InOrder(Tree->lchild);
        printf("%d", (Tree->key));
        InOrder(Tree->rchild);
    }
}

void Create_BST(BSTree *Tree, int nums[], int n){
    (*Tree) = NULL;
    int i = 0;
    while (i<n){
        BST_Insert(Tree, nums[i]);
        i++;
    }
}

void NoRCreate_BST(BSTree *Tree, int nums[], int n){
    (*Tree) = NULL;
    int i = 0;
    while (i<n){
        NoRBST_Insert(Tree, nums[i]);
        i++;
    }
}