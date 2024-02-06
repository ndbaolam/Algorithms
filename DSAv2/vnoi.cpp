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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;
	char a[n+1][m+1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j];

	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m-2;j++)
		{
			if(a[i][j]=='.')
			{
				if(a[i][j+1]=='.'&&a[i][j+2]=='.')
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
}