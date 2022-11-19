#ifndef NODE_HPP
#define NODE_HPP

using namespace std;


#include <iostream>
#include <vector>

struct Node {
    Node(int dat): id(dat) {}
    int id;
    vector<int> neighbors;
};

#endif