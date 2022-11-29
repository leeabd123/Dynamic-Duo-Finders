#include "graph.h"
#include <iostream>
// #include "../data/Edge-StartNode-EndNode-Dist.csv"
void printTraversal(std::vector<int> traversal) {
    std::cout << "traversal from node " << traversal.at(0) << ": " << std::endl;
    for (int node_id: traversal) {
        std::cout << node_id << " ";
    }
    std::cout << std::endl;
}
void testSmall() {
    Graph g;
    for (int i = 0; i < 5; i++) {
        g.addNode(i);
    }
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(1,3,1);
    g.addEdge(3,4,1);
    g.printAdjLists();
    /**
     *    -x
     * x-x
     *    -x-x
     **/

    std::vector<int> traversal0 = g.BFS(0);
    printTraversal(traversal0);
}

void testFull() {
    // Need to initialize with filename
    Graph g2("./data/Edge-StartNode-EndNode-Dist.csv");
    g2.printAdjLists();
}

int main() {

    testSmall();
    // testFull();

    return 0;
}