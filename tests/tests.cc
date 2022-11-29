// test bfs gives traversal of correct size

// #ifndef CATCH_CONFIG_MAIN
// #  define CATCH_CONFIG_MAIN
// #endif
#pragma once

#include "catch.hpp"

#include <stdexcept>

#include "graph.h"
// int main() {
//     Graph g;
//     for (int i = 0; i < 3; i++) {
//         g.addNode(i);
//     }
//     g.addEdge(0,1,1);
//     g.addEdge(1,2,1);
//     g.printAdjLists();

//     return 0;
// }

TEST_CASE("Test BFS Size", "[BFS]") {
    Graph g;
    for (int i = 0; i < 3; i++) {
        g.addNode(i);
    }
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    REQUIRE(g.BFS().size() == 3);

}