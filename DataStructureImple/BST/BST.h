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
int BST_Insert(BSTree *T, int key){
    // 若树为空则直接插入
    if((*T) == NULL){
        (*T) = (BSTNode *)malloc(sizeof(BSTNode));
        (*T)->key = key;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
        return 1;
    }
    else if(key == (*T)->key)
        return 0;
    else if(key < (*T)->key)
        return BST_Insert(&((*T)->lchild), key);
    else
        return BST_Insert(&((*T)->rchild), key);
}
// 非递归插入，最差空间复杂度为O(1)
int NoRBST_Insert(BSTree *T, int key){
    // 若树为空，则直接插入
    if ((*T) == NULL)
    {
        (*T) = (BSTNode *)malloc(sizeof(BSTNode));
        (*T)->key = key;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
        return 1;
    }
    
    // 树不为空，则记录上一个节点与自己
    BSTNode *pre = NULL;
    BSTNode *now = (*T);
    while (now != NULL)
    {
        if(key == now->key)
            return 0;
        else if(key < now->key){
            pre = now;
            now = now->lchild;
        }
        else{
            pre = now;
            now = now->rchild;
        }
    }
    
    // 之后判断key值与pre的关系
    if (key < pre->key)
    {
        BSTNode *curr = (BSTNode *)malloc(sizeof(BSTNode));
        curr->key = key;
        curr->lchild=curr->rchild=NULL;
        pre->lchild = curr;
    }
    else
    {
        BSTNode *curr = (BSTNode *)malloc(sizeof(BSTNode));
        curr->key = key;
        curr->lchild=curr->rchild=NULL;
        pre->rchild = curr;
    }
    return 1;
}

// 中序遍历，递归实现
void InOrder(BSTree T){
    if (T != NULL){
        InOrder(T->lchild);
        printf("%d", (T->key));
        InOrder(T->rchild);
    }
}

void Create_BST(BSTree *T, int nums[], int n){
    (*T) = NULL;
    int i = 0;
    while (i<n){
        BST_Insert(T, nums[i]);
        i++;
    }
}

void NoRCreate_BST(BSTree *T, int nums[], int n){
    (*T) = NULL;
    int i = 0;
    while (i<n){
        NoRBST_Insert(T, nums[i]);
        i++;
    }
}