
#include "../src/graph.h"
#include <iostream>
#include <stdexcept>

/////////////////////////////////////////////////////////////////////////////////////////////
//                                   BFS TESTS                                             //
/////////////////////////////////////////////////////////////////////////////////////////////

void test_smallBFS_size() {
    Graph g;
    for (int i = 0; i < 3; i++) {
        g.addNode(i);
    }
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    assert(g.BFS(0).size() == 3);
    if (g.BFS(0).size() == 3) {
        std::cout << "TEST SMALL BFS SIZE: PASSED" << std::endl;
    } else {
        std::cout << "TEST SMALL BFS SIZE: FAILED" << std::endl;
    }
}

void test_smallBFS_traversal() {
    Graph g;
    for (int i = 0; i < 3; i++) {
        g.addNode(i);
    }
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    vector<int> vect{ 0, 1, 2 };
    vector<int> testvec = g.BFS(0);
    assert(testvec == vect);
    if (testvec == vect) {
        std::cout << "TEST SMALL BFS TRAVERSAL: PASSED" << std::endl;
    } else {
        std::cout << "TEST SMALL BFS TRAVERSAL: FAILED" << std::endl;
    }
}
void test_BFS_traversal() {
    Graph g;
    for (int i = 0; i < 9; i++) {
        g.addNode(i);
    }
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(3,2,1);
    g.addEdge(4,2,1);
    g.addEdge(1,5,1);
    g.addEdge(0,6,1);
    g.addEdge(6,7,1);
    g.addEdge(7,8,1);

    /*
        THIS IS THE GRAPH WE MADE
                    0
                 ___/\__
                1       6
            ___/ \__     \__
            2       5       7
        ___/ \__             \__
        3       4               8
    */
    vector<int> vect{ 0, 1, 6, 2, 5, 7, 3, 4, 8};
    vector<int> testvec = g.BFS(0);
    assert(testvec == vect);
    if (testvec == vect) {
        std::cout << "TEST NORMAL BFS TRAVERSAL: PASSED" << std::endl;
    } else {
        std::cout << "TEST NORMAL BFS TRAVERSAL: FAILED" << std::endl;
    }
}

void test_largeBFS_details() {
    Graph g("./data/Edge-StartNode-EndNode-Dist.csv");
    vector<int> testvec = g.BFS(618);

    // make sure the starting node is right
    assert(testvec[0] == 618);
    if (testvec[0] == 618) {
        std::cout << "TEST LARGE BFS START NODE: PASSED" << std::endl;
    } else {
        std::cout << "TEST LARGE BFS START NODE: FAILED" << std::endl;
    }
    
    // making sure the next nodes are accurate for the starting node
    assert(testvec[2] == 611 && testvec [1] == 625);
    if (testvec[2] == 611 && testvec [1] == 625) {
        std::cout << "TEST LARGE BFS ADJACENT NODES: PASSED" << std::endl;
    } else {
        std::cout << "TEST LARGE BFS ADJACENT NODES: FAILED" << std::endl;
    }
}

int main() {
    // BFS
    test_smallBFS_size();
    test_smallBFS_traversal();
    test_BFS_traversal();
    test_largeBFS_details();

    

    
    return 0;
}