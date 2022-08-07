#include<stdio.h>
#include<stdlib.h>
#include "graph.h"

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

int main(){
    MGraph G;
    InitGraph(&G);
    printf("wuhu");
    return 1;
}