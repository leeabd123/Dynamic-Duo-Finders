#include "graph.hpp"


using namespace std;

vector<int> Graph::BFS(int start_id) {
    vector<bool> visited(nodes_.size(), false);
    vector<int> trav;
    queue<int> q;
    q.push(start_id);
    visited[start_id] = true;

    while (!q.empty()) {
        int cur_node = q.front();
        q.pop();
        trav.push_back(cur_node);
        visited[cur_node] = true;
        for(unsigned i = 0; i < cur_node.neighbors.size(); i++) {
            if (!visited[cur_node.neighbors[i].first]) {
                q.push(cur_node.neighbors[i].first);
            }
        }

    }
    return trav;
}