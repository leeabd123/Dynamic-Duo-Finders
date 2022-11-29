#include "graph.h"
#include <algorithm>
#include <sstream>
#include <fenv.h>
#include <signal.h>
#include <vector>

using namespace std;

Graph::Graph(const std::string & filename) {
    string file = file_to_string(filename);
    vector<string> lines;
    SplitString(file, '\n', lines);
    // fill the nodes_ vector with nodes that have ids corresponding to their index
    for (unsigned i = 0; i < lines.size(); i++) {
        nodes_.push_back(Node(i));
    }
    for(string line : lines) {
        vector<string> thisline;
        SplitString(line, ' ', thisline);
        if (thisline.size() == 4) {
            int n1 = stoi(Trim(thisline[1]));
            int n2 = stoi(Trim(thisline[2]));
            double dist = stod(Trim(thisline[3]));
            addEdge(n1,n2, dist);
        }

    }
    // clean up extra nodes
    int i = nodes_.size() - 1;
    while (nodes_[i].neighbors.size() == 0) {
        nodes_.pop_back();
        i--;
    }
}


vector<int> Graph::BFS(int start_id) {
    Node start = nodes_.at(start_id);
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

std::string file_to_string(const std::string& filename){
  std::ifstream text(filename);

  std::stringstream strStream;
  if (text.is_open()) {
    strStream << text.rdbuf();
  }
  return strStream.str();
}

std::string TrimRight(const std::string & str) {
    std::string tmp = str;
    return tmp.erase(tmp.find_last_not_of(" ") + 1);
}

std::string TrimLeft(const std::string & str) {
    std::string tmp = str;
    return tmp.erase(0, tmp.find_first_not_of(" "));
}

std::string Trim(const std::string & str) {
    std::string tmp = str;
    return TrimLeft(TrimRight(str));
}

int SplitString(const std::string & str1, char sep, std::vector<std::string> &fields) {
    std::string str = str1;
    std::string::size_type pos;
    while((pos=str.find(sep)) != std::string::npos) {
        fields.push_back(str.substr(0,pos));
        str.erase(0,pos+1);  
    }
    fields.push_back(str);
    return fields.size();
}