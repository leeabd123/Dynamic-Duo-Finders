#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include "node.h"
#include <queue>
#include <list>
// #include <ArrayList>

using namespace std;

class Graph {
    public:
    int V;
    Graph(int V) { //specify number of verticies
        this->V = V;
    }
    void addEdge(Node x, Node y, double distance) {
        pair<int, double> node1(x.id, 100/distance);
        pair<int, double> node2(y.id, 100/distance);
        x.neighbors.push_back(node2);
        y.neighbors.push_back(node1);
    }
    void printAdjLists() {
        for (auto node: nodes_) {
            std::cout << node.id << ": " << std::endl;
            for (auto neighbor: node.neighbors) {
                std::cout << neighbor.first << " " << std::endl;
            }
        }
    }
    void addNode(Node node) {
        auto lookup = find(nodes_.begin(), nodes_.end(), node);
        if (lookup == nodes_.end()) {
            nodes_.push_back(node);
        }
    } 

    // returns the ids of nodes visited started from input node id in a bfs
    vector<int> BFS(int start_id);


    private:
    vector<Node> nodes_;
};
