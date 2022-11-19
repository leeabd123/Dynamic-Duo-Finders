#ifndef NODE_HPP
#define NODE_HPP

using namespace std;


#include <iostream>
#include <vector>
#include <pair>

struct Node {
    Node(int dat): id(dat) {}
    int id;
    vector<pair<int, double>> neighbors;
};

#endif