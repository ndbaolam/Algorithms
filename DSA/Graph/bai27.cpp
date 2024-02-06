#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= (int)b; ++i)
#define DREP(i,a,b) for(int i = (int)a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;
const int N = 1005;
const ll mod = 1e9 + 7;

vector<int> a[N];
bool visited[N];
int n, m, cnt;

void inp()
{
	cin >> n >> m;
	REP(i,1,m)
	{
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
}

void DFS(int v)
{
	++cnt;
	visited[v] = true;
	for(int x : a[v])
		if(!visited[x])
			DFS(x);
}

int main()
{
	inp();
	int ans = 0;
	REP(i,1,n)
	{
		if(!visited[i])
			DFS(i);
		ans = max(ans, cnt);
		cnt = 0;
	}
	cout << ans << endl;
}