// #ifndef NODE_HPP
// #define NODE_HPP
#pragma once



#include <iostream>
#include <vector>
#include <utility>
// #include <pair>
using namespace std;

struct Node {
    Node(int dat): id(dat) {}
    int id;
    vector<pair<int, double>> neighbors;
};

// #endif