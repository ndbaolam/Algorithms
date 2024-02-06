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

vector<int> a[N];
bool visited[N];
int parent[N];
int n, m;

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

void DFS(int v)
{
	visited[v] = true;
	for(int x : a[v])
	{
		if(!visited[x])
		{
			visited[x] = true;
			DFS(x);
		}
	}
}

int main()
{
	inp();
	if(m != n-1)
	{
		cout << 0; return 0;
	}
	DFS(1);
	REP(i,1,n)
	{
		if(!visited[i])
		{
			cout << 0 << endl;
			return 0;
		}
	}
	cout << 1 << endl;
}