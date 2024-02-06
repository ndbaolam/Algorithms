#include <iostream>
#include <vector>
using namespace std;

vector<int> w;
vector<vector<int>> adjList;
vector<bool> visited;
int maxWeight;

void backtrack(int v, int prev, int currentWeight) {
    visited[v] = true;
    currentWeight += w[v];
    maxWeight = max(maxWeight, currentWeight);
    for (int next : adjList[v]) {
        if (!visited[next] && next != prev) {
            backtrack(next, v, currentWeight);
        }
    }
    visited[v] = false;
}

int main() {
    int n;
    cin >> n;
    w.resize(n + 1);
    adjList.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    maxWeight = 0;
    backtrack(1, -1, 0);

    cout << maxWeight << endl;

    return 0;
}