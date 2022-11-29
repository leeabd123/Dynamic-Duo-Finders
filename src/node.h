#pragma once

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

struct Node {
    Node(int dat): id(dat) {}
    int id;
    vector<pair<int, double>> neighbors;
};