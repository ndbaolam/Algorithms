#include<bits/stdc++.h>
#include "E:\Code\Cprograming\debug.h"
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= (int)b; ++i)
#define DREP(i,a,b) for(int i = (int)a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;

vector<int> a[1005], trans_a[1005];
bool visited[1005];
stack<int> st;
int n, m;

void inp()
{
    cin >> n >> m;
    REP(i,1,m)
    {
        int x, y; cin >> x >> y;
        a[x].push_back(y);
        trans_a[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void dfs1(int v)
{
    visited[v] = true;
    for(int x : a[v])
        if(!visited[x])
            dfs1(x);
    st.push(v);
}

void dfs2(int v)
{
    visited[v] = true;
    for(int x : trans_a[v])
        if(!visited[x])
            dfs2(x);
}

void Kosaraju()
{
    REP(i,1,n) if(!visited[i]) dfs1(i);
    debug(st);
    memset(visited, false, sizeof(visited));
    int scc = 0;
    while(!st.empty())
    {
        int x = st.top(); st.pop();
        if(!visited[x])
        {
            ++scc;
            dfs2(x);
        }
    }
    cout << scc << endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    inp();
    Kosaraju();
}