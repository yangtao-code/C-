#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"

int visited[MAXVES] = {0}; //存放顶点是否被访问过，0为为访问

Graph *create_Graph()
{
    Graph *G = malloc(sizeof(Graph));
    printf("请输入顶点数和边数(以空格隔开):");
    scanf("%d%d", &G->numVertexes, &G->numEdges);
    getchar();

    printf("请输入顶点信息(字符表示):\n");
    for (int i = 0; i < G->numVertexes; i++)
    {
        scanf("%c", &G->vexs[i]);
    }
    //给邻接矩阵全部赋值为零进行初始化
    for (int i = 0; i < G->numVertexes; i++)
    {
        for (int j = 0; j < G->numVertexes; j++)
        {
            G->adj[i][j] = 0;
        }
    }

    for (int k = 0; k < G->numEdges; k++)
    {
        int i, j;
    again:
        printf("请输入边(vi,vj)的下标i和j:\n");
        scanf("%d%d", &i, &j);
        if (i == j || G->adj[i][j] == 1)
        {
            printf("输入错误或者该点已输入！\n");
            goto again;
        }
        G->adj[i][j] = 1;
        G->adj[j][i] = G->adj[i][j];
    }

    printf("图的初始化完成！！！\n");
    return G;
}

void PrintGraph(Graph *G)
{
    printf("顶点信息:");
    for (int i = 0; i < G->numVertexes; i++)
    {
        printf("%c ", G->vexs[i]);
    }
    printf("\n");
    printf("邻接矩阵：\n");
    for (int i = 0; i < G->numVertexes; i++)
    {
        for (int j = 0; j < G->numVertexes; j++)
        {
            printf("%-5d ", G->adj[i][j]);
        }
        printf("\n");
    }

    printf("-------------------------\n");
}

void DFSTraverse(Graph *G)
{
    for (int i = 0; i < G->numVertexes; i++)
    {
        if (visited[i] == 0)
        {
            DFS(G, i);
        }
    }
    printf("\n");
    memset(visited, 0, sizeof(int) * G->numVertexes);
}

void DFS(Graph *G, int i)
{
    printf("%c ", G->vexs[i]);
    visited[i] = 1;
    for (int j = 0; j < G->numVertexes; j++)
    {
        if (G->adj[i][j] == 1 && visited[j] == 0)
        {
            DFS(G, j);
        }
    }
}