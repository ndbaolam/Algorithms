#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 505

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
int a[MAX][MAX];
ll d[MAX][MAX];
int cnt, ans;

void loang(int i, int j)
{
	++cnt;
	a[i][j]=0;
	for(int k=0;k<4;k++)
	{
		int i1 = i+dx[k];
		int j1 = j+dy[k];
		if(a[i1][j1])
			loang(i1,j1);
	}
	ans=max(ans,cnt);
	cnt=0;
}

int main()
{
	int n, m; cin >> n >> m;
	for(int i=1;i<=n;i++)	
		for(int j=1;j<=m;j++)
			cin >> a[i][j];

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j])
				loang(i,j);
		}
	}
	cout << ans;
}