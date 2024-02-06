#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= b; ++i)
#define DREP(i,a,b) for(int i = a; i >= b; --i)
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
int visited[1005];
vector<int> a[1005];
int cnt = 1;

void DFS(int s)
{
    visited[s] = cnt;
    for(int x : a[s])
        if(!visited[x])
            DFS(x);
}

int main()
{
    int n, m; cin >> n >> m;
    while(m--)
    {
        int x, y; cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
 	REP(i,1,n)
 	{
 		if(!visited[i])
 		{
 			DFS(i);
 			++cnt;
 		}
 	}
 	int q; cin >> q;
 	while(q--)
 	{
 		int s, t; cin >> s >> t;
 		if(visited[s] == visited[t])
 			cout << 1 << endl;
 		else cout << -1 << endl;
 	}
}