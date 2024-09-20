#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    // Adjacency Matrix Representation
    vector<vector<int>> adjMatrix(n+1, vector<int>(n+1, 0));

    // Adjacency List Representation
    vector<vector<int>> adjList(n+1);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // For undirected graph, mark both directions
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Printing Adjacency Matrix
    cout << "\nAdjacency Matrix:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // Printing Adjacency List
    cout << "\nAdjacency List:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (int j : adjList[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}