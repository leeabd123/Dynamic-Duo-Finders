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
#include<algorithm>
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

    vector<int> Betweenness(); // assign centrality scores to each node
    vector<int> Shortest_Path(int start, int end);
      
    //set the start and end node here for Dijkstra's algo
    void set_start_end(int start, int end); 

    //Dijkstra's algorithm
    void Shortest_Path_Algo();

    //helper funtion for Dijkstra's that finds the vertex with the min distance value 
    //from a set of verticies not included yet in the shortest path
    int Min_Dist(vector<int> distances, vector<bool> sp_set); 

    //Prints all the distances of the shortest paths from each Nodes to the src node
    void Print_Short_Path_Distances();

    //Prints the distance of shortest path between the src node to the end node 
    void Print_Short_Path_Dist_Src_to_End();

    
    //Returns a vector to the end of shortest path between the src node to the end node 
    vector<int> A_Short_Path_Src_to_End();

    //Prints all the shortest paths from each Node to the src node
    void Print_Shortest_Paths();

    //Prints the shortest path from the end node to the src node 
    void Print_A_Shortest_Path();

    

    private:
      //a vector of all the nodes
    vector<Node> nodes_;

    //the idx of the src node
    int src_node;

    //parent of a node, the node that comes before a certain node based off the shortest path of the tree
    vector<int> parent;

    //vector of distances that each node is from the src node
    vector<int> distances; 

    //the idx of the end node
    int end_idx; 

};

std::string file_to_string(const std::string & filename);
std::string TrimRight(const std::string & str);
std::string TrimLeft(const std::string & str);
std::string Trim(const std::string & str);
int SplitString(const std::string & str1, char sep, std::vector<std::string> &fields);
