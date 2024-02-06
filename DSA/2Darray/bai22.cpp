#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 105

int n, m, s, t, u, v;
int a[MAX][MAX];
int dx[8] = {-2,-2,-1,-1,1,2,2,1};
int dy[8] = {-1,1,-2,2,-2,-1,1,2};

void nhap()
{
	cin >> n;
	m=n;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j];
}

int main()
{
	nhap();
	int j=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==1 || i==n)
				cout << a[i][j] << " ";
			else if(j==1||j==m)
				cout << a[i][j] << " ";
		}
	}
}