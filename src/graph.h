#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include "node.h"
#include <queue>
#include <list>
#include "utils.h"

#include <utility>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <fstream>
// #include <ArrayList>

using namespace std;

class Graph {
    public:
    Graph(){}
    Graph(const std::string & filename);
    Graph(vector<int> node_ids) {
        for (int id: node_ids) {
            Node node(id);
            nodes_.push_back(node);
        }
    }
    void addEdge(int x, int y, double distance) {
        pair<int, double> node1(x, 100/distance);
        pair<int, double> node2(y, 100/distance);
        nodes_.at(x).neighbors.push_back(node2);
        nodes_.at(y).neighbors.push_back(node1);
    }
    void printAdjLists() {
        for (auto node: nodes_) {
            std::cout << node.id << ": ";
            for (auto neighbor: node.neighbors) {
                std::cout << neighbor.first << " ";
            }
            std::cout << std::endl;
        }
    }
    void addNode(int node_id) {
        Node node(node_id);
        nodes_.push_back(node);
    }
    int size() {return nodes_.size();};
    // void addNode(Node node) {
    //     auto lookup = find(nodes_.begin(), nodes_.end(), node);
    //     if (lookup == nodes_.end()) {
    //         nodes_.push_back(node);
    //     }
    // } 

    // returns the ids of the nodes visited started from input node id in a bfs
    vector<int> BFS(int start_id);


    private:
    vector<Node> nodes_;
};

std::string file_to_string(const std::string & filename);
std::string TrimRight(const std::string & str);
std::string TrimLeft(const std::string & str);
std::string Trim(const std::string & str);
int SplitString(const std::string & str1, char sep, std::vector<std::string> &fields);
