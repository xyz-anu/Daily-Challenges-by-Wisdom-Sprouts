#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
bool dfs(int node, int parent, unordered_map<int, vector<int>>& adj, unordered_set<int>& visited) {
    visited.insert(node);
    for (int neighbor : adj[node]) {
        if (!visited.count(neighbor)) {
            if (dfs(neighbor, node, adj, visited))
                return true;
        } else if (neighbor != parent) {
            // Cycle detected
            return true;
        }
    }
    return false;
}
bool hasCycle(int V, vector<pair<int, int>>& edges) {
   
    if (edges.empty()) return false;

    for (auto& e : edges) {
        if (e.first == e.second)
            return true;
    }
    unordered_set<string> edgeSet;
    for (auto& e : edges) {
        int u = min(e.first, e.second);
        int v = max(e.first, e.second);
        string key = to_string(u) + "-" + to_string(v);
        if (edgeSet.count(key))
            return true;
        edgeSet.insert(key);
    }
    unordered_map<int, vector<int>> adj;
    for (auto& e : edges) {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }

    unordered_set<int> visited;
    for (int i = 0; i < V; ++i) {
        if (!visited.count(i)) {
            if (dfs(i, -1, adj, visited))
                return true;
        }
    }
    return false;
}
int main() {
    vector<pair<int, int>> edges1 = {{0,1},{1,2},{2,3},{3,4},{4,0}};
    cout << (hasCycle(5, edges1) ? "true" : "false") << endl; 
    vector<pair<int, int>> edges2 = {{0,1},{1,2}};
    cout << (hasCycle(3, edges2) ? "true" : "false") << endl;
    vector<pair<int, int>> edges3 = {};
    cout << (hasCycle(4, edges3) ? "true" : "false") << endl; 
    vector<pair<int, int>> edges4 = {{0,1},{1,2},{2,0},{2,0}};
    cout << (hasCycle(4, edges4) ? "true" : "false") << endl; 
    vector<pair<int, int>> edges5 = {{1,1}};
    cout << (hasCycle(2, edges5) ? "true" : "false") << endl; 
    return 0;
}
