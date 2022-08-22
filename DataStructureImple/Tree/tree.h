// 顺序存储
#define MAXSIZE 100
typedef struct TreeNode
{
    int value;
    int isEmpty;
}TreeNode;

// TreeNode t[MAXSIZE];  定义长度为MaxSize的数组，从上到下从左往右依次存储完全二叉树中的各个结点

// void InitTree(TreeNode t[]){
//     for (int i = 0; i < MAXSIZE; i++)
//     {
//         t->isEmpty = 1;
//     }
// }

// 链式存储，找孩子方便，找父亲困难
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
// 链式存储，找父亲方便
// typedef struct BiTNode
// {
//     int data;
//     struct BiTNode *lchild, *rchild;
//     struct BiTNode *parent;
// }BiTNode, *BiTree;

// 树的双亲表示法，顺序存储
typedef struct PTNode
{
    int data;
    int parent;
}PTNode;
typedef struct PTree
{
    PTNode nodes[MAXSIZE];
    int n;   //结点数
};

// 树的孩子表示法，顺序+链式存储
struct CTNode
{
    int child;                  // 孩子结点在数组中的位置
    struct CTNode *next;            // 下一个孩子结点
};
typedef struct CTBox
{
    int data;
    struct CTNode *firstChild;      //第一个孩子
}CTBox;
typedef struct CTree
{
    CTBox nodes[MAXSIZE];
    int n, r;       // 结点数与根所在的位置
}CTree;

// 树的左孩子右兄弟表示法，链式存储
typedef struct CSNode
{
    int data;
    struct CSNode *firstChild, *nextSibling;        // 左孩子右兄弟
}CSNode, *CSTree;


int InitBiTree(BiTree *tree){
    (*tree) = (BiTree)malloc(sizeof(BiTNode));
    if ((*tree)==NULL)
    {
        return 0;
    }
    (*tree)->data=-1;
    (*tree)->lchild=NULL;
    (*tree)->rchild=NULL;
    return 1;
}

BiTree AssignBiTree(BiTree *tree){
    int i;
    printf("请输入树结点数据\n");
    scanf("%d", &i);
    if (i == -1)
        *tree = NULL;
    else{
        InitBiTree(tree);
        (*tree)->data = i;
        AssignBiTree(&((*tree)->lchild));
        AssignBiTree(&((*tree)->rchild));
    }
}

void PreOrder(BiTree tree){
    if (tree != NULL)
    {
        printf("%d ", tree->data);
        PreOrder(tree->lchild);
        PreOrder(tree->rchild);
    }
}

void InOrder(BiTree tree){
    if (tree != NULL)
    {
        InOrder(tree->lchild);
        printf("%d ", tree->data);
        InOrder(tree->rchild);
    }
}

void PostOrder(BiTree tree){
    if (tree != NULL)
    {
        PostOrder(tree->lchild);
        PostOrder(tree->rchild);
        printf("%d ", tree->data);
    }
}

int BiTreeDepth(BiTree tree){
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        int l = BiTreeDepth(tree->lchild);
        int r = BiTreeDepth(tree->rchild);
        // 树深度等于左右子树深度最大值+1
        return l>r ? l+1 : r+1; 
    }
}

// void LevelOrder(BiTree tree)
// {
//     LinkQueue Q;
//     InitLQueue(&Q);
//     BiTree p;
//     EnLQueue(&Q, T);
//     while (!LQueueEmpty(Q))
//     {
//         DeLQueue(&Q, p);
//         printf("%d ", p->data);
//         if (p->lchild!=NULL)
//         {
//             EnLQueue(&Q, p->lchild);
//         }
//         if (p->rchild!=NULL)
//         {
//             EnLQueue(&Q, p->rchild);
//         }
//     }
// }