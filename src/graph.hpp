#ifndef GRAPH_HPP
#define GRAPH_HPP

using namespace std;


//#include <iostream>
#include <vector>
#include "node.hpp"
#include <queue>
#include <node.hpp>
#include <List>
#include <ArrayList>


class Graph {
    public:
    int V;
    list<int> *l;
    Graph(int V) { //specify number of verticies
        this->V = V;
        //each term in the list is a pointer to a list
        // 0 -> <1,2,3...
        // 1 -> <2,4,5...
        l = new list<int>[V];
    }
    void addEdge(Node x, Node y) {
        l[x.id].insert(y.id);
        l[y.id].insert(x.id);
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
    void addNode(Node node) {
        bool is_there = false;
        for (int node : l) {
            if (l == node.id) {
                is_there = true;
            }
        }
        if (!is_there) {
           l.insert(node.id);
        }
    } 


    // returns the ids of nodes visited started from input node id in a bfs
    vector<int> BFS(int start_id);


    private:
    vector<Node> nodes_;
};

#endif
