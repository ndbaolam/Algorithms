#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= (int)b; ++i)
#define DREP(i,a,b) for(int i = (int)a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;

int n, m;
vector<int> a[1005];
bool visited[1005];

void inp()
{
	cin >> n >> m;
	REP(i,1,m)
	{
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}

void dfs(int v)
{
	visited[v] = true;
	for(int x : a[v])
		if(!visited[x])
			dfs(x);
}

int connected_component()
{
	int res = 0;
	REP(i,1,n)
	{
		if(!visited[i])
		{
			++res;
			dfs(i);
		}
	}
	return res;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	inp();
	int original_cc = connected_component();
	int ans = 0;
	REP(i,1,n)
	{
		memset(visited, false, sizeof(visited));
		visited[i] = true;
		int tmp = connected_component();
		if(tmp > original_cc) ++ans;
	}
	cout << ans << endl;
}