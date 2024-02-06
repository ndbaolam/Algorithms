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

int a[N][N];
int x, y, z ,t, n;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
int d[N][N];

int BFS(int x, int y)
{
	queue<pii> q;
	q.push({x,y});
	a[x][y] = 0;
	d[x][y] = d[z][t] = 0;
	while(!q.empty())
	{
		pii x = q.front(); q.pop();
		int i = x.fi, j = x.se;
		if(i == z && j == t)
			return d[z][t];
		REP(k,0,7)
		{
			int i1 = i + dx[k];
			int j1 = j + dy[k];
			if(a[i1][j1])
			{
				a[i1][j1] = 0;
				d[i1][j1] = d[i][j] + 1;
				q.push({i1,j1});
			}
		}
	}
	return -1;
}

int main()
{	
	cin >> n >> x >> y >> z >> t; 
	REP(i,1,n) REP(j,1,n) cin >> a[i][j];
	//int cnt = -1;
	cout << BFS(x,y) << endl;
}