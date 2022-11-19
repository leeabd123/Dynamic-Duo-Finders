#ifndef GRAPH_HPP
#define GRAPH_HPP

using namespace std;


//#include <iostream>
#include <vector>
#include "node.hpp"
#include <queue>

class Graph {
    public:
    Graph() {}

    // returns the ids of nodes visited started from input node id in a bfs
    vector<int> BFS(int start_id);


    private:
    vector<Node> nodes_;
}

#endif