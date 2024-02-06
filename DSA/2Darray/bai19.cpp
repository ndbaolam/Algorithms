#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 105

int n, m;
int a[MAX][MAX];
int dx[2] = {0, 1};
int dy[2] = {1, 0};
ll ans, sum;

void nhap()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j];
}

void loang(int i, int j)
{	
	cout << "loang den " << i <<" "<< j << endl;
	sum += a[i][j];
	for(int k=0; k<2; k++)
	{
		int i1=i+dx[k];
		int j1=j+dy[k];		
		if(i1 <= n && i1 >= 1 && j1 >=1 && j1 <= m)
		{
			loang(i1,j1);		
		}
		if(i1==n && j1==m)
		{
			ans=max(sum,ans);
			cout << ans << " " << sum << endl;	
		}
		sum-=a[i1][j1];
	}
}

int main()
{
	nhap();
	loang(1,1);
	cout << ans;
}