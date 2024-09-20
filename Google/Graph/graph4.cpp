#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<int> adj[n+1];
    vector<bool> visited(n+1, false);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int componentCount = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            componentCount++;
            dfs(i, adj, visited);
        }
    }

    cout << "Number of connected components: " << componentCount << endl;
    return 0;
}