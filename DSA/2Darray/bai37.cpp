#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 105

int a[MAX][MAX];
int n;
ll d[MAX][MAX];
int dx[3]= {-1,-1,-1};
int dy[3]= {-1,0,1};

void nhap()
{
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin >>a[j][i];
}

void pre()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<3;k++)
			{
				int i1 = i+dx[k];
				int j1 = j+dy[k];
				d[i][j] = max(a[i][j]+d[i1][j1],d[i][j]);
			}
		}
	}
}

int main()
{
	nhap();
	pre();
	
	cout << *max_element(d[n],d[n]+n);
}