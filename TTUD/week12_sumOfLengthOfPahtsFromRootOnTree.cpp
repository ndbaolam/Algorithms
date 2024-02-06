#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define pii pair<int,int>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
vector<pii> a[N];
int p[N], d[N], num[N], f[N], n;
//p[u]: cha cua u
//d[u]: tong do dai tat ca duong di tu u den con chau cua no
//num[u]: so luong con chau cua u (bao gom ca u)
//f[u]: tong do dai duong di tu tat ca cac nut tren T den u

void read(){
    cin >> n;
    REP(i, 1, n - 1){
        int u, v, w; cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
}

void dfs1(int u, int par){
    num[u] = 1;
    for(auto [v, w] : a[u]){
        if(v == par) continue;
        dfs1(v, u);
        d[u] += (d[v] + num[v] * w);
        num[u] += num[v];
    }
}

void dfs2(int u, int par){
    for(auto [v, w] : a[u]){
        if(v == par) continue;
        //int F = f[u] - d[v] - num[v] * w;
        //f[v] = F + d[v] + w * (n - num[v]);
        
        f[v] = f[u] + w * n;
        dfs2(v, u);
    }
}

int main(){
    read();
    dfs1(1, 0);
    f[1] = d[1];
    dfs2(1, 0);
    cout << *max_element(f + 1, f + n + 1);
}