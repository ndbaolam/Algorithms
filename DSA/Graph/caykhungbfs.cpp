#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= (int)b; ++i)
#define DREP(i,a,b) for(int i = (int)a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;

int n, m, t;
vector<int> a[1005];
bool visited[1005];

void inp()
{
	cin >> n >> m >> t;
	REP(i,1,m)
	{
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	REP(i,1,n) sort(all(a[i]));
}

void bfs(int v)
{
	queue<int> q;
	q.push(v);
	visited[v] = true;
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for(int y : a[x])
		{
			if(!visited[y])
			{
				q.push(y);
				visited[y] = true;
				cout << x << "->" << y << endl;
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
	inp();
	bfs(t);
}