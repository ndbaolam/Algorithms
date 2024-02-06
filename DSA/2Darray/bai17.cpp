#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 100

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

int a[MAX][MAX];
int n, m;

void nhap()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j];
}
void loang(int i, int j)
{
    a[i][j] = 0;
    for(int k = 0; k < 8; k++)
    {
        int i1 = i + dx[k], j1 = j + dy[k];
        if(a[i1][j1])
        	loang(i1, j1);    
    }
}
int main()
{
	
	nhap();
	int cnt=0;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j])
			{
				loang(i,j);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}