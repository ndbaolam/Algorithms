#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 105

int a[MAX][MAX];
int n;
ll d[MAX][MAX];

void nhap()
{
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin >>a[i][j];
}

void prefix()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			d[i][j] = d[i-1][j] + d[i][j-1] - d[i-1][j-1] + a[i][j];
		}
	}
}

int main()
{
	ll sum = 0, ans = 0;
	nhap();
	prefix();
	for(int i=3;i<=n;i++)
	{
		for(int j=3;j<=n;j++)
		{
			sum = d[i][j] - d[i-3][j] - d[i][j-3] + d[i-3][j-3];
			ans = max(ans,sum);
		}
	}
	cout << ans;
}