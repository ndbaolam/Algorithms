#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int c[maxn], f[maxn], g[maxn];
bool visited[maxn];
vector <int> adj[maxn]; // Danh sách kề của các nút.

void dfs(int u)
{
    visited[u] = true;
    // Hai biến tổng lưu sum(g[v]) và sum(max(f[v], g[v]))
    int sum_f = 0, sum_g = 0;
    for (int v: adj[u])
    {
        if (visited[v]) continue;
        dfs(v);
        sum_f += g[v];
        sum_g += max(f[v], g[v]);
    }
    f[u] = c[u] + sum_f;
    g[u] = sum_g;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> c[i];
    for (int i = 1; i < N; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    cout << max(f[1], g[1]);
}
