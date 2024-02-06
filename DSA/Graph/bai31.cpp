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
bool visited[1005];
int sz[10005];

int dfs(int u)
{
	visited[u] = true;
	int res = 1;
	for(int x : a[u])
	{
		if(!visited[x])
			res += dfs(x);
	}
	return sz[u] = res;
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
	dfs(1);
	int ans = 0;
	REP(i,1,n)
	{
		cout << i << ' ' << sz[i] << endl;
		ans += sz[i];
	}
	cout << ans;
}