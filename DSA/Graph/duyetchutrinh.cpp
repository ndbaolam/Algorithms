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

int n, m, s, t;
vector<int> a[N];
bool visited[N];
int color[N];
int parent[N];

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

bool DFS(int s)
{
	color[s] = 1;
	for(int x : a[s])
	{
		if(color[x] == 0)
		{
			//parent[x] = s;
			if(DFS(x)) return true;
		}
		else if(color[x] == 1) return true;
	}
	color[s] = 2;
	return false;
}

int main()
{
	inp();
	REP(i,1,n)
	{
		if(!color[i])
		{
			if(DFS(i))
			{
				cout << 1 << endl;
				return 0;
			}
		}
	}
	cout << 0 << endl;
	return 0;
}