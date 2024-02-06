#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= (int)b; ++i)
#define DREP(i,a,b) for(int i = (int)a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;

vector<int> a[1005];
vector<int> topo;
bool visited[1005];

void dfs(int v)
{
    visited[v] = true;
    for(int x : a[v])
        if(!visited[x]);
            dfs(x);
    topo.push_back(v);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m; cin >> n >> m;
    REP(i,1,m)
    {
        int x, y; cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    REP(i,1,n)
        if(!visited[i])
            dfs(i);
    reverse(all(topo));
    for(int x : topo)
        cout << x << ' ';
}