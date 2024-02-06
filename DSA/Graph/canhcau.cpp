#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= b; ++i)
#define DREP(i,a,b) for(int i = a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;
const int N = 1005;
const ll mod = 1e9 + 7;

set<int> a[N];
vector<pii> v;
bool visited[N];
int n, m;

void inp()
{
	cin >> n >> m;
	REP(i,1,m)
	{
		int x, y; cin >> x >> y;
		a[y].insert(x);
		a[x].insert(y);
		v.push_back({x,y});
	}
	memset(visited, false, sizeof(visited));
}

void DFS(int s)
{
	visited[s] = true;
	for(int x : a[s])
		if(!visited[x])
			DFS(x);
}

int connected_component()
{
	int cnt = 0;
	REP(i,1,n)
	{
		if(!visited[i])
		{
			++cnt;
			DFS(i);
		}
	}
	return cnt;
}

int main()
{
	inp();
	int cc = connected_component();
	int ans = 0;
	for(auto [x,y] : v)
	{
		a[x].erase(y);
		a[y].erase(x);
		memset(visited, false, sizeof(visited));
		int tmp = connected_component();
		if(tmp > cc) ++ans;
		a[x].insert(y);
		a[y].insert(x);
	}
	cout << ans << endl;	
}