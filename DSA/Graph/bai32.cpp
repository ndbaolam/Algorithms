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

int n, m, cnt;
char a[N][N];
vector<int> res;
int dx[] = {0,-1,1,0};
int dy[] = {-1,0,0,1};


void DFS(int i, int j)
{
	a[i][j] = '#';
	++cnt;
	REP(k,0,3)
	{
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(a[i1][j1] == '.')
			DFS(i1,j1);
	}
}

int main()
{
	cin >> n >> m;
	REP(i,1,n) REP(j,1,m) cin >> a[i][j];
	REP(i,1,n)
	{
		REP(j,1,m)
		{
			if(a[i][j] == '.')
			{
				cnt = 0;
				DFS(i,j);
				res.push_back(cnt);
			}
		}
	}
	for(int x : res)
		cout << x << ' ';
}