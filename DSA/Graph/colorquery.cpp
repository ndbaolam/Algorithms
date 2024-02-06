#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, q;
int a[N];

struct DSU{
    vector<map<int, int>> color;
    vector<int> parent, sz;
    //dinh v mau a[v] so luong color[v][a[v]]
    DSU(int n) : color(n), parent(n), sz(n) {};

    void make_set(int v) {
        color[v][a[v]] = 1;
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        return (v ==  parent[v]) ? v : parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];

            for (auto p : color[b]) color[a][p.first] += p.second;
            color[b].clear();
        } 
    }

    int query(int v, int c) {
        v = find_set(v);
        return color[v].find(c) != color[v].end() ? color[v][c] : 0;
    }
};

signed main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    DSU g(n + 5);
    for (int i = 1; i <= n; i++) g.make_set(i);
    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) g.union_sets(x, y);
        else cout << g.query(x, y) << "\n";
    }
}