#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 105

int dx[3]={-1,-1,-1};
int dy[3]={-1,0,1};
int a[MAX][MAX];
ll d[MAX][MAX];

int main()
{
	int n; cin >> n;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin >> a[i][j];

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==1) d[i][j]=a[i][j];
			else
			{
				for(int k=0;k<3;k++)
				{
					int i1 = i+dx[k];
					int j1 = j+dy[k];
					d[i][j]=max(d[i1][j1]+a[i][j],d[i][j]);
				}
			}
		}
	}

	cout << *max_element(d[n],d[n]+n);
}