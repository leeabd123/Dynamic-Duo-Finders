#include "graph.h"


using namespace std;

vector<int> Graph::BFS(Node start) {
    vector<bool> visited(nodes_.size(), false);
    vector<int> traversal;
    queue<Node> q;
    q.push(start);
    visited[start.id] = true;

    while (!q.empty()) {
        Node cur_node = q.front();
        q.pop();
        traversal.push_back(cur_node.id);
        visited[cur_node.id] = true;
        for(auto neighbor: cur_node.neighbors) {
            if (!visited[neighbor.first]) {
                q.push(nodes_.at(neighbor.first));
            }
        }

    }
    return traversal;
}