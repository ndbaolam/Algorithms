#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

int n, m, r, c;
int d[1005][1005], a[1005][1005];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void read()
{
	cin >> n >> m >> r >> c;
	REP(i, 1, n) REP(j, 1, m) cin >> a[i][j];
}

int sovle()
{
	queue<pii> q;
	q.push({r, c});
	a[r][c] = 1;
	while(!q.empty())
	{
		pii top = q.front(); q.pop();
		int x = top.first, y = top.second;
		if(x > n or x < 1 or y > m or y < 1) return d[x][y];

		REP(k, 0, 3)
		{
			int i = x + dx[k], j = y + dy[k];
			if(!a[i][j])
			{
				q.push({i, j});
				a[i][j] = 1;
				d[i][j] = d[x][y] + 1;
			}
		}
	}
	return -1;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	faster();
	
	read();
	cout << sovle();
}