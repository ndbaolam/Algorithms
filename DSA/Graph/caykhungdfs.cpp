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
bool visited[1005];
int parent[1005];
vector<int> res;
int n, m, t;

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

void dfs(int v)
{
	visited[v] = true;
	res.push_back(v);
	for(int x : a[v])
	{
		if(!visited[x])
		{
			parent[x] = v;
			dfs(x);
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
	dfs(t);
	for(int x : res)
	{
		if(x == *res.begin()) continue;
		cout << parent[x] << "->" << x << endl;
	}
}