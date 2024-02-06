#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= (int)b; ++i)
#define DREP(i,a,b) for(int i = (int)a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;

int n, m, ans;
vector<int> k(1005), deg(1005);
vector<int> a[1005];
bool visited[1005];

void inp()
{
	cin >> n >> m;
	REP(i,1,n-1) cin >> k[i];
	REP(i,1,n-1)
	{
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}

void dfs(int v, int fear)
{
	visited[v] = true;
	fear += k[v];
	if(fear > m) return;
	for(int x : a[v])
	{
		if(!visited[x])
		{
			deg[x] = deg[v] + 1;
			ans = max(ans, deg[x]);
			dfs(x,fear);
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
	dfs(1,0);
	cout << ans << endl;
}