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

char a[N][N];
int n, m;

int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};

void inp()
{
	cin >> n >> m;
	REP(i,1,n)
		REP(j,1,m)
			cin >> a[i][j];
}

void loang(int i, int j)
{
	a[i][j] = '#';
	REP(k,0,3)
	{
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(a[i1][j1] == '.')
			loang(i1,j1);
	}
}

int main()
{
	inp();
	int cnt = 0;
	REP(i,1,n)
	{
		REP(j,1,m)
		{
			if(a[i][j] == '.')
			{
				++cnt;
				loang(i,j);
			}
		}
	}
	cout << cnt << endl;
}