#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fi first
#define se second

using namespace std;
using ll = long long;
using pii = pair <int,int>;

const int INF = 1e9;
const int MAX = 1e9+5;
const ll mod = 1e9+7;

int n, m, ans;
int a[10][10];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void loang(int i, int j)
{
	if(i==n && j==m)
		++ans;
	else
	{
		for(int k=0;k<2;k++)
		{
			int i1 = i+dx[k];
			int j1 = j+dy[k];
			if(a[i1][j1]) 
				loang(i1,j1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j];

	loang(1,1);
	cout << ans;
}