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
int color[1005];
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
	memset(color, -1, sizeof(color));
}

bool bfs(int v)
{
	queue<int> q;
	q.push(v);
	color[v] = 0;
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for(int y : a[x])
		{
			if(color[y] == color[x]) return false;
			if(color[y] == -1)
			{
				color[y] = !color[x];
				q.push(y);
			}
		}
	}
	return true;
}	

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	inp();
	bool check = true;
	REP(i,1,n)
	{
		if(color[i] == -1)
		{
			if(!bfs(i))
			{
				check = false;
				break;
			}
		}
	}
	if(check) cout << "YES" << endl;
	else cout << "NO" << endl;
}