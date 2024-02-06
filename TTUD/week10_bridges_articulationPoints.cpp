#include <bits/stdc++.h>
 
using namespace std;
 
const int maxN = 50010;

int n, m;
bool AP[maxN];
int timeDfs = 0, bridge = 0;
int low[maxN], num[maxN];
vector <int> g[maxN];
 
void dfs(int u, int pre) {
    int child = 0; // Số lượng con trực tiếp của đỉnh u trong cây DFS
    num[u] = low[u] = ++timeDfs;
    for (int v : g[u]) {
        if (v == pre) continue;
        if (!num[v]) {
            dfs(v, u); child++;
            low[u] = min(low[u], low[v]);
            if (num[u] < low[v]) bridge++;
            if (pre != -1 && num[u] <= low[v]) AP[u] = true;
        }
        else low[u] = min(low[u], num[v]);
    }
    if (u == -1 && child > 1)// Nếu u là đỉnh gốc của cây DFS
        AP[u] = true;
}
 
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) 
        if (!num[i]) dfs(i, -1);

    int cntAP = 0;
    for (int i = 1; i <= n; i++) cntAP += AP[i];

    cout << cntAP << ' ' << bridge;
}