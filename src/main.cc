#include "graph.h"
// #include "../data/Edge-StartNode-EndNode-Dist.csv"
int main() {
    // Need to initialize with filename
    Graph g;
    for (int i = 0; i < 3; i++) {
        g.addNode(i);
    }
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.printAdjLists();

    Graph g2("./data/Edge-StartNode-EndNode-Dist.csv");
    g2.printAdjLists();

    return 0;
}