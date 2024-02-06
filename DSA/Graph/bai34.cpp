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
vector<int> cnt(N);
int b[105];
bool visited[N];
int n, m, k;

void inp()
{
	cin >> k >> n >> m;
	REP(i,1,k) cin >> b[i];
	REP(i,1,m)
	{
		int x, y; cin >> x >> y;
		a[x].push_back(y);
	}
}

void dfs(int v)
{
	++cnt[v];
	visited[v] = true;
	for(int x : a[v])
		if(!visited[x])
			dfs(x);
}

int main()
{
	inp();
	REP(i,1,k)
	{
		memset(visited, false, sizeof(visited));
		dfs(b[i]);
	}
	int ans = 0;
	REP(i,1,n) if(cnt[i] == k) ++ans;
	cout << ans << endl;
}