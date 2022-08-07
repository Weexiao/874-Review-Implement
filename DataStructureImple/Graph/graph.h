# define MaxVertexNum 100
typedef char VertexType;            // 顶点的数据类型
typedef int EdgeType;               // 带权图中边上权值的数据类型
typedef struct {
    VertexType Vex[MaxVertexNum];   // 顶点表
    EdgeType Edge[MaxVertexNum][MaxVertexNum];  // 邻接矩阵，边表
    int vexnum, arcnum;                         // 图当前的顶点数和弧数
}MGraph;                            // 无向图

int Adjacent(MGraph G, int x, int y);           // 判断图是否有边(x, y)
int* Neighbors(MGraph G, int x);                 // 列出图中与结点x邻接的边
void InsertVertex(MGraph G, int x);             // 在图G中插入顶点x。
void DeleteVertex(MGraph G, int x);             // 从图G中删除顶点x。
void AddEdge(MGraph *G, int x, int y);           // 若无向边(x, y)不存在，则向图G中添加该边，
void RemoveEdge(MGraph *G,int x,int y);          // 若无向边(x, y)存在，则从图G中删除该边。
int FirstNeighbor(MGraph G, int x);             // 求图G中顶点x的第一个邻接点，若有则返回项点号。若x没有邻接点或图中不存在x，则返回-1.
int NextNeighbor(MGraph G, int x, int y);       // 假设图G中顶点y是顶点x的一个邻接点，返回除y外顶点x的下一个邻接点的顶点号，若y是x的最后一个邻接点，则返回-1。
int Get_edge_value(MGraph G, int x, int y);     //  获取图G中边(x，y)对应的权值。
void Set_edge_value(MGraph *G, int x, int y, int v); // 设置图G中边(x, y)对应的权值为V。
void IniGraph(MGraph *G);