#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= b; ++i)
#define DREP(i,a,b) for(int i = a; i >= b; --i)
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
vector<int> a[1005];
bool visited[1005];
int parent[1005];
int n, m, s, t; 

void DFS(int u)
{
	visited[u] = true;
	sort(all(a[u]));
	for(int v : a[u])
	{
		if(!visited[v])
		{
			parent[v] = u;
			DFS(v);			
		}
	}
}

int main()
{
	cin >> n >> m >> s >> t;
	REP(i,1,m)
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
	DFS(s);
	if(visited[t])
	{
		vector<int> res;
		while(t != s)
		{
			res.push_back(t);
			t = parent[t];
		}
		res.push_back(s);
		reverse(all(res));
		for(int x : res)
			cout << x << ' ';
	}
	else cout << -1;
}