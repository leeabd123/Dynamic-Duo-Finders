
#include "../src/graph.h"
#include <iostream>
#include <stdexcept>

// helper fxns
void print(std::vector<int> vec) {
    for (int i : vec) {
        std::cout << i << std::endl;
    }
}
std::pair<int,int> get_max(std::vector<int> vect) {
    int maxidx = 0;
    int maxval = -1;
    for(int i = 0; i < (int) vect.size(); i++) {
        if (vect[i] > maxval) {
            maxidx = i;
            maxval = vect[i];
        }
    }
    return {maxidx, maxval};
}

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
    vector<int> solution{ 0, 1, 2 };
    vector<int> testvec = g.BFS(0);
    assert(testvec == solution);
    if (testvec == solution) {
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

/////////////////////////////////////////////////////////////////////////////////////////////
//                                   DIJKSTRA'S TESTS                                      //
/////////////////////////////////////////////////////////////////////////////////////////////

void test_dijkstras_onepath() {
    Graph g;
    for (int i = 0; i < 3; i++) {
        g.addNode(i);
    }
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    vector<int> solution{2,1,0};
    g.set_start_end(0,2);
    g.Shortest_Path_Algo();

    vector<int> path = g.A_Short_Path_Src_to_End();
    assert(path == solution);
    if (path == solution) {
        std::cout << "TEST DIJKSTRA'S WITH ONE POSSIBLE PATH: PASSED" << std::endl;
    } else {
        std::cout << "TEST DIJKSTRA'S WITH ONE POSSIBLE PATH: FAILED" << std::endl;
    }
}

void test_dijkstras_bestpath() {
    Graph g;
    for (int i = 0; i < 3; i++) {
        g.addNode(i);
    }
    g.addEdge(0,1,10);
    g.addEdge(1,2,10);
    g.addEdge(0,2,10);

    vector<int> solution{2,0};
    g.set_start_end(0,2);
    g.Shortest_Path_Algo();

    vector<int> path = g.A_Short_Path_Src_to_End();
    assert(path == solution);
    if (path == solution) {
        std::cout << "TEST DIJKSTRA'S BEST OF MULTIPLE PATHS: PASSED" << std::endl;
    } else {
        std::cout << "TEST DIJKSTRA'S BEST OF MULTIPLE PATHS: FAILED" << std::endl;
    }
}

void test_dijkstras_full() {
    Graph g("./data/Edge-StartNode-EndNode-Dist.csv");

    g.set_start_end(9,7);
    g.Shortest_Path_Algo();
    vector<int> solution{7,5,2,9};

    vector<int> path = g.A_Short_Path_Src_to_End();
    if (path == solution) {
        std::cout << "TEST DIJKSTRA'S FULL: PASSED" << std::endl;
    } else {
        std::cout << "TEST DIJKSTRA'S FULL: FAILED" << std::endl;
    } 
}
/////////////////////////////////////////////////////////////////////////////////////////////
//                                   BETWEENNESS TESTS                                     //
/////////////////////////////////////////////////////////////////////////////////////////////

void testBetweennessSmall() {
    Graph g;
    for (int i = 0; i < 3; i++) {
        g.addNode(i);
    }
    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    vector<int> scores = g.Betweenness();
    std::pair<int,int> results = get_max(scores);

    if (results.second == 0) {
        std::cout << "TEST BETWEENNESS SMALL: PASSED" << std::endl;
    } else {
        std::cout << "TEST BETWEENNESS SMALL: FAILED" << std::endl;
    } 
}

void testBetweennessSize() {
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

    vector<int> scores = g.Betweenness();

    if ((int) scores.size() == g.size()) {
        std::cout << "TEST BETWEENNESS SIZE: PASSED" << std::endl;
    } else {
        std::cout << "TEST BETWEENNESS SIZE: FAILED" << std::endl;
    } 
}






////////////////////////////   RUN TESTS    ///////////////////////////////////////////////
int main() {
    // BFS
    test_smallBFS_size();
    test_smallBFS_traversal();
    test_BFS_traversal();
    test_largeBFS_details(); // on our dataset
    

    // Dijkstra's
    test_dijkstras_onepath();
    test_dijkstras_bestpath();
    test_dijkstras_full(); // on our dataset

    // Betweenness
    testBetweennessSmall();
    testBetweennessSmall();


    return 0;
}
