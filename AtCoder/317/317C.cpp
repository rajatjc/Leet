#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Structure to represent a road between towns
struct Road {
    int townA;
    int townB;
    int length;
};

unordered_map<int, vector<Road>> graph;
vector<bool> visited;

// DFS function to explore paths and calculate total length
int dfs(int currentTown) {
    visited[currentTown] = true;
    int maxLength = 0;

    for (const Road& road : graph[currentTown]) {
        int nextTown = (road.townA == currentTown) ? road.townB : road.townA;
        if (!visited[nextTown]) {
            int length = road.length + dfs(nextTown);
            maxLength = max(maxLength, length);
        }
    }

    visited[currentTown] = false; // Backtrack
    return maxLength;
}

int main() {
    int N, M;
    cin >> N >> M;

    graph.clear();
    visited.assign(N + 1, false);

    for (int i = 0; i < M; ++i) {
        int townA, townB, length;
        cin >> townA >> townB >> length;
        graph[townA].push_back({townA, townB, length});
        graph[townB].push_back({townB, townA, length});
    }

    int maxTotalLength = 0;
    for (int startTown = 1; startTown <= N; ++startTown) {
        maxTotalLength = max(maxTotalLength, dfs(startTown));
    }

    cout << maxTotalLength << endl;

    return 0;
}
