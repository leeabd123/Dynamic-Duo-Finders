#ifndef GRAPH_HPP
#define GRAPH_HPP

using namespace std;


//#include <iostream>
#include <vector>
#include "node.hpp"
#include <queue>

class Graph {
    public:
    int V;
    std::unordered_set<int> *l;
    Graph(int V) {
        this->V = V;
        l = new std::unordered_set<int>[V];
    }
    void addEdge(int x, int y) {
        l[x].insert(y);
        l[y].insert(x);
    }
    void printAdjList() {
        for (int i = 0; i < V; i++) {
            std::cout << "Vertex " << i << "->";
            for (int n : l[i]) {
                std::cout << n << ",";
            }
            std::cout << std::endl;
        }
    } 


    // returns the ids of nodes visited started from input node id in a bfs
    vector<int> BFS(int start_id);


    private:
    vector<Node> nodes_;
};

#endif
