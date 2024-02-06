#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 105

int n, m, s, t, u, v;
int a[MAX][MAX];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

void nhap()
{
	cin >> n >> m;
	cin >> s >> t >> u >> v;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j];
}

void loang(int i, int j)
{	
	a[i][j]=0;
	for(int k=0; k<4; k++)
	{
		int i1=i+dx[k];
		int j1=j+dy[k];		
		if(a[i1][j1])
		{
			loang(i1,j1);		
		}
	}
}

int main()
{
	nhap();
	loang(s,t);
	if(a[u][v]==0)cout << "YES";
	else cout << "NO";
}