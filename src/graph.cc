#include "graph.hpp"


using namespace std;

vector<int> Graph::BFS(int start_id) {
    vector<bool> visited(nodes_.size(), false);
    vector<int> trav;
    queue<int> q;
    q.push(start_id);
    visited[start_id] = true;

    while (!q.empty()) {
        int cur_id = q.front();
        q.pop();
        trav.push_back(cur_id);
        visited[cur_id] = true;
        for(unsigned i = 0; i < nodes_[cur_id].neighbors.size(); i++) {
            if (!visited[nodes_[cur_id].neighbors[i].first]) {
                q.push(nodes_[cur_id].neighbors[i].first);
            }
        }

    }
    return trav;
}