# define MaxVertexNum 100
typedef char VertexType;            // 顶点的数据类型
typedef int EdgeType;               // 带权图中边上权值的数据类型
typedef int InfoType;               // 邻接表法中存储权值的类型
typedef struct {
    VertexType Vex[MaxVertexNum];   // 顶点表
    EdgeType Edge[MaxVertexNum][MaxVertexNum];  // 邻接矩阵，边表
    int vexnum, arcnum;                         // 图当前的顶点数和弧数
}MGraph;                            // 无向图

// 邻接表法
// 边
typedef struct ArcNode{
    int adjvex;                     // 边指向那个结点
    typedef struct ArcNode *next    // 指向下一条边的指针
    InfoType info;                  // 权值
}ArcNode;
// 顶点
typedef struct VNode{
    VertexType data;                // 顶点信息
    ArcNode *first;                 // 第一条边
}VNode, AdjList[MaxVertexNum];
// 图
typedef struct {
    AdjList vertices;               // 顶点与边
    int vexnum, arcnum;             // 图当前的顶点数和弧树
}ALGraph;

int Adjacent(MGraph G, int x, int y)           // 判断图是否有边(x, y)
{
    return G.Edge[x][y] != 0;
}
int* Neighbors(MGraph G, int x)                 // 列出图中与结点x邻接的边
{
    int neigh[G.vexnum];
    int i = 0;
    int j = 0;
    for (i = 0; i < G.vexnum; i++)
    {
        if (G.Edge[x][i] != 0)
        {
            neigh[j++] = i;
        }
        neigh[j] = -1;
    }
    return neigh;
}
void InsertVertex(MGraph G, int x);             // 在图G中插入顶点x。
void DeleteVertex(MGraph G, int x);             // 从图G中删除顶点x。
void AddEdge(MGraph *G, int x, int y)           // 若无向边(x, y)不存在，则向图G中添加该边，
{
    if ((*G).Edge[x][y] == 0)
    {
        (*G).Edge[x][y] == 1;
    }
}
void RemoveEdge(MGraph *G,int x,int y)          // 若无向边(x, y)存在，则从图G中删除该边。
{
    if ((*G).Edge[x][y] == 1)
    {
        (*G).Edge[x][y] = 0;
    }
}
int FirstNeighbor(MGraph G, int x)             // 求图G中顶点x的第一个邻接点，若有则返回项点号。若x没有邻接点或图中不存在x，则返回-1.
{
    int i = 0;
    for (i = 0; i < G.vexnum; i++)
    {
        if (G.Edge[x][i] != 0)
        {
            return i;
        }
    }
    return -1;
}
int NextNeighbor(MGraph G, int x, int y)       // 假设图G中顶点y是顶点x的一个邻接点，返回除y外顶点x的下一个邻接点的顶点号，若y是x的最后一个邻接点，则返回-1。
{
    for (int i = y; i < G.vexnum; i++)
    {
        if (G.Edge[x][i] != 0)
        {
            return i;
        }
    }
    return -1;
}
int Get_edge_value(MGraph G, int x, int y)     //  获取图G中边(x，y)对应的权值。
{
    return G.Edge[x][y];
}
void Set_edge_value(MGraph *G, int x, int y, int v) // 设置图G中边(x, y)对应的权值为V。
{
    (*G).Edge[x][y] = v;
}
void InitGraph(MGraph *G){
    // 获得顶点数和弧数
    int vexnum, arcnum;
    scanf("%d %d", &vexnum, &arcnum);
    (*G).vexnum = vexnum;
    (*G).arcnum = arcnum;

    // 初始化顶点表
    for (int i = 0; i < vexnum; i++)
    {
        char c;
        scanf("%c", &c);
        (*G).Vex[i] = c;
    }

    // 添加边
    for (int i = 0; i < arcnum; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        AddEdge(G, x, y);
    }
    
}