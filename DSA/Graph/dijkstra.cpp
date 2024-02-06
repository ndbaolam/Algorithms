#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= (int)b; ++i)
#define DREP(i,a,b) for(int i = (int)a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;

const int INF = 1e9;
vector<pii> a[100001];
int n, m, s;

void inp()
{
    cin >> n >> m >> s;
    REP(i,1,m)
    {
        int x, y, w; cin >> x >> y >> w;
        a[x].push_back({y,w});
        a[y].push_back({x,w});
    }
}

void dijkstra(int s)
{
    vector<ll> d(n + 1, INF);
    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    //{khoang cach, dinh}
    Q.push({0,s});
    while(!Q.empty())
    {
        pii top = Q.top(); Q.pop();
        int u = top.se, k = top.fi;
        for(auto i : a[u])
        {
            int v = i.fi, w = i.se;
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }
    REP(i,1,n)
        cout << d[i] << ' ';
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    inp();
    dijkstra(s);
}