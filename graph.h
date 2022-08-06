#ifndef GRAPH_H_
#define GRAPH_H_

typedef char VertexType; //顶点类型
typedef int EdgeType;    //
#define MAXVES 20
#define INFTY 65535

typedef struct
{
    VertexType vexs[MAXVES];
    EdgeType adj[MAXVES][MAXVES];
    int numVertexes;
    int numEdges;
} Graph;

//创建一个无向图
Graph *create_Graph();
//打印图的信息
void PrintGraph(Graph *G);
//深度优先遍历
void DFSTraverse(Graph *G);

void DFS(Graph *G, int i);

#endif