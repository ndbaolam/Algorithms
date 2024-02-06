#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 105

int a[MAX][MAX];
int n, s, t, cnt;

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};

void nhap()
{
	memset(a,1,sizeof(a));
	cin >> n >> s >> t;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin >>a[i][j];
}

void loang(int i, int j)
{
	++cnt;
	a[i][j]=1;
	for(int k=0;k<4;k++)
	{
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(a[i1][j1]==0)
		{
			loang(i1,j1);
		}
	}
}

int main()
{
	nhap();
	loang(s,t);
	cout << cnt;
}