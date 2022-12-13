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

//-------------- BFS Stuff -----------------//
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
// ------------ Dijkstra's Algo Stuff -------------------- // 

void Graph::set_start_end(int start, int end) {
    src_node = start;
    end_idx = end;
}


int Graph::Min_Dist(vector<int> distances, vector<bool> sp_set) {
    int min = 2147483647;
    int min_index;

    for (int v = 0; v < size(); v++) {
        if (sp_set[v] == false && distances[v] <= min) {
            min = distances[v];
            min_index = v;
        }
        
    }
    return min_index;
}

void Graph::Shortest_Path_Algo() {
    parent.resize(size());
    distances.resize(size());
    vector<bool> spset = vector<bool>(size());
    for (int i = 0; i < size(); i++) {
        distances[i] = 2147483647;
        spset[i] = false;

    }
    distances[src_node] = 0; 
    for (int c = 0; c < (size() - 1); c++) {
        int u = Min_Dist(distances, spset); 
        spset[u] = true;
        for (int v = 0; v < size(); v++) { 
            int v_id = nodes_.at(v).id;
            bool is_edge = false;
            int dist;
            for (auto& ids : nodes_.at(u).neighbors) {
                if (ids.first == v_id) {
                    is_edge = true;
                    dist = ids.second; 
                    break;
                }
            }
            if (!spset[v] && is_edge && (distances[u] != INT16_MAX) && (distances[u] + dist < distances[v])) {
                distances[v] = distances[u] + dist; 
                parent[v] = nodes_.at(u).id;
            }
        }

    }
}
void Graph::Print_Short_Path_Distances() {
    cout << endl;
    for (int i = 0; i < size(); i++) {
        cout << "Vertex: " << nodes_.at(i).id << ", ";
        cout << "Dist from " << src_node << ": " << distances[i] << endl;
        cout << endl;
    }
}

void Graph::Print_Short_Path_Dist_Src_to_End() {
    cout << endl;
    cout << "Vertex: " << nodes_.at(end_idx).id << ", ";
    cout << "Dist from " << src_node << ": " << distances[end_idx] << endl;
    cout << endl;

}

vector<int> Graph::A_Short_Path_Src_to_End() {
    vector<int> a_path;
    int i = end_idx;
    while (i == end_idx) {
        a_path.push_back(nodes_.at(i).id);
        int parnode = parent[i];
        while (parnode != parent[src_node]) {
              a_path.push_back(nodes_.at(parnode).id);
              parnode = parent[parnode];
        }
        if (src_node == 0) {
            a_path.push_back(nodes_.at(0).id);
        }
        cout << endl;
        break;
    }
    return a_path;
}



void Graph::Print_Shortest_Paths() { 
    cout << "Printing shortest paths to src node" << endl;
    for (int i = 0; i < size(); i++) {
        cout << nodes_.at(i).id << " ";
        int parnode = parent[i];
        while (parnode != 0) {
               cout << " -> " << parnode << " ";
               parnode = parent[parnode];
        }
        //if (src_node == 0) {
            cout << "-> " << nodes_.at(0).id << endl;
        //}
        cout << endl;

    }
}

void Graph::Print_A_Shortest_Path() { 
    cout << "Printing the Shortest path from end to src node" << endl;
    int i = end_idx;
      while (i == end_idx) {
        cout << nodes_.at(i).id << " ";
        int parnode = parent[i];
        while (parnode != parent[src_node]) {
               cout << " -> " << nodes_.at(parnode).id << " ";
               parnode = parent[parnode];
        }
        //if (src_node == 0) {
            cout << "-> " << nodes_.at(0).id << endl;
        //}
        cout << endl;
        break;


    }
}

//-------------------Betweeness--------------------------------//


vector<int> Graph::Shortest_Path(int start, int end) {
    std::vector<int> path;
    std::cout << "getting shortest path from " << start << " to " << end << std::endl;
    //Shortest_Path_Algo(start);
    int i = end;
      while (i == end) {
        path.push_back(nodes_.at(i).id);
        int parnode = parent[i];
        while (parnode != parent[src_node]) {
               path.push_back(nodes_.at(parnode).id);
               parnode = parent[parnode];
        }
        // cout << "-> " << nodes_.at(src_node).id;
        cout << endl;
        break;
    }
    return path;
}

// ------------ Betweenness Algo Stuff -------------------- // 
vector<int> Graph::Betweenness() {
    vector<vector<int>> traveled(size(), vector<int>(size(), 0));
    vector<int> scores(size());
    // for node in nodes_
    for (Node node: nodes_) {
        // for node in neighbors
        for (pair<int, double> neighbor: node.neighbors) {
            if (traveled[node.id][neighbor.first] == 0) { // path not already traveled
                /// set this path to traveled (both ways)
                traveled[node.id][neighbor.first] = 1;
                traveled[neighbor.first][node.id] = 1;
                /// get shortest path between node and neighbor
                //vector<int> path = Shortest_Path(node.id, neighbor.first);
                /// increment scores for all intermediate nodes in path
                // for (unsigned int i = 1; i < path.size() - 1; i++) {
                //     int n = path[i];
                //     scores[n] = scores[n] + 1;
                // }
            }

        }
    }
    return scores;
}


// ------------- Parsing Stuff ------------------------- //
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
