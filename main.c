#include <stdio.h>
#include "graph.h"

int main(int argc, char const *argv[])
{
    Graph *g = create_Graph();
    PrintGraph(g);
    DFSTraverse(g);
    DFSTraverse(g);
    return 0;
}
