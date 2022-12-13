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
        pair<int, double> node1(x, distance); //I changed it from closeness factor to just distance 
        pair<int, double> node2(y, distance); //So when we print the distance from src for instance
        nodes_.at(x).neighbors.push_back(node2); //it wil be like 5 miles instead of a factor
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
    vector<int> Shortest_Path_Algo(int start_idx);//for each v we give the shortest path
    int Min_Dist(vector<int> distances, vector<bool> sp_set);
    void Print_Short_Path_Distances(vector<int> distances);
    void Print_Short_Path_Dist_Src_to_End(int end_idx);
    void Print_Shortest_Paths(vector<int> parent);
    void Print_A_Shortest_Path(int end_idx);
    vector<int> Betweenness(); // assign centrality scores to each node
    vector<int> Shortest_Path(int start, int end);
    


    private:
    vector<Node> nodes_;
    int src_node;
    vector<int> parent;
    vector<int> distances; 
    // int end_idx; 

};

std::string file_to_string(const std::string & filename);
std::string TrimRight(const std::string & str);
std::string TrimLeft(const std::string & str);
std::string Trim(const std::string & str);
int SplitString(const std::string & str1, char sep, std::vector<std::string> &fields);
