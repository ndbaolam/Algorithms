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
int deg[1005];
vector<int> topo;
int n, m;

void inp()
{
    cin >> n >> m;
    REP(i,1,m)
    {
        int x, y; cin >> x >> y;
        a[x].push_back(y);
        deg[y]++;
    }
}
void Kahn()
{
    queue<int> q;
    REP(i,1,n)
        if(deg[i] == 0)
            q.push(i);
    while(!q.empty())
    {
        int x = q.front(); q.pop();
        topo.push_back(x);
        for(int y : a[x])
        {
            --deg[y];
            if(deg[y] == 0)
                q.push(y);
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    inp();
    Kahn();
    for(int x : topo)
        cout << x << ' ';
}