#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= (int)b; ++i)
#define DREP(i,a,b) for(int i = (int)a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;

int n;
vector<int> a[1005];
int deg[1005], visited[1005];

void bfs(int v)
{
	queue<int> q;
	q.push(v);
	deg[v] = 0;
	visited[v] = 1;
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for(int y : a[x])
		{
			if(!visited[y])
			{
				visited[y] = 1;
				deg[y] = deg[x] + 1;
				q.push(y);
			}
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cin >> n;
	REP(i,1,n-1)
	{
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	REP(i,1,n)
		if(!visited[i])
			bfs(i);
	REP(i,1,n)
		cout << deg[i] << ' ';
}