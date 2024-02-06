#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= (int)b; ++i)
#define DREP(i,a,b) for(int i = (int)a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;

int d[1005][1005];
// d[i][j] duong di ngan nhan tu i den j
int n, m;

void inp()
{
	REP(i,1,1004) REP(j,1,1004) d[i][j] = 1e9;
	REP(i,1,1004) d[i][i] = 0;
	cin >> n >> m;
	REP(i,1,m)
	{
		int x, y, w;
		cin >> x >> y >> w;
		d[x][y] = d[y][x] = w;
	}
}

void Floyd()
{
	REP(k,1,n) REP(i,1,n) REP(j,1,n)
	d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
	inp();
	Floyd();
	int q; cin >> q;
	while(q--)
	{
		int x, y; cin >> x >> y;
		cout << d[x][y] << endl;
	}
}