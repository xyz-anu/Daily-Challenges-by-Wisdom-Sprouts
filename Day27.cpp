#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int shortestPath(int V, vector<pair<int, int>>& edges, int start, int end) {
    if (start == end) return 0;
    unordered_map<int, vector<int>> adj;
    unordered_set<string> edgeSet;
    for (auto& e : edges) {
        int u = e.first, v = e.second;
        string key = to_string(min(u, v)) + "_" + to_string(max(u, v));
        if (!edgeSet.count(key)) {
            adj[u].push_back(v);
            adj[v].push_back(u);
            edgeSet.insert(key);
        }
    }
    vector<int> dist(V, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                if (neighbor == end) return dist[neighbor];
                q.push(neighbor);
            }
        }
    }
    return -1;
}
int main() {
    int V1 = 5;
    vector<pair<int, int>> edges1 = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}};
    cout << "Test case 1 output: " << shortestPath(V1, edges1, 0, 4) << endl;
    int V2 = 3;
    vector<pair<int, int>> edges2 = {{0, 1}, {1, 2}};
    cout << "Test case 2 output: " << shortestPath(V2, edges2, 0, 2) << endl;
    int V3 = 4;
    vector<pair<int, int>> edges3 = {{0, 1}, {1, 2}};
    cout << "Test case 3 output: " << shortestPath(V3, edges3, 2, 3) << endl;
    int V4 = 1;
    vector<pair<int, int>> edges4 = {};
    cout << "Edge case output: " << shortestPath(V4, edges4, 0, 0) << endl;
    return 0;
}
